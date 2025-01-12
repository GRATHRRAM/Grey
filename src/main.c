#include <raylib.h>
#include "Map/map.h"
#include "types.h"

void  __RunGame(){
    InitWindow(800,600,"Grey");
    SetWindowState(FLAG_VSYNC_HINT);

    Map map = {};
    uint8 maplayout[] = {
        1,1,1,1,
        1,0,0,1,
        1,0,0,1,
        1,1,1,1
    };
    map.RowSize = 4;
    
    InitMap(16,maplayout, &map);

    while(!WindowShouldClose()){
        BeginDrawing();
            DrawMiniMap((Vector2){100,100},(Vector2){100,100}, &map, 1.f);
        EndDrawing();
    }

    FreeMap(&map);
}
