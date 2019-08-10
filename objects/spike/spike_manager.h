#ifndef SPIKE_MANAGER
#define SPIKE_MANAGER

#include "object_manager.h"
#include "player_manager.h"
#include "spike.h"
#include "player.h"
#include "game_states.h"
#include <SDL2/SDL.h>
#include <vector>

class SpikeManager : public ObjectManager
{
public:
  SpikeManager(SDL_Renderer*, PlayerManager*);
  ~SpikeManager();
  void update();
  void draw();
private:
  int ticks;
  vector<Spike*> objects;
  PlayerManager *playerList;
};

#endif
