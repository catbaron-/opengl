#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <GL/gl.h>

void display();
static void keybd(GLFWwindow* window, int key, int scancode, int action,int mods);
int main(int argc, char** argv)
{
    int width = 500, height = 600;
    float aspect = (float)width / (float) height;

    //init window
    if(!glfwInit())
        exit(EXIT_FAILURE);
    //create window
    GLFWwindow* window ;
    window = glfwCreateWindow(width, height, "cylinder", NULL, NULL);
    if(!window)
    {
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, keybd);
    glfwSwapBuffers(window);
    glfwSwapInterval(1);

    //Main Window Loop
    while(!glfwWindowShouldClose(window))
    {
        glClearColor(1.0,1.0,1.0,1.0);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        //glOrtho(-1, 1.0, -1.0, 1.0, -1.0, 1.0);
        gluPerspective(30.0,aspect,1.0,50.0);
        glMatrixMode(GL_MODELVIEW);
        //enable depth and cull_face
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glFrontFace(GL_CCW);

        //enable light
        GLfloat whiteLight[] = {0.05f, 0.05f, 0.05f, 1.0f};
        GLfloat sourceLight[] = {0.25f, 0.25f, 0.25f, 1.0f};
        GLfloat lightPos[] = {-5.0f, 15.0f, 5.0f, 1.0f};
        glEnable(GL_LIGHTING);
        glLightModelfv(GL_LIGHT_MODEL_AMBIENT, whiteLight);
        glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, sourceLight);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
        glEnable(GL_LIGHT0); //开启颜色追踪 
        glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
        glEnable(GL_COLOR_MATERIAL);


        //glViewport(0,0,width,height);
        display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwDestroyWindow(window);
    glfwTerminate();
    
    return(0);
}
static void keybd(GLFWwindow* window, int key, int scancode, int action,int mods){
    exit(0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLUquadricObj *quadricObj = gluNewQuadric();
    gluQuadricDrawStyle(quadricObj, GLU_FLAT);
    float cy_hight = 0.5;
    //gltDrawUnitAxes();

    glPushMatrix();
    glTranslatef(0.0, 0.0, -3.5);

    glPushMatrix();
    glRotatef(90, 1, 0, 0);

    glTranslatef(0.0, 0.0, -0.5*cy_hight);
    glColor3f(0.5, 0.8, 0.1);
    gluCylinder(quadricObj, 0.2, 0.2, cy_hight, 50, 13);

    glTranslatef(0.0, 0.0, cy_hight);
    glColor3f(0.7, 0.5, 0.3);
    gluCylinder(quadricObj, 0.2, 0.2, cy_hight, 50, 13);

    glTranslatef(0.0, 0.0, -2*cy_hight);
    glColor3f(0.3, 0.2, 0.7);
    gluCylinder(quadricObj, 0.2, 0.2, cy_hight, 50, 13);
    glPopMatrix();
    glPopMatrix();
    glFlush();
}
