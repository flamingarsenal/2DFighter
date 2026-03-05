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
        
        // decide animation based on horizontal velocity
        if (player->vx == 0) {
            player->anim = ANIM_IDLE;
        } else {
            player->anim = ANIM_WALK;
        }
    } else {
        player->vy -= GRAVITY; // increase the fall rate of the player
    }

    // check if the player is beyond the edge of the screen
    if (player->x < 0) { // left edge
        player->x = 0; // set player at the left border
    } else if (player->x + PLAYER_WIDTH > SCREEN_WIDTH) { // right edge
        player->x = SCREEN_WIDTH - PLAYER_WIDTH; // set player at the right border
    }
}

int checkHit() {

}
