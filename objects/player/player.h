#ifndef PLAYER
#define PLAYER

#include "game_object.h"
#include <SDL2/SDL.h>

class Player : public GameObject
{
public:
  Player(const char *texturesheet, SDL_Renderer *ren, int x, int y):GameObject(texturesheet, ren, x, y) {
    destRect = {576, 384, 64, 64};
  }

  void update();
private:
  int runTicks;
};

#endif
