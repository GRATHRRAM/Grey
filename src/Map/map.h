#ifndef MAP_H
#define MAP_H
#include "../types.h"
#include "../Player/player.h"
#include <raylib.h>

#define MAP_ERR_OK 0x0
#define MAP_ERR_CANT_ALLOC_MEM 0x1

#define MAP_FLAG_NONE      0b00000000
#define MAP_FLAG_DRAW_DIR  0b00000001

typedef struct Map {
    uint16 ChunkCount;
    uint8  *Chunks;

    uint16 RowSize;
} Map;

/* InitMap Sets Map->RowSize to 8 if zero! */
uint8 InitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize);
uint8 ReInitMap(Map *map, uint16 ChunkCout, uint8 *Chunks, uint16 RowSize);
void  FreeMap(Map *map);

void DrawMiniMap(Map *map, Player *_Player, Vector2 MiniMapPosition, float Scale, uint8 Flags);

#endif // !MAP_H
