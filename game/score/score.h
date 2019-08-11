#ifndef SCORE
#define SCORE

#include "game_states.h"

class Score
{
public:
  static void update();
  static int getScore();
private:
  Score();
  static int score;
  static int ticks;
};

#endif
