#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#include "paddle.h"

#define WIDTH 1080
#define HEIGHT 720

void update();
void render();
void listenForKeyEvents();
void loadEntities();

//Key event mappings
bool keyUp, keyDown, keyLeft, keyRight;

//Entities
struct Paddle* paddle;
SDL_Rect ballHitbox;
SDL_Texture* ballTexture;
float ballSpeed;
int ballDirectionX;
int ballDirectionY;

bool running = true;

int main(void) {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    

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

    //Init ball
    ballTexture = IMG_LoadTexture(renderer, "palantir.png");
    ballHitbox.x = WIDTH / 2.0;
    ballHitbox.y = 10;
    ballHitbox.w = 35;
    ballHitbox.h = 35;
    ballSpeed = 1.0f;
    ballDirectionX = 1;
    ballDirectionY = 1;

    //Init paddle
    paddle = malloc(sizeof(struct Paddle));
    paddle->width = 100;
    paddle->height = 20;
    paddle->speed = 1.0f;

    paddle->x = WIDTH / 2.0 - paddle->width;
    paddle->y = HEIGHT - 50;


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
            update(deltaTime);
            lastTime = currentTime;
        }
        render(renderer); 
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    free(paddle);
    SDL_Quit();

    return 0;
}

void loadEntities() {
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
    if (keyLeft) {
        //Check for collision with left wall
        if (paddle->x != 0) {
            paddle->x -= (int)(paddle->speed * deltaTime);
        }
    }
    if (keyRight) {
        //Check for collision with left wall
        if (paddle->x != WIDTH - paddle->width) {
            paddle->x += (int)(paddle->speed * deltaTime);
        }
    }

    //Ball with wall collision
    if (ballHitbox.x > WIDTH - ballHitbox.w) {
        ballDirectionX = -1;
    }
    if (ballHitbox.y > HEIGHT - ballHitbox.h) {
        ballDirectionY = -1;
    }
    if (ballHitbox.x < 0) {
        ballDirectionX = 1;
    }
    if (ballHitbox.y < 0) {
        ballDirectionY = 1;
    }

    //Ball with paddle collision
    if (ballHitbox.y + ballHitbox.h > paddle->y &&
        ballHitbox.x >= paddle->x &&
        ballHitbox.x <= paddle->x + paddle->width) 
    { 

        ballDirectionY = -1;

    }


    ballHitbox.x += ballSpeed * ballDirectionX * deltaTime;
    ballHitbox.y += ballSpeed * ballDirectionY * deltaTime;
}

void render(SDL_Renderer* renderer) {

    //Renderer color white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    //Draw filled paddle
    SDL_Rect rect;
    rect.x = paddle->x;
    rect.y = paddle->y;
    rect.w = paddle->width;
    rect.h = paddle->height;
    SDL_RenderFillRect(renderer, &rect);

    //Draw Ball
    SDL_RenderCopy(renderer, ballTexture, NULL, &ballHitbox);

    //Draw
    SDL_RenderPresent(renderer);
}
