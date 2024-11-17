#include "renderer.h"
#include <QPainter>

#include <iostream>

constexpr float EPS = 1e-7;


Renderer::Renderer(QObject *parent)
    : QObject{parent}
{

}



void Renderer::paint_carcas(QPixmap *pxmp)
{
    /*Model3D curr_model = cubeBuilder.build_cube(100); //

    QPainter painter(pxmp);
    painter.setPen(QPen(curr_model._edges[0].borderColor, 1, Qt::SolidLine));


    for (auto& edge: curr_model._edges)
    {
        QPointF p1 =  {edge._points[0][0], edge._points[0][1]};
        QPointF p2 =  {edge._points[1][0], edge._points[1][1]};
        QPointF p3 =  {edge._points[2][0], edge._points[2][1]};

        painter.drawLine( p1, p2 );
        painter.drawLine( p2, p3 );
        painter.drawLine( p3, p1 );
    }
*/

}


void Renderer::paint_carcas_all(QPixmap *pxmp, std::vector<Model3D> models)
{
    /*Model3D curr_model = cubeBuilder.build_cube(100); //

    QPainter painter(pxmp);
    painter.setPen(QPen(curr_model._edges[0].borderColor, 1, Qt::SolidLine));


    for (auto& edge: curr_model._edges)
    {
        QPointF p1 =  {edge._points[0][0], edge._points[0][1]};
        QPointF p2 =  {edge._points[1][0], edge._points[1][1]};
        QPointF p3 =  {edge._points[2][0], edge._points[2][1]};

        painter.drawLine( p1, p2 );
        painter.drawLine( p2, p3 );
        painter.drawLine( p3, p1 );
    }*/

    std::map<int, QColor> color_square {
                                       {0, QColor(Qt::red)}, {1, Qt::black},  {2, QColor(Qt::yellow)},
                                       {3, QColor(Qt::green)}, {4, QColor(Qt::cyan)},
                                       {5, QColor(Qt::blue)}, {6, QColor(Qt::magenta)},
                                        {7, QColor(Qt::white)},
                                       };

    QPainter painter(pxmp);
    for (auto& model: models)
    {
        int col = 0;
        ///painter.setPen(QPen(model.borderColor, 1, Qt::SolidLine));
        for (auto& edge: model._edges)
        {
            //painter.setPen(QPen(color_square[col], 1, Qt::SolidLine));
            painter.setPen(QPen(model.borderColor, 1, Qt::SolidLine));
            col++;
            QPointF p1 =  {edge._points[0][0], edge._points[0][1]};
            QPointF p2 =  {edge._points[1][0], edge._points[1][1]};
            QPointF p3 =  {edge._points[2][0], edge._points[2][1]};

            painter.drawLine( p1, p2 );
            painter.drawLine( p2, p3 );
            painter.drawLine( p3, p1 );
        }
    }

}

QPointF min_point_y(std::vector<QPointF> vec)
{
    QPointF min_y = vec[0];
    for (auto& point: vec)
    {
        if (point.y() < min_y.y() ) { min_y = point;}
    }
    return min_y;

}

QPointF max_point_y(std::vector<QPointF> vec)
{
    QPointF max_y = vec[0];
    for (auto& point: vec)
    {
        if (point.y() > max_y.y() ) { max_y = point;}
    }
    return max_y;

}

