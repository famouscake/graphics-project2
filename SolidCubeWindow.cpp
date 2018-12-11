#include "SolidCubeWindow.h"

// constructor / destructor
SolidCubeWindow::SolidCubeWindow(QWidget *parent)
    : QWidget(parent)
{ // constructor

    // create menu bar
    menuBar = new QMenuBar(this);

    // create file menu
    fileMenu = menuBar->addMenu("&File");

    // create the action
    actionQuit = new QAction("&Quit", this);

    // leave signals & slots to the controller

    // add the item to the menu
    fileMenu->addAction(actionQuit);

    // create the window layout
    windowLayout = new QBoxLayout(QBoxLayout::TopToBottom, this);

    // create main widget
    cubeWidget = new SolidCubeWidget(this);
    windowLayout->addWidget(cubeWidget);

    // create slider
    nVerticesSlider = new QSlider(Qt::Horizontal);
    windowLayout->addWidget(nVerticesSlider);


    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, cubeWidget, [=](){ cubeWidget->angle += 0.1; cubeWidget->update();});
    timer->start(1);



} // constructor

SolidCubeWindow::~SolidCubeWindow()
{ // destructor
    delete nVerticesSlider;
    delete cubeWidget;
    delete windowLayout;
    delete actionQuit;
    delete fileMenu;
    delete menuBar;
} // destructor

// resets all the interface elements
void SolidCubeWindow::ResetInterface()
{ // ResetInterface()

    nVerticesSlider->setMinimum(3);
    nVerticesSlider->setMaximum(30);

    //don't use the slider for now

    //	nVerticesSlider->setValue(thePolygon->nVertices);

    // now force refresh
    cubeWidget->update();
    update();
} // ResetInterface()
