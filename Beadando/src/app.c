#include "app.h"
#include <stdbool.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#define PICK_BUFFER_SIZE 256


void init_app(App* app, int width, int height)
{
    int error_code;
    int inited_loaders;
    app->appWidth=width;
    app->appHeight=height;
    app->is_running = false;
    app->fog = false;
    app->selected_structure=0;

    error_code = SDL_Init(SDL_INIT_EVERYTHING);
    if (error_code != 0) {
        printf("[ERROR] SDL initialization error: %s\n", SDL_GetError());
        return;
    }

    app->window = SDL_CreateWindow(
        "Cube!",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        width, height,
        SDL_WINDOW_OPENGL);
    if (app->window == NULL) {
        printf("[ERROR] Unable to create the application window!\n");
        return;
    }

    inited_loaders = IMG_Init(IMG_INIT_PNG);
    if (inited_loaders == 0) {
        printf("[ERROR] IMG initialization error: %s\n", IMG_GetError());
        return;
    }

    app->gl_context = SDL_GL_CreateContext(app->window);
    if (app->gl_context == NULL) {
        printf("[ERROR] Unable to create the OpenGL context!\n");
        return;
    }

    init_opengl();
    reshape(width, height);

    init_camera(&(app->camera));
    init_scene(&(app->scene));

    app->is_running = true;
    // printf("width:%d, height:%d \n", app->appWidth, app->appHeight );
}

void init_opengl()
{
    glShadeModel(GL_SMOOTH);
    glEnable(GL_STENCIL_TEST);
    glClearStencil(0);


    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(0.9, 0.9, 0.9, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_DEPTH_TEST);

    glClearDepth(1.0);

    glEnable(GL_TEXTURE_2D);
    glDisable(GL_FOG);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_COLOR_MATERIAL);
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(
        -.08, .08,
        -.06, .06,
        .1, 100000
    );
}

void handle_app_events(App* app)
{
    SDL_Event event;
    static bool is_mouse_down = false;
    static int mouse_x = 0;
    static int mouse_y = 0;
    int x;
    int y;
    double zoom;
    int appWidth = app->appWidth;
    int appHeight = app->appHeight;
    
    float fog_start = 0.0005;       //0.0005
    float fog_end = 1;              //1
    float density= .01;             //0.01
    glFogfv(GL_FOG_DENSITY, &density);
    glFogfv(GL_FOG_START, &fog_start);
    glFogfv(GL_FOG_END, &fog_end);

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_ESCAPE:
                app->is_running = false;
                break;
            case SDL_SCANCODE_W:
                set_camera_speed(&(app->camera), 15);
                break;
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), -15);
                break;
            case SDL_SCANCODE_A:
                set_camera_side_speed(&(app->camera), 15);
                break;
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), -15);
                break;
            case SDL_SCANCODE_0:
                            app->selected_structure=0;
                             printf("%d \n", app->selected_structure);
                            break;    
            case SDL_SCANCODE_1:
                            app->selected_structure=1;
                            printf("%d\n", app->selected_structure);
                            break;
            case SDL_SCANCODE_2:
                            app->selected_structure=2;
                            printf("%d\n", app->selected_structure);
                            break;
            case SDL_SCANCODE_E:
                printf("E nyomódott\n");

                printf("fog is: %s \n", app->fog ? "true" : "false");
                app->fog = !app->fog;
                printf("fog is: %s \n", app->fog ? "true" : "false");
                if (app->fog)
                {
                    glEnable(GL_FOG);
                     float fog_color[] = {0.9, 0.9, 0.9, 0.9};
                    glFogfv(GL_FOG_COLOR, fog_color);
                }
                else{
                    glDisable(GL_FOG);
                }
                break;
            default:
                break;
            }
            break;
        case SDL_KEYUP:
            switch (event.key.keysym.scancode) {
            case SDL_SCANCODE_W:
            case SDL_SCANCODE_S:
                set_camera_speed(&(app->camera), 0);
                break;
            case SDL_SCANCODE_A:
            case SDL_SCANCODE_D:
                set_camera_side_speed(&(app->camera), 0);
                break;
            default:
                break;
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
             if (event.button.button == SDL_BUTTON_LEFT) {
                is_mouse_down = true;
            } else if (event.button.button == SDL_BUTTON_RIGHT) {
                SDL_GetMouseState(&x, &y);
                printf("Pick object at (%d, %d):\n", x, y);
                pick_test(app);
                unsigned int object_name = find_object_on_scene(&(app->scene), x, y);
                printf("Picked object name: %u\n", object_name);
            }
            break;
        case SDL_MOUSEMOTION:
            SDL_GetMouseState(&x, &y);
            if (is_mouse_down) {
                rotate_camera(&(app->camera), mouse_x - x, mouse_y - y);
            }
            mouse_x = x;
            mouse_y = y;
            // printf("%d\n",y);
            if(y<50)
            {
                set_camera_speed(&(app->camera),15);
            }

           if (y>50 && y<appHeight-50)
            {
                set_camera_speed(&(app->camera),0);
            }
           
            if  (y>appHeight-50)
            {
                
                set_camera_speed(&(app->camera),-15);
            }

             if(x < 50){set_camera_side_speed(&(app->camera),15);}
           if (x > 50 && x < appWidth-50)
            {
                set_camera_side_speed(&(app->camera),0);
            }
            if  (x>appWidth-50)
            {
               set_camera_side_speed(&(app->camera),-15);
            }
            break;
        case SDL_MOUSEBUTTONUP:
            is_mouse_down = false;
            break;
        
        case SDL_MOUSEWHEEL:
            zoom=0.0;
            app->camera.zoom+=zoom-event.wheel.y/-0.80;
            // printf("%lf ", app->camera.zoom);
            break;
        case SDL_QUIT:
            app->is_running = false;
            break;
        default:
            break;
        }
    }
}

void update_app(App* app)
{
    double current_time;
    double elapsed_time;

    current_time = (double)SDL_GetTicks() / 1000;
    elapsed_time = current_time - app->uptime;
    app->uptime = current_time;

    update_camera(&(app->camera), elapsed_time);
    update_scene(&(app->scene), elapsed_time );
}

void render_app(App* app)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    if (app->camera.is_preview_visible) {
        show_texture_preview();
    }

    SDL_GL_SwapWindow(app->window);
}

void destroy_app(App* app)
{
    if (app->gl_context != NULL) {
        SDL_GL_DeleteContext(app->gl_context);
    }

    if (app->window != NULL) {
        SDL_DestroyWindow(app->window);
    }

    SDL_Quit();
}

void pick_test(App* app)
{
    printf("Pick test ...\n");

    unsigned int pick_buffer[PICK_BUFFER_SIZE];
    glSelectBuffer(PICK_BUFFER_SIZE, pick_buffer);

    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(BACKGROUND);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
    set_view(&(app->camera));
    render_scene(&(app->scene));
    glPopMatrix();

    GLint n_hits = glRenderMode(GL_RENDER);
    printf("Number of hits: %d\n", n_hits);
}

