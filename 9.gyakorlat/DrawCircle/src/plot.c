#include "plot.h"
#include <obj/draw.h>

void draw_plot(Plot cube ){
    glBegin(GL_QUADS);
    if (cube.bonus == 1)
    {
    glColor3i(102, 153, 102);
        
    }
    
    glVertex3f(cube.x1,cube.y1,0);
    glVertex3f(cube.x2,cube.y1,0);
    glVertex3f(cube.x2,cube.y2,0);
    glVertex3f(cube.x1,cube.y2,0);
    glEnd();
}