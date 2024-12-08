#ifndef EDGE3D_H
#define EDGE3D_H

#include <QVector3D>
#include <QVector4D>
#include <vector>
#include <QColor>

struct Edge3D
{
public:
    Edge3D(QVector4D p1, QVector4D p2, QVector4D p3, QColor bodyColor=Qt::white, QColor borderColor=Qt::black);
    Edge3D(QVector4D p1, QVector4D p2, QVector4D p3, QVector4D normal);

    void calculate_normal();


    Edge3D(const Edge3D &edge);
    Edge3D& operator=(const Edge3D &edge);
    Edge3D& operator=(const Edge3D edge);

    QColor bodyColor;
    QColor borderColor;

    QVector4D _points[3];
    QVector4D _plane_normal;

};

#endif // EDGE3D_H
