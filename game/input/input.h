#ifndef INPUT
#define INPUT

#include <SDL2/SDL.h>

class Input
{
public:
  static bool getUpKey();
  static void changeUpKey(bool);

  static bool getLeftClick();
  static void setLeftClick(bool);

  static void updateMouse(); // Updates known mouse position
  static int getMouseX();
  static int getMouseY();
private:
  static bool upKey;
  static bool leftClick;
  static int mouseX;
  static int mouseY;
};

#endif
