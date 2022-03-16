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

void explodeAt(int x, int y, int directionX, int directionY, SDL_Renderer* renderer) {
}

