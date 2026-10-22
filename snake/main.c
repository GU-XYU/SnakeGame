#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include "map.h"
#include "snake.h"
#include "food.h"

int main(void) {
	system("chcp 936 > nul");
	int x, y;
	char keyboardinput = 'A';
	scanf("%d %d", &x, &y);    //输入地图大小
	while (getchar() != '\n');
	snake *snakehead = NULL, *snaketail = NULL;
	point *foodpoint = NULL;

	srand(clock());

	snakeinit(3, x, y, &snakehead, &snaketail);
	initfood(x, y, &foodpoint);

	printf("\033[?25l");         //隐藏光标
	printf("\033[2J\033[H");     //清屏

	while (1) {
		if (_kbhit()) {
			keyboardinput = _getch();
		}

		int eat = snakeeatfood(snakehead, &foodpoint);
		movesnake(keyboardinput, eat, &snakehead, &snaketail);
		if (eat) initfood(x, y, &foodpoint);
		drawmap(x, y, snakehead, foodpoint);
		Sleep(100);
	}

}