#pragma once
#include <stdlib.h>
#include <time.h>
#include "snake.h"

typedef struct point {
	int x, y;
}point;

//初始化 创建一个食物
void initfood(int x, int y, point** foodpoint);

//判断该坐标是否为食物 如果是return 1 不是return 0
int isfood(int x, int y, const point* foodpoint);

//判断snakehead是否在食物上 如果是return 1并free 如果不是return 0
int snakeeatfood(const snake* snakehead, point** foodpoint);