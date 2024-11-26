#include "scene.h"
#include <map>

#include <iostream>

Scene::Scene(QObject *parent)
    : QObject{parent}
{
    this->centreScene = {500, 500, 0};
    this->lightSource = Light();

    make_initial_state();
}


void Scene::make_initial_state()
{
    float square_length = 200;
    std::map<int, QColor> color_square {{0, QColor(255, 255, 240)}, {1, QColor(131, 86, 62)}};

    this->_centreComposition = {this->centreScene[0], this->centreScene[1], 0, 1};



    ModelCubeBuilder cubeBuilder;
    ModelTorusBuilder torusBuilder;

    /*for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            QColor color_body;
            if (i==0 && j == 0)
            {
                color_body = Qt::red;
            }
            else if (i == 7 && j == 0)
            {
                color_body = Qt::green;
            }
            else
            {
                color_body = color_square[(i + j)%2];
            }
            Model3D curr_model = cubeBuilder.build_cube(square_length, color_body, color_body);

            QVector3D bias{this->_centreComposition[0] + (i-4)*(square_length + 0) , this->_centreComposition[1] + (j-4)*(square_length + 0), 0};
            this->_positionChanger.move_model(curr_model, bias);

            QVector3D ang{0, 0, 0};
            this->_positionChanger.rotate_model(curr_model, ang, this->_centreComposition);

            this->chessBoardSquares.push_back(curr_model);
        }
    }*/
    //debug
    QColor color_body = Qt::green;
    Model3D curr_model = cubeBuilder.build_cube(square_length, color_body, color_body);
    Model3D curr_torus = torusBuilder.build_torus(200, 100, 100, 100);
    QVector3D ang{0, 0, 0};


    //this->_positionChanger.rotate_model(curr_torus, ang, curr_torus._centre);

    this->_positionChanger.move_model(curr_model, {200, 200, 0});
    this->_positionChanger.move_model(curr_torus, {600, 600, 0});

    //this->_positionChanger.rotate_model(curr_torus, {50, 90, 0}, curr_torus._centre);
    //this->_positionChanger.rotate_model(curr_torus, {90, 0, 0}, this->centreScene);
    //this->_positionChanger.rotate_model(curr_model, {90, 0, 0}, this->centreScene);

    std::cout << curr_torus._centre[0] << " " << curr_torus._centre[1] << " " << std::endl;

    this->chessBoardSquares.push_back(curr_model);
    this->chessBoardSquares.push_back(curr_torus);

}


std::vector<Model3D> Scene::get_all_models()
{
    std::vector<Model3D> models;
    for (auto& item: chessBoardSquares)
    {
        models.push_back(item);
    }
    // for white checks
    // for black checks

    return models;
}

Light Scene::get_light_sources()
{
    return lightSource;
}


void Scene::move_item(Model3D &item, QVector3D bias)
{

    for (auto& edge: item._edges)
    {
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                edge._points[i][j] += bias[j];
            }
        }
    }
}

