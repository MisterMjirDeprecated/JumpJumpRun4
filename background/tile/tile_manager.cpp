#include "tile_manager.h"

TileManager::TileManager(SDL_Renderer *ren):ObjectManager(ren)
{
  // Create tiles
  for (int row = 0; row < 5; row++)
  {
    for (int col = 0; col < 21; col++)
    {
      SDL_Rect sRect;
      SDL_Rect dRect;
      if (row == 0)
      {
        sRect = {0, 0, 16, 16};
      } else {
        sRect = {16, 0, 16, 16};
      }
      Tile *tile = new Tile("images/tilemap.png", renderer, 0, 0);
      dRect = {col * 64, 448 + row * 64, 64, 64};
      tile->setRects(sRect, dRect);
      objects.push_back(tile);
    }
  }
}

TileManager::~TileManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}
