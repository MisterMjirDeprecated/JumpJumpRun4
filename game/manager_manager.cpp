#include "manager_manager.h"

ManagerManager::ManagerManager(SDL_Renderer *ren)
{
  PlayerManager *playerM = new PlayerManager(ren);
  objects.push_back(playerM);
  TileManager *tileM = new TileManager(ren);
  objects.push_back(tileM);
  CloudManager *cloudM = new CloudManager(ren);
  objects.push_back(cloudM);
}

ManagerManager::~ManagerManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void ManagerManager::update()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->update();
}

void ManagerManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
