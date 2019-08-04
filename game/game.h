/*
 * There should only ever be one instance of this class,
 * I am not enforcing it due to languorouitis
 */
#ifndef GAME
#define GAME

#include "game_object.h"
#include "manager_manager.h"
#include "input.h"
#include "game_states.h"
#include <SDL2/SDL.h>

class Game
{
public:
  Game(const char *, int, int, int, int, bool);
  ~Game();

  void input();
  void update();
  void draw();

  bool isRunning();
private:
  bool running;
  SDL_Window *window;
  SDL_Renderer *renderer;
  ManagerManager *managerManager;
};

#endif
