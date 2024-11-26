#include "modelbuilder.h"
#include <math.h>
#include "mathtransformation.h"
#include <iostream>

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

Model3D ModelCubeBuilder::build_torus(float R, float r, int N, int M, QColor bodyColor , QColor boardColor)
{
    Model3D torus;
    QVector<QVector3D> torusPoints;
    for (int i = 0; i < N; ++i )
    {
        for (int j = 0; j < M; ++j )
        {
            float u = 2 * M_PI * i / N;
            float v = M_PI * j / M - M_PI / 2;

            float x = (R + r * cos(v)) * cos(u);
            float y = (R + r * cos(v)) * sin(u);
            float z = r * sin(v);

            torusPoints.push_back({x, y, z});
        }
    }

    for (int i = 0; i < N; ++i )
    {
        for (int j = 0; j < M; ++j )
        {
            if (i < N - 1 and j < M - 1)
            {
                //# Индексы вершин
                int a = i * M + j;
                int b = (i + 1) * M + j;
                int c = i * M + (j + 1);
                int d = (i + 1) * M + (j + 1);
                torus.add_edge( {torusPoints[a], torusPoints[b], torusPoints[c]} );
                torus.add_edge( {torusPoints[b], torusPoints[d], torusPoints[c]} );
            }

        }
    }
    torus.bodyColor = bodyColor;
    torus.borderColor = boardColor;
    torus.set_centre({0, 0, 0});
    return torus;
}

//----------------------------------------------------------------------------------------------
ModelTorusBuilder::ModelTorusBuilder(QObject *parent)
: ModelBuilder{parent}
{

}

Model3D ModelTorusBuilder::build_torus(float R, float r, int N, int M, QColor bodyColor , QColor boardColor)
{
    std::map<int, QColor> color_square {{0, Qt::white}, {1, Qt::black},
                                       {2, QColor(Qt::red)}, {3, QColor(Qt::yellow)},
                                       {4, QColor(Qt::green)}, {5, QColor(Qt::cyan)},
                                       {6, QColor(Qt::blue)}, {7, QColor(Qt::magenta)}

                                       };
    Model3D torus;
    QVector<QVector4D> torusPoints;
    QVector<QVector<QVector4D>> torusByPoints;


    QVector<QVector4D> circlePoints;
    //create circle radius r, centre (0, 0, 0)
    for (int j = 0; j < M; ++j )
    {
        float x = r * cos(j* 2 * M_PI / M);
        float y = r * sin(j * 2 * M_PI / M);
        float z = 0;

        std::cout << j << " " << j * 2 * M_PI / M << std::endl;

        circlePoints.push_back({x, y, z, 1});
    }


    //move circle to centre (R, 0, 0)
    MathTransformation transformPoints;
    QVector3D bias {R - 0, 0, 0};
    for (int j = 0; j < M; ++j )
    {
        transformPoints.move_point(circlePoints[j], bias);
    }
    float angle = float(360.0)/(float(N));

    //now rotate each point of each circle by axis y over point (0, 0, 0)
    for (int i = 0; i < N; ++i )
    {
        QVector<QVector4D> curr_copy(circlePoints), curr_empty;
        torusByPoints.push_back(curr_empty);

        for (auto & point: curr_copy)
        {
            float y_angle = angle * i;//(i * 360)/N;
            transformPoints.rotate_point(point, {0, y_angle, 0}, {0, 0, 0, 1});

            torusByPoints[i].push_back(point);
        }

    }

    //we have array of points; now have to connect them to edges
    int ind1, ind2, ind3, ind4;
    for (int i = 0; i < N; ++i )
    {
        for (int j = 0; j < M; ++j )
        {
            torus.add_edge({torusByPoints[i][j], torusByPoints[i][(j+1)%M], torusByPoints[(i+1)%N][ j ]});
            torus.add_edge({torusByPoints[i][(j+1)%M ], torusByPoints[(i+1)%N][ j ], torusByPoints[(i+1)%N][ (j+1)%M ]});

        }
    }

    torus.bodyColor = bodyColor;
    torus.borderColor = boardColor;
    torus.set_centre({0, 0, 0});
    return torus;
}

//-----------------------------------------------------------------------------------------------------------

