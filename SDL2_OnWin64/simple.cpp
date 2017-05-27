#include <stdio.h>
#include "SDL.h"

int wmain(int argc, char** argv) {

    printf("Before SDL_Init\n");
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }
    printf("After SDL_Init\n");


    SDL_Quit();
    return 0;
}
