#include "scene.h"
#include "math.h"
#include "blocks.h"
#include <obj/load.h>
#include <obj/draw.h>

#

void init_scene(Scene* scene)
{
    scene->rotation =0;
    load_model(&(scene->cube), "assets/models/cube.obj");
    load_model(&(scene->cityPlot), "assets/models/houseBlockTM.obj");
    load_model(&(scene->templePlot), "assets/models/templeBlockTM.obj");
    load_model(&(scene->factoryPlot), "assets/models/factoryBlockTM.obj");
    load_model(&(scene->sphere), "assets/models/sphere.obj");
    // scene->texture_id = load_texture("assets/textures/cube.png");

    // glBindTexture(GL_TEXTURE_2D, scene->texture_id);

    // scene->material.ambient.red = 0.0;
    // scene->material.ambient.green = 0.0;
    // scene->material.ambient.blue = 0.0;

    // scene->material.diffuse.red = 1.0;
    // scene->material.diffuse.green = 1.0;
    // scene->material.diffuse.blue = 0.0;

    // scene->material.specular.red = 0.0;
    // scene->material.specular.green = 0.0;
    // scene->material.specular.blue = 0.0;

    // scene->material.shininess = 0.0;
for (int x = 0; x < MAP_WIDTH ; x++)
{
    for (int y = 0; y < MAP_HEIGHT; y++)
    {
        scene->map[x][y].structure=rand() % (2 + 1 - 0) + 0;

        switch (scene->map[x][y].structure)
        {
        case 0:
        scene->map[x][y].bonus=0;
        scene->map[x][y].effect=0;
        scene->map[x][y].radius=0;
        break;
        case 1:
            scene->map[x][y].bonus=5;
            scene->map[x][y].effect=1;
            scene->map[x][y].radius=1;
        break;
        case 2:
            scene->map[x][y].bonus=-5;
            scene->map[x][y].effect=-1;
            scene->map[x][y].radius=1;
        break;
                
        default:
            break;
        }
        
        
        
        // if (x==y)
        // {
        //     scene->map[x][y].structure=1;
        //     scene->map[x][y].effect=1;
        // scene->map[x][y].radius=1;
            
        // }
        // if ((x+y)== 4)
        // {
            
        //     scene->map[x][y].structure=2; 
        //     scene->map[x][y].effect=-1;
        // scene->map[x][y].radius=1;
        // }
        
        
    }
    
}




    
}

void set_lighting()
{
    float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double elapsed_time)
{
    scene->rotation += 36*elapsed_time;
    
    for (int x = 0; x < MAP_WIDTH ; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            if (scene->map[x][y].structure!=0)
            {
                /* code */
            //TODO: ha az adot ponton lévő objektum nem lakóépület, akkor a körülötte lévő lakóépületek bonuszát csökkentse vagy növelje 

            //TODO: megnézzük a távolságot
                double distance =check_distance(GRID_SOMETHING*x,GRID_SOMETHING*y,GRID_SOMETHING*1,GRID_SOMETHING*x,GRID_SOMETHING*y);
                if (distance<0)
                {
                    // printf("cube %d is in the circle\n",i);
                    // scene->cubes[i].bonus= scene->cubes[i].bonus+1;
                    // printf("cube %d  current bonus: %d\n",i,scene->cubes[i].bonus);
                    // update_plot(scene->cubes[i]);
                }
            //TODO: ha a távolság rendben, megnézzük ott milyen épület van
            //TODO: update-eljük színt    








            }
        }
    }
    
    

}

void render_scene(const Scene* scene)
{
    // set_material(&(scene->material));
    set_lighting();
    draw_origin();
    draw_Moon_circle(62.5,62.5, 0.0,150.0);
    for (int i = 0; i < MAP_WIDTH; i++)
    {
        
        for (int j = 0; j < MAP_HEIGHT; j++)
        {
        
        glPushMatrix();
        
        glTranslatef(i*25, j*25,0);
        draw_Circle(i*25,j*25,0,25*scene->map[i][j].radius);
        //DRAW MAP 
        switch (scene->map[i][j].structure)
        {
        case 0:
            glColor3f(0.5, 0.5, 0.5);
            draw_model(&(scene->cube));
            break;
        case 1:
            glColor3f(0, 1, 0);
            draw_model(&(scene->templePlot));
            break;
        case 2: 
            glColor3f(1,0,0);
            draw_model(&(scene->factoryPlot));
            break;
        default:
            break;
        }
        



        glPopMatrix();
        
        
            /* code */
        }   /* code */
    
    }
    // for (int i = 0; i < 9; i++)
    // {
    //     glPushMatrix();
    //     glTranslatef(0.55+i*1.1,-0.45,-0.45) ;
    //     glScalef(0.1,0.1,0.1);
    //     draw_model(&(scene->cube));
    //     glPopMatrix();    /* code */
    // }
    
    
    
    
    
}

void draw_origin()
{


    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}


void draw_Circle( double x, double y, double z, double radius){

    double angle;
    glPointSize(2);
    glBegin( GL_POINTS);
    glColor3f(0.5,0.5,0.5);
 for (angle = 0.0; angle <= (2.0 * M_PI); angle += 0.01)
 {
 x = radius * sin(angle);
 y = radius * cos(angle);
 glVertex3f(x, y, z);
 }
//  glPushMatrix();
//  glTranslatef(x,y,z);
//  draw_model(&(scene->sphere));
//  glPopMatrix();
 glEnd();
}

void draw_Moon_circle( double x, double y, double z, double radius){

    double angle;
    glPointSize(2);
    glBegin( GL_POINTS);
    glColor3f(1,0,0);
 for (angle = 0.0; angle <= (2.0 * M_PI); angle += 0.01)
 {
 x = radius * sin(angle);
 z = radius * cos(angle);
 glVertex3f(x, y, z);
 }
//  glPushMatrix();
//  glTranslatef(x,y,z);
//  draw_model(&(scene->sphere));
//  glPopMatrix();
 glEnd();
}
