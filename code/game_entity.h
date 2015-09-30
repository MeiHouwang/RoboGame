#pragma once
#include "precomp.h"
#include "game_defines.h"
#include "game_memory.h"
#include "tile_map.h"


enum entity_types
{
	EntityType_Null,
	EntityType_Robot,
	EntityType_Stone,
	EntityType_Storage,
	EntityType_Wall,
};

enum entity_movement
{
	EntityMove_Up = (1 << 0),
	EntityMove_Down = (1 << 1),
	EntityMove_Left = (1 << 2),
	EntityMove_Right = (1 << 3),
};

enum entity_flags
{
	EntityFlag_Collides = (1 << 1),
};

// „T„~„y„r„u„‚„ƒ„p„|„Ž„~„p„‘ „…„„‚„p„r„|„‘„„‹„p„‘ „ƒ„„„‚„…„{„„„…„‚„p
// „I„ƒ„„€„|„Ž„x„…„u„„„ƒ„‘ „y „t„|„‘ „„u„‚„u„t„p„‰„y „{„€„}„p„~„t „€„„ „y„s„‚„€„{„p, „y „t„|„‘ „I„I
struct entity_controller
{
	uint8 Active;
	uint8 MoveOrder;
};

struct entity_active_data;


// „P„‚„u„t„ƒ„„„p„r„|„‘„u„„ „r„ƒ„u „p„{„„„y„r„~„„u „€„q„Œ„u„{„„„ „r „y„s„‚„u
struct entity
{
	entity_types EntityType;
	world_position Position;
	uint8 Orientation;		// 0 - „r„„‚„p„r„€
							// 1 - „r„~„y„x
							// 2 - „r„|„u„r„€
							// 3 - „r„r„u„‚„‡

	entity_controller Controller;
	
	// Animation parameters
	uint8 EntityFrame;
	Vec2f LastMoveInPixels;


	uint32 Flags;

	// „U„y„x„y„‰„u„ƒ„{„y„u „„p„‚„p„}„u„„„‚„
	float Mass;
	float RResistance; // „S„‚„u„~„y„u „t„r„y„w„y„„„u„|„u„z
	float CurrentSpeed;
	Vec2f MovementVector;
	
	uint8 CollisionType;	// 0 - no collision
							// 1 - 1 collision box
							// 2 - 2 collision boxes

	Rectf CollisionBox;
	Rectf CollisionBox2;

	entity_active_data *ActiveData;
};

// „D„p„~„~„„u „t„|„‘ „p„{„„„y„r„~„€„s„€ „€„q„Œ„u„{„„„p
// TODO: „„u„‚„u„~„u„ƒ„„„y „r „€„ƒ„~„€„r„~„„u „t„p„~„~„„u „y „…„q„‚„p„„„Ž „~„p„†„y„{ „|„y„Š„~„„ „ƒ„…„‹„~„€„ƒ„„„Ž?
struct entity_active_data
{
	Vec2f Pos; // Relative to the current camera tile

	uint32 ActiveEntityIndex;
	entity *EntityBaseData;
};

// „V„‚„p„~„y„|„y„‹„u „€„q„Œ„u„{„„„€„r
struct entity_group
{
	uint32 EntityCount;
	uint32 GroupSize;
	entity *Entities;
	entity_group *NextGroup;
};


float CollideEntity_MovingWithFixedInCameraSpace(entity *MovingEntity, entity *FixedEntity, Vec2f MoveDelta);
