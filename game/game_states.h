#ifndef GAME_STATES
#define GAME_STATES

enum GameState {GAME_MENU, GAME_GAME, GAME_OVER};

class GameStates
{
public:
  static GameState getState(); // Return current state
  static void changeState(GameState); // Queue state for change
  static void updateState(); // Change state before update (for game class only)
private:
  GameStates(); // Prevent initialization
  static GameState state;
  static GameState newState;
};

#endif
