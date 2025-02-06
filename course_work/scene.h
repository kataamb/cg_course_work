#ifndef SCENE_H
#define SCENE_H

#include <QObject>
#include "model3d.h"
#include "modelbuilder.h"
#include "light.h"
#include "mathtransformation.h"

#include "gamecheckcolor.h"

#include "gamecheck.h"

class Scene : public QObject
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    std::vector<Model3D> get_all_models();

    void make_initial_state();

    Light get_light_sources();

    void rotate_composition(QVector3D angle);
    void rotate_composition_backward(QVector3D angle);
    void move_all_models(const QVector3D& newPosition);

    void move_all_models_on_pos(const QVector3D& newPosition);

    void update_scene_with_checks(const std::map<std::pair<int, int>, GameCheck>& checksOnPositions);

private:
    std::vector<Model3D> chessBoardSquares;
    std::vector<Model3D> whiteChecks;
    std::vector<Model3D> blackChecks;

    Light lightSource;

    QVector3D centreScene;

    MathTransformation _positionChanger;

    QVector4D _centreComposition;

    QVector3D _initialAngle;

    QVector3D _currentAngle;

    QVector4D _currentBias;

    float _squareLength;


signals:
    void changed_scene_objects();

};

#endif // SCENE_H

