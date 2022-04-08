#pragma once
#include <SDL2/SDL.h>
#include "player_stuff.h"
#include "typedefs.h"

void renderPlayer(SDL_Renderer *renderer, struct GameResources res) {
    renderNewSprite(renderer, res.sprite_player, res.sprite_player_width, res.sprite_player_height, playerCoords.x, playerCoords.y);
}

void renderRect(SDL_Renderer *renderer, int x, int y, int w, int h, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;
    setRenderedBackgroundColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, &rect);
    setRenderedBackgroundColor(renderer, 0, 0, 0, 0);
    SDL_RenderDrawRect(renderer, &rect);
}