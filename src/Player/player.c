#include "player.h"
#include <math.h>

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed, float RotationSpeed);
void MovePlayer(Player *_Player, PlayerActions *PA, float Delta);

void InitPlayer(Player *_Player, float x, float y, float Rotation, float Speed, float RotationSpeed) {
    _Player->pos = (Vector2){x,y};
    _Player->rad = Rotation;
    _Player->speed = Speed;
    _Player->rotspeed = RotationSpeed;
    _Player->dpos.x = cos(_Player->rad) * 5;    
    _Player->dpos.y = sin(_Player->rad) * 5;
}

void MovePlayer(Player *_Player, PlayerActions *PA, float Delta) {
    if(IsKeyDown(PA->RotLeft)) {
        _Player->rad -= _Player->rotspeed * Delta;
        if(_Player->rad < 0) _Player->rad += 2*__PI;
        _Player->dpos.x = cos(_Player->rad) * 5;
        _Player->dpos.y = sin(_Player->rad) * 5;
    }
    if(IsKeyDown(PA->RotRight)) {
        _Player->rad += _Player->rotspeed * Delta;
        if(_Player->rad > 2*__PI) _Player->rad -= 2*__PI;
        _Player->dpos.x = cos(_Player->rad) * 5;
        _Player->dpos.y = sin(_Player->rad) * 5;
    }
    if(IsKeyDown(PA->Forward)){
        _Player->pos.x += _Player->dpos.x;
        _Player->pos.y += _Player->dpos.y;
    }
    if(IsKeyDown(PA->Backward)){
        _Player->pos.x -= _Player->dpos.x;
        _Player->pos.y -= _Player->dpos.y;
    }
}
