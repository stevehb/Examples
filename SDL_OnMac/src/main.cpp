#include <cstdlib>
#include <iostream>
#include <SDL/SDL.h>

const int SCREEN_WIDTH = 640; 
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 0;

int main(int argc, char* argv[]) {
  SDL_Surface* screen = 0;
  
  // initialize SDL
  std::cout << "initializing SDL...";
  if(SDL_Init(SDL_INIT_VIDEO) == 0)
    std::cout << "done" << std::endl;
  else  {
    std::cout << "error" << std::endl;
    return 1;
  }
  
  // create the window
  std::cout << "setting video mode to " << SCREEN_WIDTH << "x" << SCREEN_HEIGHT 
            << "x" << SCREEN_BPP << "...";
  screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 
                            SCREEN_BPP, SDL_HWSURFACE);
  if(screen)
    std::cout << "done" << std::endl;
  else {
    std::cout << "error" << std::endl;
    SDL_Quit();
    return 1;
  }
  
  // fill the screen with random color
  Uint32 color;
  Uint8* px = (Uint8*)(screen->pixels);
  Uint32 offset;
  int r, g, b;
  std::cout << "writing to screen with pitch=" << screen->pitch << " and bpp="
            << (int)screen->format->BytesPerPixel << std::endl;
  for(int y = 0; y < SCREEN_HEIGHT; y++) {
    for(int x = 0; x < SCREEN_WIDTH; x++) {
      r = rand() % 255;
      g = rand() % 255;
      b = rand() % 255;
      color = SDL_MapRGB(screen->format, r, g, b);
      offset = (y * screen->pitch) + (x * screen->format->BytesPerPixel);
      *(Uint32*)(px + offset) = color;
    } 
    SDL_Flip(screen);
  }
  
  SDL_FreeSurface(screen);
  SDL_Quit();
  return 0;
}
