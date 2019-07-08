#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
GameObject* player;
Map* map;
SDL_Renderer* Game::renderer = NULL;
Game::Game()
{

}
Game::~Game()
{

}
void Game::init(const char* title, int xpos , int ypos, int width, int height, bool fullscreen)
{
  int flags = 0;
  if(fullscreen){
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING)==0){
    std::cout<<"Subytems initialized"<<"\n";
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer)
    {
      std::cout<<"renderer made"<<"\n";
      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      std::cout<<"SDL Rendered!"<<"\n";
    }
    isRunning = true;

   }
    player = new GameObject("/Users/mattbarron/things/game/assets/ben.png", 0, 0);
    map = new Map();
}
void Game::handleEvents()
{
  player->handleEvents();

  SDL_Event event;

  SDL_PollEvent(&event);

  switch (event.type)
  {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
  }

}
void Game::update()
{
  player->Update();
  //map->LoadMap();
}
void Game::render()
{
  SDL_RenderClear(renderer);
  map->DrawMap();
  player->Render();
  SDL_RenderPresent(renderer);
}
void Game::clean()
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();

}
