#include "Win32_app.h"
/*
    === Win32 platform layer ===

	Не совсем чистая платформенная оболочка, учитывая, что используется кланлиб,
	но сюда вынесен по возможности весь Win32-зависимый код.
*/

#include "game_assets.h"

// Когда последний раз обновлялся файл
// - используется для динамического обновления кода игры
inline FILETIME Win32_GetLastWriteTime(char *Filename)
{
	FILETIME LastWriteTime = {};

	WIN32_FIND_DATA FindData;
	HANDLE FileHandle = FindFirstFileA(Filename, &FindData);
	if (FileHandle != INVALID_HANDLE_VALUE)
	{
		LastWriteTime = FindData.ftLastWriteTime;
		FindClose(FileHandle);
	}

	return LastWriteTime;
}

// Подгружает код из dll
win32_game_code Win32_LoadGameCode(char* SourceDLLName)
{
	win32_game_code Result = {};
	Result.GameUpdate = GameUpdateStub;
	Result.GameRender = GameRenderStub;

	char* TempDLLName = "Game_temp.dll";

	Result.DLLLastWriteTime = Win32_GetLastWriteTime(SourceDLLName);

	CopyFile(SourceDLLName, TempDLLName, FALSE);
	Result.GameCodeDLL = LoadLibraryA(TempDLLName);
	if (Result.GameCodeDLL)
	{
		Result.GameUpdate = (game_update*) GetProcAddress(Result.GameCodeDLL, "GameUpdate");
		Result.GameRender = (game_render*) GetProcAddress(Result.GameCodeDLL, "GameRender");

		Result.IsValid = (Result.GameUpdate && Result.GameRender);
	}
	if (!Result.IsValid)
	{
		Result.GameUpdate = GameUpdateStub;
		Result.GameRender = GameRenderStub;
	}

	return Result;
}

// Выгружает библиотеку с динамическим кодом из памяти
void Win32_UnloadGameCode(win32_game_code *GameCode)
{
	if (GameCode->GameCodeDLL)
	{
		FreeLibrary(GameCode->GameCodeDLL);
	}
	GameCode->IsValid = false;
	GameCode->GameUpdate = GameUpdateStub;
	GameCode->GameRender = GameRenderStub;
}


// ClanLib specifics
ApplicationInstance<Win32_App> clanapp;

