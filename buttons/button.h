#ifndef PLAYER
#define PLAYER

#include "game_object.h"
#include "input.h"
#include "game_states.h"
#include <cmath>
#include <SDL2/SDL.h>

enum ButtonStates {SLIDING, BOUNCING};

class Button : public GameObject
{
public:
  Button(const char*, SDL_Renderer*, SDL_Rect, SDL_Rect);

  void update();
private:
  int ticks;
  int hoverTicks; // How long the mouse is hovering it
  SDL_Rect myPos;
  ButtonStates state;
};

#endif
