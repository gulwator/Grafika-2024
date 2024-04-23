#ifndef PLOT_H
#define PLOT_H
#include <obj/draw.h>
#include <GL/gl.h>

typedef struct Plot{
    double x1;
    double x2;
    double y1;
    double y2;
    int bonus;
}Plot;

void draw_plot(Plot cube);
void update_plot(Plot cube);


#endif /*PLOT_H*/