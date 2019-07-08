
#include"game.h"
#pragma once
class GameObject{

public:
  GameObject(const char* texturesheet, int x, int y);
  ~GameObject();
  void handleEvents();
  void Update();
  void Render();
private:

  int ypos;
  int xpos;

  SDL_Texture* objTexture;
  SDL_Rect srcRect, destRect;

  bool moveup =false;
  bool movedown = false;
  bool moveright = false;
  bool moveleft = false;

};
