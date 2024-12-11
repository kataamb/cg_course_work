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

    // Подключаем сигналы от спинбоксов к слоту
       /*connect(ui->angleX, SIGNAL(valueChanged(double)), this, SLOT(onAnglesChanged()));
       connect(ui->angleY, SIGNAL(valueChanged(double)), this, SLOT(onAnglesChanged()));
       connect(ui->angleZ, SIGNAL(valueChanged(double)), this, SLOT(onAnglesChanged()));
       */

       connect(ui->buttonRotate, &QPushButton::clicked, this, &MainWindow::onRotateButtonClicked);


}

/*void MainWindow::onAnglesChanged()
{
    // Получаем значения углов
    float angleX = ui->angleX->value();
    float angleY = ui->angleY->value();
    float angleZ = ui->angleZ->value();

    // Поворачиваем все модели
    QVector3D angle = {angleX, angleY, angleZ};
    this->scene->rotate_composition(angle);

    // Обновляем сцену
    updateScene();
}*/

void MainWindow::onRotateButtonClicked()
{
    // Получаем значения углов
    float angleX = ui->angleX->value();
    float angleY = ui->angleY->value();
    float angleZ = ui->angleZ->value();

    // Поворачиваем все модели
    QVector3D angle = {angleX, angleY, angleZ};
    this->scene->rotate_composition(angle);

    // Обновляем сцену
    updateScene();
}

void MainWindow::updateScene()
{
    // Очищаем изображение
    img->fill(QColor(212, 116, 121));
    *pxmp = QPixmap::fromImage(*img);

    // Перерисовываем сцену
    Light light = scene->get_light_sources();
    renderer->render_all_models(pxmp, scene->get_all_models(), light);
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

