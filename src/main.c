#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
    if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS)) {
        SDL_Window* window = SDL_CreateWindow("2DFighter", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 800, 0);
        SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000);
        SDL_Quit();
    }
    return 0;
}