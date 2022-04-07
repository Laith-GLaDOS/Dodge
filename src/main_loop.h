#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include "typedefs.h"
#include "renderer_funcs.h"
#include "player_stuff.h"
#include "render_stuff.h"

void main_loop(SDL_Renderer *renderer, struct GameResources res) {
    playerCoords.x = 290; // set player position
    playerCoords.y = 400;
    Mix_PlayChannel(-1, res.sound_gameload, 0); // play load sound

    bool hasQuit = false;
    SDL_Event event;
    while (!hasQuit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) hasQuit = true;
            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_a) movePlayerToLeft();
                if (event.key.keysym.sym == SDLK_d) movePlayerToRight();
            }
        }
        clearRendered(renderer);
        setRenderedBackgroundColor(renderer, 0, 0, 0, 0);
        renderStuff(renderer, res);
        displayRendered(renderer);
    }
}