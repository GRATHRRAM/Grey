#include "../types.h"
#include "raylib.h"
#include "map.h"
#include <stdlib.h>
#include <stdio.h>

uint8 InitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize);
uint8 ReInitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize);
void  FreeMap(Map *map);

void DrawMiniMap(Map *map, Player *_Player, Vector2 MiniMapPosition, float Scale, uint8 Flags);

/* Source */

uint8 InitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize) {
    map->Chunks = calloc(ChunkCout, sizeof(uint8));
    if(map->Chunks == NULL) return MAP_ERR_CANT_ALLOC_MEM;

    for(uint16 cc = 0; cc < ChunkCout; ++cc) {
        map->Chunks[cc] = Chunks[cc];
    }

    map->ChunkCount = ChunkCout;
    map->RowSize = RowSize;

    return MAP_ERR_OK; 
}

uint8 ReInitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize) {
    map->Chunks = realloc(map->Chunks, ChunkCout * sizeof(uint8));
    if(map->Chunks == NULL) return MAP_ERR_CANT_ALLOC_MEM;
    
    for(uint16 cc = 0; cc < ChunkCout; ++cc) {
        map->Chunks[cc] = Chunks[cc];
    
    }
    
    map->ChunkCount = map->ChunkCount;
    map->RowSize = RowSize;
    
    return MAP_ERR_OK; 
}

void FreeMap(Map *map) {
    free(map->Chunks);
}

void DrawMiniMap(Map *map, Player *_Player, Vector2 MiniMapPosition, float Scale, uint8 Flags) {
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

    if(Flags & MAP_FLAG_DRAW_DIR) {
        DrawLineEx(
                (Vector2){
                (_Player->pos.x - 5 + MiniMapPosition.x) * Scale,
                (_Player->pos.y - 5 + MiniMapPosition.y) * Scale},
                (Vector2){
                ((_Player->dpos.x * 6) + _Player->pos.x + MiniMapPosition.x) * Scale,
                ((_Player->dpos.y * 6) + _Player->pos.y + MiniMapPosition.y) * Scale},
                Scale * 2,
                YELLOW
        ); 
    }

    DrawRectangle(
            (_Player->pos.x - 5 + MiniMapPosition.x) * Scale,
            (_Player->pos.y - 5 + MiniMapPosition.y) * Scale,
            10 * Scale,
            10 * Scale,
            YELLOW
    ); 
}
