#ifndef LIGHT_H
#define LIGHT_H

#include "color.h"
#include <QVector3D>
#include <QVector4D>

struct LightAttr
{
    Color color;
    QVector4D position;
    QVector4D target;
    float intensity;
};

class Light
{
public:
    Light();
    Light(const LightAttr &attr);
    float getI() const { return intensity; }
    QVector4D getPos() const { return position; }
    QVector4D getDir() const;
private:
    Color color;
    QVector4D target;
    QVector4D position;
    float intensity;
};

#endif // LIGHT_H
