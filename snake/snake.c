#include "snake.h"

void snakeinit(int l, int h, int w, snake** snakehead, snake** snaketail) {  //l长度，hw地图大小
	
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

int findsnake(int x, int y, const snake* head) {  //检查当前xy值位置是否为蛇

	while (head != NULL) {
		if (head->x == x && head->y == y) return 1;
		head = head->next;
	}

	return 0;
}

void findtail(snake** snakehead, snake** snaketail, snake** prevnode) {  //进 findtail 时至少有 2 个节点
	snake* head = *snakehead;
	snake* temp = NULL;
	if (head->next == NULL) *snaketail = *snakehead;
	else{
		while (head->next != NULL) {
			temp = head;
			head = head->next;
		}
		*snaketail = head;
		*prevnode = temp;
	}
	return;
}

void movesnake(char mf, int eat, snake** snakehead, snake** snaketail) {  //eat为蛇进食状态，1为食用，0为未食用。mf为蛇前进方向WASD
	snake* prevnode = NULL;
	switch (mf) {
		case 'W': {
			snake* newnode = malloc(sizeof(snake));
			if (!newnode) return;
			newnode->x = (*snakehead)->x;
			newnode->y = (*snakehead)->y + 1;
			newnode->next = *snakehead;
			*snakehead = newnode;
			if (eat == 0) {
				findtail(snakehead, snaketail, &prevnode);
				prevnode->next = NULL;
				free(*snaketail);
				*snaketail = prevnode;
				break;
			}
			break;
		}
		case 'S': {
			snake* newnode = malloc(sizeof(snake));
			if (!newnode) return;
			newnode->x = (*snakehead)->x;
			newnode->y = (*snakehead)->y - 1;
			newnode->next = *snakehead;
			*snakehead = newnode;
			if (eat == 0) {
				findtail(snakehead, snaketail, &prevnode);
				prevnode->next = NULL;
				free(*snaketail);
				*snaketail = prevnode;
				break;
			}
			break;
		}
		case 'A': {
			snake* newnode = malloc(sizeof(snake));
			if (!newnode) return;
			newnode->x = (*snakehead)->x - 1;
			newnode->y = (*snakehead)->y;
			newnode->next = *snakehead;
			*snakehead = newnode;
			if (eat == 0) {
				findtail(snakehead, snaketail, &prevnode);
				prevnode->next = NULL;
				free(*snaketail);
				*snaketail = prevnode;
				break;
			}
			break;
		}
		case 'D': {
			snake* newnode = malloc(sizeof(snake));
			if (!newnode) return;
			newnode->x = (*snakehead)->x + 1;
			newnode->y = (*snakehead)->y;
			newnode->next = *snakehead;
			*snakehead = newnode;
			if (eat == 0) {
				findtail(snakehead, snaketail, &prevnode);
				prevnode->next = NULL;
				free(*snaketail);
				*snaketail = prevnode;
				break;
			}
			break;
		}
	}

}