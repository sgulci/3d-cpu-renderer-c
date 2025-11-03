#include <stdio.h>
#include <stdint.h>
#include "display.h"
#include "vector.h"

#define N_POINTS (9*9*9) //cube 

bool is_running = false;

// const int N_POINTS = 9*9*9; // cube 
vec3_t cube_points[N_POINTS];

void setup(void){

  color_buffer = (uint32_t*)malloc(sizeof(uint32_t)* window_width * window_height);
  color_buffer_texture = SDL_CreateTexture(
        renderer,
        SDL_PIXELFORMAT_ARGB8888,
        SDL_TEXTUREACCESS_STREAMING,
        window_width,
        window_height
      );


  int point_count = 0;

  // load vector 
  // from -1 to 1 for cube
  for (float x = -1; x < 1; x += 0.25){
    for (float y = -1; y < 1; y += 0.25){
      for (float z = -1; z < 1; z += 0.25){
        vec3_t new_point ={x,y,z};
        cube_points[point_count++] = new_point;

      }
    }
  }
  
  
}

void process_input(void){

  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type){
    case SDL_QUIT:
      is_running = false;
      break;
    case SDL_KEYDOWN:
      if(event.key.keysym.sym == SDLK_ESCAPE){
        is_running = false;
      }
      break;
  
  }

}

void update(void){

}

void render(void){
  SDL_SetRenderDrawColor(renderer,255,0,0,255);
  SDL_RenderClear(renderer);


  // draw_grid();
  draw_pixel(50,50,0x00000000);
  draw_rectangle(200,200,100,50,0x00000000);

  render_color_buffer();
  clear_color_buffer(0xFFFFFF00);

  SDL_RenderPresent(renderer);

}

int main(void){

  is_running = initialize_window();
  setup();
  while(is_running){
    process_input();
    update();
    render();
  }

  destroy_variables();
}