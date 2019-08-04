#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "object_manager.h"
#include "player.h"
#include <SDL2/SDL.h>
#include <vector>

class PlayerManager : public ObjectManager
{
public:
  PlayerManager(SDL_Renderer*);
  ~PlayerManager();
  void update();
  void draw();
  Player* playerAt(int);
private:
  vector<Player*> objects;
};

#endif
