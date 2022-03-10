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

Ball* createBall(int x, int y, int width, int height, int directionX, int directionY, int speed) {
    Ball* ball = malloc(sizeof(Ball));
    ball->x = x;
    ball->y = y;
    ball->width = width;
    ball->height = height;
    ball->speed = speed;
    ball->directionX = directionX;
    ball->directionY = directionY;

    return ball;
}

void destroyBall(Ball* ball) {
    free(ball);
}
