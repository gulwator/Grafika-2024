#include "utils.h"

#include <math.h>

double degree_to_radian(double degree)
{
	return degree * M_PI / 180.0;
}

double check_distance(double circle_origo_x, double circle_origo_y, double circle_radius, double middle_x, double middle_y ){
	double first_value = circle_origo_x-middle_x;
	double second_value = circle_origo_y-middle_y;
	double distance_circle_to_square= sqrt((first_value*first_value)+ (second_value*second_value));
	return distance_circle_to_square;
}
