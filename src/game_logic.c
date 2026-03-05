#include <stdio.h>
#include "game_logic.h"
#include "physics.h"
#include "render.h"

#define START_DISTANCE 50 // distance from the center each player starts the round at (in pixels)

GameState game; // define the global gamestate

void init_player(Player *p, int startX, int startY, int facing) {
    *p = (Player){
        .x = startX,
        .y = startY,
        .vx = 0,
        .vy = 0,
        .facing = facing,
        .health = 100,
        .stamina = 100,
        .score = 0,
        .anim = ANIM_IDLE,
        .frame = 0
    };
}

void init_game(int w, int h) {
    // player one would start to the left of the center, which is lower than half of screen width
    // vice versa for player two
    // hence the facing values
    // 1 = left, -1 = right
    int p1facing = -1;
    int p2facing = 1;
    int p1x = (int) (w / 2) + START_DISTANCE * p1facing - PLAYER_WIDTH; // player 1's right edge should be the specified distance away from the middle
    int p2x = (int) (w / 2) + START_DISTANCE * p2facing;
    // screen coord increases downwards
    // since ground y should be higher than the bottom, we substract ground y
    // substract the player height because player coord is the top-left corner of the sprite
    int py = h - GROUND_Y - PLAYER_HEIGHT;

    // initialize the two players
    init_player(&game.player1, p1x, py, p1facing);
    init_player(&game.player2, p2x, py, p2facing);

    game.round = 1;
    game.time = 60; // one minute
    game.isPaused = 0; // false
}

void update(SDL_Renderer *renderer) {
    physicsUpdate(&game.player1);
    renderGame(renderer);
}

