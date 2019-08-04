#include "game_states.h"

GameState GameStates::state = GAME_MENU;
GameState GameStates::newState = GAME_MENU;

GameState GameStates::getState()
{
  return state;
}

void GameStates::changeState(GameState tempState)
{
  newState = tempState;
}

void GameStates::updateState()
{
  state = newState;
}
