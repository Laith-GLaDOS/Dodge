#pragma once
#include <SDL2/SDL.h>
// bool
#define bool int
#define true 1
#define false 0

// GameResources
struct GameResources {
    Mix_Chunk *sound_gameload;
    SDL_Texture *sprite_player;
    int sprite_player_width;
    int sprite_player_height;
    SDL_Texture *sprite_laserWarning;
    int sprite_laserWarning_width;
    int sprite_laserWarning_height;
};