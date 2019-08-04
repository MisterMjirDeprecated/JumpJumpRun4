#include "text_manager.h"

TextManager::TextManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

TextManager::~TextManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void TextManager::update()
{
  if (GameStates::getState() == GAME_MENU)
  {
    if (objects.size() == 0)
    {
      SDL_Rect startPos = {512, -272, 256, 272};
      SDL_Rect endPos = {512, 32, 256, 272};
      Text *title = new Text("images/title.png", renderer, startPos, endPos);
      objects.push_back(title);
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

void TextManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
