#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_thread.h>
#include <stdlib.h>
#include <time.h>
#include "typedefs.h"
#include "renderer_funcs.h"
#include "player_stuff.h"
#include "laser_stuff.h"
#include "render_stuff.h"

int random(int min, int max){
    srand(time(NULL));
    return min + rand() % max + (102 / 7 * (rand() % 7 - 3) + min + rand() % max + (102 / 7 * (rand() % 7 - 3)));
}

SDL_Renderer *renderer = NULL;
struct GameResources res = {0, 0, 0, 0, 0, 0, 0};

int laserstuff_thread_func(void* data) {
    while (true) {
        int laser_x = random(0, 640);
        printf(" %d\n", laser_x);
        laserWarning(renderer, laser_x, res);
        fireLaser(renderer, laser_x);
    }
    return 0;
}

void main_loop(SDL_Renderer *renderera, struct GameResources resa) {
    res = resa;
    renderer = renderera;
    SDL_Thread* laserstuff_thread = SDL_CreateThread(laserstuff_thread_func, "dingus", (void*) 0); // thread for drawing lasers and handling circle detection in lasers
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
        renderPlayer(renderer, res);
        displayRendered(renderer);
    }
}