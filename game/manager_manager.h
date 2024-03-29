#ifndef MANAGER_MANAGER
#define MANAGER_MANAGER

// Include managers in order of which should be painted
#include "object_manager.h"
#include "player_manager.h"
#include "tile_manager.h"
#include "cloud_manager.h"
#include "spike_manager.h"
#include "text_manager.h"
#include "button_manager.h"
#include <SDL2/SDL.h>
#include <vector>
using std::vector;

class ManagerManager
{
public:
  ManagerManager(SDL_Renderer *);
  ~ManagerManager();
  void update();
  void draw();
private:
  vector<ObjectManager*> objects;
};

#endif
