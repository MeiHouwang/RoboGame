#include "game_precomp.h"
#include "game.h"
#include "intrinsics.h"
#include "game_entity_renders.h"


// TODO : „R„„y„ƒ„€„{ „„„€„s„€, „‰„„„€ „~„…„w„~„€ „ƒ„t„u„|„p„„„
/*

// +++ „@„‚„‡„y„„„u„{„„„…„‚„p

// + „M„u„~„u„w„}„u„~„„ „€„q„Œ„u„{„„„€„r „r „„p„}„‘„„„y
//		„V„‚„p„~„u„~„y„u „ƒ„p„}„y„‡ „~„u„„€„t„r„y„w„~„„‡ „€„q„Œ„u„{„„„€„r, „y„‡ „}„€„w„u„„ „q„„„„ „€„‰„u„~„ „}„~„€„s„€ - „ƒ„„y„ƒ„{„€„}-„ˆ„u„„€„‰„{„€„z, „r„„t„u„|„‘„„„ „„p„}„‘„„„ „„€ „}„u„‚„u „x„p„„€„|„~„u„~„y„‘
//			„y„~„t„u„{„ƒ „„‚„y „„„„€„} „ƒ„{„r„€„x„~„€„z.
//		„H„p„s„‚„…„x„{„p „y „r„„s„‚„…„x„{„p „p„{„„„y„r„~„„‡ „€„q„Œ„u„{„„„€„r „y„x „€„q„‹„u„s„€ „}„p„ƒ„ƒ„y„r„p.

// + „H„p„s„‚„…„x„{„p „‚„u„ƒ„…„‚„ƒ„€„r
//		„E„t„y„~„€„u „‡„‚„p„~„y„|„y„‹„u „‚„u„ƒ„…„‚„ƒ„€„r, „„€„t„s„‚„…„x„{„p „y „r„„s„‚„…„x„{„p „‚„u„ƒ„…„‚„ƒ„€„r

// + „U„y„x„y„{„p
//		„U„y„x„y„{„p „t„r„y„w„u„~„y„‘ „‚„€„q„€„„„€„r - „}„€„„„€„‚„, „s„…„ƒ„u„~„y„ˆ„, „ƒ„ˆ„u„„|„u„~„y„u „„€„‰„r„, „}„€„‹„~„€„ƒ„„„ „}„€„„„€„‚„€„r, „‚„p„x„s„€„~ „y „„„€„‚„€„}„w„u„~„y„u, „~„p„{„|„€„~ „„€„r„u„‚„‡„~„€„ƒ„„„y
//		„@„~„y„}„p„ˆ„y„‘ „r „ƒ„€„€„„„r„u„„„ƒ„„„r„y„y „ƒ „†„y„x„y„{„€„z

// + „K„€„|„|„y„x„y„y
//		„R„„„€„|„{„~„€„r„u„~„y„u „t„r„y„w„…„‹„y„‡„ƒ„‘ „€„q„Œ„u„{„„„€„r
//		„O„t„~„y „€„q„Œ„u„{„„„ „„„€„|„{„p„„„ „t„‚„…„s„y„u
//		„P„‚„‘„}„€„…„s„y„|„„~„y„{„y „„‚„€„y„x„r„€„|„„~„€„z „„€„x„y„ˆ„y„y

// + „@„~„y„}„p„ˆ„y„‘
//		„T„~„y„†„y„ˆ„y„‚„€„r„p„~„~„„z „†„€„‚„}„p„„ „s„‚„p„†„y„{„y - „p„~„y„}„p„ˆ„y„y - „{„€„|„|„y„x„y„z?
//		„@„~„y„}„p„ˆ„y„‘ „p„{„„„y„r„~„„‡ „y „„p„ƒ„ƒ„y„r„~„„‡ „€„q„Œ„u„{„„„€„r
//		„P„€„„„€„{ „p„~„y„}„p„ˆ„y„€„~„~„„‡ „„†„†„u„{„„„€„r, „y„ƒ„‰„u„x„p„„‹„y„‡ („‰„p„ƒ„„„y„ˆ„, „t„„}, „ƒ„|„u„t„(?) „y „„.„t.)

// + „M„y„‚
//		„K„€„~„ƒ„„„‚„…„{„„„€„‚ „}„y„‚„p „p„r„„„€„}„p„„„y„‰„u„ƒ„{„y„z
//		„I„~„ƒ„„„‚„…„}„u„~„„ „{„€„~„ƒ„„„‚„…„y„‚„€„r„p„~„y„‘ „}„y„‚„p „‚„…„‰„~„€„z

// + Z
//		„B„„ƒ„€„„„p „y „~„p„{„|„€„~ „„„p„z„|„€„r???
//		Z-„y„~„t„u„{„ƒ „„‚„y „‚„u„~„t„u„‚„y„~„s„u „€„q„Œ„u„{„„„€„r „y „‰„p„ƒ„„„u„z „‚„€„q„€„„„€„r

// + „H„r„…„{
//		„M„…„x„„{„p „y „x„r„…„{„y

// NOTE: „ƒ„t„u„|„p„~„€, „r„€„x„}„€„w„~„ „„u„‚„u„t„u„|„{„y:
// „V„‚„p„~„u„~„y„u „€„q„Œ„u„{„„„€„r, „„‚„€„y„x„r„€„t„‘„‹„y„‡ „t„u„z„ƒ„„„r„y„‘, „r „€„t„~„€„} „€„q„‹„u„} „}„p„ƒ„ƒ„y„r„u - 
// „V„‚„p„~„u„~„y„u „p„{„„„y„r„~„„‡ „€„q„Œ„u„{„„„€„r „r „€„q„|„p„ƒ„„„y „t„u„z„ƒ„„„r„y„‘ „{„p„}„u„‚„

// +++ NOTE: „I„s„‚„€„r„€„u:
// + „I„s„‚„€„{
//		„C„|„p„r„‚„€„q„€„„ - „q„€„u„r„€„z „‚„€„q„€„„, „y„}„u„u„„ „r „{„€„‚„„…„ƒ„u:
//			„€„t„y„~ „}„p„~„y„„…„|„‘„„„€„‚ „…„~„y„r„u„‚„ƒ„p„|„„~„„z
//			„x„p„‚„‘„t„~„„z „‹„…„ „…„~„y„r„u„‚„ƒ„p„|„„~„„z(?)
//			„‚„u„z„|-„s„p„~, „„y„„„p„„‹„y„z„ƒ„‘ „€„„ „ˆ„u„~„„„‚„p„|„„~„€„s„€ „p„{„{„…„}„…„|„‘„„„€„‚„p, „ƒ„„„‚„u„|„‘„u„„ „ƒ„„„p„|„„~„„}„y „Š„p„‚„p„}„y, „~„p „ƒ„„„p„‚„„„u „q„u„x „q„€„u„„‚„y„„p„ƒ„€„r
//			„‚„p„{„u„„„~„p„‘ „…„ƒ„„„p„~„€„r„{„p „ƒ „ƒ„p„}„€„~„p„r„€„t„‘„‹„y„}„y„ƒ„‘ „‚„p„{„u„„„p„}„y, „~„p „ƒ„„„p„‚„„„u „q„u„x „‚„p„{„u„„
//			„ƒ„€„„|„p „…„ƒ„{„€„‚„y„„„u„|„u„z „„u„‚„u„t„~„u„s„€ „y „x„p„t„~„u„s„€ „‡„€„t„p, „~„p „ƒ„„„p„‚„„„u „q„u„x „{„u„‚„€„ƒ„y„~„p
//		„R„y„ƒ„„„u„}„p „„€„r„‚„u„w„t„u„~„y„z „|„y„ƒ„„„€„r „q„‚„€„~„y „y „r„~„…„„„‚„u„~„~„y„‡ „}„u„‡„p„~„y„x„}„€„r
//		„@„{„{„…„}„…„|„‘„„„€„‚ „ƒ „{„‚„y„r„€„z „r„„t„p„r„p„u„}„€„s„€ „…„t„u„|„„~„€„s„€ „„„€„{„p „r „x„p„r„y„ƒ„y„}„€„ƒ„„„y „€„„ „…„‚„€„r„~„‘ „x„p„‚„‘„t„p. „‰„„„€„q„ „}„€„‹„~„€„ƒ„„„ „„p„t„p„|„p
//			„ƒ „…„}„u„~„„Š„u„~„y„u„} „x„p„‚„‘„t„p.

// + „B„‚„p„s„y
//		„V„€„t„‘„‰„p„‘ „|„p„x„u„‚„~„p„‘ „…„ƒ„„„p„~„€„r„{„p

// + „N„u„z„„„‚„p„|„„~„„u „‚„€„q„€„„„
//		„Q„€„q„€„„ - „‚„u„}„€„~„„„~„y„{
//		„Q„€„q„€„„ - „„€„s„‚„…„x„‰„y„{
//		„S„‚„p„~„ƒ„„€„‚„„„~„p„‘ „ƒ„y„ƒ„„„u„}„p(„w„u„|„u„x„~„p„‘ „t„€„‚„€„s„p)
//		„Q„€„q„€„„„-„{„€„~„ƒ„„„‚„…„{„„„€„‚„ „ƒ„„u„ˆ„y„p„|„y„x„y„‚„€„r„p„~„~„„u

*/


