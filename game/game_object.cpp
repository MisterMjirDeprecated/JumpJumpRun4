#include "game_object.h"
#include "texturemanager.h"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren, int startX, int startY)
{
  renderer = ren;
  x = startX, y = startY;
  texture = TextureManager::loadTexture(texturesheet, renderer);
}

void GameObject::changeTexture(const char *texturesheet)
{
  texture = TextureManager::loadTexture(texturesheet, renderer);
}

void GameObject::draw()
{
  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
