#include <SDL2/SDL.h>
#include "paddle.h"

void drawPaddle(Paddle* paddle, SDL_Renderer* renderer) {
    for (int i = paddle->x; i < paddle->width; i++) {
        for (int j = paddle->y; j < paddle->height; j++) {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
}