void InitializeArena(memory_arena *Arena, size_t Size, uint8 *Base)
{
	Arena->Size = Size;
	Arena->Base = Base;
	Arena->Used = 0;
}

// „@„{„„„y„r„y„‚„…„u„„ „€„q„Œ„u„{„„
void SetEntityToActive(entity *Entity, game_state *GameState)
{
	if (GameState->ActiveEntityCount < ArrayCount(GameState->ActiveEntities))
	{
		Entity->ActiveData = &GameState->ActiveEntities[GameState->ActiveEntityCount];
		Entity->ActiveData->ActiveEntityIndex = GameState->ActiveEntityCount++;
		Entity->ActiveData->EntityBaseData = Entity;
		Entity->ActiveData->Pos = Vec2f(Entity->Position.Tile - GameState->CameraPos.Tile) + Entity->Position.TilePos;
	}
	else
	{
		log_event("DEBUG", "ERROR : Failed to activate entity!");
	}
}

// „R„€„x„t„p„„„ „t„p„~„~„„u „p„{„„„y„r„~„€„s„€ „€„q„Œ„u„{„„„p
// TODO: „y„x„q„p„r„y„„„„ƒ„‘ „€„„ „„„„€„s„€ „y„x„r„‚„p„‹„u„~„y„‘
void PushActiveEntity(entity *Entity, memory_arena *Arena, world_position CameraPos)
{
	Entity->ActiveData = PushStruct(Arena, entity_active_data);
	Entity->ActiveData->EntityBaseData = Entity;
	Entity->ActiveData->Pos = Vec2f(Entity->Position.Tile - CameraPos.Tile) + Entity->Position.TilePos;
}

// „D„u„p„{„„„y„r„y„‚„…„u„„ „€„q„Œ„u„{„„
void RemoveActiveEntity(entity_active_data *Entity, game_state *GameState)
{
	// Remove entity from active entities array
	Assert(GameState->ActiveEntityCount);
	Assert(Entity->ActiveEntityIndex < GameState->ActiveEntityCount);
	Entity->EntityBaseData->ActiveData = 0;
	if (Entity->ActiveEntityIndex != (GameState->ActiveEntityCount - 1))
	{
		uint32 Index = Entity->ActiveEntityIndex;
		GameState->ActiveEntities[Index] = GameState->ActiveEntities[GameState->ActiveEntityCount - 1];
		GameState->ActiveEntities[Index].ActiveEntityIndex = Index;
	}
	GameState->ActiveEntityCount--;
}

