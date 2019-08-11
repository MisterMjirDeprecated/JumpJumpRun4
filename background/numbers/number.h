#ifndef NUMBER
#define NUMBER

#include "text.h"
#include "score.h"
#include <cmath>

class Number : public Text
{
public:
  Number(const char*, SDL_Renderer*, SDL_Rect, SDL_Rect, int);
  void update();
  void draw();
private:
  int position; // 1st number, 2nd number, 3rd number, etc.
};

#endif
