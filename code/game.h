#if !defined(GAME_H)
#include "game_state_defines.h"


// DLL export defines
#define GAME_UPDATE(name) void name(game_memory* Memory, Canvas &canvas)
typedef GAME_UPDATE(game_update);
GAME_UPDATE(GameUpdateStub)
{
}

#define GAME_RENDER(name) void name(game_memory* Memory, Canvas &canvas)
typedef GAME_RENDER(game_render);
GAME_RENDER(GameRenderStub)
{
}


#define GAME_H
#endif
