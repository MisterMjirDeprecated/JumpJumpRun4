#include "spike.h"

Spike::Spike(const char *texturesheet, SDL_Renderer *ren, Player *player):GameObject(texturesheet, ren)
{
  speed = 3;
  destRect = {1280, 424, 64, 24};
  srcRect = {0, 10, 16, 6};
  targetPlayer = player;
}

void Spike::update()
{
  destRect.x -= speed;
}

bool Spike::offScreen()
{
  if (destRect.x < -64)
    return true;
  else
    return false;
}

bool Spike::collidesPlayer()
{
  int x = destRect.x;
  int y = destRect.y;
  int pX = targetPlayer->getX();
  int pY = targetPlayer->getY();

  bool xColl = (x < pX + 64 && x > pX) || (x + 64 < pX + 64 && x + 64 > pX);
  bool yColl = (y < pY + 64 && y > pY) || (y + 64 < pY + 64 && y + 64 > pY);
  if (xColl && yColl)
    return true;
  else
    return false;

}