/* \ */
void sort_points_y(std::vector<QPointF> & vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        for (size_t j = i+1; j < vec.size(); ++j)
        {
            if (vec[i].y() > vec[j].y())
            {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}

/*float calculateDepth(int x, int y, const QPointF &p1, const QPointF &p2, const QPointF &p3) {
    // Здесь можно использовать барицентрические координаты или другую формулу
    // для вычисления глубины в зависимости от x и y.
    // Например:
    float alpha = ((p2.y() - p3.y()) * (x - p3.x()) + (p3.x() - p2.x()) * (y - p3.y())) /
                   ((p2.y() - p3.y()) * (p1.x() - p3.x()) + (p3.x() - p2.x()) * (p1.y() - p3.y()));
    float beta = ((p3.y() - p1.y()) * (x - p3.x()) + (p1.x() - p3.x()) * (y - p3.y())) /
                  ((p2.y() - p3.y()) * (p1.x() - p3.x()) + (p3.x() - p2.x()) * (p1.y() - p3.y()));
    float gamma = 1.0f - alpha - beta;

    return alpha * p1.z() + beta * p2.z() + gamma * p3.z(); // Предполагается, что у вас есть z-координаты у точек
}*/

void Renderer::fill_color_edges(QPixmap *pxmp, std::vector<Model3D> models)
{
    QImage image(pxmp->toImage().convertToFormat(QImage::Format_ARGB32));
    QPainter painter(pxmp);

    std::map<int, QColor> color_square {{0, QColor(Qt::red)}, {1, QColor(246, 99, 8)},
                                       {2, QColor(Qt::yellow)}, {3,QColor(Qt::green)},
                                       {4, QColor(Qt::cyan)}, {5, QColor(Qt::blue)},
                                       {6, QColor(128, 0, 255)}, {7, QColor(Qt::magenta)},
                                        {8, QColor(150, 75, 0)}, {9, QColor(Qt::black)},
                                        {10, QColor(255, 192, 203)}, {11, QColor(Qt::white)},
                                       };

    //int col = 0;
    for (auto& model: models)
    {

        for (auto& edge: model._edges)
        {
            //painter.setPen(QPen(color_square[col], Qt::DashLine ));
            painter.setPen(QPen(model.bodyColor, Qt::DashLine ));
            //col++;
            //1. get three points of current triangle and sort them by y
            QPointF q1 =  {edge._points[0][0], edge._points[0][1]};
            QPointF q2 =  {edge._points[1][0], edge._points[1][1]};
            QPointF q3 =  {edge._points[2][0], edge._points[2][1]};

            std::vector<QPointF> triangle_points { q1, q2, q3 };

            sort_points_y(triangle_points);

            QPointF p1 = triangle_points[0], p2 = triangle_points[1], p3 = triangle_points[2];

            //2.Вычисляем приращения по оси x для трёх сторон треугольника.
            // Если ординаты двух точек совпадают (отсутствует верхний, нижний или оба полутреугольника), приращения полагаются равными нулю.
            // приращения по оси x для трёх сторон
            // треугольника
            float dx13 = 0, dx12 = 0, dx23 = 0;


             // вычисляем приращения
             // в случае, если ординаты двух точек
             // совпадают, приращения
             // полагаются равными нулю
             if ( abs(p3.y() - p1.y()) > EPS )
             {
                    dx13 = (p3.x() - p1.x());
                    dx13 /= (p3.y() - p1.y());
             }

             if ( abs(p2.y() - p1.y()) > EPS )
             {
                        dx12 = (p2.x() - p1.x());
                        dx12 /= (p2.y() - p1.y());
             }

             if ( abs(p3.y() - p2.y()) > EPS )
             {
                        dx23 = p3.x() - p2.x();
                        dx23 /= (p3.y() - p2.y());
             }


             //3.
             // "рабочие точки"
             // изначально они находятся в верхней точке


             float line12 = p1.x();
             float line13 = p1.x();


             //???????

             //4. сохраняем приращение dx13 в другой переменной
             float _dx13 = dx13;



             std::cout << "p1:" << p1.x() << " " << p1.y() << std::endl;
             std::cout << "p2:" << p2.x() << " " << p2.y() << std::endl;
             std::cout << "p3:" << p3.x() << " " << p3.y() << std::endl;

             std::cout << "d13 d12 d23:" << dx13 << " " << dx12 << " " << dx23 << std::endl;


             //std::cout << "begin x end x:" << begin_x << " " << end_x << std::endl;



             //6.
             // растеризуем верхний полутреугольник
             for (int i = p1.y(); i < p2.y(); i++)
             {
                 float cur_beg = line13, cur_end = line12;
                 if (cur_beg > cur_end) {std::swap(cur_beg, cur_end);}

                    // рисуем горизонтальную линию между рабочими
                    // точками
                    for (int j = (cur_beg); j <= (cur_end); j++)
                    {
                       painter.drawPoint(QPointF(j, i));
                    }
                    painter.drawPoint(QPointF(cur_beg, i));
                    painter.drawPoint(QPointF(cur_end, i));

                    line13 += dx13;
                    line12 += dx12;

              }

             //7. вырожденный случай, когда верхнего полутреугольника нет
             // надо разнести рабочие точки по оси x, т.к. изначально они совпадают


             float line23 = line12;

             if ( abs(p1.y() - p2.y()) < EPS )
             {
                     line13 = p1.x();
                     line23 = p2.x();
             }



             //9. растеризуем нижний полутреугольник
             for (int i = p2.y(); i <= p3.y(); i++)
             {
             // рисуем горизонтальную линию между рабочими
             // точками
                 float cur_beg = line13, cur_end = line23;
                 if (cur_beg > cur_end) {std::swap(cur_beg, cur_end);}
                for (int j = cur_beg; j <= cur_end; j++)
                {
                    //SetPixel(hdc, j, i, 0);
                    painter.drawPoint(QPointF(j, i));
                }
                 painter.drawPoint(QPointF(cur_beg, i));
                 painter.drawPoint(QPointF(cur_end, i));

                line13 += dx13;
                line23 += dx23;
             }




        }
    }

}




void Renderer::draw_initial_image(QPixmap *pxmp, std::vector<Model3D> models)
{
    //paint_carcas(pxmp);
    paint_carcas_all(pxmp, models);
    fill_color_edges(pxmp, models);
}


void Renderer::change_image(QPixmap *pxmp, QColor bgColor)
{

}



