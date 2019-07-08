#include "game.h"
Game *game = NULL;
const int SCREEN_HEIGHT = 500;
const int SCREEN_WIDTH = 640;
int main(int argc, const char *argv[]) {

  const int FPS = 60;
  const int frameDelay = 1000/FPS;

  Uint32 frameStart;
  int frameTime;

  game = new Game();
  game->init("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, false);
  while(game->running()){
    frameStart = SDL_GetTicks();
    game->handleEvents();
    game->update();
    game->render();
    frameTime = SDL_GetTicks() - frameStart;
    if(frameDelay > frameTime){
      SDL_Delay(frameDelay - frameTime);
    }
  }
  game->clean();
  return 0;
}
