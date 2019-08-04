#include "button_manager.h"

ButtonManager::ButtonManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

ButtonManager::~ButtonManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void ButtonManager::update()
{
  if (GameStates::getState() == GAME_MENU)
  {
    if (objects.size() == 0)
    {
      SDL_Rect startPos = {600, 832, 64, 32};
      SDL_Rect endPos = {600, 500, 64, 32};
      Button *button = new Button("images/play_button.png", renderer, startPos, endPos);
      objects.push_back(button);
    }
  }
  else
  {
    if (objects.size() > 0)
      objects.erase(objects.begin());
  }
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->update();
}

void ButtonManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
