#include "plot.h"
#include <obj/draw.h>
#include <stdio.h>
#include <GL/gl.h>

void draw_plot(Plot cube ){
    glBegin(GL_QUADS);
    printf("%d\n",cube.bonus);
    switch(cube.bonus){
        case 1:
            glColor3f(1.0f, 0.0f, 0.0f);
        break;
        default:
         glColor3f(0.5f, 0.5f, 0.5f);
    }
    
    
    glVertex3f(cube.x1,cube.y1,0);
    glVertex3f(cube.x2,cube.y1,0);
    glVertex3f(cube.x2,cube.y2,0);
    glVertex3f(cube.x1,cube.y2,0);
    glEnd();
}


//ELVILEG TELJESEN FELESLEGES
void update_plot(Plot cube){
     glBegin(GL_QUADS);
    if (cube.bonus == 1)
    {
        // printf(" cube x1: %lf, x2:%lf, y1:%lf, y2:%lf, bonus: %d \n",cube.x1,cube.x2,cube.y1,cube.y2,cube.bonus);
    glColor3i(0, 255, 0);
        
    }
    
    glVertex3f(cube.x1,cube.y1,0);
    glVertex3f(cube.x2,cube.y1,0);
    glVertex3f(cube.x2,cube.y2,0);
    glVertex3f(cube.x1,cube.y2,0);
    glEnd();
}