#include <stdio.h>
#include "main.h"
#include "game_logic.h"
#include "physics.h"

void physicsUpdate(Player* player) {
    player->y -= player->vy; // change the players position according to their  velocities
    player->x += player->vx;
    
    // check if the player is beloew the ground
    if (player->y >= SCREEN_HEIGHT - GROUND_Y - PLAYER_HEIGHT) {
        player->y = SCREEN_HEIGHT - GROUND_Y - PLAYER_HEIGHT; // put the player on the ground
        player->vy = 0;
        player->anim = ANIM_IDLE;
    } else {
        player->vy -= GRAVITY; // increase the fall rate of the player
    }

    // check if the player is beyond the edge of the screen
    if (player->y < 0) { // left edge
        player->y = 0;
    } else if (player->y > SCREEN_WIDTH) { // right edge
        player->y = SCREEN_WIDTH;
    }
}

int checkHit() {

}