// „@„{„„„y„r„y„‚„…„u„„ „€„‰„u„‚„u„t„~„€„z „€„q„Œ„u„{„„ „y„x „x„p„„p„ƒ„p „y „r„€„x„r„‚„p„‹„p„u„„ „…„{„p„x„p„„„u„|„ „~„p „~„u„s„€
entity *AddEntity(game_state *GameState)
{
	entity *Result = 0;

	if (GameState->EntityCount < ArrayCount(GameState->Entities))
	{
		Result = &GameState->Entities[GameState->EntityCount++];
		*Result = {};
		//Result->ActiveData = 0;
	}
	else
	{
		// TODO : allocate more memory
		log_event("DEBUG", "ERROR : Failed to add entity!");
		Assert(!"Allocate more memory!")
	}

	return Result;
}

/*
// „S„€ „w„u „ƒ„p„}„€„u, „~„€ „t„€„„€„|„~„y„„„u„|„„~„€ „y„~„y„ˆ„y„p„|„y„x„y„…„u„„ „~„u„{„€„„„€„‚„„u „„p„‚„p„}„u„„„‚„
// TODO: „…„q„‚„p„„„? „B„ƒ„v „‚„p„r„~„€ „~„y„s„t„u „~„u „y„ƒ„„€„|„„x„…„
entity *AddEntity(game_state *GameState, world_position EntityPos, entity_types EntityType, Rectf CollisionBox)
{
	entity *Result = 0;

	if (GameState->EntityCount < ArrayCount(GameState->Entities))
	{
		Result = &GameState->Entities[GameState->EntityCount++];
		*Result = {};
		Result->EntityType = EntityType;
		Result->Position = EntityPos;
		Result->CollisionBox = CollisionBox;
		Result->ActiveData = 0;
	}
	else
	{
		// TODO : allocate more memory
		log_event("DEBUG", "Failed to add entity!");
		Assert(!"Allocate more memory!")
	}

	return Result;
}
*/

// „D„€„q„p„r„|„‘„u„„ „€„q„Œ„u„{„„ „r „‡„‚„p„~„y„|„y„‹„u
// „B„€„x„r„‚„p„‹„p„u„„ „s„|„€„q„p„|„„~„„z „y„~„t„u„{„ƒ „€„q„Œ„u„{„„„p „r „s„‚„…„„„u
uint32 AddEntityToGroup(memory_arena *Arena, entity_group *Group)
{
	uint32 Result = 0;
	entity_group *ActiveGroup = Group;
	while (ActiveGroup->NextGroup)
	{
		Result += ActiveGroup->GroupSize;
		ActiveGroup = ActiveGroup->NextGroup;
	}

	if (ActiveGroup->EntityCount == ActiveGroup->GroupSize)
	{
		// „P„u„‚„u„„€„|„~„u„~„y„u, „r„„t„u„|„y„„„ „}„u„ƒ„„„€ „„€„t „~„€„r„…„ „s„‚„…„„„…
		entity_group *NextGroup = PushStruct(Arena, entity_group);
		Assert(NextGroup);

		NextGroup->Entities = PushArray(Arena, 4096, entity);
		Assert(NextGroup->Entities);

		NextGroup->GroupSize = 4096;
		NextGroup->EntityCount = 0;
		NextGroup->NextGroup = 0;
		ActiveGroup->NextGroup = NextGroup;
		ActiveGroup = NextGroup;
	}

	Result += ActiveGroup->EntityCount++;
	
	return Result;
}

entity *GetEntityFromGroupByIndex(entity_group *Group, uint32 Index)
{
	uint32 ResultIndex = Index;
	entity_group *ResultGroup = Group;
	while (ResultIndex >= ResultGroup->GroupSize)
	{
		ResultIndex -= ResultGroup->GroupSize;
		ResultGroup = ResultGroup->NextGroup;
	}
	entity *Result = &ResultGroup->Entities[ResultIndex];

	return Result;
}

void MapEntitiesInCameraSpace(game_state *GameState)
{
	// „T„q„‚„p„„„ „r„„|„u„„„u„r„Š„y„u „x„p „„‚„u„t„u„|„ „p„{„„„y„r„~„€„z „x„€„~„ „€„q„Œ„u„{„„„
	uint32 active_entity_count = 0;
	while (active_entity_count < GameState->ActiveEntityCount)
	{
		entity_active_data *ActiveEntity = &GameState->ActiveEntities[active_entity_count];
		if (!GameState->EntityToCameraOut.contains(ActiveEntity->Pos))
		{
			RemoveActiveEntity(ActiveEntity, GameState);
		}
		else
		{
			active_entity_count++;
		}
	}
	// „I „p„{„„„y„r„y„‚„€„r„p„„„ „r„|„u„„„u„r„Š„y„u
	uint32 entity_count = 0;
	while (entity_count < GameState->EntityCount)
	{
		entity *Entity = &GameState->Entities[entity_count];
		if (Entity->EntityType != EntityType_Robot && !Entity->ActiveData && GameState->EntityToCameraIn.contains(Entity->Position.Tile - GameState->CameraPos.Tile))
		{
			SetEntityToActive(Entity, GameState);
		}
		entity_count++;
	}
}

