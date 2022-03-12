#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#include "../include/draw.h"
#include "../include/entity.h"


#define WIDTH 1080
#define HEIGHT 720

void update();
void render();
void listenForKeyEvents();
void initEntities();

//Key event mappings
bool keyUp, keyDown, keyLeft, keyRight;

//Entities
Paddle* paddle;
Ball* ball;

bool running = true;

int main(void) {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    //init all the game entities
    initEntities();

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "SDL_Init() has failed ");
        printf("%s\n", SDL_GetError());
        return 1;
    }
    printf("Initialization successful\n");

    window = SDL_CreateWindow("Essdl", SDL_WINDOWPOS_CENTERED,
                                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("ERROR CREATING WINDOW. Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    /*Game loop
     * TODO: Need to understand game loop timing
     *  
     * */
    int updatesPerSecond = 60;
    double lastTime = SDL_GetTicks();
    while (running) {

        double currentTime = SDL_GetTicks();
        double deltaTime = currentTime - lastTime;
        listenForKeyEvents();
        if (deltaTime > (1.0 / updatesPerSecond) * 1000) {
            update(deltaTime / 10);
            lastTime = currentTime;
        }
        render(renderer); 
    }

    // Cleanup
    destroyPaddle(paddle); 
    destroyBall(ball);
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void initEntities() {
    int w = 150;
    paddle = createPaddle(WIDTH / 2 - w, HEIGHT - 40, 150, 15, 5);
    ball = createBall(WIDTH / 2, HEIGHT / 2, 20, 20, 1, 1, 4);
}

void listenForKeyEvents() {

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) 
            running = false;
        //If it is a key press
        if (e.type == SDL_KEYDOWN) {
            switch(e.key.keysym.sym) {
                case SDLK_UP:
                    keyUp = true;
                    break;
                case SDLK_DOWN:
                    keyDown = true;
                    break;
                case SDLK_LEFT:
                    keyLeft = true;
                    break;
                case SDLK_RIGHT:
                    keyRight = true;
                    break;
                default:
                    break;
            }
        }

        //If it is a key release
        if (e.type == SDL_KEYUP) {
            switch(e.key.keysym.sym) {
                case SDLK_UP:
                    keyUp = false;
                    break;
                case SDLK_DOWN:
                    keyDown = false;
                    break;
                case SDLK_LEFT:
                    keyLeft = false;
                    break;
                case SDLK_RIGHT:
                    keyRight = false;
                    break;
                default:
                    break;
            }
        }
    }
}

void update(double deltaTime) {

    //if (keyUp) {
    //    paddle->y -= (int)(paddle->speed * deltaTime); 
    //}
    //if (keyDown) {
    //    paddle->y += (int)(paddle->speed * deltaTime);
    //}
    //
    if (keyLeft) {
        //Check for collision with left wall
        if (paddle->x > 0) {
            paddle->x -= (int)(paddle->speed * deltaTime);
        }
    }
    if (keyRight) {
        //Check for collision with left wall
        if (paddle->x < WIDTH - paddle->width) {
            paddle->x += (int)(paddle->speed * deltaTime);
        }
    }


    //CHECKING BALL COLLIDING WITH WALL
    if (ball->x >= WIDTH - ball->width) {
        ball->directionX = -1;
    }
    if (ball->x <= 0) {
        ball->directionX = 1;
    }
    if (ball->y >= HEIGHT - ball->height) {
        ball->directionY = -1;
    }
    if (ball->y <= 0) {
        ball->directionY = 1;
    }

    //CHECKING BALL COLLIDING WITH PADDLE
    if (ball->x + ball->width >= paddle->x && ball->x <= paddle->x + paddle->width) {
        if (ball->y + ball->height >= paddle->y) {
            ball->directionY = -1;
        }
    }

    ball->x += ball->directionX * ball->speed * deltaTime;
    ball->y += ball->directionY * ball->speed * deltaTime;
}

void render(SDL_Renderer* renderer) {

    //Renderer color white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    //Clear Screen
    SDL_RenderClear(renderer);

    //Drawing the ball and the paddle
    drawPaddle(paddle, renderer);
    drawBall(ball, renderer);

    // Present Buffer
    SDL_RenderPresent(renderer);
}