#include <raylib.h>
#include "Map/map.h"
#include "Player/player.h"

void  __RunGame(){
    InitWindow(800,600,"Grey");
    SetWindowState(FLAG_VSYNC_HINT);
    SetTargetFPS(60); 

    Map map = {};
    uint8 maplayout[] = {
        1,1,1,1,1,
        1,0,0,0,1,
        1,0,1,1,1,
        1,0,0,0,1,
        1,1,1,1,1
    };
    
    InitMap(&map, 25, maplayout, 5);

    Player pl = {};
    InitPlayer(&pl, 100, 100, 0, 7, 7);
    
    PlayerActions pla = {};
    pla.Forward = KEY_W;
    pla.Backward = KEY_S;
    pla.RotLeft = KEY_LEFT;
    pla.RotRight = KEY_RIGHT;

    while(!WindowShouldClose()){
        MovePlayer(&pl,&pla,GetFrameTime());

        BeginDrawing();
            ClearBackground(BLACK);
            DrawMiniMap(&map, &pl, (Vector2){}, 1.f, MAP_FLAG_DRAW_DIR);
        EndDrawing();
    }

    FreeMap(&map);
}
