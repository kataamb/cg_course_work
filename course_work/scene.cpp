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
    _squareLength = square_length;

    std::map<int, QColor> color_square {{0, QColor(255, 255, 240)}, {1, QColor(131, 86, 62)}};

    this->_centreComposition = {this->centreScene[0], this->centreScene[1], this->centreScene[2], 1};

    this->_currentAngle = this->_initialAngle = {0, 0, 0};

    this->_currentBias = {0, 0, 0, 0};

    this->_currentAngle += {45, 0, 180};

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

            this->_positionChanger.rotate_model(curr_model, this->_currentAngle, this->_centreComposition);
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

                this->_positionChanger.rotate_model(check, this->_currentAngle, this->_centreComposition);

                whiteChecks.push_back(check);
                std::cout<<row<<" "<< col<<std::endl;

            }
        }
    }

    std::cout<<std::endl;

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

                this->_positionChanger.rotate_model(check, this->_currentAngle, this->_centreComposition);

                blackChecks.push_back(check);
                std::cout<<row<<" "<< col<<std::endl;
            }
        }
    }

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

    this->_currentAngle += angle;
    for (int i = 0; i < 3; ++i)
    {
        if (this->_currentAngle[i] > 360)
        {
            this->_currentAngle[i] -= 360;
        }
    }
}

void Scene::rotate_composition_backward(QVector3D angle)
{
    for (auto& model : this->chessBoardSquares)
    {
        this->_positionChanger.rotate_model_backward(model, angle, this->_centreComposition);
    }

    for (auto& model : this->whiteChecks)
    {
        this->_positionChanger.rotate_model_backward(model, angle, this->_centreComposition);
    }

    for (auto& model : this->blackChecks)
    {
        this->_positionChanger.rotate_model_backward(model, angle, this->_centreComposition);
    }

    /*this->_currentAngle -= angle;
    for (int i = 0; i < 3; ++i)
    {
        if (this->_currentAngle[i] < 360)
        {
            this->_currentAngle[i] += 360;
        }
    }*/
}

void Scene::update_scene_with_checks(const std::map<std::pair<int, int>, GameCheck>& checksOnPositions)
{
    //remember angle
     QVector3D currAngle = this->_currentAngle;

    // Очищаем текущие шашки и доску
    this->chessBoardSquares.clear();
    this->whiteChecks.clear();
    this->blackChecks.clear();

     ModelCubeBuilder cubeBuilder;
     std::map<int, QColor> color_square {{0, QColor(255, 255, 240)}, {1, QColor(131, 86, 62)}};

    // Создаем доску заново
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

            Model3D curr_model = cubeBuilder.build_cube(_squareLength, color_body, color_body);

            float xcurr = this->_centreComposition[0] + (i - 3.5f) * _squareLength;
            float ycurr = this->_centreComposition[1] + (j - 3.5f) * _squareLength;

            QVector3D bias{xcurr, ycurr, 0};
            this->_positionChanger.move_model_on_pos(curr_model, bias);

            this->chessBoardSquares.push_back(curr_model);

        }
    }

    // Параметры шашек
    float check_height = 50;  // высота шашек
    float check_radius = _squareLength / 2.5;  // радиус шашек

    // Проходим по всем шашкам в checksOnPositions и добавляем их на сцену
    for (const auto& entry : checksOnPositions)
    {
        const auto& position = entry.first; // Позиция шашки (строка, столбец)
        const GameCheck& check = entry.second; // Шашка

        // Определяем цвет шашки
        QColor color_body = (check.checkColor == white) ? Qt::white : QColor(69, 50, 46);

        // Создаем шашку
        ModelCheckBuilder checkBuilder;
        Model3D newCheck = checkBuilder.build_check(check_radius, check_radius / 4, check_height, 50, 50, color_body, color_body);

        // Вычисляем позицию на доске
        float xcurr = this->_centreComposition[0] + (position.second - 3.5f) * _squareLength; // столбец
        float ycurr = this->_centreComposition[1] + (position.first - 3.5f) * _squareLength; // строка
        float zcurr = -_squareLength / 2;  // отрицательное значение Z

        QVector3D bias{xcurr, ycurr, zcurr};
        this->_positionChanger.move_model_on_pos(newCheck, bias);

        // Поворачиваем шашку, чтобы она стояла на доске
        this->_positionChanger.rotate_model(newCheck, {270, 0, 0}, newCheck._centre);

        // Добавляем шашку в соответствующий вектор
        if (check.checkColor == white)
        {
            whiteChecks.push_back(newCheck);
        }
        else
        {
            blackChecks.push_back(newCheck);
        }
    }

    this->rotate_composition(currAngle);
    this->_currentAngle = currAngle;

    // Обновляем текущий угол, если необходимо
    //this->_currentAngle = this->_initialAngle; // или установите нужный угол
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

