#include "../types.h"
#include "raylib.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

uint8 InitMap(uint16 ChunkCout, uint8 *Chunks, Map *map);
uint8 ReInitMap(uint16 ChunkCout, uint8 *Chunks, Map *map);
void  FreeMap(Map *map);

void DrawMiniMap(Vector2 MiniMapPosition, Vector2 PlayerPosition, Map *map, float Scale);

/* Source */

uint8 InitMap(uint16 ChunkCout, uint8 *Chunks, Map *map) {
    map->Chunks = calloc(ChunkCout, sizeof(uint8));
    if(map->Chunks == NULL) return MAP_ERR_CANT_ALLOC_MEM;

    for(uint16 cc = 0; cc < ChunkCout; ++cc) {
        map->Chunks[cc] = Chunks[cc];
    }

    if(map->RowSize == 0) map->RowSize = 0x8;
    map->ChunkCount = ChunkCout;

    return MAP_ERR_OK; 
}

uint8 ReInitMap(uint16 ChunkCout, uint8 *Chunks, Map *map) {
    map->Chunks = realloc(map->Chunks, ChunkCout * sizeof(uint8));
    if(map->Chunks == NULL) return MAP_ERR_CANT_ALLOC_MEM;
    
    for(uint16 cc = 0; cc < ChunkCout; ++cc) {
        map->Chunks[cc] = Chunks[cc];
    
    }
    map->ChunkCount = map->ChunkCount;
    
    return MAP_ERR_OK; 
}

void FreeMap(Map *map) {
    free(map->Chunks);
}

void DrawMiniMap(Vector2 MiniMapPosition, Vector2 PlayerPosition, Map *map, float Scale) {
    uint16 cc = 0;//Current Chunk
    for(uint16 y = 0 ;; ++y) {
        if(cc == map->ChunkCount) break;
        for(uint x = 0 ;; ++x) {
            if(x == map->RowSize) break;
         
            if(map->Chunks[cc] == (uint8) 0x0) {
                DrawRectangle(
                    ((x * 50) * Scale) + MiniMapPosition.x,
                    ((y * 50) * Scale) + MiniMapPosition.y,
                    50 * Scale,
                    50 * Scale, 
                    LIGHTGRAY
                );
            } else {
                DrawRectangle(
                    ((x * 50) * Scale) + MiniMapPosition.x,
                    ((y * 50) * Scale) + MiniMapPosition.y,
                    50 * Scale,
                    50 * Scale, 
                    DARKBLUE
               );
            }
            cc++;
        }
    }

    DrawRectangle(
            (PlayerPosition.x - 5 + MiniMapPosition.x) * Scale,
            (PlayerPosition.y - 5 + MiniMapPosition.y) * Scale,
            10 * Scale,
            10 * Scale,
            YELLOW
    ); 
}
