#ifndef DRAW_H_
#define DRAW_H_

#include <SDL2/SDL.h>
#include "entity.h"

void drawPaddle(Paddle* paddle, SDL_Renderer* renderer);
void drawBall(Ball* ball, SDL_Renderer*  renderer);

#endif
