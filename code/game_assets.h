#pragma once
#include "precomp.h"
#include "game_defines.h"
#include "game_memory.h"


// TODO: „M„u„~„u„t„w„u„‚ „‚„u„ƒ„…„‚„ƒ„€„r „y „„€„„„€„{„€„r„…„ „„€„t„s„‚„…„x„{„…

void LoadGameSpriteFromImage(Canvas &canvas, Sprite &sprite, const char* sprite_name);
void LoadGameSpriteFromResource(Canvas &canvas, ResourceManager* resources, Sprite &sprite, const char* sprite_name);
void AddGameSpriteFrameFromImage(Canvas &canvas, Sprite &sprite, const char* frame_name);
