#pragma once
#include <cstdint>
#include <math.h>
#include "game_defines.h"
#include "game_memory.h"
#include "tile_map.h"
#include "game_entity.h"

#define TICK_DURATION 16.7f

struct game_button_state
{
	int HalfTransitionCount;
	int EndedDown;
};

struct game_controller_input
{
	bool IsAnalog;

	float StartX;
	float StartY;

	float MinX;
	float MinY;

	float MaxX;
	float MaxY;

	float EndX;
	float EndY;

	union
	{
		game_button_state Buttons[6];
		struct
		{
			game_button_state Up;
			game_button_state Down;
			game_button_state Left;
			game_button_state Right;
			game_button_state LeftShoulder;
			game_button_state RightShoulder;
		};
	};
};

struct game_input
{
	game_controller_input Controllers[4];

	int KeyStateUp;
	int KeyStateDown;
	int KeyStateLeft;
	int KeyStateRight;

	int ShiftPressed;

	int Key1;
	int Key1_last;
	int Key2;
	int Key3;
	int Key4;
	int Key5;
};

struct world
{
	Vec2f TileSizeMeters;
	Vec2f TileSizePixels;
	Vec2f MetersToPixels;

	float g; // ÑTÑÉÑ{ÑÄÑÇÑuÑ~ÑyÑu ÑÉÑrÑÄÑqÑÄÑtÑ~ÑÄÑsÑÄ ÑÅÑpÑtÑuÑ~ÑyÑë

	tile_map *TileMap;
};

struct game_assets_sprites
{
	Sprite tmp_sprite;
	Sprite tmp_ground_sprite_01;
	Sprite tmp_object_sprite_001;
	Sprite tmp_object_sprite_002;
	Sprite tmp_object_sprite_003;
	Sprite tmp_object_sprite_004;
	Sprite tmp_object_sprite_005;

	Sprite tmp_object_sprite_stone1;
	Sprite tmp_wall_sprite1;

	Sprite tmp_player_image;
	Sprite tmp_player_image_v;
	Sprite tmp_player_image_track_left;
	Sprite tmp_player_image_track_right;
	Sprite tmp_player_image_track_up;
	Sprite tmp_player_image_track_down;
	Sprite tmp_player_image_torso;

	Sprite tmp_player_image_ur;
	Sprite tmp_player_image_ul;
	Sprite tmp_player_image_track_ur;
	Sprite tmp_player_image_track_ul;
	Sprite tmp_player_image_track_br;
	Sprite tmp_player_image_track_bl;

};

struct game_state
{
	int IsInitialized;

	memory_arena WorldArena;

	float TimeFromLastFrame;
	uint32 Tick;
	float TimeElapsedFromLastTick;

	Sizef ScreenSize;

	entity *PlayerEntity;

	world_position CameraPos;
	Vec2f CameraOrigin;
	Rect EntityToCameraIn;
	Rectf EntityToCameraOut;

	world *World;
	Size TilesOnHalfScreen;

	game_input GameInput;

	entity Entities[4096]; // all passive entities
	uint32 EntityCount;
	entity_active_data ActiveEntities[2048]; // all entities in camera space
	uint32 ActiveEntityCount;
	entity_group TiledEntities; // All entities contained in tile map

	ResourceManager game_resources;
	game_assets_sprites GameSprites;

	void(*LoadGameSpriteFromImage)(Canvas &canvas, Sprite &sprite, const char* sprite_name);
	void(*LoadGameSpriteFromResource)(Canvas &canvas, ResourceManager* resources, Sprite &sprite, const char* sprite_name);
	void(*AddGameSpriteFrameFromImage)(Canvas &canvas, Sprite &sprite, const char* frame_name);


	float temp_float_value_1;
	float temp_float_value_2;
	float temp_float_value_3;
	float temp_float_value_4;
	float temp_float_value_5;
	double temp_double_value_1;
	double temp_double_value_2;
	double temp_double_value_3;
	double temp_double_value_4;
	double temp_double_value_5;
};
