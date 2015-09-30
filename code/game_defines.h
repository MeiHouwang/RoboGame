#if !defined(COMMON_GAME_DEFINES_H)
#define COMMON_GAME_DEFINES_H

#ifdef _DEBUG
#define Assert(Expression) if(!(Expression)) {*(int*)0 = 0;}
#else
#define Assert(Expression)
#endif

#define ArrayCount(array) (sizeof((array))/sizeof((array)[0]))

#include <math.h>

#define internal static;
#define global_variable static;

#define Pi32 3.14159265359f

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

#endif
