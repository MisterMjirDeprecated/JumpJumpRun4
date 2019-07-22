#include "player.h"

void Player::update()
{
  runTicks++;
  if (runTicks > 11)
    runTicks = 0;
  int playerXs[] = {0, 16, 32, 48};
  int playerYs[] = {0, 16, 32, 48};
  if (runTicks == 0)
    srcRect = {playerXs[1], playerYs[0], 16, 16};
  else if (runTicks == 1)
    srcRect = {playerXs[2], playerYs[0], 16, 16};
  else if (runTicks == 2)
    srcRect = {playerXs[3], playerYs[0], 16, 16};
  else if (runTicks == 3)
    srcRect = {playerXs[0], playerYs[1], 16, 16};
  else if (runTicks == 4)
    srcRect = {playerXs[1], playerYs[1], 16, 16};
  else if (runTicks == 5)
    srcRect = {playerXs[2], playerYs[1], 16, 16};
  else if (runTicks == 6)
    srcRect = {playerXs[3], playerYs[1], 16, 16};
  else if (runTicks == 7)
    srcRect = {playerXs[0], playerYs[2], 16, 16};
  else if (runTicks == 8)
    srcRect = {playerXs[1], playerYs[2], 16, 16};
  else if (runTicks == 9)
    srcRect = {playerXs[2], playerYs[2], 16, 16};
  else if (runTicks == 10)
    srcRect = {playerXs[3], playerYs[2], 16, 16};
  else
    srcRect = {playerXs[0], playerYs[3], 16, 16};
}