void InitGameMemory(game_memory *Memory, Canvas &canvas)
{
	// „I„~„y„ˆ„y„p„|„y„x„p„ˆ„y„‘
	game_state* GameState = (game_state*)Memory->PermanentStorage;

	InitializeArena(&GameState->WorldArena, Memory->PermanentStorageSize - sizeof(game_state), (uint8*)Memory->PermanentStorage + sizeof(game_state));

	GameState->World = PushStruct(&GameState->WorldArena, world);
	world *World = GameState->World;
	World->TileMap = PushStruct(&GameState->WorldArena, tile_map);
	tile_map *TileMap = World->TileMap;

	GameState->Tick = 0;
	GameState->TimeElapsedFromLastTick = 0;

	// Camera 
	GameState->CameraPos.Tile = Vec2i(0, 0);
	GameState->CameraPos.TilePos = Vec2f(0, 0);
	GameState->CameraOrigin = GameState->ScreenSize / 2.0f;

	GameState->EntityToCameraIn = Rect(-7, -5, 7, 5);
	GameState->EntityToCameraOut = Rect(-8, -6, 8, 6);

	// „H„p„s„‚„…„x„y„„„ „ƒ„„‚„p„z„„„
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_sprite, "sand_tile_01.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_object_sprite_001, "object_storage_01.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_object_sprite_stone1, "object_stone_01.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_player_image, "robot_base_horizontal.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_player_image_v, "robot_base_vertical.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_player_image_ur, "robot_base_diagonal_ur.png");
	GameState->LoadGameSpriteFromImage(canvas, GameState->GameSprites.tmp_player_image_ul, "robot_base_diagonal_ul.png");

	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_ground_sprite_01, "ground_concrete_tileset");
	GameState->AddGameSpriteFrameFromImage(canvas, GameState->GameSprites.tmp_ground_sprite_01, "ground_tile_01.png");

	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_torso, "robot_torso");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_down, "track_v_down");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_left, "track_h_left");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_right, "track_h_right");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_up, "track_v_up");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_ur, "track_d_ur");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_ul, "track_d_ul");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_br, "track_d_br");
	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_player_image_track_bl, "track_d_bl");

	GameState->LoadGameSpriteFromResource(canvas, &GameState->game_resources, GameState->GameSprites.tmp_wall_sprite1, "tileset_brick_wall");

	// Player entity
	//
	GameState->PlayerEntity = AddEntity(GameState);
	GameState->PlayerEntity->Position.Tile = Vec2i(0, 0);
	GameState->PlayerEntity->Position.TilePos = Vec2f(0, 0);
	GameState->PlayerEntity->EntityType = EntityType_Robot;
	GameState->PlayerEntity->CollisionType = 1;
	GameState->PlayerEntity->CollisionBox = Rectf(-0.45f, -0.25f, 0.45f, 0.25f);
	GameState->PlayerEntity->Controller.Active = 1;

	GameState->PlayerEntity->Mass = 20000.0f;
	GameState->PlayerEntity->RResistance = 0.008f;

	SetEntityToActive(GameState->PlayerEntity, GameState);

	World->TileSizeMeters = Vec2f(1.0f, 1.0f);
	World->TileSizePixels = Vec2f(100.0f, 100.0f);
	World->MetersToPixels = World->TileSizePixels / World->TileSizeMeters;

	World->g = 4.2f;

	TileMap->TileChunkSize = Vec2ui(16, 16);
	//TileMap->CenterChunkPosition = TileMap->TileChunksCount / (uint32)2;

	GameState->TilesOnHalfScreen.width = (int)((GameState->ScreenSize.width / 2) / World->TileSizePixels.x) + 1;
	GameState->TilesOnHalfScreen.height = (int)((GameState->ScreenSize.height / 2) / World->TileSizePixels.y) + 1;

	Vec2i TilesPerScreen = GameState->TilesOnHalfScreen * 2;

	for (int32 ScreenY = -16; ScreenY < 16; ScreenY++)
	{
		for (int32 ScreenX = -16; ScreenX < 16; ScreenX++)
		{
			for (int32 TY = 0; TY < TilesPerScreen.y; TY++)
			{
				for (int32 TX = 0; TX < TilesPerScreen.x; TX++)
				{
					int32 AbsTileX = ScreenX * TilesPerScreen.x + TX;
					int32 AbsTileY = ScreenY * TilesPerScreen.y + TY;

					SetTileValue(&GameState->WorldArena, TileMap, Vec2i(AbsTileX, AbsTileY), rand() % 16 + 1);
				}
			}
		}
	}
	/*
	for (int32 Y = 1; Y < 4; Y++)
	{
		for (int32 X = 1; X < 5; X++)
		{
			SetTileValue(&GameState->WorldArena, TileMap, Vec2i(X, Y), 5);
			SetTileValue(&GameState->WorldArena, TileMap, Vec2i(X - 7, Y), 5);
			SetTileValue(&GameState->WorldArena, TileMap, Vec2i(X - 5, Y + 6), 4);
		}
	}
	*/

	// Game entities
	GameState->TiledEntities.Entities = PushArray(&GameState->WorldArena, 4096, entity);
	GameState->TiledEntities.GroupSize = 4096;
	GameState->TiledEntities.EntityCount = 0;
	GameState->TiledEntities.NextGroup = 0;
	AddEntityToGroup(&GameState->WorldArena, &GameState->TiledEntities); // „N„…„|„u„r„€„z „€„q„Œ„u„{„„ „~„u „y„ƒ„„€„|„„x„…„u„„„ƒ„‘

	// Add many stone entities
	world_position EntityPos;
	//Rectf CollisionBox(-0.4f, 0.0f, 0.4f, 0.3f);
	Rectf CollisionBox(-0.5f, -0.5f, 0.5f, 0.5f);
	for (int32 Y = 1; Y < 10; Y++)
	{
		for (int32 X = 1; X < 10; X++)
		{
			EntityPos.Tile = Vec2i(X, Y);
			EntityPos.TilePos = Vec2f(0, 0);

			uint32 StoneIndex = AddEntityToGroup(&GameState->WorldArena, &GameState->TiledEntities);
			entity *Entity = GetEntityFromGroupByIndex(&GameState->TiledEntities, StoneIndex);
			Entity->EntityType = EntityType_Storage;
			Entity->Position = EntityPos;
			Entity->CollisionType = 1;
			Entity->CollisionBox = CollisionBox;
			AddEntityToTile(GameState->World->TileMap, EntityPos.Tile, StoneIndex);
		}
	}

	/*
	EntityPos.Tile = Vec2i(1, 1);
	EntityPos.TilePos = Vec2f(0, 0);
	entity *Entity = AddEntity(GameState);
	Entity->EntityType = EntityType_Stone;
	Entity->Position = EntityPos;
	Entity->CollisionType = 1;
	Entity->CollisionBox = CollisionBox;
	//SetEntityToActive(Entity, GameState);

	/*
	Entity = AddEntity(GameState);
	Entity->EntityType = EntityType_Wall;
	EntityPos.Tile = Vec2i(0, -2);
	Entity->Position = EntityPos;
	Entity->CollisionType = 1;
	Entity->CollisionBox = Rectf(-0.5f, -0.1f, 0.5f, 0.1f);
	Entity->EntityFrame = 0;
	//SetEntityToActive(Entity, GameState);
	*/

	// Call to camera reset to activate entities in camera space
	MapEntitiesInCameraSpace(GameState);

	GameState->IsInitialized = 1;
}

