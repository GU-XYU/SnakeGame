//
// Created by 123 on 2026/10/13.
//

#include <stdlib.h>
#include "map.h"
#include "snake.h"

Snake MoveSnake(Snake *snake, const enum Direction direction) {//蛇的下一个坐标列表,长度+1
    snake->length++;
    for (int i = snake->length; i >= 1; i--) {//移动蛇身
        snake->body[i] = snake->body[i - 1];
    }
    switch(direction) {//移动蛇头
        case UP:
            snake->body[0].y--;
            break;
        case DOWN:
            snake->body[0].y++;
            break;
        case LEFT:
            snake->body[0].x--;
            break;
        case RIGHT:
            snake->body[0].x++;
            break;
    }
    return *snake;
}

Snake DeleteTail(Snake *snake) {// 删除蛇尾,长度-1
    snake->length--;
    return *snake;
}

Snake SnakeInit(const Position startPos, const int length) {//生成一条蛇的坐标
    Snake *snake = malloc(sizeof(Snake));
    for (int i = 0; i < length; i++) {
        snake->body[i] = startPos;
    }
    snake->length = length;
    return *snake;
}

char GetSnakeHeadNextChar(Map *map, const Snake *snake, enum Direction direction) {//获取蛇头下一步的字符
    switch (direction) {
        case UP:
            return map->map[snake->body[0].y - 1][snake->body[0].x];
        case DOWN:
            return map->map[snake->body[0].y + 1][snake->body[0].x];
        case LEFT:
            return map->map[snake->body[0].y][snake->body[0].x - 1];
        case RIGHT:
            return map->map[snake->body[0].y][snake->body[0].x + 1];
        default:
            return ' '; //默认返回空格
    }
}