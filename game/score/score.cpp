#include "score.h"

int Score::score = 0;
int Score::ticks = 0;

void Score::update()
{
  switch (GameStates::getState())
  {
    case GAME_MENU:
      score = 0;
      break;
    case GAME_GAME:
      if (++ticks % 24 == 0)
      {
        score++;
        ticks = 0;
      }
      break;
    case GAME_OVER:
      break;
  }
}

int Score::getScore()
{
  return score;
}
