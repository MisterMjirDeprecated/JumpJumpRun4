#include "game_object.h"
#include "texture_manager.h"

GameObject::GameObject(const char *texturesheet, SDL_Renderer *ren)
{
  renderer = ren;
  texture = TextureManager::loadTexture(texturesheet, renderer);
  // Initalize rects in case not initialized
  srcRect = {0, 0, 0, 0};
  destRect = {0, 0, 0, 0};
}

void GameObject::changeTexture(const char *texturesheet)
{
  texture = TextureManager::loadTexture(texturesheet, renderer);
}

void GameObject::draw()
{
  SDL_RenderCopy(renderer, texture, &srcRect, &destRect);
}
