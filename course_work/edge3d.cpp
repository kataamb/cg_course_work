#include "edge3d.h"

Edge3D::Edge3D(QVector4D p1, QVector4D p2, QVector4D p3, QColor bodyColor, QColor borderColor)
{
    this->_points[0] = p1;
    this->_points[1] = p2;
    this->_points[2] = p3;

    this->bodyColor = bodyColor;
    this->borderColor = borderColor;
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
