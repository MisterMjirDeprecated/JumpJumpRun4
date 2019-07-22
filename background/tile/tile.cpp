#include "tile.h"

Tile::Tile(const char *texturesheet, SDL_Renderer *ren, int x, int y):GameObject(texturesheet, ren, x, y)
{
  ticks = 0;
}

void Tile::update()
{
 ticks += 3;
 if (ticks > 63)
 {
   ticks = 0;
   destRect.x = ogDestRect.x;
 } else {
   destRect.x = ogDestRect.x - ticks;
 }
}

void Tile::setRects(SDL_Rect sRect, SDL_Rect dRect)
{
  srcRect = sRect;
  destRect = dRect;
  ogDestRect = destRect;
}
