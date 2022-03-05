#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WIDTH 1080
#define HEIGHT 720

void update();
void render();
void listenForKeyEvents();

//Key event mappings
bool keyUp, keyDown, keyLeft, keyRight;

SDL_Rect paddle;
float xspeed;
float yspeed;

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

    //Init paddle
    paddle.w = 100;
    paddle.h = 20;
    xspeed = 1.0f;
    yspeed = 1.0f;

    paddle.x = WIDTH / 2 - paddle.w;
    paddle.y = HEIGHT - 50;


    /*Game loop
     * TODO: Need to understand game loop timing
     *  
     * */
    double lastTime = SDL_GetTicks();
    while (running) {

        double currentTime = SDL_GetTicks();
        double deltaTime = currentTime - lastTime;
        listenForKeyEvents();
        update(deltaTime);
        render(renderer); 
        lastTime = currentTime;
    }

    // Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
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

    if (keyUp) {
        paddle.y -= (int)(yspeed * deltaTime); 
        printf("%f\n", yspeed * deltaTime);
    }
    if (keyDown) {
        paddle.y += (int)(yspeed * deltaTime);
    }
    if (keyLeft) {
        paddle.x -= (int)(xspeed * deltaTime);
    }
    if (keyRight) {
        paddle.x += (int)(xspeed * deltaTime);
    }

    //TODO: Paddle out of bounds

    //Handling Collision
    //if (paddle.x == WIDTH - paddle.w) {
    //    xspeed = -1; 
    //}
    //else if (paddle.y == HEIGHT - paddle.h) {
    //    yspeed = -1; 
    //}
    //else if (paddle.x == 0) {
    //    xspeed = 1; 
    //}
    //else if (paddle.y == 0) {
    //    yspeed = 1; 
    //}

    //Updating position of paddle
}

void render(SDL_Renderer* renderer) {

    //Renderer color white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    //Draw filled paddle
    SDL_RenderFillRect(renderer, &paddle);

    //Draw
    SDL_RenderPresent(renderer);
}
