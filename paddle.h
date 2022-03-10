#ifndef PADDLE_H_
#define PADDLE_H_

struct Paddle {
    int x;
    int y;
    int width;
    int height;
    int color;
}typedef Paddle;

Paddle* createPaddle(int x, int y, int width, int height, int color);
void destroyPaddle(Paddle* paddle);

#endif
