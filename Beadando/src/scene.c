#include "scene.h"
#include "math.h"
#include <obj/load.h>
#include <obj/draw.h>

void init_scene(Scene* scene)
{
    scene->rotation =0;
    load_model(&(scene->cube), "assets/models/cube.obj");
    load_model(&(scene->cityBlock), "assets/models/City_Block.obj");
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
    
    
    
    

}

void render_scene(const Scene* scene)
{
    // set_material(&(scene->material));
    set_lighting();
    draw_origin();
    for (int i = 0; i < 1; i++)
    {
        
        for (int j = 0; j < 1; j++)
        {
        
        glPushMatrix();
        // glRotatef(i*10,0,0,36);
        glTranslatef(i*1.1, j*1.1,0);
        // glScalef(0.1,0.1,0.1);
        // printf("%lf  %lf \n",sin(scene->rotation), scene->rotation );
        
        //forgatás
         //glRotatef(i*j*10, 0,0,1);
        
        //kicsinyit
        //  glRotatef(scene->rotation, 0,0,0);
        // glRotatef(scene->rotation, 0,0,1);
        draw_model(&(scene->cityBlock));
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
