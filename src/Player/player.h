#ifndef PLAYER_H
#define PLAYER_H

#include "../types.h"

typedef struct Player {
    Vector2 pos;
    Vector2 dpos;
    float rad; //Rotation in radians
    float speed;
    float rotspeed;
} Player;

typedef struct PlayerActions {
    Key Forward;
    Key Backward;
    Key Left;
    Key Right;

    Key RotLeft;
    Key RotRight;
} PlayerActions;

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed, float RotationSpeed);
void MovePlayer(Player *_Player, PlayerActions *PA, float Delta);

#endif // !PLAYER_H
