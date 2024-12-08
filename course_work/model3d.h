#ifndef MODEL3D_H
#define MODEL3D_H

#include "edge3d.h"
#include <vector>
#include <QColor>
#include <QVector3D>

struct Vector4DCompare {
    bool operator()(const QVector4D& a, const QVector4D& b) const {
        if (a.x() != b.x()) return a.x() < b.x();
        if (a.y() != b.y()) return a.y() < b.y();
        if (a.z() != b.z()) return a.z() < b.z();
        return a.w() < b.w();
    }
};

class Model3D
{
public:
    Model3D();
    Model3D(std::vector<Edge3D> edges, QColor bodyColor=Qt::white, QColor borderColor=Qt::black);
    void add_edge(Edge3D edge);

    std::vector< Edge3D > _edges;

    QColor bodyColor;
    QColor borderColor;

    QVector4D _centre;
    void set_centre(QVector4D centre);
    void set_centre(QVector3D centre);
    void rotate(float angleX, float angleY, float angleZ);

    void fix_edges_orientation();
    void calculateVertexNormals();
    QVector4D getVertexNormal(const QVector4D& vertex) const;
private:
    std::map<QVector4D, QVector4D, Vector4DCompare> vertexNormals;

};


#endif // MODEL3D_H
