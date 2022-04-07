#ifndef ENTITY_H_
#define ENTITY_H_

#include <SDL2/SDL.h>

/* PADDLE */
struct Paddle {
    int x;
    int y;
    int width;
    int height;
    int speed;
}typedef Paddle;

Paddle* createPaddle(int x, int y, int width, int height, int speed);

void drawPaddle(Paddle* paddle, SDL_Renderer* renderer);
void destroyPaddle(Paddle* paddle);
/* PADDLE END */

/* BALL */
struct Ball {
    int x;
    int y;
    int width;
    int height;
    int speed;
    int directionX;
    int directionY;
}typedef Ball;

Ball* createBall(int x, int y, int width, int height, int speed, int directionX, int directionY);
void drawBall(Ball* ball, SDL_Renderer*  renderer);
void destroyBall(Ball* ball);
/* PADDLE END */

/* BRICK */
struct Brick {
    int x;
    int y;
    int width;
    int height;
}typedef Brick;
Brick* createBrick(int x, int y, int width, int height);
void drawBrick(Brick* brick, SDL_Renderer* renderer, int r, int g, int b);
void destroyBrick(Brick* brick);

void explodeAt(int x, int y, int directionX, int directionY, SDL_Renderer* renderer);

#endif
