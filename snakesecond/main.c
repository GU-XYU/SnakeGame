#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "map.h"
#include "snake.h"
#include "display.h"
#include <conio.h>

static void MapBuild(const Map *map, const Snake *snake, const Position foodPos) {
    MapInit(map);
    MapBuildEdge(map);
    MapBuildSnake(map, snake);
    MapBuildFood(map, foodPos);
}

static enum Direction GetDirectionFromInput(const char input) {//根据输入获取方向
    switch (input) {
        case 'w':
            return UP;
        case 's':
            return DOWN;
        case 'a':
            return LEFT;
        case 'd':
            return RIGHT;
        default:
            return UP; //默认向上
    }
}

static Position GenerateFood(const Map *map) {//生成食物坐标
    Position foodPos;
    do {
        foodPos.x = rand() % (map->max_x - 2) + 1;
        foodPos.y = rand() % (map->max_y - 2) + 1;
    } while (map->map[foodPos.y][foodPos.x] != ' ');//确保食物不在蛇身上
    return foodPos;
}

static void RunOneFrame(Map *map, Snake *snake, Position *foodPos, enum Direction direction) {
    //移动蛇
    MoveSnake(snake, direction);

    //检查蛇是否吃到食物
    if (snake->body[0].x == foodPos->x && snake->body[0].y == foodPos->y) {
        //生成新的食物
        *foodPos = GenerateFood(map);
    } else {
        //删除蛇尾
        DeleteTail(snake);
    }

    //更新地图
    MapBuild(map, snake, *foodPos);
}

int main() {
    char* nullptr = NULL;
    setbuf(stdout, nullptr);//防止神秘故障

    int max_x, max_y, snakeLength = 0;
    printf("Map dimensions: ");
    scanf("%d %d", &max_x, &max_y);
    printf("Snake length: ");
    scanf("%d", &snakeLength);

    //初始化地图
    Map map;
    map.max_x = max_x;
    map.max_y = max_y;
    //申请指针
    map.map = malloc(max_y * sizeof(char *));
    for (int y = 0; y < max_y; y++) {
        map.map[y] = malloc(max_x * sizeof(char));
    }

    //初始化蛇
    Position snake_position;
    snake_position.x = max_x / 2;
    snake_position.y = max_y / 2;

    Snake snake = SnakeInit(snake_position, snakeLength);

    MapInit(&map);
    MapBuildEdge(&map);
    MapBuildSnake(&map, &snake);//这个要在生成食物之前,否则食物可能会生成在蛇身上
    //生成一个食物
    Position foodPos = GenerateFood(&map);
    MapBuildFood(&map, foodPos);

    DisplayDraw(&map);//绘制一次地图

    char input = 'w';
    enum Direction input_direction = UP;
    char snake_head_next_char = ' ';//蛇头下一步指向的字符
    long long int point = 0;
    while (1) {
        if (_kbhit()) {
            input = (char)_getch();
        }
        input_direction = GetDirectionFromInput(input);
        snake_head_next_char = GetSnakeHeadNextChar(&map, &snake, input_direction);
        RunOneFrame(&map, &snake, &foodPos, input_direction);//运行一帧
        if (snake_head_next_char == '#' || snake_head_next_char == 'X') {//撞墙或撞自己
            break;
        }

        point++;
        DisplayDraw(&map);//绘制地图
        Sleep(500); //延迟
    }

    printf("Game Over\n%lld\n", point);

    printf("Pass Enter to exit...");
    _getche();

    //释放内存
    for (int y = 0; y < map.max_y; y++) {
        free(map.map[y]);
    }
    free(map.map);
    map.map = nullptr;



    return 0;
}
