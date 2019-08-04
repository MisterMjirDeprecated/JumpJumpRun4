#include "input.h"

bool Input::upKey = false;
bool Input::leftClick = false;
int Input::mouseX = 0;
int Input::mouseY = 0;

bool Input::getUpKey()
{
  return upKey;
}

void Input::changeUpKey(bool value)
{
  upKey = value;
}

bool Input::getLeftClick()
{
  return leftClick;
}

void Input::setLeftClick(bool value)
{
  leftClick = value;
}

void Input::updateMouse()
{
  SDL_GetMouseState(&mouseX, &mouseY);
}

int Input::getMouseX()
{
  return mouseX;
}

int Input::getMouseY()
{
  return mouseY;
}
