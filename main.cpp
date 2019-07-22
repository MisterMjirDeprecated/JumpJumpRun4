#include "game.h"

int main()
{
  const int FPS = 12;
  const int frameDelay = 1000 / FPS;

  Uint32 frameStart;
  int frameTime;

  Game game;
  game.init("Jump! Jump! Run! 4", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 768, false);

  while (game.isRunning())
  {
    frameStart = SDL_GetTicks();

    game.input();
    game.update();
    game.draw();

    frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime)
    {
      SDL_Delay(frameDelay - frameTime);
    }
  }

  game.close();

  return 0;
}
