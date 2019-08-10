#ifndef TEXT
#define TEXT

#include "game_object.h"
#include <cmath>
#include <SDL2/SDL.h>

enum TextStates {SLIDING, BOUNCING};

class Text : public GameObject
{
public:
  Text(const char*, SDL_Renderer*, SDL_Rect, SDL_Rect);

  void update();
  void draw();
private:
  int ticks;
  SDL_Rect myPos; // Where it should be
  TextStates state;
};

#endif
