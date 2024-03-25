#ifndef LINE_H
#define LINE_H

/**
 * Data of a circle object in Descartes coordinate system
 */
typedef struct Line
{
	double start_x;
	double start_y;
	double end_x;
	double end_y;
	int color;
} Line;


void set_start(Line* line, double start_x, double start_y);
void set_end(Line* line, double end_x,double enx_y);
void set_color(Line* line, int color);
#endif // LINE_H