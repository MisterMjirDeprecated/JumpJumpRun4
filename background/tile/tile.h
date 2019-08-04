#ifndef TILEMAP
#define TILEMAP

#include "game_object.h"
#include <SDL2/SDL.h>

class Tile : public GameObject
{
public:
  Tile(const char*, SDL_Renderer*);

  void update();
  void setRects(SDL_Rect, SDL_Rect);
private:
  int ticks;
  SDL_Rect ogDestRect;
};

#endif
