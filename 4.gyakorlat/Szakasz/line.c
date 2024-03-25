#include "line.h"

void set_start(Line* line, double x, double y){
    line->start_x =x;
    line->start_y =y;
}
void set_end(Line* line, double x,double y){
    line->end_x =x;
    line->end_y =y;
}
void set_color(Line* line, int color){
    // glColor3f(0.5,0,1);
}