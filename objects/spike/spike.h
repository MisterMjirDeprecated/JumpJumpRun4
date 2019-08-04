#ifndef SPIKE
#define SPIKE

#include "game_object.h"
#include "player.h"
#include <SDL2/SDL.h>

class Spike : public GameObject
{
public:
  Spike(const char*, SDL_Renderer*, Player*);
  void update();
  bool offScreen();
  bool collidesPlayer();
private:
  int speed;
  Player *targetPlayer;
};

#endif
