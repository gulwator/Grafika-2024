#ifndef BLOCKS_H
#define BLOCKS_H

typedef struct Plot{
    double xCoordinate;
    double yCoordinate;
    enum Structure;
    int bonus;
    double radius;
}Plot;


void init_plot(Plot* plot, double x, double y,);
void init_plot_with_bonus(Plot* plot, double x, double y, int bonus, double radius);
void update_plot_bonus();

#endif /*BLOCKS_H*/