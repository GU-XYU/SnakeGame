#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "snake.h"

void drawmap(int x, int y, const snake* snakehead) {
	for (int h = 0; h < y; h++) {
		for (int w = 0; w < x; w++) {
			if (findsnake(w, h, snakehead)) printf("O");
			else if(h == 0 || h == y-1 || w == 0 || w == x-1) printf("#");
			else printf(" ");
		}

		printf("\n");
	}
	return;
}