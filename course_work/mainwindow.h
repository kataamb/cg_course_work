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

private:
    Ui::MainWindow *ui;
    QImage *img;
    QPixmap *pxmp;

    Renderer *renderer;

    Scene *scene;
    Camera *camera;
signals:
    void change_image_signal(QPixmap *, QColor );
    void draw_initial_image_signal(QPixmap *);
};
#endif // MAINWINDOW_H
