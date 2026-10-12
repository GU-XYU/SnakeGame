#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct snake {
	int x;
	int y;
	struct snake* next;
}snake;

int findsnake(int x, int y, const snake* head);
void snakeinit(int l, int h, int w, snake** snakehead, snake** snaketail);
void findtail(snake** snakehead, snake** snaketail, snake** prevnode);
void movesnake(char mf, int eat, snake** snakehead, snake** snaketail);