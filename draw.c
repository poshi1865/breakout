#include <SDL2/SDL.h>
#include "entity.h"

void drawPaddle(Paddle* paddle, SDL_Renderer* renderer) {
    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    for (int i = paddle->x; i < paddle->width + paddle->x; i++) {
        for (int j = paddle->y; j < paddle->height + paddle->y; j++) {
            SDL_RenderDrawPoint(renderer, i, j);
        }
    }
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
