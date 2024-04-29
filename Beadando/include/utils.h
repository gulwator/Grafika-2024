#ifndef UTILS_H
#define UTILS_H

/**
 * GLSL-like three dimensional vector
 */
typedef struct vec3
{
    float x;
    float y;
    float z;
} vec3;

/**
 * Color with RGB components
 */
typedef struct Color
{
    float red;
    float green;
    float blue;
} Color;

/**
 * Material
 */
typedef struct Material
{
    struct Color ambient;
    struct Color diffuse;
    struct Color specular;
    float shininess;
} Material;

/**
 * Calculates radian from degree.
 */
double degree_to_radian(double degree);

/**
 * calculates obj in X,Y in the circle radius
 * circle_origo_x,
 * circle_origo y,
 * circle_radius,
 * object X,
 * object Y,
*/
double check_distance(double circle_origo_x, double circle_origo_y, double circle_radius, double middle_x, double middle_y );

#endif /* UTILS_H */
