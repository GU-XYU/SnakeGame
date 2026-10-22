#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "snake.h"
#include "map.h"
#include "food.h"
void drawmap(int x, int y, const snake* snakehead, const point* foodpoint) {

	int mapsize = x * y + y + 1;
	char* allmap = (char*)malloc(mapsize * sizeof(char));
	int index = 0;

	printf("\033[H");


	for (int h = 0; h < y; h++) {
		for (int w = 0; w < x; w++) {
			if (issnake(w, h, snakehead))                     allmap[index++] = 'O';
			else if(isfood(w, h, foodpoint))                  allmap[index++] = 'H';
			else if(h == 0 || h == y-1 || w == 0 || w == x-1) allmap[index++] = '#';
			else                                              allmap[index++] = ' ';
		}

		allmap[index++] = '\n';
	}
	allmap[index] = '\0';

	printf("%s", allmap);

	free(allmap);

	return;
}

