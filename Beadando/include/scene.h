#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"
#include "blocks.h"
#include "utils.h"
#include <obj/model.h>

#define MAP_WIDTH 4
#define MAP_HEIGHT  4
#define GRID_SOMETHING 25

typedef struct Scene
{
    Model cube;
    Model templePlot;
    Model factoryPlot;
    Model cityPlot;
    Model sphere;
    Material material;
    GLuint texture_id;
    double rotation;
    Plot map[MAP_WIDTH][MAP_HEIGHT];
    Color effect_colors[7];
    
} Scene;

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
void update_scene(Scene* scene,double elapsed_time);

/**
 * Render the scene objects.
 */
void render_scene(const Scene* scene );

/**
 * Draw the origin of the world coordinate system.
 
 */
void draw_origin();

/**
 * Draw a circle around the object
 * x is the x coord
 * y is the y coord
 * z is the z coord
 * radius is the radius of the circle
 * 
*/
void draw_Circle( double x, double y, double z, double radius);
#endif /* SCENE_H */
