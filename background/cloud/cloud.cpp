#include "cloud.h"

Cloud::Cloud(const char *texturesheet, SDL_Renderer *ren):GameObject(texturesheet, ren)
{
  srcRect = {0, 0, 1, 1};
  srand(time(0));
  int type = 1 + rand() % 3;
  if (type == 1)
  {
    destRect = {1280, rand() % 32, 128, 64};
    speed = 18;
  } else if (type == 2) {
    destRect = {1280, rand() % 32, 160, 96};
    speed = 12;
  } else {
    destRect = {1280, rand() % 32, 192, 128};
    speed = 6;
  }
}

void Cloud::update()
{
  destRect.x -= speed;
}

void Cloud::draw()
{
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 128);
  SDL_RenderFillRect(renderer, &destRect);
}

bool Cloud::offScreen()
{
  if (destRect.x < -192)
    return true;
  else
    return false;
}
