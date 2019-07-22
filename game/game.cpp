#include "game.h"
#include "game_object.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::init(const char *title, int x, int y, int width, int height, bool fullScreen)
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

void Game::input()
{
  SDL_Event e; // Create event object
  SDL_PollEvent(&e); // Check for events
  switch (e.type) // Switch for the options
  {
    // If close button is clicked
    case SDL_QUIT:
      running = false;
      break;
    // Default case
    default:
      break;
  }
}

void Game::update()
{
  managerManager->update();
}

void Game::draw()
{
  SDL_SetRenderDrawColor(renderer, 0x68, 0xac, 0xa9, 255);
  SDL_RenderClear(renderer);

  managerManager->draw();

  SDL_RenderPresent(renderer);
}

void Game::close()
{
  delete managerManager;
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
