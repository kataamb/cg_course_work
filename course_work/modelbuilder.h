#ifndef MODELBUILDER_H
#define MODELBUILDER_H

#include <QObject>
#include <QColor>
#include "model3d.h"
#include <QVector4D>


class ModelBuilder : public QObject
{
    Q_OBJECT
public:
    explicit ModelBuilder(QObject *parent = nullptr);


signals:

};


class ModelCubeBuilder: public ModelBuilder
{
    Q_OBJECT
public:
    ModelCubeBuilder(QObject *parent = nullptr);

    Model3D build_cube(float length, QColor bodyColor = Qt::white, QColor boardColor = Qt::white);
public slots:
    //void build_cube_model(Model3D *model, float length, QColor bodyColor = Qt::white, QColor boardColor = Qt::black); //model already created with  new
    //define copy constructor for model3d
    //void build_cube_model(Model3D *model, float length, QColor bodyColor = Qt::white, QColor boardColor = Qt::black);

signals:
    void ready_cube_model_signal(Model3D model);
private:

};


/*class ModelCylinderBuilder
{
    Q_OBJECT
public:
    ModelCylinderBuilder(QObject *parent = nullptr);




signals:
};*/

#endif // MODELBUILDER_H
