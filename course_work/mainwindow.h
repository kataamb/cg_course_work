#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>

//#include <QObject>
#include "renderer.h"
#include "scene.h"
#include "camera.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int getWidth(){return imWidth;}
    int getHeight(){return imHeight;}

private:
    Ui::MainWindow *ui;
    QImage *img;
    QPixmap *pxmp;
    int imWidth;
    int imHeight;

    Renderer *renderer;
    Scene *scene;
    Camera *camera;

private slots:
    //void onAnglesChanged();  // новый слот для обработки изменения углов
    void onRotateButtonClicked();
    void updateScene();      // метод для перерисовки сцены


signals:

};
#endif // MAINWINDOW_H
