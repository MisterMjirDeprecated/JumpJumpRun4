#ifndef PLAYER
#define PLAYER

#include "input.h"
#include "game_object.h"
#include <SDL2/SDL.h>

class Player : public GameObject
{
public:
  Player(const char*, SDL_Renderer*);

  void update();
  void changeHP(int);
  int getX();
  int getY();
private:
  int hp;
  int runTicks;
  int yVel;
  enum States {RUNNING, JUMPING, FALLING};
  States state;
};

#endif
