#ifndef TEXT_MANAGER
#define TEXT_MANAGER

#include "object_manager.h"
#include "text.h"
#include "game_states.h"
#include <SDL2/SDL.h>

class TextManager : public ObjectManager
{
public:
  TextManager(SDL_Renderer*);
  ~TextManager();
  void update();
};

#endif
