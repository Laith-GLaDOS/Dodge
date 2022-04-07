#pragma once
#include <SDL2/SDL.h>
#include "player_stuff.h"
#include "typedefs.h"

void renderStuff(SDL_Renderer *renderer, struct GameResources res) {
    renderNewSprite(renderer, res.sprite_player, res.sprite_player_width, res.sprite_player_height, playerCoords.x, playerCoords.y);
}