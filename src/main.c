#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include "main_loop.h"
#include "typedefs.h"

int main(int argc, char *argv[]) {    // for initialising SDL2 and SDL2_image only, then load sprites/sounds, then call main loop, then destroy/close everything
    printf("Loading...\n");

    // init region
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) > 0) {
        printf("Loading failed! (SDL_Init failed)\n");
        return 1;
    }
    if (IMG_Init(IMG_INIT_PNG) > 0) {
        //printf("Loading failed! (IMG_Init failed)\n");
        //return 1;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) > 0) {
        printf("Loading failed! (Mix_OpenAudio failed)\n");
        return 1;
    }
    // end region

    // window and renderer region
    SDL_Window *window = SDL_CreateWindow("Dodge!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    // end region

    // load region
    Mix_Chunk *sound_gameload = Mix_LoadWAV("res/audio/load.wav");
    SDL_Texture *sprite_player = IMG_LoadTexture(renderer, "res/image/player.png");
    if (sound_gameload == NULL) {
        printf("Loading failed! (Mix_LoadWAV(\"res/audio/load.wav\") failed)\n");
        return 1;
    }
    if (sprite_player == NULL) {
        printf("Loading failed! (IMG_LoadTexture(\"res/image/player.png\") failed)\n");
        return 1;
    }
    struct GameResources res = {
        .sound_gameload = sound_gameload,
        .sprite_player = sprite_player,
        .sprite_player_width = 79,
        .sprite_player_height = 63
    };
    // end region

    printf("Loaded!\n"); // print loaded msg
    // main loop region
    main_loop(renderer, res);
    // end region

    // destroy/close region
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    IMG_Quit();
    Mix_CloseAudio();
    // end region

    return 0;
}

int WinMain(int argc, char *argv[]) { // for Windows only
    return main(argc, argv);
}