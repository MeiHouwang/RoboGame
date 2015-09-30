#include "game_entity.h"


// Get collision time
// 0.0 - 1.0 = collision
float CollideEntity_MovingWithFixedInCameraSpace(entity *MovingEntity, entity *FixedEntity, Vec2f MoveDelta)
{
	float Result = 2.0f;
	float tEpsilon = 0.00001f;

	if (MovingEntity->CollisionType && FixedEntity->CollisionType)
	{
		// „S„u„ƒ„„ „„€ „M„y„~„Ž„{„€„r„ƒ„{„€„}„…
		entity_active_data *ActiveEntity = FixedEntity->ActiveData;
		entity_active_data *ActiveMovingEntity = MovingEntity->ActiveData;
		Rectf TestBox(ActiveEntity->Pos.x + (ActiveEntity->EntityBaseData->CollisionBox.left + MovingEntity->CollisionBox.left),
			ActiveEntity->Pos.y + (ActiveEntity->EntityBaseData->CollisionBox.top + MovingEntity->CollisionBox.top),
			ActiveEntity->Pos.x + (ActiveEntity->EntityBaseData->CollisionBox.right + MovingEntity->CollisionBox.right),
			ActiveEntity->Pos.y + (ActiveEntity->EntityBaseData->CollisionBox.bottom + MovingEntity->CollisionBox.bottom));
		if (MoveDelta.x != 0)
		{
			// „B„u„‚„„„y„{„p„|„Ž„~„p„‘ „s„‚„p„~„Ž
			float tResult = (TestBox.right - ActiveMovingEntity->Pos.x) / MoveDelta.x;
			float Y = ActiveMovingEntity->Pos.y + tResult * MoveDelta.y;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((Y >= TestBox.top) && (Y <= TestBox.bottom))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}

			tResult = (TestBox.left - ActiveMovingEntity->Pos.x) / MoveDelta.x;
			Y = ActiveMovingEntity->Pos.y + tResult * MoveDelta.y;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((Y >= TestBox.top) && (Y <= TestBox.bottom))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}
		}
		if (MoveDelta.y != 0)
		{
			// „C„€„‚„y„x„€„~„„„p„|„Ž„~„p„‘ „s„‚„p„~„Ž
			float tResult = (TestBox.top - ActiveMovingEntity->Pos.y) / MoveDelta.y;
			float X = ActiveMovingEntity->Pos.x + tResult * MoveDelta.x;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((X >= TestBox.left) && (X <= TestBox.right))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}

			tResult = (TestBox.bottom - ActiveMovingEntity->Pos.y) / MoveDelta.y;
			X = ActiveMovingEntity->Pos.x + tResult * MoveDelta.x;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((X >= TestBox.left) && (X <= TestBox.right))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}
		}
	}
	if (FixedEntity->CollisionType == 2)
	{
		// „S„u„ƒ„„ „„€ „M„y„~„Ž„{„€„r„ƒ„{„€„}„…
		entity_active_data *ActiveEntity = FixedEntity->ActiveData;
		entity_active_data *ActiveMovingEntity = MovingEntity->ActiveData;
		Rectf TestBox(ActiveEntity->Pos.x + (ActiveEntity->EntityBaseData->CollisionBox2.left + MovingEntity->CollisionBox.left),
			ActiveEntity->Pos.y + (ActiveEntity->EntityBaseData->CollisionBox2.top + MovingEntity->CollisionBox.top),
			ActiveEntity->Pos.x + (ActiveEntity->EntityBaseData->CollisionBox2.right + MovingEntity->CollisionBox.right),
			ActiveEntity->Pos.y + (ActiveEntity->EntityBaseData->CollisionBox2.bottom + MovingEntity->CollisionBox.bottom));
		if (MoveDelta.x != 0)
		{
			// „B„u„‚„„„y„{„p„|„Ž„~„p„‘ „s„‚„p„~„Ž
			float tResult = (TestBox.right - ActiveMovingEntity->Pos.x) / MoveDelta.x;
			float Y = ActiveMovingEntity->Pos.y + tResult * MoveDelta.y;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((Y >= TestBox.top) && (Y <= TestBox.bottom))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}

			tResult = (TestBox.left - ActiveMovingEntity->Pos.x) / MoveDelta.x;
			Y = ActiveMovingEntity->Pos.y + tResult * MoveDelta.y;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((Y >= TestBox.top) && (Y <= TestBox.bottom))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}
		}
		if (MoveDelta.y != 0)
		{
			// „C„€„‚„y„x„€„~„„„p„|„Ž„~„p„‘ „s„‚„p„~„Ž
			float tResult = (TestBox.top - ActiveMovingEntity->Pos.y) / MoveDelta.y;
			float X = ActiveMovingEntity->Pos.x + tResult * MoveDelta.x;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((X >= TestBox.left) && (X <= TestBox.right))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}

			tResult = (TestBox.bottom - ActiveMovingEntity->Pos.y) / MoveDelta.y;
			X = ActiveMovingEntity->Pos.x + tResult * MoveDelta.x;
			if ((tResult >= 0) && (Result > tResult))
			{
				if ((X >= TestBox.left) && (X <= TestBox.right))
				{
					Result = max(0.0f, tResult - tEpsilon);
				}
			}
		}
	}
	// TODO : „P„‚„€„y„x„r„€„|„Ž„~„€„u „{„€„|„y„‰„u„ƒ„„„r„€ „†„€„‚„} „{„€„|„|„y„x„y„z

	return Result;
}

