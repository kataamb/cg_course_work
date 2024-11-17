#include "model3d.h"
#include <QMatrix4x4>
#include <cmath>
#include <iostream>

Model3D::Model3D()
{

}

Model3D::Model3D(std::vector<Edge3D> edges, QColor bodyColor, QColor borderColor)
{
    this->bodyColor = bodyColor;
    this->borderColor = borderColor;

    for (auto& edge: edges)
    {
        this->_edges.push_back(edge);
    }
}

void Model3D::add_edge(Edge3D edge)
{
    this->_edges.push_back(edge);
}

void Model3D::set_centre(QVector3D centre)
{
    this->_centre = {centre[0], centre[1], centre[2], 1};
}

void Model3D::set_centre(QVector4D centre)
{
    this->_centre = centre;
}

float _degrees_to_radians(float degrees)
{
    return degrees * M_PI / 180;
}
void Model3D::rotate(float angleX, float angleY, float angleZ)
{
    std::cout << this->_edges.size()<<std::endl<<std::endl;
    // Преобразуем углы из градусов в радианы
    float radX = _degrees_to_radians(angleX);
    float radY = _degrees_to_radians(angleY);
    float radZ = _degrees_to_radians(angleZ);

    // Создаем матрицы поворота
    QMatrix4x4 rotationX;
    rotationX.rotate(radX, 1.0f, 0.0f, 0.0f); // Поворот вокруг оси X

    QMatrix4x4 rotationY;
    rotationY.rotate(radY, 0.0f, 1.0f, 0.0f); // Поворот вокруг оси Y

    QMatrix4x4 rotationZ;
    rotationZ.rotate(radZ, 0.0f, 0.0f, 1.0f); // Поворот вокруг оси Z

    // Объединяем матрицы поворота
    QMatrix4x4 rotationMatrix = rotationZ * rotationY * rotationX;

    // Применяем матрицу поворота к каждой грани модели
    for (Edge3D &edge : _edges) {
        for (int i = 0; i < 3; ++i) {
            edge._points[i] = rotationMatrix * edge._points[i];
        }
        edge._plane_normal = rotationMatrix * edge._plane_normal; // Поворачиваем нормаль
    }

    // Если необходимо, можно обновить центр модели
    // Например, можно пересчитать центр после поворота.
    std::cout << this->_edges.size() << std::endl;
}

