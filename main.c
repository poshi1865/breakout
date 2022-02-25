#include <stdio.h>
#include <stdbool.h>

#include <SDL2/SDL_surface.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WIDTH 1080
#define HEIGHT 720

void update();
void render();

SDL_Rect square;
int xoffset;
int yoffset;

int main(void) {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    
    bool running = true;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "SDL_Init() has failed ");
        printf("%s\n", SDL_GetError());
        return 1;
    }

    printf("Initialization successful\n");

    window = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (window == NULL) {
        printf("ERROR CREATING WINDOW. Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    //Init square
    square.w = 20;
    square.h = 20;
    xoffset = 1;
    yoffset = 1;

    square.x = 10;
    square.y = 10;


    /*Game loop
     * Need to make loop run 60 times a second
     * 
     * */
    while (running) {
        SDL_Event e;
        
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) 
                running = false;
        }

        SDL_Delay(2);
        update();
        render(renderer); 
    }

    //Cleanup
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();

    return 0;
}

void update() {

    if (square.x == WIDTH - square.w) {
        xoffset = -1; 
    }
    else if (square.y == HEIGHT - square.h) {
        yoffset = -1; 
    }
    else if (square.x == 0) {
        xoffset = 1; 
    }
    else if (square.y == 0) {
        yoffset = 1; 
    }

    square.x += xoffset;
    square.y += yoffset;
}

void render(SDL_Renderer* renderer) {

    //Renderer color white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

    //Clear Screen
    SDL_RenderClear(renderer);

    //Renderer color red
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);

    //Draw filled square
    SDL_RenderFillRect(renderer, &square);

    //Draw
    SDL_RenderPresent(renderer);
}
