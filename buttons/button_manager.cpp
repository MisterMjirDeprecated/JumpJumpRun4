#include "button_manager.h"

ButtonManager::ButtonManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

ButtonManager::~ButtonManager()
{
  removeObjects();
}

void ButtonManager::update()
{
  if (GameStates::getState() == GAME_MENU)
  {
    if (GameStates::getFirstTick())
    {
      removeObjects();
      SDL_Rect startPos = {600, 832, 64, 32};
      SDL_Rect endPos = {600, 500, 64, 32};
      Button *button = new Button("images/play_button.png", renderer, startPos, endPos, GAME_GAME);
      objects.push_back(button);
    }
  }
  else if (GameStates::getState() == GAME_OVER)
  {
    if (GameStates::getFirstTick())
    {
      removeObjects();
      SDL_Rect startPos = {600, 832, 64, 32};
      SDL_Rect endPos = {600, 500, 64, 32};
      Button *button = new Button("images/home_button.png", renderer, startPos, endPos, GAME_MENU);
      objects.push_back(button);
    }
  }
  else
  {
    removeObjects();
  }
  ObjectManager::update();
}
