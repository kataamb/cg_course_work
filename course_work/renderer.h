#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QPixmap>
#include "model3d.h"
#include "modelbuilder.h"
#include "color.h"
#include "light.h"
#include "mathtransformation.h"

/*
 * class which changes or creates, if initial state, pixmap to show
 */

class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr, int w = 9669, int h = 1079);

    //inline QPixmap * get_pixmap(){ return _curPxmp; }

    //void perspectivize_objects();
    void paint_carcas(QPixmap *pxmp);
    void paint_carcas_all(QPixmap *pxmp, std::vector<Model3D> models);
    void fill_color_edges(QPixmap *pxmp, std::vector<Model3D> models);
    void render_all_models(QPixmap *pxmp, std::vector<Model3D> models, Light & light);

    void render_edge(QPixmap *pxmp, QPainter & painter, Model3D & model, Edge3D & edge, Color color, Light light);
    //void make_shaded_edges();

    //void cut_invisible_edges();

    //void draw_initial_image(QPixmap *pxmp, std::vector<Model3D> models,  Light & light);
    void draw_initial_image(QPixmap *pxmp, std::vector<Model3D> models, Light light);
    Color calculate_phong_lighting(const Color &materialColor,
                                           const QVector4D &normal,
                                           const Light &light,
                                           const QVector4D &point);


    //---
    Color calculate_intensity(const Color &color, float mProp, const QVector4D normal, const Light &light);
    Color interpolate_color(float x1, float x2, float x, const Color &col1, const Color &col2);
    std::vector<double> barycentric(QVector4D &v0, QVector4D &v1, QVector4D &v2, double x, double y);
    bool do_intersect(const QVector4D & p0, const QVector4D & p1, const QVector4D & p2, float y, float& x1, float& x2, bool& below1);
    bool isPointInsideTriangle(QVector4D & v0, QVector4D & v1, QVector4D & v2, double x, double y);

private:
     QPixmap *_curPxmp;
     int height;
     int width;

     std::vector<std::vector<double>> zBuf; // z-буфер

     MathTransformation mth;//for different math operations and transformations

     void clearZBuffer();


     ////ModelCubeBuilder cubeBuilder;
     //Camera *_camera
     //Scene *_scene
public slots:
     //void change_image(QPixmap *, QColor);

signals:
     void ready_pixmap_signal(QPixmap *);



};

#endif // RENDERER_H
