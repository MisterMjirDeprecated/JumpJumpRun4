#ifndef BUTTON_MANAGER
#define BUTTON_MANAGER

#include "object_manager.h"
#include "button.h"
#include "game_states.h"
#include <SDL2/SDL.h>

class ButtonManager : public ObjectManager
{
public:
  ButtonManager(SDL_Renderer*);
  ~ButtonManager();
  void update();
};

#endif
