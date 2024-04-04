#include "blocks.h"

void init_block(Blocks* block, double x, double y){
    block->xCoordinate=x;
    block->yCoordinate = y;
    block->radius =0;
    block->bonus = 0;
}
void init_plot_with_bonus(Plot* plot, double x, double y, int bonus, double radius);