// „O„ƒ„~„€„r„~„€„z „y„s„‚„€„r„€„z „{„€„t, „r„„x„„r„p„u„„„ƒ„‘ „{„p„w„t„„z „{„p„t„‚
// „P„‚„y„~„y„}„p„u„„ „~„p „r„‡„€„t „ƒ„ƒ„„|„{„… „~„p „„p„}„‘„„„, „ƒ„€„t„u„‚„w„p„‹„…„ „r„ƒ„u „y„s„‚„€„r„„u „t„p„~„~„„u
// NOTE: „^„„„€„„ „{„€„t „t„€„|„w„u„~ „q„„„„ „„|„p„„„†„€„‚„}„€„~„u„x„p„r„y„ƒ„y„}„„}
extern "C" 
__declspec(dllexport)
GAME_UPDATE(GameUpdate)
{
	// (game_memory* Memory)
	Assert(sizeof(game_state) <= Memory->PermanentStorageSize);
	game_state* GameState = (game_state*)Memory->PermanentStorage;

	if (!GameState->IsInitialized)
	{
		InitGameMemory(Memory, canvas);
	}

	// Game timings
	// NOTE: „R„|„u„t„…„u„„ „|„y „€„q„‚„p„q„p„„„„r„p„„„ „{„p„w„t„„z „„„y„{, „~„u„x„p„r„y„ƒ„y„}„€ „€„„ „„„€„s„€, „ƒ„{„€„|„„{„€ „y„‡ „q„„|„€ „r „€„t„~„€„} „{„p„t„‚„u?
	//
	GameState->TimeElapsedFromLastTick += GameState->TimeFromLastFrame;
	while (GameState->TimeElapsedFromLastTick > TICK_DURATION)
	{
		GameState->TimeElapsedFromLastTick -= TICK_DURATION;
		GameState->Tick++;
	}

	// Game world
	world *World = GameState->World;
	tile_map *TileMap = World->TileMap;

	memory_arena TempArena;
	InitializeArena(&TempArena, Memory->TransientStorageSize, (uint8*)Memory->TransientStorage);
	
	// NOTE: Player movement, should be the same for all entities
	//
	GameState->PlayerEntity->Controller.MoveOrder = 0;
	GameState->PlayerEntity->Controller.MoveOrder |= GameState->GameInput.KeyStateUp ? EntityMove_Up : 0;
	GameState->PlayerEntity->Controller.MoveOrder |= GameState->GameInput.KeyStateDown ? EntityMove_Down : 0;
	GameState->PlayerEntity->Controller.MoveOrder |= GameState->GameInput.KeyStateLeft ? EntityMove_Left : 0;
	GameState->PlayerEntity->Controller.MoveOrder |= GameState->GameInput.KeyStateRight ? EntityMove_Right : 0;
	
	// Active entity movement
	//
	float dT = GameState->TimeFromLastFrame;
	for (uint32 a_e_count = 0; a_e_count < GameState->ActiveEntityCount; a_e_count++)
	{
		entity_active_data *CurrentActiveEntity = &GameState->ActiveEntities[a_e_count];
		entity *Entity = CurrentActiveEntity->EntityBaseData;

		if (Entity->Controller.Active || Entity->CurrentSpeed != 0)
		{
			switch (Entity->EntityType)
			{
			case EntityType_Robot:
			{
				Vec2f ControlVector(((Entity->Controller.MoveOrder & EntityMove_Right) ? 1.0f : 0) - ((Entity->Controller.MoveOrder & EntityMove_Left) ? 1.0f : 0),
					((Entity->Controller.MoveOrder & EntityMove_Down) ? 1.0f : 0) - ((Entity->Controller.MoveOrder & EntityMove_Up) ? 1.0f : 0));
				ControlVector.normalize();
				
				// TODO: „U„y„x„y„{„… „t„r„y„w„u„~„y„‘ „‚„p„x„t„u„|„„~„„‡ „s„…„ƒ„u„~„y„ˆ „r„€ „r„ƒ„u „„€„|„‘
				float MoveAccel = 0;
				float TorqueForce = 0;
				float BrakesForce = 4000.0f;
				int BrakesEnabled = 0;

				if (Entity->Controller.MoveOrder)
				{
					// „M„€„„„€„‚ „r„{„|„„‰„u„~
					// TODO: „P„u„‚„u„t„p„‰„y
					TorqueForce = 2000.0f;
				}
				else
				{
					BrakesEnabled = 1;
				}

				if (!Entity->CurrentSpeed)
				{
					Entity->MovementVector = ControlVector;
					BrakesEnabled = 0;
				}
				else
				{
				}

				float RollingResistanceForce = Entity->RResistance * Entity->Mass * World->g;

				float ResultForce = TorqueForce - RollingResistanceForce;
				if (BrakesEnabled)
					ResultForce -= BrakesForce;

				MoveAccel = ResultForce / Entity->Mass;
				if (GameState->GameInput.ShiftPressed)
					MoveAccel *= 5.0f;

				if (MoveAccel != 0)
				{
					Entity->CurrentSpeed += MoveAccel;
					if (Entity->CurrentSpeed < 0)
						Entity->CurrentSpeed = 0;
				}


				// Collisions
				float tile_speed = (Entity->CurrentSpeed / 1000.0f) / World->TileSizeMeters.x; // „„„p„z„|„€„r „r „}„y„|„|„y„ƒ„u„{„…„~„t„…
				float dt_min = 1.0f;
				float tEpsilon = 0.00001f;
				entity *EntityCollided = 0;

				if (Entity->MovementVector.x != 0 || Entity->MovementVector.y != 0)
				{
					Vec2f Delta = Entity->MovementVector * (tile_speed * dt_min * dT);
					//
					// Collision with active entities
					//
					for (uint32 active_entity_count = 0; active_entity_count < GameState->ActiveEntityCount; active_entity_count++)
					{
						entity_active_data *ActiveEntity = &GameState->ActiveEntities[active_entity_count];
						if (ActiveEntity->EntityBaseData->CollisionType && ActiveEntity->EntityBaseData->EntityType != EntityType_Robot)
						{
							// CollisionType > 0
							float dt_next = CollideEntity_MovingWithFixedInCameraSpace(Entity, ActiveEntity->EntityBaseData, Delta);
							if (dt_next < dt_min)
							{
								dt_min = dt_next;
								EntityCollided = ActiveEntity->EntityBaseData;
								Entity->CurrentSpeed = 0;
							}
						}
					}
					//
					// Collisions with tiled entities
					// TODO: „ƒ„u„z„‰„p„ƒ „„„„€ „„‚„€„ƒ„„„€ „„‚„€„r„u„‚„{„p „{„r„p„t„‚„p„„„p 3„‡3, „„€„„„€„} „ƒ„t„u„|„p„„„ „r„„‰„y„ƒ„|„u„~„y„u „t„u„z„ƒ„„„r„y„„„u„|„„~„€ „„u„‚„u„ƒ„u„{„p„u„}„„‡ „„„p„z„|„€„r
					for (int Y = -1; Y <= 1; Y++)
					{
						for (int X = -1; X <= 1; X++)
						{
							Vec2i Tile = Entity->Position.Tile + Vec2i(X, Y);
							uint32 TileValue = GetTileValue(TileMap, Tile);
							uint32 Index = GetTiledIndex(TileValue);
							if (Index)
							{
								entity *TiledEntity = GetEntityFromGroupByIndex(&GameState->TiledEntities, Index);
								// 
								// TODO : „I„x„q„p„r„y„„„„ƒ„‘ „€„„ „~„u„€„q„‡„€„t„y„}„€„ƒ„„„y „ƒ„€„x„t„p„r„p„„„ „p„{„„„y„r„~„„z „€„q„Œ„u„{„„
								PushActiveEntity(TiledEntity, &TempArena, GameState->CameraPos);
								//
								if (TiledEntity->CollisionType)
								{
									// CollisionType > 0
									float dt_next = CollideEntity_MovingWithFixedInCameraSpace(Entity, TiledEntity, Delta);
									if (dt_next < dt_min)
									{
										dt_min = dt_next;
										EntityCollided = TiledEntity;
										Entity->CurrentSpeed = 0;
									}
								}
							}
						}
					}
				}

				float dt_travel = dT * dt_min;
				if (dt_travel > 0)
				{
					// „Q„€„q„€„„ „ƒ„t„r„y„~„…„|„ƒ„‘ „ƒ „}„u„ƒ„„„p
					Vec2f dPos = (Entity->MovementVector * Entity->CurrentSpeed * (dt_travel / 1000.0f)) / Vec2f(World->TileSizeMeters);
					CurrentActiveEntity->Pos += dPos;
					Entity->Position.TilePos += dPos;
					Entity->Position = RecanonicalPosition(GameState->PlayerEntity->Position);

					Entity->LastMoveInPixels = dPos * GameState->World->TileSizePixels.x;

					// Player orientation
					if (dPos.y > 0)
						Entity->Orientation = 2;
					if (dPos.y < 0)
						Entity->Orientation = 0;
					if (dPos.x > 0)
						if (dPos.y > 0)
							Entity->Orientation = 5;
						else if (dPos.y < 0)
							Entity->Orientation = 4;
						else
							Entity->Orientation = 1;
					if (dPos.x < 0)
						if (dPos.y > 0)
							Entity->Orientation = 6;
						else if (dPos.y < 0)
							Entity->Orientation = 7;
						else
							Entity->Orientation = 3;
				}
				break;
			}
			default:
				break;
			}
		}
	}

	//
	// TODO: „K„p„}„u„‚„u „ƒ„|„u„t„…„u„„ „x„p „y„s„‚„€„{„€„}, „~„€ „„€„x„y„ˆ„y„ „„‚„y„r„‘„x„{„y „}„u„~„‘„„„ „„„€„|„„{„€ „„€ „‚„p„x„}„u„‚„… „‰„p„~„{„p?
	//
	//world_position NewCameraPos = GameState->PlayerEntity->Position;
	world_position NewCameraPos = GameState->CameraPos;
	Vec2f PlayerOffset = ((Vec2f)(GameState->PlayerEntity->Position.Tile - GameState->CameraPos.Tile) * Vec2f(World->TileSizePixels)) + GameState->PlayerEntity->Position.TilePos * Vec2f(World->TileSizePixels) - GameState->CameraPos.TilePos * Vec2f(World->TileSizePixels);
	Vec2f CameraWindow(300.0f, 220.0f);
	Vec2f CameraMove(0, 0);
	if (Abs(PlayerOffset.x) > CameraWindow.x)
	{
		CameraMove.x = (Abs(PlayerOffset.x) - CameraWindow.x) * Sign(PlayerOffset.x);
	}
	if (Abs(PlayerOffset.y) > CameraWindow.y)
	{
		CameraMove.y = (Abs(PlayerOffset.y) - CameraWindow.y) * Sign(PlayerOffset.y);
	}
	NewCameraPos.TilePos += CameraMove / World->TileSizePixels;
	NewCameraPos = RecanonicalPosition(NewCameraPos);
	uint32 IsRemapEntities = 0;
	if (GameState->CameraPos.Tile != NewCameraPos.Tile)
	{
		// „P„u„‚„u„ƒ„‰„y„„„p„„„ „„€„|„€„w„u„~„y„u „r„ƒ„u„‡ „p„{„„„y„r„~„„‡ „€„q„Œ„u„{„„„€„r
		Vec2f EntityDPos = Vec2f(GameState->CameraPos.Tile - NewCameraPos.Tile);
		for (uint32 active_entity_count = 0; active_entity_count < GameState->ActiveEntityCount; active_entity_count++)
		{
			GameState->ActiveEntities[active_entity_count].Pos += EntityDPos;
		}
		IsRemapEntities = 1;
	}
	GameState->CameraPos = NewCameraPos;
	if (IsRemapEntities)
	{
		MapEntitiesInCameraSpace(GameState);
	}

	if (GameState->GameInput.Key1_last == 1 && GameState->GameInput.Key1 == 0)
	{
		GameState->PlayerEntity->Orientation = (GameState->PlayerEntity->Orientation + 1) % 8;
		GameState->GameInput.Key1_last = 0;
	}
}

