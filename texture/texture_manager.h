#ifndef TEXTURE_MANAGER
#define TEXTURE_MANAGER

#include <SDL2/SDL.h>

class TextureManager
{
public:
  static SDL_Texture* loadTexture(const char *, SDL_Renderer *);
};

#endif
