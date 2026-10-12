#define _CRT_SECURE_NO_WARNINGS
#include "map.h"
#include "snake.h"

int main(void) {
	int x, y;
	scanf("%d %d", &x, &y);    //输入地图大小
	snake *snakehead = NULL, *snaketail = NULL;
	snakeinit(3, y, x, &snakehead, &snaketail);
	drawmap(x, y, snakehead);
	while (1) {
		movesnake('W', 0, &snakehead, &snaketail);
		drawmap(x, y, snakehead);
	}

}