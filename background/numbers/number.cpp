#include "number.h"
#include <iostream>

Number::Number(const char* texture, SDL_Renderer* ren, SDL_Rect startPos, SDL_Rect endPos, int myPos):Text(texture, ren, startPos, endPos)
{
  srcRect = {0, 0, 16, 18};
  position = myPos;
}

void Number::update()
{
  int score = Score::getScore();
  std::cout << "Score " << score << "\n";
  int digits = 0;
  while (score != 0)
  {
    score /= 10;
    digits++;
  }
  if (digits == 0)
    digits = 1;
  std::cout << "Digits " << digits << "\n";
  int place = 0;
  place = static_cast<int>(log10(pow(pow(10, digits - 1), 1.0 / position)) + 1);
  int digit = (static_cast<int>(Score::getScore() / pow(10, place - 1)) % 10);
  std::cout << "Position " << position << "\n";
  std::cout << "Place " << place << "\n";
  std::cout << "Place (10) " << pow(pow(10, digits - 1), 1.0 / position) << "\n";
  std::cout << "Digit " << digit << "\n\n";
  srcRect = {16 * (digit % 4), 18 * (digit / 4), 16, 18}; // Purposely using integer slicing
  Text::update();
}

void Number::draw()
{
  GameObject::draw();
}
