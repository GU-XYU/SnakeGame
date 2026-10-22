//
// Created by 123 on 2026/10/13.
//

#include <stdio.h>
#include "map.h"
#include "display.h"
#include <stdlib.h>


void DisplayDraw(const Map *map) {
    system("cls");
    printf("\033[2J\033[H");//清屏并将光标移动到左上角
    for (int i = 0; i < map->max_y; i++) {
        for (int j = 0; j < map->max_x; j++) {
            printf("%c", map->map[i][j]);
        }
        printf("\n");
    }
}
