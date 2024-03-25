#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <app.h>

/**
 * SDL2 example
 */
int main(int argc, char* argv[])
{
  App app
  init_app(&app,800,600);
  while (app.is_running){
    hande_app_events(&app);
    update_app(&app);
    render_app(&app);
  }
  destroy_app(&app);
    
return 0;
//   int error_code;
//   SDL_Window* window;
//   bool need_run;
//   SDL_Event event;
//   SDL_Renderer* renderer;
//   int i;

//   error_code = SDL_Init(SDL_INIT_EVERYTHING);
//   if (error_code != 0) {
//     printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
//     return error_code;
//   }

//   window = SDL_CreateWindow(
//     "Hello SDL!",
//     SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
//     800, 600, 0);

//   renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

//   SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
//   SDL_RenderClear(renderer);
//    SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
//                 SDL_RenderDrawLine(renderer,600,0,800,600);
//                 SDL_RenderPresent(renderer);
//  SDL_RenderPresent(renderer);
  
//     static bool is_mouse_down = false;
//     static int mouse_x = 0;
//     static int mouse_y = 0;
//     int start_x, start_y, end_x,end_y;
//     int x;
//     int y;
//     bool firstClick=true;
//       need_run = true;
//   while (need_run) {

// while (SDL_PollEvent(&event)) {
//         switch (event.type) {
//         case SDL_MOUSEBUTTONDOWN:
//             is_mouse_down = true;
            
//             if(firstClick){
//                 SDL_GetMouseState(&start_x,&start_y);
//                 SDL_Log("Clicked Start main: %d, %d", x,y);
//                 // set_start(&x,&y);
//                 firstClick=false;
//             }else{
//                 SDL_GetMouseState(&end_x,&end_y);
//                 SDL_Log("Clicked end main: %d, %d", x,y);
//                 // set_end(x,y);
//                 SDL_SetRenderDrawColor(renderer, 100, 100, 100, SDL_ALPHA_OPAQUE);
//                 SDL_RenderDrawLine(renderer,start_x,start_y,end_x,end_y);
//                 SDL_RenderPresent(renderer);
//                 firstClick=true;
               
//             }
//             break;
//         case SDL_MOUSEMOTION:
//             SDL_GetMouseState(&x, &y);
//             mouse_x = x;
//             mouse_y = y;
//             break;
//         case SDL_MOUSEBUTTONUP:
//             is_mouse_down = false;
//             break;
//         case SDL_QUIT:
//              need_run = false;
//             break;
//         default:
//             break;
//         }

//     }
    
//   }
//   SDL_SetRenderDrawColor(renderer, 255, i, 0, SDL_ALPHA_OPAQUE);
//   SDL_RenderDrawLine(renderer, 0, 0, 500, i * 2);
//   SDL_RenderPresent(renderer);




//   SDL_DestroyRenderer(renderer);
//   SDL_DestroyWindow(window);
//   SDL_Quit();

//   return 0;
}
