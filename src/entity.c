#include <stdlib.h>
#include "../include/entity.h"
#include <SDL2/SDL.h>

Paddle* createPaddle(int x, int y, int width, int height, int speed) {
    Paddle* paddle = malloc(sizeof(Paddle));
    paddle->x = x;
    paddle->y = y;
    paddle->width = width;
    paddle->height = height;
    paddle->speed = speed;

    return paddle;
}

void drawPaddle(Paddle* paddle, SDL_Renderer* renderer) {
    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    for (int i = paddle->x; i < paddle->width + paddle->x; i++) {
        for (int j = paddle->y; j < paddle->height + paddle->y; j++) {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
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


void drawBall(Ball* ball, SDL_Renderer* renderer) {
    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xAA, 0xAA);
    for (int i = ball->x; i < ball->width + ball->x; i++) {
        for (int j = ball->y; j < ball->height + ball->y; j++) {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}

void destroyBall(Ball* ball) {
    free(ball);
}

Brick* createBrick(int x, int y, int width, int height) {
    Brick* brick = malloc(sizeof(Brick));
    brick->x = x;
    brick->y = y;
    brick->width = width;
    brick->height = height;

    return brick;
}

void drawBrick(Brick* brick, SDL_Renderer* renderer, int r, int g, int b) {
    for (int i = brick->x; i < brick->width + brick->x; i++) {
        for (int j = brick->y; j < brick->height + brick->y; j++) {
            SDL_SetRenderDrawColor(renderer, r, g, b, b);
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}

void destroyBrick(Brick* brick) {
    free(brick);
}

void explodeAt(int x, int y, int directionX, int directionY, SDL_Renderer* renderer) {
}

