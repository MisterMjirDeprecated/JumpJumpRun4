#ifndef CLOUDMANAGER
#define CLOUDMANAGER

#include "object_manager.h"
#include "cloud.h"
#include <SDL2/SDL.h>

#include <vector>
using std::vector;

class CloudManager : public ObjectManager
{
public:
  CloudManager(SDL_Renderer*);
  ~CloudManager();
  void update();
  void draw();
private:
  int ticks;
  vector<Cloud*> objects;
};

#endif
