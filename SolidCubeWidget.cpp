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
    27.8 
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



} // initializeGL()


// called every time the widget is resized
void SolidCubeWidget::resizeGL(int w, int h)
{ // resizeGL()
    // set the viewport to the entire widget
    glViewport(0, 0, w, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //GLfloat light_pos[] = {0., 0., 10., 1.};	
    //glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    //glLightf (GL_LIGHT0, GL_SPOT_CUTOFF,15.);

    glShadeModel(GL_SMOOTH);


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-4.0, 4.0, -4.0, 4.0, 0, 4000.0);
    //glFrustum(-4.0, 4.0, -4.0, 4.0, 0, 4000.0);
    gluPerspective(100, 16/9, 2, 100);

} // resizeGL()


void SolidCubeWidget::cube(){

    //glutSolidSphere(5., 200, 200);

    //glMatrixMode(GL_MODELVIEW);
    //glRotatef(this->angle, 1., 1., 1.);


    // Here are the normals, correctly calculated for the cube faces below  
    GLfloat normals[][3] = { {1., 0. ,0.}, {-1., 0., 0.}, {0., 0., 1.}, {0., 0., -1.} };

    // Here we give every face the same normal
    //GLfloat normals[][3] = { {0.333, 0.333, 0.333 }, {0.333, 0.333, 0.333}, {0.333, 0.333, 0.333}, {0.3333, 0.3333, 0.333}};

    // Here we have permuted the first normal array
    // GLfloat normals[][3] = {  {-1., 0., 0.}, {0., 0., 1.}, {1., 0. ,0.}, {0., 0., -1.} };

    materialStruct* p_front = &brassMaterials;
    glMaterialfv(GL_FRONT, GL_AMBIENT,    p_front->ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,    p_front->diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,   p_front->specular);
    glMaterialf(GL_FRONT, GL_SHININESS,   p_front->shininess);

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

    glNormal3fv(normals[1]);
    glBegin(GL_POLYGON);

    glVertex3f( 100.0,  100.0, -10.0);

    glVertex3f( -100.0, 100.0, -10.0);

    glVertex3f( -100.0, -100.0,  -10.0);

    glVertex3f( 100.0, -100.0,  -10.0);
    glEnd();

}

// called every time the widget needs painting
void SolidCubeWidget::paintGL()
{ // paintGL()
    // clear the widget
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // You must set the matrix mode to model view directly before enabling the depth test

    glEnable(GL_DEPTH_TEST); // comment out depth test to observe the result                                                                                                    


    glPushMatrix();
    glLoadIdentity();

    GLfloat light_pos[] = {20., 20., 20., 1.};

    //GLfloat spot_direction[] = { .0, .0, 1.0 };
    //GLfloat spot_direction[] = { .0, .0, .0 };
    
    //GLfloat light_pos[] = {10 * qSin(this->angle), 10 * qCos(this->angle), 0., 1.};
    //GLfloat spot_direction[] = {-light_pos[0], -light_pos[1], -light_pos[2]};

    //GLfloat spot_direction[] = {light_pos[0], light_pos[1], light_pos[2]};
    //GLfloat spot_direction[] = {0., 0., -1.};

    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
    //glLightf (GL_LIGHT0, GL_SPOT_CUTOFF, 180);
    //glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_direction);

    glPopMatrix();




    glPushMatrix();

    //glTranslatef(light_pos[0], light_pos[1], light_pos[2]);
    //glutSolidSphere(1, 20, 20);

    glPopMatrix();



    this->cube();
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 50., 0.0,0.0,0.0, 0.0,1.0,0.0);

    //gluLookAt(qSin(this->angle),1.,qCos(this->angle), 0.0,0.0,0.0, 0.0,1.0,0.0);

    // flush to screen
    glFlush();	

} // paintGL()
