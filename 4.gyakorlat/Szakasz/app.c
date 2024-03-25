#include "app.h"

void init_app(App* app){
    app->is_running = false;
    app->width =width;
    app->height = height;
    if (init_sdl(game)== false){
        return;
    }
    init_opengl(app);
    app->is_running = true
    
}
void destroy_app();
void handle_app_events();
void update_app();
void render_app();
