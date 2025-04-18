#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_image.h>
#include "Car/Car.h"
#include "Constants.h"
#include "Input.h"

int main(){
  printf("Hello World!\n");

  SDL_Window* window;
  SDL_Renderer* renderer;

  printf("%d\n",SDL_Init(SDL_INIT_EVERYTHING));
  printf("%d\n",SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer));

  SDL_Event e;

  CAR_Car car;
  car.renderer = &renderer;
  const char* carPictureFilename = "./Media/Car_Topdown_Red.png";
  const char* tirePictureFilename = "./Media/Tire.png";
  const char* tireSideViewFilename = "./Media/TireSideView.png";
  CAR_loadTexture(&car, carPictureFilename, tirePictureFilename, tireSideViewFilename);
  CAR_Instantiate(&car, 300, 400, 0, B, L);

  bool running = true;


  while(running){
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_QUIT) {
        running = false;
      }else{
        INP_update(&car.carInput, &e);
      }
    }

    // geometry.x += sin(rotation) * moveSpeed;
    // geometry.y -= cos(rotation) * moveSpeed;
    CAR_Update(&car, TIME_STEP);
 
    SDL_SetRenderDrawColor(renderer, 70, 70, 70, 200); 
    SDL_RenderClear(renderer);

    CAR_draw(&car);
    SDL_SetRenderDrawColor(renderer,WHITE,255);

    SDL_RenderPresent(renderer);
    SDL_Delay(TIME_STEP*1000.0);
  }


}
