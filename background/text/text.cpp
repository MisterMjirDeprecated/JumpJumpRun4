#include "text.h"

Text::Text(const char *texturesheet, SDL_Renderer *ren, SDL_Rect startPos, SDL_Rect endPos):GameObject(texturesheet, ren)
{
  srcRect = {0, 0, 32, 34};
  destRect = startPos;
  myPos = endPos;
  state = SLIDING;
  ticks = -1;
}

void Text::update()
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
      break;
    }
    default:
      break;
  }
}
