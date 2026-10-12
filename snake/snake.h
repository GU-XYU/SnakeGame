#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct snake {
	int x;
	int y;
	struct snake* next;
}snake;

//检查当前xy值位置是否为蛇
int findsnake(int x, int y, const snake* head);

//l长度 hw地图大小
void snakeinit(int l, int h, int w, snake** snakehead, snake** snaketail);

//找最后一个节点和倒二 进 findtail 时至少有 2 个节点
void findtail(snake** snakehead, snake** snaketail, snake** prevnode);

//eat为蛇进食状态 1为食用 0为未食用 mf为蛇前进方向WASD
void movesnake(char mf, int eat, snake** snakehead, snake** snaketail);