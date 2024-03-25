#ifndef APP_H
#define APP_H

#include "line.h"

#include <SDL2/SDL.h>

#include <stdbool.h>

#define VIEWPORT_RATIO (4.0 / 3.0)
#define VIEWPORT_ASPECT 50.0

typedef struct App
{
    SDL_Window* window;
    SDL_GLContext gl_context;
    bool is_running;
    double uptime;
    double last_update_time;
    
} App;


void init_app(App* app);
void destroy_app();
void handle_app_events();
void update_app();
void render_app();
#endif