#include "model3d.h"
#include <QMatrix4x4>
#include <cmath>
#include <iostream>

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
    this->_centre = {centre[0], centre[1], centre[2], 1};
}

void Model3D::set_centre(QVector4D centre)
{
    this->_centre = centre;
}

float _degrees_to_radians(float degrees)
{
    return degrees * M_PI / 180;
}
void Model3D::rotate(float angleX, float angleY, float angleZ)
{
    std::cout << this->_edges.size()<<std::endl<<std::endl;
    // Преобразуем углы из градусов в радианы
    float radX = _degrees_to_radians(angleX);
    float radY = _degrees_to_radians(angleY);
    float radZ = _degrees_to_radians(angleZ);

    // Создаем матрицы поворота
    QMatrix4x4 rotationX;
    rotationX.rotate(radX, 1.0f, 0.0f, 0.0f); // Поворот вокруг оси X

    QMatrix4x4 rotationY;
    rotationY.rotate(radY, 0.0f, 1.0f, 0.0f); // Поворот вокруг оси Y

    QMatrix4x4 rotationZ;
    rotationZ.rotate(radZ, 0.0f, 0.0f, 1.0f); // Поворот вокруг оси Z

    // Объединяем матрицы поворота
    QMatrix4x4 rotationMatrix = rotationZ * rotationY * rotationX;

    // Применяем матрицу поворота к каждой грани модели
    for (Edge3D &edge : _edges) {
        for (int i = 0; i < 3; ++i) {
            edge._points[i] = rotationMatrix * edge._points[i];
        }
        edge._plane_normal = rotationMatrix * edge._plane_normal; // Поворачиваем нормаль
    }

    // Если необходимо, можно обновить центр модели
    // Например, можно пересчитать центр после поворота.
    std::cout << this->_edges.size() << std::endl;
}


void Model3D::fix_edges_orientation() {
    for (auto& edge : _edges) {
        // Проверяем, смотрит ли нормаль наружу
        QVector3D centreToFace = (edge._points[0].toVector3D() - _centre.toVector3D());
        if (QVector3D::dotProduct(edge._plane_normal.toVector3D(), centreToFace) > 0) {
            // Если нормаль направлена внутрь, меняем порядок вершин
            std::swap(edge._points[1], edge._points[2]);
            edge.calculate_normal();  // Пересчитываем нормаль
        }
    }
}

void  Model3D::calculateVertexNormals() {
    // Очищаем старые нормали
    vertexNormals.clear();

    // Словарь для накопления нормалей для каждой вершины
    std::map<QVector4D, QVector3D, Vector4DCompare> tempNormals;
    std::map<QVector4D, int, Vector4DCompare> vertexCount;

    // Проходим по всем граням
    for (const auto& edge : _edges) {
        // Вычисляем нормаль грани
        QVector3D v1 = (edge._points[1] - edge._points[0]).toVector3D();
        QVector3D v2 = (edge._points[2] - edge._points[0]).toVector3D();
        QVector3D faceNormal = QVector3D::crossProduct(v1, v2);
        faceNormal.normalize();

        // Добавляем нормаль грани к каждой вершине
        for (int i = 0; i < 3; ++i) {
            tempNormals[edge._points[i]] += faceNormal;
            vertexCount[edge._points[i]]++;
        }
    }

    // Вычисляем среднюю нормаль для каждой вершины
    for (auto& pair : tempNormals) {
        QVector3D avgNormal = pair.second / vertexCount[pair.first];
        avgNormal.normalize();
        vertexNormals[pair.first] = QVector4D(avgNormal, 0);
    }
}

// Получение нормали для вершины
QVector4D Model3D::getVertexNormal(const QVector4D& vertex) const {
    auto it = vertexNormals.find(vertex);
    if (it != vertexNormals.end()) {
        return it->second;
    }
    return QVector4D(0, 0, 1, 0); // дефолтная нормаль, если не найдена
}

