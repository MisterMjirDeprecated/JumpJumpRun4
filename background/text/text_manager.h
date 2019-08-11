#ifndef TEXT_MANAGER
#define TEXT_MANAGER

#include "object_manager.h"
#include "text.h"
#include "number.h"
#include "game_states.h"
#include "score.h"
#include <cmath>
#include <SDL2/SDL.h>

class TextManager : public ObjectManager
{
public:
  TextManager(SDL_Renderer*);
  ~TextManager();
  void update();
};

#endif
