#include "mathtransformation.h"
#include <cmath>

#include <QMatrix4x4>

MathTransformation::MathTransformation(QObject *parent)
    : QObject{parent}
{

}

void MathTransformation::move_model( Model3D & model, QVector3D bias )
{
    for (auto & edge: model._edges)
    {
        for (auto& point: edge._points)
        {
            move_point(point, bias);
        }
        edge.calculate_normal();
    }
    move_point(model._centre, bias);
}
void MathTransformation::rotate_model( Model3D & model, QVector3D angle, QVector4D centre )
{
    for (auto & edge: model._edges)
    {
        for (auto& point: edge._points)
        {
            rotate_point(point, angle, centre);
        }
        edge.calculate_normal();
    }
    rotate_point(model._centre, angle, centre);

}
void MathTransformation::move_model_on_pos( Model3D & model, QVector3D newPos )
{
    QVector3D bias {newPos[0] - model._centre[0], newPos[1] - model._centre[1], newPos[2] - model._centre[2]};
    move_model(model, bias);
}


QVector4D MathTransformation::calcNormal(QVector4D p1, QVector4D p2, QVector4D p3)
{
    QVector4D normal;
    QVector4D vector1  {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2], 1};
    QVector4D vector2 {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2], 1};

    normal[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
    normal[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
    normal[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
    normal[3] = 0;

    double length = std::sqrt(normal[0] * normal[0] + normal[1] * normal[1] + normal[2] * normal[2]);
    normal[0] /= length;
    normal[1] /= length;
    normal[2] /= length;
    return normal;
}

float MathTransformation::scalarProduct(const QVector4D &vec1, const QVector4D &vec2)
{
    return QVector4D::dotProduct(vec1, vec2);
}


//----private methods

void MathTransformation::move_point(QVector4D &point, QVector3D bias)
{
    float Matrix[4][4] = {
                { 1, 0, 0, bias[0] },
                { 0, 1, 0, bias[1] },
                { 0, 0, 1, bias[2] },
                { 0, 0, 0, 1       }
    };
    //Matrix * point

    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * point[j];
        }
        point[i] = cur_val;
    }
}

void MathTransformation::rotate_point( QVector4D &point, QVector3D angle, QVector4D centre )
{
    QVector4D vector_bias=  {point[0] - centre[0], point[1] - centre[1], point[2] - centre[2], 0};
    rotate_vector_x(vector_bias, angle[0]);
    rotate_vector_y(vector_bias, angle[1]);
    rotate_vector_z(vector_bias, angle[2]);

    point = {centre[0] + vector_bias[0], centre[1] + vector_bias[1], centre[2] + vector_bias[2], 1};
}


float degrees_to_radians(float degrees)
{
    return degrees * M_PI / 180;
}


void MathTransformation::rotate_vector_x(QVector4D &vector, float angX)
{
    float anX = degrees_to_radians(angX);

    float cosX = cos(anX);
    float sinX = sin(anX);

    float Matrix[4][4] = {
                { 1, 0, 0, 0       },
                { 0, cosX, -sinX, 0 },
                { 0, sinX, cosX, 0 },
                { 0, 0, 0, 1       }
    };


    QVector4D copy(vector);
    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        copy[i] = cur_val;
    }
    vector = copy;
}

void MathTransformation::rotate_vector_y(QVector4D &vector, float angY)
{
    float anY = degrees_to_radians(angY);

    float cosX = cos(anY);
    float sinX = sin(anY);

    float Matrix[4][4] = {
                { cosX, 0, sinX, 0 },
                { 0, 1, 0, 0 },
                { -sinX, 0, cosX, 0 },
                { 0, 0, 0, 1       }
    };

    QVector4D copy(vector);
    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        copy[i] = cur_val;
     }
    vector = copy;
}

void MathTransformation::rotate_vector_z(QVector4D &vector, float angZ)
{
    float anZ = degrees_to_radians(angZ);

    float cosZ = cos(anZ);
    float sinZ = sin(anZ);

    float Matrix[4][4] = {
                { cosZ, -sinZ, 0, 0 },
                { sinZ, cosZ, 0, 0 },
                { 0, 0, 1, 0 },
                { 0, 0, 0, 1 }
    };

    QVector4D copy(vector);
    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        copy[i] = cur_val;
     }
    vector = copy;
}

