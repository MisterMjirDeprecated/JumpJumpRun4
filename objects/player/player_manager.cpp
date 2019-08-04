#include "player_manager.h"

PlayerManager::PlayerManager(SDL_Renderer *ren):ObjectManager(ren)
{
  Player *player = new Player("images/retroboi.png", renderer);
  objects.push_back(player);
}

PlayerManager::~PlayerManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void PlayerManager::update()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->update();
}

void PlayerManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}

Player* PlayerManager::playerAt(int index)
{
  return objects.at(index);
}
