#include <stdio.h>
#include "main.h"
#include "game_logic.h"
#include "physics.h"

void physicsUpdate(Player* player) {
    player->y -= player->vy; // make the player go down
    // check if the player is beloew the ground
    if (player->y >= SCREEN_HEIGHT - GROUND_Y - PLAYER_HEIGHT) {
        player->y = SCREEN_HEIGHT - GROUND_Y - PLAYER_HEIGHT; // put the player on the ground
        player->vy = 0;
        player->anim = ANIM_IDLE;
    } else {
        player->vy -= GRAVITY; // increase the fall rate of the player
    }
    printf("%d\n", player->y);
}

int checkHit() {

}
