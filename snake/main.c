#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include "map.h"
#include "snake.h"
#include "food.h"
#include "over.h"

int main(void) {
	system("chcp 936 > nul");
	int x, y;
	char keyboardinput = 'A';
	printf("游戏时全屏窗口\n输入地图大小，例160 50");
	scanf("%d %d", &x, &y);    //输入地图大小
	while (getchar() != '\n');
	snake *snakehead = NULL, *snaketail = NULL;
	point *foodpoint = NULL;

	srand(clock());

	snakeinit(10, x, y, &snakehead, &snaketail);
	initfood(x, y, &foodpoint);

	printf("\033[?25l");         //隐藏光标
	printf("\033[2J\033[H");     //清屏

	while (1) {
		if (_kbhit()) {
			keyboardinput = _getch();
		}

		Sleep(50);
		int eat = snakeeatfood(snakehead, &foodpoint);
		movesnake(keyboardinput, eat, &snakehead, &snaketail);
		if (eat) initfood(x, y, &foodpoint);
		if (detectover(x, y, snakehead) == 1) break;
		drawmap(x, y, snakehead, foodpoint);
		
	}
	system("pause");
}