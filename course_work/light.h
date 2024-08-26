#ifndef LIGHT_H
#define LIGHT_H

#include <QVector3D>
#include <QColor>

class Light
{
public:
    Light();
    Light(QVector3D pposition, float intencity, QColor color = Qt::white);
private:
    QVector3D _position;
    QColor _color;
    float _intencity;
};

#endif // LIGHT_H
