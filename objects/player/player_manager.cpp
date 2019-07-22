#include "player_manager.h"

PlayerManager::PlayerManager(SDL_Renderer *ren):ObjectManager(ren)
{
  Player *player = new Player("images/retroboi.png", renderer, 0, 0);
  objects.push_back(player);
}

PlayerManager::~PlayerManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}
