#ifndef RAY_H
#define RAY_H

#include "../types.h"
#include "../Map/map.h"

/*
typedef struct RayInfo {
    Vector2 StartPosition;
    Vector2 EndPosition;
    float Angle;
    float Distance;
} RayInfo;
*/

float CastRay(Vector2 StartPosition, float Angle, Map *_Map);
//RayInfo CastRayFullInfo(Vector2 StartPosition, float Angle, Map *_Map);

#endif // !RAY_H
