#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
void windowInit();
void display();
void keybd(unsigned char key, int x, int y);
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    //init window
    windowInit();
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
    glutKeyboardFunc(keybd);
    glutDisplayFunc(display);
    glutMainLoop();
    return(0);
}
void windowInit(){
    int width = 500, height = 500;
    float aspect = (float)width / (float) height;
    glutInitWindowPosition(200,500);
    glutInitWindowSize(width, height);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DEPTH);
    glutCreateWindow("cylinder");
    glClearColor(1.0,1.0,1.0,1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-1, 1.0, -1.0, 1.0, -1.0, 1.0);
    gluPerspective(30.0,aspect,1.0,50.0);
    //glMatrixMode(GL_MODELVIEW);
}

void keybd(unsigned char key, int x, int y){
    exit(0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLUquadricObj *quadricObj = gluNewQuadric();
    gluQuadricDrawStyle(quadricObj, GLU_FLAT);
    float cy_hight = 0.5;
    //gltDrawUnitAxes();
    glTranslatef(0.0, 0.0, -1.8);

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
    glFlush();
}
