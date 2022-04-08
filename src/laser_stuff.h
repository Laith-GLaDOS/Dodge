#pragma once
#include <SDL2/SDL.h>
#include "render_stuff.h"
#include "renderer_funcs.h"
#include "typedefs.h"

void fireLaser(SDL_Renderer *renderer, int x) {
    renderRect(renderer, x, 0, 10, 1000, 222, 44, 56, 255);
}

void laserWarning(SDL_Renderer *renderer, int x, struct GameResources res) {
    renderNewSprite(renderer, res.sprite_laserWarning, res.sprite_laserWarning_width, res.sprite_laserWarning_height, x, 10);
}