#include "button.h"

Button::Button(const char *texturesheet, SDL_Renderer *ren, SDL_Rect startPos, SDL_Rect endPos, GameState myState):GameObject(texturesheet, ren)
{
  srcRect = {0, 0, 32, 16};
  ticks = -1;
  hoverTicks = 0;
  destRect = startPos;
  myPos = endPos;
  state = SLIDING;
  newState = myState;
}

void Button::update()
{
  switch (state)
  {
    case SLIDING:
    {
      double xInc = (myPos.x - destRect.x) / 8.0;
      if (xInc > 0)
        xInc = std::ceil(xInc);
      else
        xInc = std::floor(xInc);
      destRect.x += xInc;

      double yInc = (myPos.y - destRect.y) / 8.0;
      if (yInc > 0)
        yInc = std::ceil(yInc);
      else
        yInc = std::floor(yInc);
      destRect.y += yInc;

      if ((destRect.x == myPos.x) && (destRect.y == myPos.y))
        state = BOUNCING;
      break;
    }
    case BOUNCING:
    {
      ticks++;
      destRect.y = myPos.y + (std::sin(0.25 * ticks) * 4);
      if (Input::getMouseX() >= destRect.x && Input::getMouseX() <= destRect.x + 64 && Input::getMouseY() >= destRect.y && Input::getMouseY() <= destRect.y + 32)
      {
        if (hoverTicks < 8)
          hoverTicks++;
        if (Input::getLeftClick())
          GameStates::changeState(newState);
      }
      else
      {
        if (hoverTicks > 0)
          hoverTicks--;
      }
      srcRect = {32 * (hoverTicks % 3), 16 * (hoverTicks / 3), 32, 16};
      break;
    }
    default:
      break;
  }
}
