#include "model3d.h"

Model3D::Model3D()
{

}

Model3D::Model3D(std::vector<Edge3D> edges, QColor bodyColor, QColor borderColor)
{
    this->bodyColor = bodyColor;
    this->borderColor = borderColor;

    for (auto& edge: edges)
    {
        this->_edges.push_back(edge);
    }
}

void Model3D::add_edge(Edge3D edge)
{
    this->_edges.push_back(edge);
}


void Model3D::set_centre(QVector3D centre)
{
    this->_centre = centre;
}

