#ifndef TYPES_H
#define TYPES_H

#include <stdint.h>
#include <raylib.h>
#include <math.h>

typedef  uint8_t  uint8;
typedef  uint16_t uint16;
typedef  uint32_t uint32;
typedef  uint64_t uint64;

/* Type Vec2 Use in Source Files Only */
/* Full Types Mainly for Headers To Read Them More Easly */
typedef uint16 Key;

typedef struct Vector2i { int x; int y; } Vector2i;

#define __PI 3.1415926

#define Deg2Rad(angleInDegrees) ((angleInDegrees) * __PI / 180.0)
#define Rad2Deg(angleInRadians) ((angleInRadians) * 180.0 / __PI)

#endif // !TYPES_H
