#include "entity.h"
#include <stdlib.h>

Paddle* createPaddle(int x, int y, int width, int height, int speed) {
    Paddle* paddle = malloc(sizeof(Paddle));
    paddle->x = x;
    paddle->y = y;
    paddle->width = width;
    paddle->height = height;
    paddle->speed = speed;

    return paddle;
}

void destroyPaddle(Paddle* paddle) {
    free(paddle);
}
