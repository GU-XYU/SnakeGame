//
// Created by 123 on 2026/10/13.
//

#ifndef SNAKEGAME_MAP_H
#define SNAKEGAME_MAP_H

typedef struct Position { //一个点
    int x;
    int y;
} Position;

typedef struct Map {
    char **map; //地图
    int max_x;
    int max_y;
} Map;

#include "snake.h" // snake 引用了Position,要在这里include
void MapBuildEdge(const Map *map);
void MapBuildFood(const Map *map, Position foodPos);
void MapBuildSnake(const Map *map, const Snake *snake);
void MapInit(const Map *map);


#endif //SNAKEGAME_MAP_H
