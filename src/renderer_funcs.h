#pragma once
#include <SDL2/SDL.h>

void clearRendered(SDL_Renderer *renderer) {
    SDL_RenderClear(renderer);
}

void renderNewSprite(SDL_Renderer *renderer, SDL_Texture* texture, const int width, const int height, const int position_x, const int position_y) {
    SDL_Rect src;
    src.x = 0;
    src.y = 0;
    src.h = height;
    src.w = width;
    SDL_Rect dst;
    dst.x = position_x;
    dst.y = position_y;
    dst.h = src.h;
    dst.w = src.w;
    SDL_RenderCopy(renderer, texture, &src, &dst);
}

void setRenderedBackgroundColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void displayRendered(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer);
}