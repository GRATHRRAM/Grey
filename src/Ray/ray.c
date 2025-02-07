#include "ray.h"

float CastRay(Vector2 StartPosition, float Angle, Map *_Map);
//RayInfo CastRayFullInfo(Vector2 StartPosition, Vector2 Direction, Map *_Map);


float CastRay(Vector2 StartPosition, float Angle, Map *_Map) {
    float Rad = Deg2Rad(Angle);

    Vector2 Ray = {};
    float StepSize = 0.1;

    while(1) {
        Ray.x += cos(Rad) * StepSize;
        Ray.y += sin(Rad) * StepSize;

        Vector2i MapPos = {(int) Ray.x,(int) Ray.y};

    }

    return 0;
}

/*
RayInfo CastRayFullInfo(Vector2 StartPosition, Vector2 Direction, Map *_Map) {
    return (RayInfo){};
}*/
