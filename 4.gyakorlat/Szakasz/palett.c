#include "palett.h"

void init_palett(Palett* palett, int width, int height){
    palett->width = width;
    palett->height = height;

}
void init_colors(Palett* palett ){
    palett->color[0][0].red=1;
    palett->color[0][0].green=1;
    palett->color[0][0].blue=1;
    palett->color[0][1].red=1;
    palett->color[0][1].green=0;
    palett->color[0][1].blue=0;
    palett->color[1][0].red=0;
    palett->color[1][0].green=1;
    palett->color[1][0].blue=0;
    palett->color[1][1].red=0;
    palett->color[1][1].green=0;
    palett->color[1][1].blue=1;
    }
void render_palett(Palett* palett){
    float x1, x2, y1, y2;
    x1 = 600;
    x2 = 800;
    
}