Win32_App::Win32_App()
{
	SourceDLLName = "Game.dll";
	//GameCode = Win32_LoadGameCode(SourceDLLName);

#ifdef _DEBUG
	// Дебажная консоль
	FileLogger flogger("debug.log");
	log_event("SYSTEM", "Logger initialized");
#endif

	try
	{
		// We support all display targets, in order listed here
#ifdef WIN32
		D3DTarget::enable();
#endif
		OpenGLTarget::enable();
	}
	catch (Exception exception)
	{
		// Create a console window for text-output if not available
		ConsoleWindow console("Console", 80, 160);
		Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console.display_close_message();

		quit = true;
	}

	// TODO: сохранять настройки графики
	fullscreen = 0;
	// TODO: Масштабировать окно
	InitScreenSize = Sizef(1024.0f, 768.0f);
	ScreenSize = InitScreenSize;
	DisplayWindowDescription window_description;
	window_description.set_title("Robot Game");
	window_description.set_size(ScreenSize, true);
	window_description.set_allow_resize(true);
	//window_description.set_type(WindowType::tool);
	window = DisplayWindow(window_description);

	canvas = Canvas(window);

	// Подключим коллбэки на слоты пользовательского ввода
	keyboard = window.get_ic().get_keyboard();
	sc.connect(window.sig_window_close(), bind_member(this, &Win32_App::Win32_OnWindowClose));
	sc.connect(window.get_ic().get_keyboard().sig_key_up(), bind_member(this, &Win32_App::Win32_OnKeyUp));
	sc.connect(window.get_ic().get_keyboard().sig_key_down(), bind_member(this, &Win32_App::Win32_OnKeyDown));
	sc.connect(window.get_ic().get_mouse().sig_key_down(), bind_member(this, &Win32_App::Win32_OnMouseDown));

	// Sound
	SoundOutput sound_output(48000);
/*
	SoundBuffer sbuffer("cheer1.ogg");
	sbuffer.play();
*/


	// Game memory
	LPVOID BaseAddress = 0;
	GameMemory.PermanentStorageSize = Megabytes(256);
	GameMemory.TransientStorageSize = Megabytes(256);
	size_t TotalStorageSize = (size_t)(GameMemory.PermanentStorageSize + GameMemory.TransientStorageSize);
	GameMemory.PermanentStorage = VirtualAlloc(BaseAddress, TotalStorageSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	GameMemory.TransientStorage = ((uint8*)GameMemory.PermanentStorage + GameMemory.PermanentStorageSize);

	// Game state
	GameState = (game_state*)GameMemory.PermanentStorage;
	*GameState = {};
	GameState->ScreenSize = ScreenSize;


	// Resources
	//OpenGLTarget::set_current();
	GameState->game_resources = clan::XMLResourceManager::create(clan::XMLResourceDocument("sprites.xml"));

	GameState->LoadGameSpriteFromImage = &LoadGameSpriteFromImage;
	GameState->LoadGameSpriteFromResource = &LoadGameSpriteFromResource;
	GameState->AddGameSpriteFrameFromImage = &AddGameSpriteFrameFromImage;

	// Main display buffers
	//GameState->MainDisplayBuffer = PixelBuffer(1024, 768, TextureFormat::tf_rgba8, GameMemory.TransientStorage);


	// Win32 Timings
	CanSleepSafe = (timeBeginPeriod(1) == TIMERR_NOERROR);
	QueryPerformanceFrequency(&PerfCounterFrequencyQ);
	PerfCounterFrequency = PerfCounterFrequencyQ.QuadPart;

	QueryPerformanceCounter(&LastCounter);

	LastCycleCount = __rdtsc();

	game_time.reset();

	//console.display_close_message();
	//timeEndPeriod(1);
}

// Вызывается кланлибом непрерывно, пока возвращает true
bool Win32_App::update()
{
#ifdef _DEBUG
	// Update game code
	FILETIME DLLWriteTime = Win32_GetLastWriteTime(SourceDLLName);
	if (CompareFileTime(&DLLWriteTime, &GameCode.DLLLastWriteTime) != 0)
	{
		Win32_UnloadGameCode(&GameCode);
		GameCode = Win32_LoadGameCode(SourceDLLName);
	}
#endif

	game_time.update();

	// Timing
	LARGE_INTEGER EndCounter;
	uint64 EndCycleCount = __rdtsc();
	QueryPerformanceCounter(&EndCounter);
	uint64 CounterElapsed = EndCounter.QuadPart - LastCounter.QuadPart;
	mSecsElapsed = ((1000.0f * (float)CounterElapsed) / (float)PerfCounterFrequency);

	/*
	uint64 CyclesElapsed = EndCycleCount - LastCycleCount;
	uint32 fps = (uint32)PerfCounterFrequency / (uint32)CounterElapsed;
	uint32 mcyc = (uint32)(CyclesElapsed / 1000000);
	log_event("TIMING", "ms : %1, mcyc : %2, fps : %3", mSecsElapsed, mcyc, fps);
	*/
	LastCounter = EndCounter;
	LastCycleCount = EndCycleCount;

	// NOTE: Зафиксируем максимальный возможный лаг для внутриигрового времени в 30 фпс
	float mSecsToUpdate = 33.3f;
	if (mSecsElapsed < mSecsToUpdate)
		mSecsToUpdate = mSecsElapsed;
	GameState->TimeFromLastFrame = mSecsToUpdate;

	// Проверка состояния клавиатуры для избежания залипания клавиш при пропуске событий key_up
	Win32_CheckKeyboard();

	// Game logic
	// Апдейт состояния - ему уходит адрес памяти с игровыми данными, тайминг, (ввод пользователя?)
	if (GameCode.IsValid)
		GameCode.GameUpdate(&GameMemory, canvas);
	// Вывод графики и звука - канвас, буфер графики, (буфер звука?)
	canvas.clear(Colorf(0.0f, 0.0f, 0.0f));
	if (GameCode.IsValid)
		GameCode.GameRender(&GameMemory, canvas);
	// temp buffer
	//Image Image1(canvas, GameState->MainDisplayBuffer, Rect(0, 0, 1024, 768));
	//Image1.draw(canvas, 0, 0);


	// Sleep timings
	EndCycleCount = __rdtsc();
	QueryPerformanceCounter(&EndCounter);
	CounterElapsed = EndCounter.QuadPart - LastCounter.QuadPart;
	mSecsElapsed = ((1000.0f * (float)CounterElapsed) / (float)PerfCounterFrequency);

	DWORD time_to_sleep = 0;
	if (mSecsElapsed < mSecsPerFrame)
		time_to_sleep = (DWORD)(mSecsPerFrame - mSecsElapsed);

	if (CanSleepSafe)
	{
		if (mSecsElapsed < mSecsPerFrame)
		{
			//log_event("TIMING", "time to sleep : %1", time_to_sleep);
			Sleep(time_to_sleep);
		}
	}
	else
	{
		System::sleep(time_to_sleep);
	}

	window.flip(0);

	return !quit;
}


void Win32_App::Win32_OnWindowClose()
{
	quit = true;
}

void Win32_App::Win32_OnKeyDown(const InputEvent &key)
{
	if (key.id == keycode_up)
	{
		GameState->GameInput.KeyStateUp = 1;
	}
	if (key.id == keycode_down)
	{
		GameState->GameInput.KeyStateDown = 1;
	}
	if (key.id == keycode_left)
	{
		GameState->GameInput.KeyStateLeft = 1;
	}
	if (key.id == keycode_right)
	{
		GameState->GameInput.KeyStateRight = 1;
	}
	if (key.id == keycode_shift)
	{
		GameState->GameInput.ShiftPressed = 1;
	}
	if (key.id == keycode_space)
	{
		GameState->GameInput.Key1_last = GameState->GameInput.Key1;
		GameState->GameInput.Key1 = 1;
	}
}

void Win32_App::Win32_OnKeyUp(const InputEvent &key)
{
	if((key.id == keycode_f4) && key.alt)
	{
		quit = true;
	}
	if (key.id == keycode_f11)
	{
		fullscreen = !fullscreen;
		window.toggle_fullscreen();
		if (!fullscreen)
		{
			window.set_size(InitScreenSize.width, InitScreenSize.height, true);
		}
		ScreenSize = window.get_geometry().get_size();
		GameState->ScreenSize = ScreenSize;
	}

	if (key.id == keycode_up)
	{
		GameState->GameInput.KeyStateUp = 0;
	}
	if (key.id == keycode_down)
	{
		GameState->GameInput.KeyStateDown = 0;
	}
	if (key.id == keycode_left)
	{
		GameState->GameInput.KeyStateLeft = 0;
	}
	if (key.id == keycode_right)
	{
		GameState->GameInput.KeyStateRight = 0;
	}
	if (key.id == keycode_shift)
	{
		GameState->GameInput.ShiftPressed = 0;
	}
	if (key.id == keycode_space)
	{
		GameState->GameInput.Key1_last = GameState->GameInput.Key1;
		GameState->GameInput.Key1 = 0;
	}
}

void Win32_App::Win32_OnMouseDown(const InputEvent &key)
{
}

void Win32_App::Win32_CheckKeyboard()
{
	if (!keyboard.get_keycode(keycode_up))
	{
		GameState->GameInput.KeyStateUp = 0;
	}
	if (!keyboard.get_keycode(keycode_down))
	{
		GameState->GameInput.KeyStateDown = 0;
	}
	if (!keyboard.get_keycode(keycode_left))
	{
		GameState->GameInput.KeyStateLeft = 0;
	}
	if (!keyboard.get_keycode(keycode_right))
	{
		GameState->GameInput.KeyStateRight = 0;
	}
	if (!keyboard.get_keycode(keycode_shift))
	{
		GameState->GameInput.ShiftPressed = 0;
	}
	if (!keyboard.get_keycode(keycode_space))
	{
		if (GameState->GameInput.Key1)
			GameState->GameInput.Key1_last = GameState->GameInput.Key1;
		GameState->GameInput.Key1 = 0;
	}
}
