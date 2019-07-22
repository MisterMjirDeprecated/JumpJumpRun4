#ifndef GAME
#define GAME

#include "manager_manager.h"
#include <SDL2/SDL.h>

class Game
{
public:
  Game();
  ~Game();

  void init(const char *, int, int, int, int, bool);
  void input();
  void update();
  void draw();
  void close();

  bool isRunning() {return running;}
private:
  bool running;
  SDL_Window *window;
  SDL_Renderer *renderer;
  ManagerManager *managerManager;
};

#endif