// „E„t„y„~„„z „r„„x„€„r „t„|„‘ „‚„u„~„t„u„‚„p
extern "C" 
__declspec(dllexport)
GAME_RENDER(GameRender)
{
	//(game_memory* GameMemory, Canvas &canvas)
	game_state* GameState = (game_state*)Memory->PermanentStorage;

	world *World = GameState->World;
	tile_map *TileMap = World->TileMap;

	World->TileSizePixels = Sizef(128.0f, 128.0f);
	GameState->TilesOnHalfScreen.width = (int)((GameState->ScreenSize.width / 2) / World->TileSizePixels.x) + 1;
	GameState->TilesOnHalfScreen.height = (int)((GameState->ScreenSize.height / 2) / World->TileSizePixels.y) + 1;

	FontDescription tile_font_desc;
	tile_font_desc.set_height(12);
	Font TileFont = Font("Tahoma", tile_font_desc);

	float PlayerScale = 0.5f;

	GameState->GameSprites.tmp_object_sprite_001.set_alignment(origin_center);
	GameState->GameSprites.tmp_ground_sprite_01.set_alignment(origin_center);

	//
	// NOTE: Render tile map
	//
#ifdef WIN32
	uint64 StartCycleCounter = __rdtsc();
	uint64 EndCycleCounter;
	uint64 TileRenderCounts = 0;
	uint64 FontRenderCounts = 0;
#endif
	for (int y = -GameState->TilesOnHalfScreen.height; y <= GameState->TilesOnHalfScreen.height; y++)
	{
		for (int x = -GameState->TilesOnHalfScreen.width; x <= GameState->TilesOnHalfScreen.width; x++)
		{
			Vec2i CurrentTile = GameState->CameraPos.Tile + Vec2i(x, y);
			uint32 Tile = GetTileValue(TileMap, CurrentTile) & 0x0000ffff;
			if (Tile > 0)
			{
				//GameState->tmp_sprite.set_frame(Tile - 1);
				//GameState->tmp_sprite.set_alignment(Origin::origin_center);
				GameState->GameSprites.tmp_ground_sprite_01.set_frame(Tile - 1);
				GameState->GameSprites.tmp_ground_sprite_01.set_alignment(Origin::origin_center);
				Sizef SpriteSize(GameState->GameSprites.tmp_ground_sprite_01.get_size());
				Vec2f TilePosition = GameState->CameraOrigin - (GameState->CameraPos.TilePos - Vec2f((float)x, (float)y)) * Vec2f(World->TileSizePixels);
				//GameState->tmp_sprite.set_scale(World->TileSizePixels.x / SpriteSize.width, World->TileSizePixels.y / SpriteSize.height);
				//GameState->tmp_sprite.draw(canvas, TilePosition.x, TilePosition.y);
				GameState->GameSprites.tmp_ground_sprite_01.set_scale(World->TileSizePixels.x / SpriteSize.width, World->TileSizePixels.y / SpriteSize.height);
				GameState->GameSprites.tmp_ground_sprite_01.draw(canvas, TilePosition.x, TilePosition.y);
#if 0
				if (Tile > 10)
				{
					//canvas.fill_rect(TilePosition.x - World->TileSizePixels.width / 2, TilePosition.y - World->TileSizePixels.height / 2, TilePosition.x + World->TileSizePixels.width / 2, TilePosition.y + World->TileSizePixels.height/2);
					//GameState->tmp_object_sprite1.set_scale(World->TileSizePixels.width / SpriteSize.width, World->TileSizePixels.height / SpriteSize.height);
					//GameState->tmp_object_sprite1.draw(canvas, TilePosition.x, TilePosition.y);
					GameState->tmp_wall_sprite1.set_alignment(Origin::origin_center);
					GameState->tmp_wall_sprite1.set_frame(Tile - 11);
					GameState->tmp_wall_sprite1.set_scale(World->TileSizePixels.x / SpriteSize.width, World->TileSizePixels.y / SpriteSize.height);
					GameState->tmp_wall_sprite1.draw(canvas, TilePosition.x, TilePosition.y - (128.0f * PlayerScale));
				}
#endif
#ifdef WIN32
				EndCycleCounter = __rdtsc();
				TileRenderCounts += EndCycleCounter - StartCycleCounter;
				StartCycleCounter = __rdtsc();
#endif
				/*
				if ((GameState->CameraPos.Tile + Vec2i(x, y)) == GameState->PlayerEntity->Position.Tile)
				{
					/// Player bounding box
					//canvas.fill_rect(TilePosition.x - World->TileSizePixels.width / 2, TilePosition.y - World->TileSizePixels.height / 2, TilePosition.x + World->TileSizePixels.width / 2, TilePosition.y + World->TileSizePixels.height / 2, Colorf::black);
					canvas.draw_box(TilePosition.x - World->TileSizePixels.x / 2, TilePosition.y - World->TileSizePixels.y / 2, TilePosition.x + World->TileSizePixels.x / 2, TilePosition.y + World->TileSizePixels.y / 2, Colorf::black);
				}
				{
					// Tile coordinates
					//canvas.draw_box(TilePosition.x - World->TileSizePixels.x / 2, TilePosition.y - World->TileSizePixels.y / 2, TilePosition.x + World->TileSizePixels.x / 2, TilePosition.y + World->TileSizePixels.y / 2, Colorf::green);
					//std::string text1(string_format("%1, %2", CurrentTile.x, CurrentTile.y));
					//std::string text2(string_format("%1", Tile));
					//TileFont.draw_text(canvas, 2 + TilePosition.x - World->TileSizePixels.x / 2, 14 + TilePosition.y - World->TileSizePixels.y / 2, text1, Colorf::green);
					//TileFont.draw_text(canvas, 2 + TilePosition.x - World->TileSizePixels.x / 2, 28 + TilePosition.y - World->TileSizePixels.y / 2, text2, Colorf::green);
				}
				*/
#ifdef WIN32
				EndCycleCounter = __rdtsc();
				FontRenderCounts += EndCycleCounter - StartCycleCounter;
				StartCycleCounter = __rdtsc();
#endif
			}
		}
	}
	//
	// NOTE: Render tiled entities
	//
	for (int y = -GameState->TilesOnHalfScreen.height; y <= GameState->TilesOnHalfScreen.height; y++)
	{
		for (int x = -GameState->TilesOnHalfScreen.width; x <= GameState->TilesOnHalfScreen.width; x++)
		{
			Vec2i CurrentTile = GameState->CameraPos.Tile + Vec2i(x, y);
			uint32 Index = (GetTileValue(TileMap, CurrentTile) >> 16) & 0x0000ffff;
			if (Index)
			{
				// Draw tiled entity
				entity *Entity = GetEntityFromGroupByIndex(&GameState->TiledEntities, Index);
				if (Entity->EntityType == EntityType_Stone)
				{
					RenderStaticEntity(canvas, &GameState->GameSprites.tmp_object_sprite_stone1, Entity, GameState, PlayerScale);
				}
				if (Entity->EntityType == EntityType_Storage)
				{
					RenderStaticEntity(canvas, &GameState->GameSprites.tmp_object_sprite_001, Entity, GameState, PlayerScale);
				}
			}
		}
	}
	//
	// NOTE: Render entities
	//
	for (uint32 active_entity_count = 0; active_entity_count < GameState->ActiveEntityCount; active_entity_count++)
	{
		entity_active_data *ActiveEntity = &GameState->ActiveEntities[active_entity_count];

		switch (ActiveEntity->EntityBaseData->EntityType)
		{
		case EntityType_Robot:
		{
			//
			// NOTE: Render robots
			//
			RenderBattleRobotEntity(canvas, ActiveEntity->EntityBaseData, GameState, PlayerScale);
			break;
		}
		case EntityType_Stone:
		case EntityType_Storage:
		case EntityType_Wall:
		{
			// TODO: Move render info to entity
			RenderStaticEntity(canvas, &GameState->GameSprites.tmp_object_sprite_stone1, ActiveEntity->EntityBaseData, GameState, PlayerScale);
			break;
		}
		default:
			break;
		}
	}

	/// Player position
	canvas.fill_rect(0, 0, 200, 100, Colorf::black);
	TileFont.draw_text(canvas, 2, 14, string_format("%1, %2", GameState->PlayerEntity->ActiveData->Pos.x, GameState->PlayerEntity->ActiveData->Pos.y));
	TileFont.draw_text(canvas, 2, 28, string_format("%1", GameState->CameraPos.Tile.x));
	TileFont.draw_text(canvas, 2, 42, string_format("%1", GameState->CameraPos.Tile.y));
#ifdef WIN32
	TileFont.draw_text(canvas, 2, 56, string_format("Tile render mcycs : %1", (TileRenderCounts / 1000000)));
	TileFont.draw_text(canvas, 2, 70, string_format("Font render mcycs : %1", (FontRenderCounts / 1000000)));
#endif
}



// WIN32 code

#include <Windows.h>
BOOL WINAPI DllMain(
  _In_ HINSTANCE hinstDLL,
  _In_ DWORD     fdwReason,
  _In_ LPVOID    lpvReserved
)
{
	return TRUE;
}
