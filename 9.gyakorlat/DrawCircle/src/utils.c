#include "utils.h"
#include "math.h"
#include <math.h>

double degree_to_radian(double degree)
{
	return degree * M_PI / 180.0;
}
double check_distance(double circle_origo_x, double circle_origo_y, double circle_radius, double middle_x, double middle_y ){
	double distance_circle_to_square= sqrt((circle_origo_x-middle_x)*(circle_origo_x-middle_x)+ (circle_origo_y-middle_y)*(circle_origo_y-middle_y));
	return distance_circle_to_square-circle_radius;
}

void get_midlepoint(Plot* cube, double* middle_x, double* middle_y){
	 *middle_x = (cube->x1 + cube->x2)/2;
	 *middle_y = (cube->y1+cube->y2)/2;
}
