#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "model3d.h"
#include "modelbuilder.h"
#include "light.h"
#include "mathtransformation.h"

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    std::vector<Model3D> get_all_models();

    void make_initial_state();

    void add_light_source(Light light);

    std::vector<Light> get_light_sources();
    /*void rotate();
    void move();
    void move_check();*/
private:
    std::vector<Model3D> chessBoardSquares;
    //std::vector<Model3D> whiteChecks;
    //std::vector<Model3D> blackChecks;

    std::vector<Light> lightSources;


    QVector3D centreScene;

    MathTransformation _positionChanger;



    QVector4D _centreComposition;



    void move_item(Model3D &item, QVector3D bias);
signals:
    void changed_scene_objects();

};

#endif // SCENE_H

