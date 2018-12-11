#include <GL/glu.h>
#include <GL/glut.h>
#include <QGLWidget>
#include <QtMath>
#include "SolidCubeWidget.h"


// Setting up material properties
typedef struct materialStruct {
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat shininess;
} materialStruct;


static materialStruct brassMaterials = {
    { 0.33, 0.22, 0.03, 1.0},
    { 0.78, 0.57, 0.11, 1.0},
    { 0.99, 0.91, 0.81, 1.0},
    20
};

static materialStruct whiteShinyMaterials = {
    { 1.0, 1.0, 1.0, 1.0},
    { 1.0, 1.0, 1.0, 1.0},
    { 1.0, 1.0, 1.0, 1.0},
    100.0 
};


// constructor
SolidCubeWidget::SolidCubeWidget(QWidget *parent)
    : QGLWidget(parent)
{ // constructor


} // constructor

// called when OpenGL context is set up
void SolidCubeWidget::initializeGL()
{ // initializeGL()
    // set the widget background colour
    glClearColor(0.3, 0.3, 0.3, 0.0);
    glShadeModel(GL_SMOOTH);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(70, 1, 2, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

} // initializeGL()


// called every time the widget is resized
void SolidCubeWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}

void SolidCubeWidget::coordinateSystem()
{
    // At (0, 0, 0)
    //glutSolidSphere(0.5, 20, 20);

    // At (1, 0, 0)
    glPushMatrix();
    {
        glTranslatef(3.0, 0.0, 0.0);
        glutSolidSphere(0.2, 20, 20);
    }
    glPopMatrix();


    // At (0, 1, 0)
    glPushMatrix();
    {
        glTranslatef(0.0, 3.0, 0.0);
        glutSolidSphere(0.2, 20, 20);
    }
    glPopMatrix();


    // At (0, 0, 1)
    glPushMatrix();
    {
        glTranslatef(0.0, 0.0, 3.0);
        glutSolidSphere(0.2, 20, 20);
    }
    glPopMatrix();






    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    //glRotatef(90.0f, 0.0f, 1.0f, 0.0f);

    gluCylinder(quadratic, 0.1f, 0.1f, 3.0f, 32, 32);

    glPushMatrix();
    {
        glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
        gluCylinder(quadratic, 0.1f, 0.1f, 3.0f, 32, 32);
    }
    glPopMatrix();

    glPushMatrix();
    {
        glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
        gluCylinder(quadratic, 0.1f, 0.1f, 3.0f, 32, 32);
    }
    glPopMatrix();

}


void SolidCubeWidget::maySpheres()
{
    glPushMatrix(); {

        glRotatef(this->angle * 10, 0, 5, 0);
        glTranslatef(5, 0, 0);
        glutSolidSphere(2, 200, 200);

        glPushMatrix(); {

            glRotatef(this->angle * 10, 0, 5, 0);
            glTranslatef(5, 0, 0);
            glutSolidSphere(2, 200, 200);

            glPushMatrix(); {
                glRotatef(this->angle * 10, 0, 5, 0);
                glTranslatef(5, 0, 0);
                glutSolidSphere(2, 200, 200);
            } glPopMatrix();

        } glPopMatrix();


        glRotatef(this->angle * 10, 0, 5, 0);
        glTranslatef(5, 0, 0);
        glutSolidSphere(2, 200, 200);

    } glPopMatrix();
}

