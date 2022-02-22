#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>

#define WIDTH 640
#define HEIGHT 480

void update();
void render();

int main(void) {

    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Surface* bitmap_surface = NULL;
    SDL_Texture* bitmap_tex = NULL;

    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "SDL_Init() has failed ");
        printf("%s\n", SDL_GetError());
        return 1;
    }
    
    IMG_Init(IMG_INIT_JPG); 

    printf("Initialization successful\n");

    window = SDL_CreateWindow("Example", SDL_WINDOWPOS_CENTERED,
                                        SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bitmap_surface = IMG_Load("image.jpg");
    bitmap_tex = SDL_CreateTextureFromSurface(renderer, bitmap_surface);
    SDL_FreeSurface(bitmap_surface);

    if (window == NULL) {
        printf("ERROR CREATING WINDOW. Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, bitmap_tex, NULL, NULL);
    SDL_RenderPresent(renderer);

    SDL_DestroyTexture(bitmap_tex);

    SDL_Delay(5000);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    IMG_Quit();
    SDL_Quit();

    return 0;
}

void update() {

}

void render() {

}
