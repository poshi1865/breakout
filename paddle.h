#ifndef PADDLE_H_
#define PADDLE_H_

struct Paddle {
    int x;
    int y;
    int width;
    int height;
    int color;
    int speed;
}typedef Paddle;

Paddle* createPaddle(int x, int y, int width, int height, int speed);
void destroyPaddle(Paddle* paddle);

#endif
