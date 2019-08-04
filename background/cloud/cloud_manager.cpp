#include "cloud_manager.h"

CloudManager::CloudManager(SDL_Renderer *ren):ObjectManager(ren)
{
  ticks = 0;
}

CloudManager::~CloudManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void CloudManager::update()
{
  ticks++;
  if (ticks % 25 == 0)
  {
    Cloud *cloud = new Cloud("images/white75.png", renderer);
    objects.push_back(cloud);
  }
  for (int i = objects.size() - 1; i >= 0; i--)
  {
    objects.at(i)->update();
    if (objects.at(i)->offScreen())
      objects.erase(objects.begin() + i);
  }
}

void CloudManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
