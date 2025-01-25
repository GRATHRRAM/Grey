#ifndef PLAYER_H
#define PLAYER_H

#include "../types.h"

typedef struct Player {
    Vector2 pos;
    float rot;
    float speed;
} Player;

typedef struct PlayerActions {
    RayKey Forward;
    RayKey Backward;
    RayKey Left;
    RayKey Right;

    RayKey RotLeft;
    RayKey RotRight;
} PlayerActions;

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed);
void MovePlayer(Player *_Player, PlayerActions *PA, float Delta);

#endif // !PLAYER_H
