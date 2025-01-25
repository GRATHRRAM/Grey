#include <raylib.h>
#include "Map/map.h"
#include "Player/player.h"

void  __RunGame(){
    InitWindow(800,600,"Grey");
    SetWindowState(FLAG_VSYNC_HINT);
    SetTargetFPS(60); 

    Map map = {};
    uint8 maplayout[] = {
        1,1,1,1,
        1,0,0,1,
        1,0,0,1,
        1,1,1,1
    };
    
    InitMap(16,maplayout, &map);
    map.RowSize = 4;

    Player pl = {};
    InitPlayer(&pl, 100, 100, 0, 200);
    
    PlayerActions pla = {};
    pla.Forward = KEY_W;

    while(!WindowShouldClose()){
        MovePlayer(&pl,&pla,GetFrameTime());

        BeginDrawing();
            ClearBackground(BLACK);
            DrawMiniMap((Vector2){},pl.pos, &map, 1.f);
        EndDrawing();
    }

    FreeMap(&map);
}
