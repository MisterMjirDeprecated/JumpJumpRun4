#include "text_manager.h"

TextManager::TextManager(SDL_Renderer *ren):ObjectManager(ren)
{

}

TextManager::~TextManager()
{
  removeObjects();
}

void TextManager::update()
{
  switch (GameStates::getState())
  {
    case GAME_MENU:
      if (GameStates::getFirstTick())
      {
        removeObjects();
        SDL_Rect startPos = {512, -272, 256, 272};
        SDL_Rect endPos = {512, 32, 256, 272};
        Text *title = new Text("images/title.png", renderer, startPos, endPos);
        objects.push_back(title);
      }
      break;
    case GAME_GAME:
      if (GameStates::getFirstTick())
      {
        removeObjects();
        SDL_Rect startPos = {16, 16, 80, 20};
        SDL_Rect endPos = {16, 16, 80, 20};
        Text *score = new Text("images/score.png", renderer, startPos, endPos);
        objects.push_back(score);
      }
      else
      {
        int score = Score::getScore();
        int digits = 0;
        while (score != 0)
        {
          score /= 10;
          digits++;
        }
        if (digits == 0)
          digits = 1;
        while (objects.size() - 1 < digits)
        {
          SDL_Rect startPos = {static_cast<int>(16 * objects.size() + 96), 16, 16, 18};
          SDL_Rect endPos = {static_cast<int>(16 * objects.size() + 96), 16, 16, 18};
          Number *digit = new Number("images/numbers.png", renderer, startPos, endPos, objects.size());
          objects.push_back(digit);
        }
      }
      break;
    case GAME_OVER:
      if (GameStates::getFirstTick())
      {
        SDL_Rect startPos = {512, -272, 256, 176};
        SDL_Rect endPos = {512, 64, 256, 176};
        Text *title = new Text("images/game_over.png", renderer, startPos, endPos);
        objects.push_back(title);
      }
      break;
    default:
      removeObjects();
  }
  ObjectManager::update();
}
