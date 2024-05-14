#include "scene.h"
#include "math.h"
#include "blocks.h"

#include <obj/load.h>
#include <obj/draw.h>
#include <GL/glu.h>
#include <stdio.h>

#define PICK_BUFFER_SIZE 256

void init_scene(Scene* scene)
{
    scene->effect_colors[0].red=0.8;
    scene->effect_colors[0].green=0.2;
    scene->effect_colors[0].blue=0.2;

    scene->effect_colors[1].red=0.7;
    scene->effect_colors[1].green=0.3;
    scene->effect_colors[1].blue=0.3;
    
    scene->effect_colors[2].red=0.6;
    scene->effect_colors[2].green=0.4;
    scene->effect_colors[2].blue=0.4;
    
    scene->effect_colors[3].red=0.5;
    scene->effect_colors[3].green=0.5;
    scene->effect_colors[3].blue=0.5;
    
    scene->effect_colors[4].red=0.4;
    scene->effect_colors[4].green=0.6;
    scene->effect_colors[4].blue=0.4;
    
    scene->effect_colors[5].red=0.3;
    scene->effect_colors[5].green=0.7;
    scene->effect_colors[5].blue=0.3;
    
    scene->effect_colors[6].red=0.2;
    scene->effect_colors[6].green=0.8;
    scene->effect_colors[6].blue=0.2;

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
        //   scene->map[x][y].structure=rand() % (2 + 1 - 0) + 0;
        // if(x==y && x<2){
        //     scene->map[x][y].structure=1;
        // }else{
        //     scene->map[x][y].structure=0;
        // }
        scene->map[x][y].structure=0;

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
            if(scene->map[x][y].structure==0){
                scene->map[x][y].bonus=0;
            }}}
    //végigmegyek a MAP-on
    for (int x = 0; x < MAP_WIDTH ; x++)
    {
        for (int y = 0; y < MAP_HEIGHT; y++)
        {
            
            //Ha nem lakóépületen állok
            if (scene->map[x][y].structure!=0)
            {
              
            //akkor megnézem az adott épüóletnek a közelségét
            double radius = scene->map[x][y].radius;
            
            //ezena távon megnézem minden irányba hogy mekkor aa körülötte lévők távolsága tőle
                for(int i= -radius ; i<=radius; i++){
                    for(int j = -radius; j<=radius;j++){
                        double distance =check_distance(x,y,radius,x+i,y+j);
                        // printf("%d %d -től distance: %f  radius: %f  nézett pont: %d , %d , i: %d j: %d\n",x,y, distance,radius, x+i,y+j,i,j);
                        if(distance<=radius){
                            if(scene->map[x+i][y+j].structure==0)
                            {
                                
                                scene->map[x+i][y+j].bonus+= scene->map[x][y].effect;   
                                // printf("valtozott a bonus x:%d, y:%d   helyen %d-re\n", x+i,y+j,scene->map[x+i][y+j].bonus);
                            }
                        }
                    }
                }
            }
                // printf("%d ,%d koordinátának %d bunusza van\n",x,y,scene->map[x][y].bonus);
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
        printf(" structure x: %d, y: %d\n", i*25,j*25);
        // draw_Circle(i*25,j*25,0,25*scene->map[i][j].radius);
        //DRAW MAP 
        switch (scene->map[i][j].structure)
        {
        case 0:
            switch (scene->map[i][j].bonus)
            {
            case -3:
                glColor3f(scene->effect_colors[0].red,scene->effect_colors[0].green,scene->effect_colors[0].blue);
                break;
            case -2:
                glColor3f(scene->effect_colors[1].red,scene->effect_colors[1].green,scene->effect_colors[1].blue);
                break;
            case -1:
                glColor3f(scene->effect_colors[2].red,scene->effect_colors[2].green,scene->effect_colors[2].blue);
                break;
            case 0:
                glColor3f(scene->effect_colors[3].red,scene->effect_colors[3].green,scene->effect_colors[3].blue);
                break;
            case 1:
                glColor3f(scene->effect_colors[4].red,scene->effect_colors[4].green,scene->effect_colors[4].blue);
                break;
            case 2:
                glColor3f(scene->effect_colors[5].red,scene->effect_colors[5].green,scene->effect_colors[5].blue);
                break;
            case 3:
                glColor3f(scene->effect_colors[6].red,scene->effect_colors[6].green,scene->effect_colors[6].blue);
                break;
            default:
                break;
            }
            // printf("%d a bonusza: %d, %d-nek\n",scene->map[i][j].bonus, i,j );
             
            draw_model(&(scene->cityPlot));
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
        }   /* code */
    
    }
      
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
unsigned int find_object_on_scene(const Scene* scene, int x, int y)
{
    unsigned int pick_buffer[PICK_BUFFER_SIZE];

    glSelectBuffer(PICK_BUFFER_SIZE, pick_buffer);

    glRenderMode(GL_SELECT);
    glInitNames();
    glPushName(BACKGROUND);
    // NOTE: Lighting, shading and texturing can be disabled for better performance.

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(-(0 + 90), 1.0, 0, 0);
    glRotatef(-(0 - 90), 0, 0, 1.0);
    glTranslatef(0, 0, -1);
    glPushMatrix();
    render_scene(scene);
    glPopMatrix();

    GLint depth;
    glGetIntegerv(GL_NAME_STACK_DEPTH, &depth);
    printf("Depth: %d\n", depth);

    GLint n_hits = glRenderMode(GL_RENDER);
    printf("Number of hits: %d\n", n_hits);

    for (int i = 0; i < n_hits; ++i) {
        int n_items = pick_buffer[i + 0];
        printf("----\n");
        printf("Hit %d\n", i);
        printf("nitems : %d\n", n_items);
        printf("zmin   : %d\n", pick_buffer[i + 1]);
        printf("zmax   : %d\n", pick_buffer[i + 2]);
        for (int j = 0; j < n_items; ++j) {
            printf("- item %d\n", pick_buffer[3 + j]);
        }
        // A kattintási pont helyzetének visszaszerzése a térben
        GLint viewport[4];
        GLdouble modelview[16], projection[16];
        GLfloat winX, winY, winZ;
        GLdouble posX, posY, posZ;

        glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
        glGetDoublev(GL_PROJECTION_MATRIX, projection);
        glGetIntegerv(GL_VIEWPORT, viewport);

        winX = (float)x;
        winY = (float)viewport[3] - (float)y;
        glReadPixels(x, (GLint)winY, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

        gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

        printf("Object position: (%f, %f, %f)\n", posX, posY, posZ);
    }
    printf("\n");

    return 234;
}

