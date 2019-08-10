#include "player.h"

Player::Player(const char *texturesheet, SDL_Renderer *ren):GameObject(texturesheet, ren)
{
  yVel = 0;
  state = RUNNING;
  destRect = {576, 384, 64, 64};
  srcRect = {48, 48, 16, 16};
  hp = 1;
}

void Player::update()
{
  if (state == RUNNING)
  {
    srcRect = {16 * (((runTicks - runTicks % 2) / 2) % 4), 16 * (((runTicks - runTicks % 2) / 2) / 4), 16, 16};

    if (Input::getUpKey())
      state = JUMPING;

    runTicks++;
    if (runTicks > 23)
      runTicks = 0;
  } else if (state == JUMPING)
  {
    srcRect = {0, 48, 16, 16};

    if (!(Input::getUpKey()) && (yVel > 3))
      state = FALLING;

    //if (yVel == 0)
      //destRect.y -= 24;

    yVel++;
    destRect.y -= yVel;
    if (yVel > 10)
      state = FALLING;
  } else if (state == FALLING)
  {
    srcRect = {16, 48, 16, 16};

    yVel -= 2;
    destRect.y -= yVel;
    if (destRect.y > 384)
    {
      yVel = 0;
      destRect.y = 384;
      state = RUNNING;
    }
  }
}

int Player::getX()
{
  return destRect.x;
}

int Player::getY()
{
  return destRect.y;
}

void Player::changeHP(int change)
{
  hp += change;
}
