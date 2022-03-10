#include "paddle.h"
#include <stdlib.h>

Paddle* createPaddle(int x, int y, int width, int height, int color) {
    Paddle* paddle = malloc(sizeof(Paddle));
    paddle->x = x;
    paddle->y = y;
    paddle->width = width;
    paddle->height = height;

    return paddle;
}

void destroyPaddle(Paddle* paddle) {
    free(paddle);
}
