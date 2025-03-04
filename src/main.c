#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_render.h>
#include <stdio.h>
#include <stdbool.h>

int main(){
  printf("Hello World!\n");

  #define WHITE 255,255,255

  SDL_Window* window;
  SDL_Renderer* renderer;



  SDL_Event e;

  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Rect rectangle = {20, 400, 50, 80};
  SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
  bool running = true;

  while(running){
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT) {
        running = false;
      }
    }
    SDL_SetRenderDrawColor(renderer, 70, 70, 70, 200); 
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,WHITE,255);
    SDL_RenderDrawRect(renderer, &rectangle);

    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }


}
