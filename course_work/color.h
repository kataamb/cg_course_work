#ifndef COLOR_H
#define COLOR_H

#include <cmath>

#include <QColor>

typedef unsigned char byte;

class Color
{
public:
    Color();
    Color(const int rVal, const int gVal, const int bVal);
    Color(const QColor& color);
    void setR(const int val) {r = val;};
    void setG(const int val) {g = val;};
    void setB(const int val) {b = val;};
    void setI_R(const float val) {i_r = val;};
    void setI_G(const float val) {i_g = val;};
    void setI_B(const float val) {i_b = val;};

    int getR() const {return r;};
    int getG() const {return g;};
    int getB() const {return b;};
    float getI_R() const {return i_r;};
    float getI_G() const {return i_g;};
    float getI_B() const {return i_b;};

    inline QRgb rgb() const { return qRgb(round(i_r), round(i_g), round(i_b)); };
private:
    int r;
    int g;
    int b;
    float i_r;
    float i_g;
    float i_b;
};

#endif // COLOR_H
