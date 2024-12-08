#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>


#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->imWidth = 9669;
    this->imHeight = 1079;
    img = new QImage(9669, 1079, QImage::Format_ARGB32);
    img->fill(QColor(	212, 116, 121)); //141,  29,  44       255,239,213

    //ui->labelView->setPixmap( QPixmap::fromImage(*img) );
    pxmp = new QPixmap(  QPixmap::fromImage(*img) );
    renderer = new Renderer;
    scene = new Scene;
    //object (of class) to

    renderer->draw_initial_image(pxmp, scene->get_all_models(), scene->get_light_sources());//method to draw image
    ui->labelView->setPixmap(*pxmp);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete img;
    delete pxmp;
    delete renderer;

    delete scene;
}