void SolidCubeWidget::cube()
{
    materialStruct* p_front = &brassMaterials;


    glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

    GLfloat mat_emission[] = {0., 0., 0., 0.0};
    glMaterialfv(GL_FRONT, GL_EMISSION,   mat_emission);

    //glRotatef(this->angle, 1, 1, 1);


    //glTranslatef(0, 5, 0);
    //glutSolidCube(1);
    glutSolidSphere(2, 200, 200);

    //glTranslatef(0, -5, 0);

    //glLoadIdentity();
    
    //GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };
    
    GLfloat n[] = {0., 1., 0.};

    //glTranslatef(0, -10, 0);
    //glNormal3fv(n);
    //glBegin(GL_POLYGON);
    //glVertex3f( 30.0, 0.0,  30.0);
    //glVertex3f( 30.0, 0.0,  -30.0);
    //glVertex3f( -30.0, 0.0,  -30.0);
    //glVertex3f( -30.0, 0.0,  30.0);
    //glEnd();


    return;


    // Here are the normals, correctly calculated for the cube faces below  
    //GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

    //// Here we give every face the same normal
    ////GLfloat normals[][3] = { {0.333, 0.333, 0.333 }, {0.333, 0.333, 0.333}, {0.333, 0.333, 0.333}, {0.3333, 0.3333, 0.333}};

    //// Here we have permuted the first normal array
    //// GLfloat normals[][3] = {  {-1., 0., 0.}, {0., 0., 1.}, {1., 0. ,0.}, {0., 0., -1.} };

    //materialStruct* p_front = &brassMaterials;

    //glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
    //glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
    //glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
    //glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

    //glNormal3fv(normals[0]);
    //glBegin(GL_POLYGON);
    //glVertex3f( 1.0, -1.0,  1.0);
    //glVertex3f( 1.0, -1.0, -1.0);
    //glVertex3f( 1.0,  1.0, -1.0);
    //glVertex3f( 1.0,  1.0,  1.0);
    //glEnd();

    //glNormal3fv(normals[3]); 
    //glBegin(GL_POLYGON);
    //glVertex3f(-1.0, -1.0, -1.0);
    //glVertex3f( 1.0, -1.0, -1.0);
    //glVertex3f( 1.0,  1.0, -1.0);
    //glVertex3f(-1.0,  1.0, -1.0);
    //glEnd();

    //glNormal3fv(normals[2]); 
    //glBegin(GL_POLYGON);
    //glVertex3f(-1.0, -1.0, 1.0);
    //glVertex3f( 1.0, -1.0, 1.0);
    //glVertex3f( 1.0,  1.0, 1.0);
    //glVertex3f(-1.0,  1.0, 1.0);
    //glEnd();

    //glNormal3fv(normals[1]);
    //glBegin(GL_POLYGON);
    //glVertex3f( -1.0, -1.0,  1.0);
    //glVertex3f( -1.0, -1.0, -1.0);
    //glVertex3f( -1.0,  1.0, -1.0);
    //glVertex3f( -1.0,  1.0,  1.0);
    //glEnd();

}

// called every time the widget needs painting
void SolidCubeWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // You must set the matrix mode to model view directly before enabling the depth test
    glEnable(GL_DEPTH_TEST);


    GLfloat eye[] = {0., 0., 20.};


    glPushMatrix();
    {
        //glLoadIdentity();

        //glRotatef(this->angle * 10, 0, 1, 0);
        glTranslatef(-10, 0, 0);

        GLfloat light_pos[] = {0., 0., 0., 1.};
        //GLfloat light_dir[] = {0., 0., 0.};
        glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
        glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 180);
        //glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_dir);


        //GLfloat mat_emission[] = {0, 0., 1, 1.0};
        //glMaterialfv(GL_FRONT, GL_EMISSION,   mat_emission);
        glMaterialf(GL_FRONT, GL_AMBIENT,   1);
        glPushMatrix();
        glTranslatef(-1*this->angle/10, 0, 0);
        glutSolidSphere(1, 20, 20);
        glPopMatrix();
    }
    glPopMatrix();



    this->coordinateSystem();
    this->cube();


    this->maySpheres();


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glRotatef(90.0, 1., 0., 0.);

    //gluLookAt(20 * qSin(this->angle), 0, 20 * qCos(this->angle), 0.0,0.0,0.0, 0.0,1.0,0.0);

    gluLookAt(15, 15, 15, 0.0,0.0,0.0, 0.0,1.0,0.0);


    // flush to screen
    glFlush();	

} // paintGL()
