#include "spike_manager.h"

SpikeManager::SpikeManager(SDL_Renderer *ren, PlayerManager *playerM):ObjectManager(ren) // Player*
{
  ticks = 0;
  playerList = playerM;
}

SpikeManager::~SpikeManager()
{
  for (int i = objects.size() - 1; i >=0; i--)
    objects.erase(objects.begin() + i);
}

void SpikeManager::update()
{
  if (GameStates::getState() == GAME_GAME)
  {
    ticks++;
    if (ticks > 24)
    {
      if (ticks % 100 == 0) {
        Spike *spike = new Spike("images/spike.png", renderer, playerList->playerAt(0));
        objects.push_back(spike);
      }
      for (int i = objects.size() - 1; i >= 0; i--)
      {
        objects.at(i)->update();
        if (objects.at(i)->offScreen())
          objects.erase(objects.begin() + i);
        else if (objects.at(i)->collidesPlayer())
          GameStates::changeState(GAME_OVER);
      }
    }
  }
  else
  {
    if (objects.size() > 0)
      for (int i = objects.size() - 1; i >=0; i--)
        objects.erase(objects.begin() + i);
  }
}

void SpikeManager::draw()
{
  for (int i = 0; i < objects.size(); i++)
    objects.at(i)->draw();
}
