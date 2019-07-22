#ifndef CLOUD
#define CLOUD

#include "game_object.h"
#include <SDL2/SDL.h>
#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

class Cloud : public GameObject
{
public:
  Cloud(const char *, SDL_Renderer*, int, int);
  void update();
  void draw();
  bool offScreen();
private:
  vector<Cloud*> *list;
  int id;
  int speed;
};

#endif
