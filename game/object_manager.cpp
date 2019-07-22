#include "object_manager.h"

ObjectManager::ObjectManager(SDL_Renderer *ren)
{
  renderer = ren;
}

ObjectManager::~ObjectManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void ObjectManager::update()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->update();
}

void ObjectManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
