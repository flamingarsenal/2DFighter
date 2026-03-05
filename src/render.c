#include <SDL2/SDL_render.h>
#include "main.h"
#include "game_logic.h"

void renderPlayer(SDL_Renderer *renderer, Player *player) {
    SDL_Rect rect = { player->x, player->y, PLAYER_WIDTH, PLAYER_HEIGHT };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // white
    SDL_RenderFillRect(renderer, &rect);
}

void renderGame(SDL_Renderer *renderer) {
    // clear the background to black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // black
    SDL_RenderClear(renderer);

    // draw the player
    renderPlayer(renderer, &game.player1);
    renderPlayer(renderer, &game.player2);

    // present the frame
    SDL_RenderPresent(renderer);
}
