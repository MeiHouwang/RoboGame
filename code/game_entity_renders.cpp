#include "game_entity_renders.h"

void RenderBattleRobotEntity(Canvas &canvas, entity *Entity, game_state *GameState, float Scale)
{
	world *World = GameState->World;
	Vec2f PlayerOffset = ((Vec2f)(Entity->Position.Tile - GameState->CameraPos.Tile) * Vec2f(World->TileSizePixels)) + Entity->Position.TilePos * Vec2f(World->TileSizePixels) - GameState->CameraPos.TilePos * Vec2f(World->TileSizePixels);
	Vec2f torso_offset[8] = { Vec2f(0, -20.0f), Vec2f(-10.0f, -40.0f), Vec2f(0, -30.0f), Vec2f(10.0f, -40.0f), Vec2f(20.0f, -30.0f), Vec2f(20.0f, -30.0f), Vec2f(20.0f, -30.0f), Vec2f(20.0f, -30.0f) };
	//track
	Sprite TrackSprite;
	switch (Entity->Orientation)
	{
		case 0:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_up;
			break;
		case 1:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_right;
			break;
		case 2:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_down;
			break;
		case 3:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_left;
			break;
		case 4:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_ur;
			break;
		case 5:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_br;
			break;
		case 6:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_bl;
			break;
		case 7:
			TrackSprite = GameState->GameSprites.tmp_player_image_track_ul;
			break;
	}
	if (Entity->Orientation == 0 || Entity->Orientation == 2)
	{
		// Vertical
		TrackSprite.set_scale(Scale, Scale);
		TrackSprite.set_alignment(Origin::origin_center);
		TrackSprite.set_delay(100);
		TrackSprite.update(int(abs(Entity->LastMoveInPixels.y) * 90.0f * Scale));
		// base
		GameState->GameSprites.tmp_player_image_v.set_scale(Scale, Scale);
		GameState->GameSprites.tmp_player_image_v.set_alignment(Origin::origin_center);
		GameState->GameSprites.tmp_player_image_v.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x, GameState->CameraOrigin.y + PlayerOffset.y);
		//tracks
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x - (80.0f * Scale), GameState->CameraOrigin.y + PlayerOffset.y);
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x + (74.0f * Scale), GameState->CameraOrigin.y + PlayerOffset.y);
	}
	else if (Entity->Orientation == 1 || Entity->Orientation == 3)
	{
		// Horizontal
		TrackSprite.set_scale(Scale, Scale);
		TrackSprite.set_alignment(Origin::origin_center);
		TrackSprite.set_delay(100);
		TrackSprite.update(int(abs(Entity->LastMoveInPixels.x) * 90.0f * Scale));
		// track
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x, GameState->CameraOrigin.y + PlayerOffset.y - (52.0f * Scale));
		// base
		GameState->GameSprites.tmp_player_image.set_scale(Scale, Scale);
		GameState->GameSprites.tmp_player_image.set_alignment(Origin::origin_center);
		GameState->GameSprites.tmp_player_image.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x, GameState->CameraOrigin.y + PlayerOffset.y);
		// track
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x, GameState->CameraOrigin.y + PlayerOffset.y);
	}
	else
	{
		// Diagonal
		TrackSprite.set_scale(Scale, Scale);
		TrackSprite.set_alignment(Origin::origin_center);
		TrackSprite.set_delay(100);
		TrackSprite.update(int(abs(Entity->LastMoveInPixels.x) * 64.0f * Scale));
		float TrackXOffset = ((Entity->Orientation % 2) ? -54.0f : 54.0f) * Scale;
		float TrackXBaseOffset = ((Entity->Orientation % 2) ? -18.0f : 18.0f) * Scale;
		float TrackYOffset = 35.0f * Scale;
		float TrackYBaseOffset = 8.0f * Scale;
		Sprite BaseSprite;
		if (Entity->Orientation % 2)
			BaseSprite = GameState->GameSprites.tmp_player_image_ul;
		else
			BaseSprite = GameState->GameSprites.tmp_player_image_ur;
		// track
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x - TrackXOffset - TrackXBaseOffset, GameState->CameraOrigin.y + PlayerOffset.y - TrackYOffset - TrackYBaseOffset);
		// base
		BaseSprite.set_scale(Scale, Scale);
		BaseSprite.set_alignment(Origin::origin_center);
		BaseSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x, GameState->CameraOrigin.y + PlayerOffset.y);
		// track
		TrackSprite.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x + TrackXOffset - TrackXBaseOffset, GameState->CameraOrigin.y + PlayerOffset.y + TrackYOffset - TrackYBaseOffset);
	}
	// torso
	GameState->GameSprites.tmp_player_image_torso.set_alignment(Origin::origin_center);
	GameState->GameSprites.tmp_player_image_torso.set_scale(Scale, Scale);
	GameState->GameSprites.tmp_player_image_torso.set_frame(Entity->Orientation);
	GameState->GameSprites.tmp_player_image_torso.draw(canvas, GameState->CameraOrigin.x + PlayerOffset.x + torso_offset[Entity->Orientation % 4].x * Scale, GameState->CameraOrigin.y + PlayerOffset.y + torso_offset[Entity->Orientation % 8].y * Scale);
	// Collision box
	//canvas.fill_rect(GameState->CameraOrigin.x + PlayerOffset.x + ActiveEntity->EntityBaseData->CollisionBox.left * GameState->World->TileSizePixels.x, GameState->CameraOrigin.y + PlayerOffset.y + ActiveEntity->EntityBaseData->CollisionBox.top * GameState->World->TileSizePixels.x, GameState->CameraOrigin.x + PlayerOffset.x + ActiveEntity->EntityBaseData->CollisionBox.right * GameState->World->TileSizePixels.x, GameState->CameraOrigin.y + PlayerOffset.y + ActiveEntity->EntityBaseData->CollisionBox.bottom * GameState->World->TileSizePixels.y, Colorf::yellow);
}

