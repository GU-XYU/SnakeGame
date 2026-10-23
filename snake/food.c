#include "food.h"
#include "snake.h"

void initfood(int x, int y, point** foodpoint) {
	if (*foodpoint == NULL) {
		*foodpoint = malloc(sizeof(point));
		if (*foodpoint == NULL) return;
	}
	(*foodpoint)->x = 1 + rand() % (x - 2);
	(*foodpoint)->y = 1 + rand() % (y - 2);

}

int isfood(int x, int y, const point* foodpoint) {
	if (foodpoint->x == x && foodpoint->y == y) return 1;
	else return 0;
}

int snakeeatfood(const snake* snakehead, point** foodpoint) {
	if (snakehead->x == (*foodpoint)->x && snakehead->y == (*foodpoint)->y) {
		free(*foodpoint);
		*foodpoint = NULL;
		return 1;
	}
	else return 0;
}