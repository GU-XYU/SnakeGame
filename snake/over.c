#include "over.h"
#include "snake.h"

static int detectwallover(int x, int y, const snake* snakehead) {
	if (snakehead == NULL) return 1;
	if (snakehead->x <= 0 || snakehead->x >= x - 1 || snakehead->y <= 0 || snakehead->y >= y - 1) {
		printf("game over!");
		return 1;
	}
	return 0;
}

static int detectsnakeover(const snake* snakehead) {
	if (snakehead == NULL) return 1;
	int headx = snakehead->x;
	int heady = snakehead->y;
	snake* temp = snakehead->next;
	while (temp->next != NULL) {
		if (temp->x == headx && temp->y == heady) {
			printf("game over!");
			return 1;
		}
		temp = temp->next;
	}
	temp = NULL;
	return 0;
}

int detectover(int x, int y, const snake* snakehead) {
	int w = detectwallover(x, y, snakehead);
	int s = detectsnakeover(snakehead);
	if (w || s) return 1;
	else return 0;
}