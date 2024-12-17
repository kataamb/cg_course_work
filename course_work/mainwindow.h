#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>

#include <QMessageBox>

//#include <QObject>
#include "renderer.h"
#include "scene.h"
#include "gamemanager.h"

#include "gamecheckcolor.h"

#include "performancetester.h"

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

    void runPerformanceTest();

private:
    Ui::MainWindow *ui;
    QImage *img;
    QPixmap *pxmp;
    int imWidth;
    int imHeight;

    Renderer *renderer;
    Scene *scene;
    GameManager *gameManager;

    std::pair<int, int> convertPosition(std::pair<char, int> position);

private slots:
    void onRotateButtonClicked();
    //------------------
    void onMakeMoveButtonClicked();
    //------------------
    void updateScene();      // метод для перерисовки сцены
    //-----------------
    void onGameInitialStateButtonClicked();

signals:

};
#endif // MAINWINDOW_H
