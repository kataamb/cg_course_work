#ifndef MATHTRANSFORMATION_H
#define MATHTRANSFORMATION_H

#include <QObject>
#include "model3d.h"
#include <QVector4D>


class MathTransformation : public QObject
{
    Q_OBJECT
public:
    explicit MathTransformation(QObject *parent = nullptr);

    //matrix 4d to move
    //matrix 4d to rotate +
    // + vector calculating(?)
    // vector vector multipliing


    void move_model( Model3D & model, QVector3D bias );
    void rotate_model( Model3D & model, QVector3D angle, QVector4D centre );
    void move_model_on_pos( Model3D & model, QVector3D new_position );

    void move_point( QVector4D &point, QVector3D bias );
    void rotate_point( QVector4D &point, QVector3D angle, QVector4D centre );
    void move_point_to_new_pos(QVector4D &point, QVector3D bias); //point, position*/

    private:

    void rotate_vector_x(QVector4D &vector, float angX);
    void rotate_point_x(QVector4D &point, float angX, QVector4D centre);
    void rotate_vector_y(QVector4D &vector, float angX);
    void rotate_vector_z(QVector4D &vector, float angZ);

signals:

};

#endif // MATHTRANSFORMATION_H
