#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "map.h"
#include "snake.h"
#include "food.h"

int main(void) {

	int x, y;
	char keyboardinput;
	scanf("%d %d", &x, &y);    //输入地图大小
	snake *snakehead = NULL, *snaketail = NULL;
	point* foodpoint = NULL;

	snakeinit(3, y, x, &snakehead, &snaketail);

	while (1) {
		if (_kbhit()) {
			keyboardinput = _getch();
		}
		movesnake(keyboardinput, 0, &snakehead, &snaketail);
		drawmap(x, y, snakehead, &foodpoint);
	}

}