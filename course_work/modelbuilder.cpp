#include "modelbuilder.h"

ModelBuilder::ModelBuilder(QObject *parent)
    : QObject{parent}
{

}


//----------------------------------------------------------------------------------------------
ModelCubeBuilder::ModelCubeBuilder(QObject *parent)
: ModelBuilder{parent}
{

}

Model3D ModelCubeBuilder::build_cube(float length, QColor bodyColor , QColor boardColor)
{
    float h = length;

    Model3D cube( {
                      {{0, 0, 0, 1}, {0, h, 0, 1}, {h, h, 0, 1}},
                      {{h, h, 0, 1}, {h, 0, 0, 1}, {0, 0, 0, 1}},
                      {{h, 0, 0, 1}, {h, h, 0, 1}, {h, h, h, 1}},
                      {{h, h, h, 1}, {h, 0, h, 1}, {h, 0, 0, 1}},
                      {{h, h, h, 1}, {h, 0, h, 1}, {0, h, h, 1}},
                      {{0, h, h, 1}, {0, 0, h, 1}, {h, 0, h, 1}},
                      {{0, h, h, 1}, {0, 0, h, 1}, {0, h, 0, 1}},
                      {{0, h, 0, 1}, {0, 0, 0, 1}, {0, 0, h, 1}},

                      {{0, h, 0, 1}, {h, h, 0, 1}, {0, h, h, 1}},
                      {{h, h, 0, 1}, {h, h, h, 1}, {0, h, h, 1}},

                      {{0, 0, 0, 1}, {h, 0, 0, 1}, {0, 0, h, 1}},
                      {{0, 0, h, 1}, {h, 0, h, 1}, {h, 0, 0, 1}}
                  },
                  bodyColor,  boardColor);
    cube.set_centre({h/2,  h/2, h/2});

    return cube;

}
