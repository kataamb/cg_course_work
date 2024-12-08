#include "edge3d.h"
#include <cmath>

Edge3D::Edge3D(QVector4D p1, QVector4D p2, QVector4D p3, QColor bodyColor, QColor borderColor)
{
    this->_points[0] = p1;
    this->_points[1] = p2;
    this->_points[2] = p3;

    this->bodyColor = bodyColor;
    this->borderColor = borderColor;
    calculate_normal();
}

void Edge3D::calculate_normal()
{
    QVector4D p1 = _points[0],  p2 = _points[1],  p3 = _points[2];
    // Вычисляем нормаль
           QVector3D v1(p2.x() - p1.x(), p2.y() - p1.y(), p2.z() - p1.z());
           QVector3D v2(p3.x() - p1.x(), p3.y() - p1.y(), p3.z() - p1.z());
           QVector3D normal = QVector3D::crossProduct(v1, v2);
           normal.normalize();

           // Преобразуем в QVector4D (w = 0 для векторов)
           _plane_normal = QVector4D(normal.x(), normal.y(), normal.z(), 0.0f);
}


Edge3D::Edge3D(QVector4D p1, QVector4D p2, QVector4D p3, QVector4D normal)
{

}

Edge3D::Edge3D(const Edge3D &edge)
{
    for (int i = 0; i < 3; ++i)
    {
        this->_points[i] = edge._points[i];
    }

    this->bodyColor = edge.bodyColor;
    this->borderColor = edge.borderColor;
    this->_plane_normal = edge._plane_normal;

}

/*QVector4D Edge3D::calcNormal()
{
    QVector4D normal;
    QVector4D vector1  {_points[1][0] - _points[0][0], _points[1][1] - _points[0][1], _points[1][2] - _points[0][2], 1};
    QVector4D vector2 {_points[2][0] - _points[0][0], _points[2][1] - _points[0][1], _points[2][2] - _points[0][2], 1};

    normal[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    normal[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    normal[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    normal[3] = 0;

    double length = std::sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
    normal[0] /= length;
    normal[1] /= length;
    normal[2] /= length;
    return normal;
}*/


Edge3D& Edge3D::operator=(const Edge3D &edge)
{
    for (int i = 0; i < 3; ++i)
    {
        this->_points[i] = edge._points[i];
    }

    this->bodyColor = edge.bodyColor;
    this->borderColor = edge.borderColor;
    this->_plane_normal = edge._plane_normal;

    return *this;
}
Edge3D& Edge3D::operator=(const Edge3D edge)
{
    for (int i = 0; i < 3; ++i)
    {
        this->_points[i] = edge._points[i];
    }

    this->bodyColor = edge.bodyColor;
    this->borderColor = edge.borderColor;
    this->_plane_normal = edge._plane_normal;

    return *this;
}
