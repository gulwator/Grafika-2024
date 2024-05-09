#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

#include <obj/model.h>

typedef struct Scene
{
    Model cube;
    Material red_material;
    Material green_material;
    Material blue_material;
} Scene;

/**
 * Unique names of the selectable (pickable) objects
 */
enum ObjectName {
    BACKGROUND,
    RED_CUBE,
    GREEN_CUBE,
    BLUE_CUBE
};

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
void update_scene(Scene* scene);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene);

/**
 * Find the object on the scene at position (x, y) and returns its object name.
 */
unsigned int find_object_on_scene(const Scene* scene, int x, int y);

#endif /* SCENE_H */

