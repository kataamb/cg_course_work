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
    for (int i = 0; i < N; ++i )
    {
        for (int j = 0; j < M; ++j )
        {
            // Первая грань
            torus.add_edge({torusByPoints[i][j], torusByPoints[(i+1)%N][j], torusByPoints[i][(j+1)%M]});

            // Вторая грань
            torus.add_edge({torusByPoints[i][(j+1)%M], torusByPoints[(i+1)%N][j], torusByPoints[(i+1)%N][(j+1)%M]});
        }
    }

    torus.bodyColor = bodyColor;
    torus.borderColor = boardColor;
    torus.set_centre({0, 0, 0});

    //torus.fix_edges_orientation();

    return torus;
}

//-----------------------------------------------------------------------------------------------------------
ModelCylinderBuilder::ModelCylinderBuilder(QObject *parent)
    : ModelBuilder{parent}
    {

    }


//cylinder
//void generateCylinder(float height, float radius, int divisions) {
Model3D ModelCylinderBuilder::build_cylinder(float h, float r, int N, QColor bodyColor , QColor boardColor)
{
      Model3D cylinder;
       // Создаем верхнюю и нижнюю окружности
       std::vector<QVector4D> topCircle;
       std::vector<QVector4D> bottomCircle;

       // Вычисляем углы и создаем точки
       for (int i = 0; i < N; ++i) {
           float angle = (2.0f * M_PI * i) / N;
           float x = r * cos(angle);
           float z = r * sin(angle);

           // Верхняя окружность
           topCircle.push_back(QVector4D(x, h / 2, z, 1.0f));
           // Нижняя окружность
           bottomCircle.push_back(QVector4D(x, -h / 2, z, 1.0f));
       }

       // Создаем боковые грани
       for (int i = 0; i < N; ++i) {
           int next = (i + 1) % N;

           // Верхний треугольник
           cylinder.add_edge(Edge3D(topCircle[i], bottomCircle[i], bottomCircle[next]));

           // Нижний треугольник
           cylinder.add_edge(Edge3D(topCircle[i], bottomCircle[next], topCircle[next]));
       }

       // Добавляем верхнее основание
       QVector4D centerTop(0, h / 2, 0, 1.0f);
       for (int i = 0; i < N; ++i) {
           cylinder.add_edge(Edge3D(centerTop, topCircle[i], topCircle[(i + 1) % N]));
       }

       // Добавляем нижнее основание
       QVector4D centerBottom(0, -h / 2, 0, 1.0f);
       for (int i = 0; i < N; ++i) {
           cylinder.add_edge(Edge3D(centerBottom, bottomCircle[i], bottomCircle[(i + 1) % N]));
       }

       cylinder.bodyColor = bodyColor;
       cylinder.borderColor = boardColor;
       cylinder.set_centre({0, 0, 0});

       return cylinder;
   }



//----------------------------------------------------------------------
//check model builder
ModelCheckBuilder::ModelCheckBuilder(QObject *parent)
    : ModelBuilder{parent}
    {

    }

Model3D ModelCheckBuilder::build_check(float R, float r, float h, int N, int M, QColor bodyColor, QColor boardColor) {
    Model3D intersection;

    ModelCylinderBuilder cylinderBuilder;
    ModelTorusBuilder torusBuilder;

    // Создаем тор
    Model3D torus = torusBuilder.build_torus(R-r + r/10, r, N, M, bodyColor, boardColor);

    // Создаем цилиндр
    Model3D cylinder = cylinderBuilder.build_cylinder(h, R, N, bodyColor, boardColor);

    // Перемещаем тор так, чтобы его центр совпадал с верхней гранью цилиндра
    MathTransformation transform;
    QVector3D bias(0, h / 2, 0);

    transform.move_model(torus, bias);

    // Объединяем точки и грани тора и цилиндра
    for (auto & edge: torus._edges)
    {
        intersection.add_edge(edge);
    }

    for (auto & edge: cylinder._edges)
    {
        intersection.add_edge(edge);
    }

    intersection.bodyColor = bodyColor;
    intersection.borderColor = boardColor;
    intersection.set_centre({0, 0, 0});

    return intersection;
}

