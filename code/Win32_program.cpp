#include "precomp.h"
#include "Win32_program.h"
#include "Win32_app.h"


int Program::main(const std::vector<std::string> &args)
{
	try
	{
		#ifdef _DEBUG
		// Дебажная консоль
		ConsoleLogger logger;
		FileLogger flogger("debug.log");
		log_event("SYSTEM", "Logger initialized");
		#endif

		// We support all display targets, in order listed here
#ifdef WIN32
		D3DTarget::enable();
#endif
		OpenGLTarget::enable();

		// Start the Application
		Win32_App app;
		int retval = app.main(args);
		return retval;
	}
	catch(Exception exception)
	{
		// Create a console window for text-output if not available
		ConsoleWindow console("Console", 80, 160);
		Console::write_line("Exception caught: " + exception.get_message_and_stack_trace());
		console.display_close_message();

		return -1;
	}
}

// Instantiate Application, informing it where the Program is located
Application app(&Program::main);
