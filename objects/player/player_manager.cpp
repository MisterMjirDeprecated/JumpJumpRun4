#include "player_manager.h"

PlayerManager::PlayerManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

PlayerManager::~PlayerManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void PlayerManager::update()
{
  if (GameStates::getState() == GAME_MENU)
  {
    if (GameStates::getFirstTick())
    {
      Player *player = new Player("images/retroboi.png", renderer);
      objects.push_back(player);
    }
  }
  else if (GameStates::getState() == GAME_OVER)
  {
    for (int i = objects.size() - 1; i >=0; i--)
      objects.erase(objects.begin() + i);
  }
  // Can't call base class function :(
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->update();
}

// Don't know why this needs to be overriden
void PlayerManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}

Player* PlayerManager::playerAt(int index)
{
  return objects.at(index);
}
