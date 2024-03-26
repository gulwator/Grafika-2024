#include "scene.h"

#include <GL/gl.h>

void init_scene(Scene* scene)
{
}

void update_scene(Scene* scene)
{
}

void render_scene(const Scene* scene)
{
    draw_origin();
    draw_cube();
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}
void draw_cube(){
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1, 1, 1);

    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, -1, -1);

    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, -1, 1);

    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);

    glEnd();
}