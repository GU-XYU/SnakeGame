#pragma once
#include "snake.h"

//检测游戏是否结束 返回0表示函数调用错误 返回1表示函数正确执行
int detectover(int x, int y, const snake* snakehead);