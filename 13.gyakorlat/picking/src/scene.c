#include "scene.h"

#include <obj/load.h>
#include <obj/draw.h>

#include <GL/gl.h>

#define PICK_BUFFER_SIZE 256

void init_scene(Scene* scene)
{
    load_model(&(scene->cube), "assets/models/cube.obj");

    scene->red_material.ambient.red = 0.0;
    scene->red_material.ambient.green = 0.0;
    scene->red_material.ambient.blue = 0.0;

    scene->red_material.diffuse.red = 1.0;
    scene->red_material.diffuse.green = 0.0;
    scene->red_material.diffuse.blue = 0.0;

    scene->red_material.specular.red = 1.0;
    scene->red_material.specular.green = 1.0;
    scene->red_material.specular.blue = 1.0;

    scene->red_material.shininess = 50.0;

    scene->green_material.ambient.red = 0.0;
    scene->green_material.ambient.green = 0.0;
    scene->green_material.ambient.blue = 0.0;

    scene->green_material.diffuse.red = 0.0;
    scene->green_material.diffuse.green = 1.0;
    scene->green_material.diffuse.blue = 0.0;

    scene->green_material.specular.red = 1.0;
    scene->green_material.specular.green = 1.0;
    scene->green_material.specular.blue = 1.0;

    scene->green_material.shininess = 50.0;

    scene->blue_material.ambient.red = 0.0;
    scene->blue_material.ambient.green = 0.0;
    scene->blue_material.ambient.blue = 0.0;

    scene->blue_material.diffuse.red = 0.0;
    scene->blue_material.diffuse.green = 0.0;
    scene->blue_material.diffuse.blue = 1.0;

    scene->blue_material.specular.red = 1.0;
    scene->blue_material.specular.green = 1.0;
    scene->blue_material.specular.blue = 1.0;

    scene->blue_material.shininess = 50.0;
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, -5.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    set_lighting();

    glLoadName(RED_CUBE);
    set_material(&(scene->red_material));
    draw_model(&(scene->cube));

    glTranslatef(2, 0, 0);
    glLoadName(GREEN_CUBE);
    set_material(&(scene->green_material));
    draw_model(&(scene->cube));

    glTranslatef(2, 0, 0);
    glLoadName(BLUE_CUBE);
    set_material(&(scene->blue_material));
    draw_model(&(scene->cube));
}

unsigned int find_object_on_scene(const Scene* scene, int x, int y)
{
    unsigned int pick_buffer[PICK_BUFFER_SIZE];

    glSelectBuffer(PICK_BUFFER_SIZE, pick_buffer);

    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(BACKGROUND);
    // NOTE: Lighting, shading and texturing can be disabled for better performance.

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-(0 + 90), 1.0, 0, 0);
    glRotatef(-(0 - 90), 0, 0, 1.0);
    glTranslatef(0, 0, -1);
    glPushMatrix();
    render_scene(scene);
    glPopMatrix();

    GLint depth;
    glGetIntegerv(GL_NAME_STACK_DEPTH, &depth);
    printf("Depth: %d\n", depth);

    GLint n_hits = glRenderMode(GL_RENDER);
    printf("Number of hits: %d\n", n_hits);

    for (int i = 0; i < n_hits; ++i) {
        int n_items = pick_buffer[i + 0];
        printf("----\n");
        printf("Hit %d\n", i);
        printf("nitems : %d\n", n_items);
        printf("zmin   : %d\n", pick_buffer[i + 1]);
        printf("zmax   : %d\n", pick_buffer[i + 2]);
        for (int j = 0; j < n_items; ++j) {
            printf("- item %d\n", pick_buffer[3 + j]);
        }
    }
    printf("\n");

    return 234;
}

