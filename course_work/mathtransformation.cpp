#include "mathtransformation.h"
#include <cmath>

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
    }
}
void MathTransformation::rotate_model( Model3D & model, QVector3D angle, QVector4D centre )
{
    for (auto & edge: model._edges)
    {
        for (auto& point: edge._points)
        {
            rotate_point(point, angle, centre);
        }
    }
}
void MathTransformation::move_model_on_pos( Model3D & model, QVector3D new_position )
{

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


    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        vector[i] = cur_val;
     }
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


    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        vector[i] = cur_val;
     }
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


    for (int i = 0; i < 4; ++i)
    {
        float cur_val = 0;
        for (int j = 0; j < 4; ++j)
        {
            cur_val += Matrix[i][j] * vector[j];
        }
        vector[i] = cur_val;
     }
}


void MathTransformation::move_point_to_new_pos(QVector4D &point, QVector3D bias)
{

}

