#include "light.h"

Light::Light()
{
    color = Color(255, 255, 255);
    target = QVector4D(0.0f, 0.0f, 0.0f, 1);
    position = QVector4D(0.0f, 0.0f, 100.0f, 1);
    intensity = 1.0;
}

Light::Light(const LightAttr &attr)
{
    color = attr.color;
    target = attr.target;
    position = attr.position;
    intensity = attr.intensity;
}

QVector4D Light::getDir() const
{
    QVector4D direction {position[0] - target[0], position[1] - target[1], position[2] - target[2], 0};

    double length = std::sqrt(direction[0] * direction[0] + direction[1] * direction[1] + direction[2] * direction[2]);
    direction[0] /= length;
    direction[1] /= length;
    direction[2] /= length;
    return direction;
}
