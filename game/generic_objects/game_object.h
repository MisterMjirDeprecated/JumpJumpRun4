#ifndef GAME_OBJECT
#define GAME_OBJECT

#include <SDL2/SDL.h>

class GameObject
{
public:
  GameObject(const char *, SDL_Renderer *);
  void changeTexture(const char *);

  virtual void update() = 0;
  virtual void draw();
protected:
  SDL_Texture *texture;
  SDL_Rect srcRect, destRect;
  SDL_Renderer *renderer;
};

#endif
