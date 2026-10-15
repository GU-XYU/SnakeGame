#pragma once
#include "snake.h"
#include <stdio.h>
#include <stdlib.h>
#include "food.h"

//x y为地图大小
void drawmap(int x, int y, const snake* snakehead, const point* foodpoint);