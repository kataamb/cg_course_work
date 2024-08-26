#ifndef RENDERER_H
#define RENDERER_H

#include <QObject>
#include <QPixmap>
#include "model3d.h"
#include "modelbuilder.h"

/*
 * class which changes or creates, if initial state, pixmap to show
 */

class Renderer : public QObject
{
    Q_OBJECT
public:
    explicit Renderer(QObject *parent = nullptr);

    //inline QPixmap * get_pixmap(){ return _curPxmp; }

    //void perspectivize_objects();
    void paint_carcas(QPixmap *pxmp);
    void paint_carcas_all(QPixmap *pxmp, std::vector<Model3D> models);
    void fill_color_edges(QPixmap *pxmp, std::vector<Model3D> models);
    //void make_shaded_edges();

    //void cut_invisible_edges();

    void draw_initial_image(QPixmap *pxmp, std::vector<Model3D> models);

private:
     QPixmap *_curPxmp;

     ////ModelCubeBuilder cubeBuilder;
     //Camera *_camera
     //Scene *_scene
public slots:
     void change_image(QPixmap *, QColor);

signals:
     void ready_pixmap_signal(QPixmap *);



};

#endif // RENDERER_H
