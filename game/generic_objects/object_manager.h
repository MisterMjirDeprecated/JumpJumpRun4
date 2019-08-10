#ifndef OBJECT_MANAGER
#define OBJECT_MANAGER

#include "game_object.h"
#include <SDL2/SDL.h>
#include <vector>
using std::vector;

class ObjectManager
{
public:
  ObjectManager(SDL_Renderer *);
  ~ObjectManager();
  virtual void update();
  virtual void draw();
protected:
  void removeObjects();
  SDL_Renderer *renderer;
  vector<GameObject*> objects;
};

#endif
