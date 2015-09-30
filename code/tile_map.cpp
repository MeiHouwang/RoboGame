#include "game_precomp.h"
#include "tile_map.h"

tile_chunk *GetTileChunk(tile_map *TileMap, Vec2ui Pos, memory_arena *Arena=0)
{
	uint32 PosX = uint32(Pos.x + 0x3FFFFFFF);
	uint32 PosY = uint32(Pos.y + 0x3FFFFFFF);
	
	// TODO: Better hash function, lol!
	uint32 HashValue = 7 * PosX + 3 * PosY;
	uint32 HashSlot = HashValue & (ArrayCount(TileMap->TileChunkHash) - 1);
	Assert(HashSlot < ArrayCount(TileMap->TileChunkHash));

	tile_chunk *Chunk = TileMap->TileChunkHash + HashSlot;

	while (Chunk)
	{
		if (Pos == Chunk->ChunkPos && Chunk->Initialized)
		{
			break;
		}

		if (Arena && Chunk->Initialized && (!Chunk->NextInHash))
		{
			// Create next in chain
			Chunk->NextInHash = PushStruct(Arena, tile_chunk);
			Chunk = Chunk->NextInHash;
			Chunk->Initialized = 0;
		}
		
		if (!Chunk->Initialized)
		{
			// Create one
			if (Arena)
			{
				uint32 TileCount = TileMap->TileChunkSize.x * TileMap->TileChunkSize.y;
				Chunk->Tiles = PushArray(Arena, TileCount, uint32);
				for (uint32 TileIndex = 0; TileIndex < TileCount; TileIndex++)
				{
					Chunk->Tiles[TileIndex] = 1;
				}
			}
			else
			{
				Chunk->Tiles = 0;
			}
			
			Chunk->ChunkPos = Pos;
			Chunk->NextInHash = 0;
			Chunk->Initialized = 1;

			break;
		}

		Chunk = Chunk->NextInHash;
	}

	return Chunk;
}

uint32 GetTileValue(tile_map *TileMap, Vec2i Pos)
{
	uint32 Result = 0;

	uint32 TileOffsetX = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.x);
	uint32 TileOffsetY = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.y);
	Assert((uint32)abs(Pos.x) < TileOffsetX);
	Assert((uint32)abs(Pos.y) < TileOffsetY);

	Vec2ui ChunkPos = Vec2ui((Pos.x + TileOffsetX) / TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) /  TileMap->TileChunkSize.y);
	Vec2ui InChunkPos = Vec2ui((Pos.x + TileOffsetX) % TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) % TileMap->TileChunkSize.y);

	tile_chunk *TileChunk = GetTileChunk(TileMap, ChunkPos);

	if (TileChunk && TileChunk->Tiles)
	{
		Result = TileChunk->Tiles[InChunkPos.y * TileMap->TileChunkSize.y + InChunkPos.x];
	}

	return Result;
}

void SetTileValue(memory_arena *Arena, tile_map *TileMap, Vec2i Pos, uint32 TileValue)
{
	uint32 TileOffsetX = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.x);
	uint32 TileOffsetY = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.y);
	Assert((uint32)abs(Pos.x) < TileOffsetX);
	Assert((uint32)abs(Pos.y) < TileOffsetY);

	Vec2ui ChunkPos = Vec2ui((Pos.x + TileOffsetX) / TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) / TileMap->TileChunkSize.y);
	Vec2ui InChunkPos = Vec2ui((Pos.x + TileOffsetX) % TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) % TileMap->TileChunkSize.y);

	tile_chunk *TileChunk = GetTileChunk(TileMap, ChunkPos, Arena);
	Assert(TileChunk);
	
	if (!TileChunk->Tiles)
	{
		uint32 TileCount = TileMap->TileChunkSize.x * TileMap->TileChunkSize.y;
		TileChunk->Tiles = PushArray(Arena, TileCount, uint32);
		for (uint32 TileIndex = 0; TileIndex < TileCount; TileIndex++)
		{
			TileChunk->Tiles[TileIndex] = 1;
		}
	}

	TileChunk->Tiles[InChunkPos.y * TileMap->TileChunkSize.y + InChunkPos.x] = TileValue;
}

void SetTileValueUnchecked(tile_map *TileMap, Vec2i Pos, uint32 TileValue)
{
	uint32 TileOffsetX = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.x);
	uint32 TileOffsetY = 0x80000000 - (0x80000000 % TileMap->TileChunkSize.y);
	Assert((uint32)abs(Pos.x) < TileOffsetX);
	Assert((uint32)abs(Pos.y) < TileOffsetY);

	Vec2ui ChunkPos = Vec2ui((Pos.x + TileOffsetX) / TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) / TileMap->TileChunkSize.y);
	Vec2ui InChunkPos = Vec2ui((Pos.x + TileOffsetX) % TileMap->TileChunkSize.x, (Pos.y + TileOffsetY) % TileMap->TileChunkSize.y);

	tile_chunk *TileChunk = GetTileChunk(TileMap, ChunkPos);
	Assert(TileChunk);
	Assert(TileChunk->Tiles);

	TileChunk->Tiles[InChunkPos.y * TileMap->TileChunkSize.y + InChunkPos.x] = TileValue;
}

void AddEntityToTile(tile_map *TileMap, Vec2i Tile, uint32 StoneIndex)
{
	uint32 TileValue = GetTileValue(TileMap, Tile);
	TileValue = (TileValue & 0x0000ffff) | ((StoneIndex << 16) & 0xffff0000);
	SetTileValueUnchecked(TileMap, Tile, TileValue);
}
