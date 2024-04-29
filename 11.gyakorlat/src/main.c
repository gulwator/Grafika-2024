
#include <math.h>
#include <stdio.h>
#include "plot.h"


#define MAP_WIDTH 5
#define MAP_HEIGHT  5
/**
 * Main function
 */
int main(int argc, char* argv[])
{
    Plot map[5][5];
    for (int x = 0; x < MAP_WIDTH ; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            map[x][y].structure=rand() % (2 + 1 - 0) + 0;

            switch (map[x][y].structure)
            {
            case 0:
                map[x][y].bonus=0;
                map[x][y].effect=0;
                map[x][y].radius=0;
            break;
            case 1:
                map[x][y].bonus=5;
                map[x][y].effect=1;
                map[x][y].radius=1;
            break;
            case 2:
                map[x][y].bonus=-5;
                map[x][y].effect=-1;
                map[x][y].radius=1;
            break;
                    
            default:
                break;
            }
            printf(" %d ",map[x][y].bonus);

        }
    }
        


    printf("hello world");
    return 0;
}
