#include "game.h"

Game::Game(const char *title, int x, int y, int width, int height, bool fullScreen)
{
  int flags = 0; // SDL Init Flags
  // Change flag if fullScreen == ture
  if (fullScreen)
    flags = SDL_WINDOW_FULLSCREEN;

  if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    // Create Window
    window = SDL_CreateWindow(title, x, y, width, height, flags);
    // Create Renderer
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    SDL_SetRenderDrawColor(renderer, 0x68, 0xac, 0xa9, 255);
    // Initialize the object manager
    managerManager = new ManagerManager(renderer);
    // Start the game
    running = true;
  } else {
    // Game is unable to run
    running = false;
  }
}

Game::~Game()
{
  delete managerManager;
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}

void Game::input()
{
  Input::updateMouse();
  SDL_Event e; // Create event object
  SDL_PollEvent(&e); // Check for events
  switch (e.type) // Switch for the options
  {
    // If close button is clicked
    case SDL_QUIT:
      running = false;
      break;
    // Key Presses
    case SDL_KEYDOWN:
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          Input::changeUpKey(true);
          break;
      }
      break;
    // Key Releases
    case SDL_KEYUP:
      switch (e.key.keysym.sym)
      {
        case SDLK_UP:
          Input::changeUpKey(false);
          break;
      }
      break;
    // Mouse Presses
    case SDL_MOUSEBUTTONDOWN:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          Input::setLeftClick(true);
          break;
      }
      break;
    // Mouse Releases
    case SDL_MOUSEBUTTONUP:
      switch (e.button.button)
      {
        case SDL_BUTTON_LEFT:
          Input::setLeftClick(false);
          break;
      }
      break;
  }
}

void Game::update()
{
  managerManager->update();
  GameStates::updateState();
}

void Game::draw()
{
  SDL_SetRenderDrawColor(renderer, 0x68, 0xac, 0xa9, 255);
  SDL_RenderClear(renderer);

  managerManager->draw();

  SDL_RenderPresent(renderer);
}

bool Game::isRunning()
{
  return running;
}
