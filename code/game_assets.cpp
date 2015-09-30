#include "game_assets.h"

void LoadGameSpriteFromImage(Canvas &canvas, Sprite &sprite, const char* sprite_name)
{
	sprite = Sprite(canvas, sprite_name);
}

void LoadGameSpriteFromResource(Canvas &canvas, ResourceManager* resources, Sprite &sprite, const char* sprite_name)
{
	sprite = Sprite::resource(canvas, sprite_name, *resources);
}

void AddGameSpriteFrameFromImage(Canvas &canvas, Sprite &sprite, const char* frame_name)
{
	sprite.add_frame(canvas, frame_name);
}
