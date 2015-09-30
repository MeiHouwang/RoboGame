#pragma once

// „P„p„}„‘„„„Ž „t„|„‘ „r„ƒ„u„‡ „~„…„w„t „y„s„‚„€„r„€„z „}„u„‡„p„~„y„{„y
// „N„p „t„p„~„~„„z „}„€„}„u„~„„ „~„u „y„ƒ„„€„|„Ž„x„…„u„„„ƒ„‘ „t„|„‘ „‡„‚„p„~„u„~„y„‘ „s„‚„p„†„y„{„y
struct game_memory
{
	int IsInitialized;
	//uint64 PermanentStorageSize;
	size_t PermanentStorageSize;
	void *PermanentStorage;
	//uint64 TransientStorageSize;
	size_t TransientStorageSize;
	void *TransientStorage;
};

// „T„~„y„r„u„‚„ƒ„p„|„Ž„~„„z „{„…„ƒ„€„{ „„p„}„‘„„„y, „€„„ „{„€„„„€„‚„€„s„€ „}„€„w„~„€ „€„„„{„…„ƒ„„r„p„„„Ž „ƒ„{„€„|„Ž„{„€ „~„…„w„~„€
struct memory_arena
{
	size_t Size;
	size_t Used;
	uint8 *Base;
};

// „M„p„{„‚„€„ƒ„ „t„|„‘ „r„„t„u„|„u„~„y„‘ „„p„}„‘„„„y „y„x „p„‚„u„~„ „„€„t „‚„p„x„}„u„‚ „„u„‚„u„t„p„~„~„€„s„€ „„„y„„p
#define PushStruct(Arena, type) (type*)PushSize_(Arena, sizeof(type))
#define PushArray(Arena, Count, type) (type*)PushSize_(Arena, (Count) * sizeof(type))
inline void *PushSize_(memory_arena *Arena, size_t Size)
{
	Assert((Arena->Used + Size) <= Arena->Size);
	void *Result = Arena->Base + Arena->Used;
	Arena->Used += Size;

	return Result;
}

