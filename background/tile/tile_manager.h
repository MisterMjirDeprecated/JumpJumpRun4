#ifndef TILE_MANAGER
#define TILE_MANAGER

#include "object_manager.h"
#include "tile.h"
#include <SDL2/SDL.h>

class TileManager : public ObjectManager
{
public:
  TileManager(SDL_Renderer*);
  ~TileManager();
};

#endif
