#include "GameObject.h"
#include "TextureManager.h"
GameObject::GameObject(const char* texturesheet, int x, int y){
  objTexture = TextureManager::LoadTexture(texturesheet);
  xpos=x;
  ypos=y;
}
void GameObject::handleEvents(){
  bool moveright = false;
  bool moveleft = false;
  bool moveup = false;
  bool movedown = false;
  SDL_Event oevent;
  SDL_PollEvent(&oevent);
  switch (oevent.type) {
    case SDL_KEYDOWN:
    switch(oevent.key.keysym.sym)
    {
      case SDLK_w:
        moveup=true;
        break;
      case SDLK_s:
        movedown=true;
        break;
      case SDLK_d:
        moveright=true;
        break;
      case SDLK_a:
        moveleft=true;
        break;
    }
    break;
    case SDL_KEYUP:
    switch(oevent.key.keysym.sym)
    {
      case SDLK_w:
        moveup=false;
        break;
      case SDLK_s:
        movedown=false;
        break;
      case SDLK_d:
        moveright=false;
        break;
      case SDLK_a:
        moveleft=false;
        break;
    }
    break;
    default:
    break;
  }

    if(moveup){ypos=ypos-3;}
    if(movedown){ypos=ypos+3;}
    if(moveright){xpos=xpos+3;}
    if(moveleft){xpos=xpos-3;}
}
void GameObject::Update(){
  srcRect.h=32;
  srcRect.w=32;
  srcRect.x=0;
  srcRect.y=0;

  destRect.x = xpos;
  destRect.y = ypos;
  destRect.h = srcRect.h * 2;
  destRect.w = srcRect.w * 2;

}
void GameObject::Render()
{
  SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}
