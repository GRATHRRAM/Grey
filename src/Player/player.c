#include "player.h"

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed);
void MovePlayer(Player *_Player, PlayerActions *PA, float Delta);

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed) {
    _Player->pos = (Vector2){x,y}; _Player->rot = Rotation; _Player->speed = Speed;
}

void MovePlayer(Player *_Player, PlayerActions *PA, float Delta) {
    if(IsKeyDown(PA->Forward)) _Player->pos.y += _Player->speed * Delta;
}
