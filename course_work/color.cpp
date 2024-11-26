#include "color.h"

Color::Color()
{
    r = 255;
    g = 255;
    b = 255;
    i_r = 255;
    i_g = 255;
    i_b = 255;
}

Color::Color(const int rVal, const int gVal, const int bVal)
{
    r = rVal;
    g = gVal;
    b = bVal;
    i_r = rVal;
    i_g = gVal;
    i_b = bVal;
}
