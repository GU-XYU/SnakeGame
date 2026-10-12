#pragma once

#include "snake.h"

/* 游戏状态：GAME_CONTINUE 表示继续，其余都是结束原因 */
typedef enum {
	GAME_CONTINUE = 0,	/* 游戏继续 */
	GAME_OVER_WALL,		/* 撞到墙 */
	GAME_OVER_SELF,		/* 咬到自己的身体 */
	GAME_OVER_WIN		/* 蛇填满地图，通关 */
} gamestate;

/* 统计蛇的长度，即节点的个数 */
int snakelen(const snake* snakehead);

/* 判断游戏是否结束：先看撞墙，再看咬到自己，最后看是否通关 */
gamestate checkgame(const snake* snakehead, int w, int h);

/* 判断状态是不是已经结束 */
int isgameover(gamestate state);

/* 输出游戏结束提示，w 为地图宽度（用来画提示框的上下边） */
void showgameover(gamestate state, int w);
