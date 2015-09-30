#if !defined(CUSTOM_INTRINSICS_H)
#define CUSTOM_INTRINSICS_H
#include "game_defines.h"

/*
   „M„p„„„u„}„p„„„y„‰„u„ƒ„{„y„u „†„…„~„{„ˆ„y„y, „„†„†„u„{„„„y„r„~„„u „r„p„‚„y„p„~„„„.
   „D„|„‘ „{„p„w„t„€„z „„|„p„„„†„€„‚„}„.
*/

inline int32 TruncateFloatToInt32(float f)
{
	int32 Result = (int32)f;
	return Result;
}


inline int32 FloorFloatToInt32(float f)
{
	int32 Result = (int32)floorf(f);
	return Result;
}

inline float Sin(float Angle)
{
	float Result = sinf(Angle);
	return Result;
}

inline float Cos(float Angle)
{
	float Result = cosf(Angle);
	return Result;
}

inline float Abs(float f)
{
	float Result = abs(f);
	return Result;
}

inline float Sign(float f)
{
	float Result = f < 0 ? -1.0f : f > 0 ? 1.0f : 0;
	return Result;
}

#endif
