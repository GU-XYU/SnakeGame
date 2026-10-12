#include "over.h"

int snakelen(const snake* snakehead) {
	int len = 0;

	for (const snake* p = snakehead; p != NULL; p = p->next) len++;
	return len;
}

static int iswall(int x, int y, int w, int h) {  //地图最外一圈是墙，蛇只能在内部活动
	return (x <= 0 || x >= w - 1 || y <= 0 || y >= h - 1);
}

gamestate checkgame(const snake* snakehead, int w, int h) {
	if (snakehead == NULL) return GAME_CONTINUE;  //还没有蛇，谈不上结束
	if (iswall(snakehead->x, snakehead->y, w, h)) return GAME_OVER_WALL;
	if (findsnake(snakehead->x, snakehead->y, snakehead->next)) return GAME_OVER_SELF;
	if (w > 2 && h > 2 && snakelen(snakehead) >= (w - 2) * (h - 2)) return GAME_OVER_WIN;
	return GAME_CONTINUE;
}

int isgameover(gamestate state) {
	return state == GAME_OVER_WALL || state == GAME_OVER_SELF || state == GAME_OVER_WIN;
}

void showgameover(gamestate state, int w) {
	const char* msg = NULL;

	switch (state) {
		case GAME_OVER_WALL:
			msg = "撞到墙了，游戏结束！";
			break;
		case GAME_OVER_SELF:
			msg = "咬到自己了，游戏结束！";
			break;
		case GAME_OVER_WIN:
			msg = "蛇填满了整个地图，你赢了！";
			break;
		default:
			return;  //游戏还在继续，什么都不输出
	}

	if (w < 1) w = 1;
	for (int i = 0; i < w; i++) putchar('#');
	printf("\n%s\n", msg);
	for (int i = 0; i < w; i++) putchar('#');
	printf("\n");
	return;
}
