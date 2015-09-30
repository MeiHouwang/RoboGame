#if !defined(TILE_MAP_H)
#include "game_defines.h"
#include "intrinsics.h"
#include "game_memory.h"

#define GetTiledIndex(value) ((value >> 16) & 0x0000ffff)

struct world_position
{
	Vec2i Tile;
	Vec2f TilePos;
};

struct tile_chunk
{
	uint32 Initialized;
	Vec2ui ChunkPos;
	uint32 *Tiles;
	tile_chunk *NextInHash;
};

struct tile_map
{
	Vec2ui TileChunkSize;
	//Vec2ui CenterChunkPosition;

	// NOTE: ÑÅÑÄÑ{Ñp ÑèÑÑÑÄ ÑtÑÄÑ|ÑwÑ~ÑÄ ÑqÑçÑÑÑé Ñ{ÑÇÑpÑÑÑ~ÑÄ ÑtÑrÑÖÑ}
	tile_chunk TileChunkHash[4096];
};

inline world_position RecanonicalPosition(world_position Pos)
{
	world_position Result = Pos;
	Vec2i Offset;
	Offset.x = TruncateFloatToInt32(Result.TilePos.x * 2.0f);
	Offset.y = TruncateFloatToInt32(Result.TilePos.y * 2.0f);
	Result.Tile += Offset;
	Result.TilePos -= Offset;

	return Result;
}

uint32 GetTileValue(tile_map *TileMap, Vec2i Pos);
void SetTileValue(memory_arena *Arena, tile_map *TileMap, Vec2i Pos, uint32 TileValue);
void AddEntityToTile(tile_map *TileMap, Vec2i Tile, uint32 StoneIndex);

#define TILE_MAP_H
#endif
