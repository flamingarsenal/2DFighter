#include <stdio.h>
#include "game_logic.h"
#include "input.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>

#define MOVEMENT_SPEED 5 // pixels per second
#define JUMP_SPEED 20

void inputHandler(SDL_Event event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_RIGHT:
            if (game.player1.anim != ANIM_CROUCH && game.player1.anim != ANIM_JUMP) {
                game.player1.vx = MOVEMENT_SPEED;
                game.player1.anim = ANIM_WALK;
            }
            break;
        case SDLK_LEFT:
            if (game.player1.anim != ANIM_CROUCH && game.player1.anim != ANIM_JUMP) {
                game.player1.vx = -MOVEMENT_SPEED;
                game.player1.anim = ANIM_WALK;
            }
            break;
        case SDLK_UP:
            if (game.player1.anim != ANIM_JUMP) {
                game.player1.vy = JUMP_SPEED;
                game.player1.anim = ANIM_JUMP;
            }
            break;
        case SDLK_DOWN:
            if (game.player1.anim != ANIM_JUMP) {
                game.player1.vx = 0;
                game.player1.anim = ANIM_CROUCH;
            }
            break;
        }
    }
}
