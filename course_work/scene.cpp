#include "scene.h"
#include <map>

#include <iostream>

Scene::Scene(QObject *parent)
    : QObject{parent}
{
    this->centreScene = {450, 450, -100};
    this->lightSource = Light();

    make_initial_state();
}

void Scene::make_initial_state()
{
    float square_length = 100;
    std::map<int, QColor> color_square {{0, QColor(255, 255, 240)}, {1, QColor(131, 86, 62)}};

    this->_centreComposition = {this->centreScene[0], this->centreScene[1], this->centreScene[2], 1};

    ModelCubeBuilder cubeBuilder;
    ModelCheckBuilder checkBuilder;

    // Создание доски - оставляем как есть
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            QColor color_body;
            if (i==0 && j == 0)
                color_body = Qt::red;
            else if (i == 7 && j == 0)
                color_body = Qt::green;
            else
                color_body = color_square[(i + j)%2];

            Model3D curr_model = cubeBuilder.build_cube(square_length, color_body, color_body);

            float xcurr = this->_centreComposition[0] + (i - 3.5f) * square_length;
            float ycurr = this->_centreComposition[1] + (j - 3.5f) * square_length;

            QVector3D bias{xcurr, ycurr, 0};
            this->_positionChanger.move_model_on_pos(curr_model, bias);

            this->_positionChanger.rotate_model(curr_model, {45, 0, 180}, this->_centreComposition);
            this->chessBoardSquares.push_back(curr_model);

        }
    }

    // Параметры шашек - увеличиваем размеры
    float check_height = 50;  // увеличиваем высоту
    float check_radius = square_length/2.5;  // увеличиваем радиус

    // Создание белых шашек
    for (int row = 0; row < 3; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                QColor color_body = Qt::white;
                Model3D check = checkBuilder.build_check(check_radius,
                    check_radius/4, check_height, 50, 50,
                    color_body, color_body);

                float xcurr = this->_centreComposition[0] + (col - 3.5f) * square_length;
                float ycurr = this->_centreComposition[1] + (row - 3.5f) * square_length;
                float zcurr = -square_length/2;  // отрицательное значение, так как центр сцены имеет z = -100

                QVector3D bias{xcurr, ycurr, zcurr};
                this->_positionChanger.move_model_on_pos(check, bias);

                // Поворачиваем шашку, чтобы она стояла на доске
                this->_positionChanger.rotate_model(check, {270, 0, 0}, check._centre);
                //this->_positionChanger.rotate_model(check, {90, 0, 0}, check._centre);

                this->_positionChanger.rotate_model(check, {45, 0, 180}, this->_centreComposition);

                whiteChecks.push_back(check);

                // Отладочный вывод
                std::cout << "White check added at: " << xcurr << ", " << ycurr << ", " << zcurr << std::endl;

            }
        }
    }

    // Создание черных шашек
    for (int row = 5; row < 8; ++row)
    {
        for (int col = 0; col < 8; ++col)
        {
            if ((row + col) % 2 == 1)
            {
                QColor color_body = QColor(69, 50, 46);
                Model3D check = checkBuilder.build_check(check_radius,
                    check_radius/4, check_height, 50, 50,
                    color_body, color_body);

                float xcurr = this->_centreComposition[0] + (col - 3.5f) * square_length;
                float ycurr = this->_centreComposition[1] + (row - 3.5f) * square_length;
                float zcurr = -square_length/2;  // отрицательное значение Z

                QVector3D bias{xcurr, ycurr, zcurr};
                this->_positionChanger.move_model_on_pos(check, bias);

                // Поворачиваем шашку
                //this->_positionChanger.rotate_model(check, {180, 0, 0}, check._centre);
                this->_positionChanger.rotate_model(check, {270, 0, 0}, check._centre);

                this->_positionChanger.rotate_model(check, {45, 0, 180}, this->_centreComposition);

                blackChecks.push_back(check);

                // Отладочный вывод
                //std::cout << "Black check added at: " << xcurr << ", " << ycurr << ", " << zcurr << std::endl;
            }
        }
    }

    // Отладочный вывод количества созданных шашек
    std::cout << "White checks created: " << whiteChecks.size() << std::endl;
    std::cout << "Black checks created: " << blackChecks.size() << std::endl;
}

void Scene::rotate_composition(QVector3D angle)
{
    for (auto& model : this->chessBoardSquares)
    {
        this->_positionChanger.rotate_model(model, angle, this->_centreComposition);
    }

    for (auto& model : this->whiteChecks)
    {
        this->_positionChanger.rotate_model(model, angle, this->_centreComposition);
    }

    for (auto& model : this->blackChecks)
    {
        this->_positionChanger.rotate_model(model, angle, this->_centreComposition);
    }
}

std::vector<Model3D> Scene::get_all_models()
{
    std::vector<Model3D> models;
    for (auto& item: chessBoardSquares)
    {
        models.push_back(item);
    }
    // for white checks
    for (auto& item: whiteChecks)
    {
        models.push_back(item);
    }
    // for black checks
    for (auto& item: blackChecks)
    {
        models.push_back(item);
    }

    return models;
}

Light Scene::get_light_sources()
{
    return lightSource;
}

