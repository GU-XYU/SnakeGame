#pragma once
#include <stdlib.h>
#include <time.h>

typedef struct point {
	int x, y;
}point;

point initfood(int x, int y);

int isfood(int x, int y, const point* foodpoint);