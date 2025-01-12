#ifndef MAP_H
#define MAP_H
#include "../types.h"
#include <raylib.h>

#define MAP_ERR_OK 0x0
#define MAP_ERR_CANT_ALLOC_MEM 0x1

typedef struct Map {
    uint16 ChunkCount;
    uint8  *Chunks;

    uint16 RowSize;
} Map;

/* InitMap Sets Map->RowSize to 8 if zero! */
uint8 InitMap(uint16 ChunkCout, uint8 *Chunks, Map *map);
uint8 ReInitMap(uint16 ChunkCout, uint8 *Chunks, Map *map);
void  FreeMap(Map *map);

void DrawMiniMap(Vector2 MiniMapPosition, Vector2 PlayerPosition, Map *map, float Scale);

#endif // !MAP_H
