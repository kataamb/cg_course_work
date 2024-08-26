#include "light.h"

Light::Light()
{

}

Light::Light(QVector3D position, float intencity = 100, QColor color)
{
    this->_position = position;
    this->_intencity = intencity;
    this->_color = color;
}
