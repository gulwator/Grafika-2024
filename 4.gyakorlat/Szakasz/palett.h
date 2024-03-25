#ifndef PALETT_H
#define PALETT_H
typedef struct Color
{
    int red;
    int green;
    int blue;
    
}Color;


typedef struct Palett
{
    int width;
    int height;
        
    Color color[2][2];

}Palett;

void init_palett(Palett* palett, int width, int height);
void init_colors(Palett* palett);
void render_palett(Palett* palett);

#endif /*PALETT_H*/