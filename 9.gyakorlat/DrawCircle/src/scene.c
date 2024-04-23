#include "scene.h"
#include "math.h"
#include "utils.h"
#include "plot.h"
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    // scene->rotation =0;
    // load_model(&(scene->cube), "assets/models/cube.obj");
    // load_model(&(scene->cityBlock), "assets/models/City_Block.obj");
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
    
    scene->cubes[0].x1=3;
    scene->cubes[0].x2=7;
    scene->cubes[0].y1=3;
    scene->cubes[0].y2=7;
    scene->cubes[1].x1=-1;
    scene->cubes[1].x2=-2;
    scene->cubes[1].y1=-1;
    scene->cubes[1].y2=-2;
    scene->cubes[2].x1=-2;
    scene->cubes[2].x2=-4;
    scene->cubes[2].y1=2;
    scene->cubes[2].y2=4;
    
}

void set_lighting()
{
    // float ambient_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    // float diffuse_light[] = { 1.0f, 1.0f, 1.0, 1.0f };
    // float specular_light[] = { 0.0f, 0.0f, 0.0f, 1.0f };
    // float position[] = { 0.0f, 0.0f, 10.0f, 1.0f };

    // glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    // glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    // glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    // glLightfv(GL_LIGHT0, GL_POSITION, position);
}

void set_material(const Material* material)
{
    // float ambient_material_color[] = {
    //     material->ambient.red,
    //     material->ambient.green,
    //     material->ambient.blue
    // };

    // float diffuse_material_color[] = {
    //     material->diffuse.red,
    //     material->diffuse.green,
    //     material->diffuse.blue
    // };

    // float specular_material_color[] = {
    //     material->specular.red,
    //     material->specular.green,
    //     material->specular.blue
    // };

    // glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    // glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    // glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    // glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

void update_scene(Scene* scene, double elapsed_time)
{
    scene->rotation += 36*elapsed_time;
    for(int i=0; i<3; i++ ){

    scene->cubes[i].bonus=0;
    double middle_x;
    double middle_y;
    get_midlepoint(&scene->cubes[i],&middle_x, &middle_y);
    double distance =check_distance(0,0,5,middle_x,middle_y);
    if (distance<0)
    {
        // printf("cube %d is in the circle\n",i);
        scene->cubes[i].bonus= scene->cubes[i].bonus+1;
        // printf("cube %d  current bonus: %d\n",i,scene->cubes[i].bonus);
        // update_plot(scene->cubes[i]);
    }
    }
    
    
    
    

}

void render_scene(const Scene* scene)
{
    
    // set_material(&(scene->material));
    // set_lighting();
    draw_origin();
    draw_Circle(0,0,5.0);
    printf(" cubes bonus %d \n",scene->cubes[1].bonus );
    draw_plot(scene->cubes[0]);
    draw_plot(scene->cubes[1]);
    draw_plot(scene->cubes[2]);
    
    // for (int i = 0; i < 1; i++)
    // {
        
    //     for (int j = 0; j < 1; j++)
    //     {
        
    //     glPushMatrix();
    //     // glRotatef(i*10,0,0,36);
    //     glTranslatef(i*1.1, j*1.1,0);
    //     // glScalef(0.1,0.1,0.1);
    //     // printf("%lf  %lf \n",sin(scene->rotation), scene->rotation );
        
    //     //forgatás
    //      //glRotatef(i*j*10, 0,0,1);
        
    //     //kicsinyit
    //     //  glRotatef(scene->rotation, 0,0,0);
    //     // glRotatef(scene->rotation, 0,0,1);
    //     draw_model(&(scene->cityBlock));
    //     glPopMatrix();
        
        
    //         /* code */
    //     }   /* code */
    
    // }
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

void draw_Circle( double x,double y, double radius){

    double angle;
    glPointSize(2);
    glBegin( GL_POINTS);
    glColor3f(0,0,1);
 for (angle = 0.0; angle <= (2.0 * M_PI); angle += 0.01)
 {
 x = radius * sin(angle);
 y = radius * cos(angle);
 glVertex3f(x, y, 0.0);
 }
 glEnd();
}
