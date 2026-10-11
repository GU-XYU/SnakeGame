#define _CRT_SECURE_NO_WARNINGS
#include "map.h"

int main(void) {
	int a, b;
	scanf("%d %d", &a, &b);
	drawmap(a, b);
	getchar();
	getchar();
}