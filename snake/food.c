#include "food.h"

point initfood(int x, int y, point** foodpoint) {
	srand(tiem());
	x = rand();
	y = rand();
	(*foodpoint)->x = x;
	(*foodpoint)->y = y;
}

int isfood(int x, int y, const point* foodpoint) {
	if (foodpoint->x == x && foodpoint->y == y) return 1;
	else return 0;
}