void RenderStaticEntity(Canvas &canvas, Sprite *EntitySprite, entity *Entity, game_state *GameState, float Scale)
{
	world *World = GameState->World;
	Vec2f EntityOffset = ((Vec2f)(Entity->Position.Tile - GameState->CameraPos.Tile) * Vec2f(World->TileSizePixels)) + Entity->Position.TilePos * Vec2f(World->TileSizePixels) - GameState->CameraPos.TilePos * Vec2f(World->TileSizePixels);
	//Vec2f EntityOffset = (ActiveEntity->Pos - GameState->CameraPos.TilePos)* Vec2f(World->TileSizePixels);
	EntitySprite->set_alignment(Origin::origin_center);
	EntitySprite->set_scale(Scale, Scale);
	EntitySprite->draw(canvas, GameState->CameraOrigin.x + EntityOffset.x, GameState->CameraOrigin.y + EntityOffset.y);
	// Collision box
	//canvas.fill_rect(GameState->CameraOrigin.x + EntityOffset.x + ActiveEntity->EntityBaseData->CollisionBox.left * GameState->World->TileSizePixels.x, GameState->CameraOrigin.y + EntityOffset.y + ActiveEntity->EntityBaseData->CollisionBox.top * GameState->World->TileSizePixels.x, GameState->CameraOrigin.x + EntityOffset.x + ActiveEntity->EntityBaseData->CollisionBox.right * GameState->World->TileSizePixels.x, GameState->CameraOrigin.y + EntityOffset.y + ActiveEntity->EntityBaseData->CollisionBox.bottom * GameState->World->TileSizePixels.y, Colorf::yellow);
	//TileFont.draw_text(canvas, GameState->CameraOrigin.x + EntityOffset.x + 50, GameState->CameraOrigin.y + EntityOffset.y, string_format("%1", ActiveEntity->Pos.x), Colorf::red);
	//TileFont.draw_text(canvas, GameState->CameraOrigin.x + EntityOffset.x + 50, GameState->CameraOrigin.y + EntityOffset.y + 14, string_format("%1", ActiveEntity->Pos.y), Colorf::red);
}
