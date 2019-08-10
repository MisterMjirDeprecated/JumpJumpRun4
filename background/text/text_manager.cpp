#include "text_manager.h"

TextManager::TextManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

TextManager::~TextManager()
{
  removeObjects();
}

void TextManager::update()
{
  if (GameStates::getState() == GAME_MENU)
  {
    if (GameStates::getFirstTick())
    {
      removeObjects();
      SDL_Rect startPos = {512, -272, 256, 272};
      SDL_Rect endPos = {512, 32, 256, 272};
      Text *title = new Text("images/title.png", renderer, startPos, endPos);
      objects.push_back(title);
    }
  }
  else if (GameStates::getState() == GAME_OVER)
  {
    if (GameStates::getFirstTick())
    {
      removeObjects();
      SDL_Rect startPos = {512, -272, 256, 176};
      SDL_Rect endPos = {512, 64, 256, 176};
      Text *title = new Text("images/game_over.png", renderer, startPos, endPos);
      objects.push_back(title);
    }
  }
  else
  {
    removeObjects();
  }
  ObjectManager::update();
}
