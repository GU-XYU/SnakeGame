#include "snake.h"

void snakeinit(int l, int x, int y, snake** snakehead, snake** snaketail) {
	
	snake* tail = NULL;
	snake* head = NULL;

	for (int i = 0; i < l; i++) {

		snake* newnode = malloc(sizeof(snake));
		if (newnode == NULL) {               //查看malloc是否成功
			printf_s("error %d", i);         //打印成功创建了多少节蛇
			*snaketail = tail;
			*snakehead = head;
			return;
		}

		newnode->x = (int)(x / 2) + i;
		newnode->y = (int)(y / 2);
		newnode->next = NULL;

		if (head == NULL) {           //没有蛇头时newnode就是蛇头
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;     ////这里有严重bug!!!!!!!!!!
			tail = newnode;           ////这里有严重bug!!!!!!!!!!
		}
	}
	*snaketail = tail;
	*snakehead = head;
	return;
}

int issnake(int x, int y, const snake* head) {

	while (head != NULL) {
		if (head->x == x && head->y == y) return 1;
		head = head->next;
	}

	return 0;
}

void findtail(snake** snakehead, snake** snaketail, snake** prevnode) {
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

void movesnake(char mf, int eat, snake** snakehead, snake** snaketail) {
	snake* prevnode = NULL;
	switch (mf) {
		case 'W': {
			snake* newnode = malloc(sizeof(snake));     //头插法 创建一个newnoode
			if (!newnode) return;
			newnode->x = (*snakehead)->x;               //定义xy坐标
			newnode->y = (*snakehead)->y - 1;
			newnode->next = *snakehead;                 //将next接到原先的蛇头上
			*snakehead = newnode;                       //更新蛇头指针
			if (eat == 0) {        //如果没吃到就free最后一个node
				findtail(snakehead, snaketail, &prevnode);
				prevnode->next = NULL;
				free(*snaketail);
				*snaketail = prevnode;
			}
			break;
		}
		case 'S': {
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
			}
			break;
		}
	}

}