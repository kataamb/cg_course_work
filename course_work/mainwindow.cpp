#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColor>

#include "gamecheck.h"

#include <iostream>
   #include <QDir>

void printCurrentWorkingDirectory() {
       QString currentDir = QDir::currentPath();
       std::cout << "Current working directory: " << currentDir.toStdString() << std::endl;
   }

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->imWidth = 9669;
    this->imHeight = 1079;
    img = new QImage(9669, 1079, QImage::Format_ARGB32);
    img->fill(QColor(	212, 116, 121)); //141,  29,  44       255,239,213

    pxmp = new QPixmap(  QPixmap::fromImage(*img) );
    renderer = new Renderer;
    scene = new Scene;
    gameManager = new GameManager;

    renderer->draw_initial_image(pxmp, scene->get_all_models(), scene->get_light_sources());//method to draw image
    ui->labelView->setPixmap(*pxmp);

    connect(ui->buttonRotate, &QPushButton::clicked, this, &MainWindow::onRotateButtonClicked);
    connect(ui->makeMoveButton, &QPushButton::clicked, this, &MainWindow::onMakeMoveButtonClicked);

    connect(ui->gameInitialStateButton, &QPushButton::clicked, this, &MainWindow::onGameInitialStateButtonClicked);

    //runPerformanceTest(); // make measures
    //printCurrentWorkingDirectory();

}

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

std::pair<int, int> MainWindow::convertPosition(std::pair<char, int> position) {
        char letter = position.first; // Приводим к нижнему регистру
        int number = position.second;// Получаем цифру


        // Преобразуем букву в индекс столбца (7-0)
        int col = 7 - (letter - 'a'); // 'a' соответствует 7, 'b' - 6, ..., 'h' - 0
        // Преобразуем цифру в индекс строки (0-7)
        int row = number - 1; // 1 соответствует 0, 2 - 1, ..., 8 - 7

        return {row, col}; // Возвращаем пару (строка, столбец)
   }

void MainWindow::onGameInitialStateButtonClicked() {

    std::cout << "here on btn clicked" <<std::endl;

    gameManager->return_initial_game(); //
    this->scene->update_scene_with_checks(this->gameManager->checksOnPositions);
    updateScene(); // Обновляем сцену после сброса
}

void MainWindow::onMakeMoveButtonClicked() {
    // Получаем значения из QLineEdit и QSpinBox
    QString curPosLetter = ui->curPosLetter->text();
    int currPosNumber = ui->currPosNumber->value();
    QString nextPosLetter = ui->nextPosLetter->text();
    int nextPosNumber = ui->nextPosNumber->value();

    // Проверяем, что буква от 'a' до 'h'
    if (curPosLetter.length() != 1 || !curPosLetter.contains(QRegExp("[a-h]"))) {
        QMessageBox::warning(this, "Ошибка", "Текущая позиция: буква должна быть от 'a' до 'h'.");
        return;
    }

    // Проверяем, что номер от 1 до 8
    if (currPosNumber < 1 || currPosNumber > 8) {
        QMessageBox::warning(this, "Ошибка", "Текущая позиция: номер должен быть от 1 до 8.");
        return;
    }

    // Проверяем, что следующая буква от 'a' до 'h'
    if (nextPosLetter.length() != 1 || !nextPosLetter.contains(QRegExp("[a-h]"))) {
        QMessageBox::warning(this, "Ошибка", "Следующая позиция: буква должна быть от 'a' до 'h'.");
        return;
    }

    // Проверяем, что следующий номер от 1 до 8
    if (nextPosNumber < 1 || nextPosNumber > 8) {
        QMessageBox::warning(this, "Ошибка", "Следующая позиция: номер должен быть от 1 до 8.");
        return;
    }


    QChar firstChar = curPosLetter[0];
    char curLetter = firstChar.toLatin1();

    QChar c2 = nextPosLetter[0];
    char nextLetter = c2.toLatin1();

    // Если все проверки пройдены, можно продолжать с полученными значениями

    // Здесь можно добавить логику для перемещения шашки
    //simply move check
    std::pair<char, int> currGetPos = {curLetter, currPosNumber}, nextGetPos = {nextLetter, nextPosNumber};

    std::pair<int, int> currPos = this->convertPosition(currGetPos), nextPos = this->convertPosition(nextGetPos);
    std::cout <<"AAAA"<< currPos.first << " " << currPos.second <<std::endl;
    std::cout <<"DDD"<< nextPos.first << " " << nextPos.second <<std::endl;

    if (!(this->gameManager->checksOnPositions.find(currPos) != this->gameManager->checksOnPositions.end()))
    {
        QMessageBox::warning(this, "Ошибка", "На текущей позиции нет шашки");
        return;
    }

    if ((this->gameManager->checksOnPositions.find(nextPos) != this->gameManager->checksOnPositions.end()))
    {
        QMessageBox::warning(this, "Ошибка", "На позиции хода стоит шашка");
        return;
    }

    //now check incorrect move by the rules
    std::cout << "difference: " << abs(currPos.first - nextPos.first) << " " << abs(currPos.second - nextPos.second) << std::endl;
    if (abs(currPos.first - nextPos.first) != abs(currPos.second - nextPos.second))
    {
        QMessageBox::warning(this, "Ошибка", " Недопустимый ход       ");
        return;
    }

    //now check possible moves
    std::pair<int, int> middlePos = { (currPos.first + nextPos.first)/2, (currPos.second + nextPos.second)/2 };
    if (abs(currPos.first - nextPos.first) == 2 && (this->gameManager->checksOnPositions.find(middlePos) != this->gameManager->checksOnPositions.end()))
    {
        this->gameManager->checksOnPositions.erase(middlePos);
    }

    auto gameCheck = this->gameManager->move_check(currPos, nextPos);
    this->scene->update_scene_with_checks(this->gameManager->checksOnPositions);
    this->updateScene();
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

void MainWindow::runPerformanceTest() {
    QPixmap testPixmap(9669, 1079); // Создаем QPixmap для тестирования
    Light testLight = scene->get_light_sources(); // Получаем источник света

    PerformanceTester tester(*renderer, &testPixmap, testLight); // Создаем экземпляр PerformanceTester
    tester.measure_render_time("render_times.csv"); // Запускаем замеры и записываем в CSV
}

MainWindow::~MainWindow()
{
    delete ui;

    delete img;
    delete pxmp;
    delete renderer;

    delete scene;

    delete gameManager;
}

