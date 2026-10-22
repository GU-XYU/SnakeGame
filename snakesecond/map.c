//
// Created by 123 on 2026/10/13.
//

#include "map.h"
#include "snake.h"

void MapBuildEdge(const Map *map) {//生成地图边界
    for (int i = 0; i < map->max_x; i++) {
        map->map[0][i] = '#';
        map->map[map->max_y - 1][i] = '#';
    }
    for (int i = 0; i < map->max_y; i++) {
        map->map[i][0] = '#';
        map->map[i][map->max_x - 1] = '#';
    }
}

void MapBuildFood(const Map *map, const Position foodPos) {//生成食物
    map->map[foodPos.y][foodPos.x] = '*';
}

void MapBuildSnake(const Map *map, const Snake *snake) {//生成蛇
    for (int i = 0; i < snake->length; i++) {
        map->map[snake->body[0].y][snake->body[0].x] = 'O';
        map->map[snake->body[i].y][snake->body[i].x] = 'X';
    }
}

void MapInit(const Map *map) {//初始化地图
    for (int i = 0; i < map->max_y; i++) {
        for (int j = 0; j < map->max_x; j++) {
            map->map[i][j] = ' ';
        }
    }
}