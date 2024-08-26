#include "scene.h"
#include <map>

#include <iostream>

Scene::Scene(QObject *parent)
    : QObject{parent}
{
    this->centreScene = {500, 500, 0};

    make_initial_state();
}


void Scene::make_initial_state()
{
    float square_length = 100;
    std::map<int, QColor> color_square {{0, QColor(255, 255, 240)}, {1, QColor(131, 86, 62)}};

    this->_centreComposition = {this->centreScene[0], this->centreScene[1], 0, 1};



    ModelCubeBuilder cubeBuilder;

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
    QVector3D ang{360, 360, 0};
    this->_positionChanger.rotate_model(curr_model, ang, {50, 50, 50, 1});
    this->_positionChanger.move_model(curr_model, {200, 200, 0});
    this->chessBoardSquares.push_back(curr_model);

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

std::vector<Light> Scene::get_light_sources()
{
    return lightSources;
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

