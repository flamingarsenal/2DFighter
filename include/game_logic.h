#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <SDL2/SDL_render.h>

#define GROUND_Y 100
#define PLAYER_WIDTH 128
#define PLAYER_HEIGHT 128

typedef enum {
    ANIM_IDLE,
    ANIM_JUMP,
    ANIM_CROUCH,
    ANIM_WALK,
    ANIM_PUNCH_HIGH_UP,
    ANIM_PUNCH_HIGH_STRAIGHT,
    ANIM_PUNCH_HIGH_DOWN,
    ANIM_PUNCH_LOW_UP,
    ANIM_PUNCH_LOW_STRAIGHT,
    ANIM_PUNCH_LOW_DOWN,
    ANIM_KICK_HIGH_UP,
    ANIM_KICK_HIGH_STRAIGHT,
    ANIM_KICK_HIGH_DOWN,
    ANIM_KICK_LOW_UP,
    ANIM_KICK_LOW_STRAIGHT,
    ANIM_KICK_LOW_DOWN,
    ANIM_BLOCK,
    ANIM_HIT,
    ANIM_THROWN_BACK,
    ANIM_KO
} AnimationState;

typedef struct {
    int x;
    int y;
    int vx;
    int vy;
    int health;
    int stamina;
    int score;
    int facing;
    AnimationState anim;
    int frame;
} Player;

typedef struct {
    Player player1;
    Player player2;
    int round;
    int time;
    int isPaused;
} GameState;

extern GameState game; // declare the global gamestate

void init_player(Player *p, int startX, int startY, int facing);
void init_game(int w, int h);
void update(SDL_Renderer *renderer);

#endif