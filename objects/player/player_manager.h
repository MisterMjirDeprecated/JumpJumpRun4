#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "object_manager.h"
#include "player.h"
#include <SDL2/SDL.h>

class PlayerManager : public ObjectManager
{
public:
  PlayerManager(SDL_Renderer*);
  ~PlayerManager();
};

#endif
