//
// Created by 123 on 2026/10/13.
//

#ifndef SNAKEGAME_SNAKE_H
#define SNAKEGAME_SNAKE_H

enum Direction { //方向
    UP,
    DOWN,
    LEFT,
    RIGHT
};

typedef struct Snake {  //蛇
    Position body[512];//蛇身,第一个(0)元素是蛇头
    int length;//长度从１开始
} Snake;

Snake MoveSnake(Snake *snake, enum Direction direction);
Snake DeleteTail(Snake *snake);
Snake SnakeInit(Position startPos, int length);
char GetSnakeHeadNextChar(Map *map, const Snake *snake, enum Direction direction);

#endif //SNAKEGAME_SNAKE_H
