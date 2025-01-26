#ifndef PLAYER_H
#define PLAYER_H

#include "../types.h"
#include <raylib.h>

#define __PI 3.1415926

typedef struct Player {
    Vector2 pos;
    Vector2 dpos;
    float rad; //Rotation in radians
    float speed;
    float rotspeed;
} Player;

typedef struct PlayerActions {
    RayKey Forward;
    RayKey Backward;
    RayKey Left;
    RayKey Right;

    RayKey RotLeft;
    RayKey RotRight;
} PlayerActions;

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed, float RotationSpeed);
void MovePlayer(Player *_Player, PlayerActions *PA, float Delta);

#endif // !PLAYER_H
