#include "snake.h"

void snakeinit(int l, int h, int w, snake** snakehead, snake** snaketail) {
	
	snake* tail = NULL;
	snake* head = NULL;

	for (int i = 0; i < l; i++) {

		snake* newnode = malloc(sizeof(snake));
		if (newnode == NULL) {
			printf_s("error %d", i);
			*snaketail = tail;
			*snakehead = head;
			return;
		}

		newnode->x = (int)(w / 2) + i;
		newnode->y = (int)(h / 2);
		newnode->next = NULL;

		if (head == NULL) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
	}
	*snaketail = tail;
	*snakehead = head;
	return;
}

int findsnake(int x, int y, const snake* head) {

	while (head != NULL) {
		if (head->x == x && head->y == y) return 1;
		head = head->next;
	}

	return 0;
}