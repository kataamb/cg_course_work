#ifndef MODEL3D_H
#define MODEL3D_H

#include "edge3d.h"
#include <vector>
#include <QColor>
#include <QVector3D>

class Model3D
{
public:
    Model3D();
    Model3D(std::vector<Edge3D> edges, QColor bodyColor=Qt::white, QColor borderColor=Qt::black);
    void add_edge(Edge3D edge);

    std::vector< Edge3D > _edges;

    QColor bodyColor;
    QColor borderColor;

    QVector3D _centre;
    void set_centre(QVector3D centre);
private:


};



#endif // MODEL3D_H
