#ifndef ENTITY_H_
#define ENTITY_H_

struct Paddle {
    int x;
    int y;
    int width;
    int height;
    int speed;
}typedef Paddle;

Paddle* createPaddle(int x, int y, int width, int height, int speed);
void destroyPaddle(Paddle* paddle);

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
void destroyBall(Ball* ball);

#endif
