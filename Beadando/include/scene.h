#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "blocks.h"

#include <obj/model.h>

#define MAP_WIDTH 5
#define MAP_HEIGHT  5

typedef struct Scene
{
    Model cube;
    Model cityBlock;
    Material material;
    GLuint texture_id;
    double rotation;
    Plot map[MAP_WIDTH][MAP_HEIGHT];
    
} Scene;

/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Update the scene.
 */
void update_scene(Scene* scene,double elapsed_time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene );

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */
