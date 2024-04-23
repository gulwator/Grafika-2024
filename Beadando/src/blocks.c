#include "blocks.h"




void init_block(Plot* plot, double x, double y){
    plot->xCoordinate=x;
    plot->yCoordinate = y;
    plot->radius =0;
    plot->bonus = 0;
}
void init_plot_with_bonus(Plot* plot, double x, double y, int bonus, double radius);