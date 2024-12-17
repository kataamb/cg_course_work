#include "renderer.h"
#include <QPainter>

#include <iostream>


constexpr float EPS = 1e-7;
constexpr float Z_BUF = 0;

Renderer::Renderer(QObject *parent, int h, int w)
    : QObject{parent}
{
   zBuf = std::vector<std::vector<double>>(h, std::vector<double>(w, std::numeric_limits<double>::max()));
    this->height = h;
    this->width = w;
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

void sort_points_y(std::vector<QVector4D> & vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        for (size_t j = i+1; j < vec.size(); ++j)
        {
            if (vec[i][1] > vec[j][1])
            {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}


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

void Renderer::clearZBuffer() {
    for (auto& row : zBuf) {
        std::fill(row.begin(), row.end(), std::numeric_limits<double>::max());
    }
}

void Renderer::render_all_models(QPixmap *pxmp, std::vector<Model3D> models, Light & light) {
    clearZBuffer();
    QPainter painter(pxmp);

    for (auto& model : models) {
        model.calculateVertexNormals();

        for (const auto& edge : model._edges) {

                render_edge(pxmp, painter, model, const_cast<Edge3D&>(edge), QColor(model.bodyColor), light);
            }
        }
}

double calculateZ(const Edge3D& edge, double x, double y) {
    QVector4D normal = edge._plane_normal;
    QVector4D point = edge._points[0];

    if (std::abs(normal.z()) < EPS) {  // используем EPS вместо qFuzzyIsNull
        return point.z();
    }

    double d = -(normal.x() * point.x() +
                 normal.y() * point.y() +
                 normal.z() * point.z());

    double z = -(normal.x() * x + normal.y() * y + d) / normal.z();

    // Добавляем небольшое смещение для избежания артефактов
    return z + EPS;
}

void Renderer::render_edge(QPixmap *pxmp, QPainter & painter, Model3D & model, Edge3D & edge, Color color, Light light)
{
    QVector4D p1 = edge._points[0], p2 = edge._points[1], p3 = edge._points[2];
    std::vector<QVector4D> triangle_points { p1, p2, p3 };
    sort_points_y(triangle_points);
    p1 = triangle_points[0], p2 = triangle_points[1], p3 = triangle_points[2];

    // Вычисляем нормали
    QVector4D n1 = model.getVertexNormal(p1);
       QVector4D n2 = model.getVertexNormal(p2);
       QVector4D n3 = model.getVertexNormal(p3);


    // Вычисляем интенсивность цвета для каждой вершины
    Color c0 = calculate_intensity(color, 0.9, n1, light);
    Color c1 = calculate_intensity(color, 0.9, n2, light);
    Color c2 = calculate_intensity(color, 0.9, n3, light);
    Color resCol, colXstart, colXend;

    float y;
    int yStart = static_cast<int>(p1[1]);
    int yEnd = static_cast<int>(p3[1]);

    // Проходим по всем строкам треугольника
    for (int yCount = yStart; yCount <= yEnd; yCount++) {
        y = static_cast<float>(yCount);
        if (yCount < 0 || yCount >= this->height) continue;

        float x1, x2;
        bool below1;
        bool res = do_intersect(p1, p2, p3, y, x1, x2, below1);
        if (!res) continue;

        int xStart, xEnd;
        // Определяем начальную и конечную точки для текущей строки
        if (below1) {
            if (x1 < x2) {
                xStart = std::max(0, static_cast<int>(x1));
                xEnd = std::min(this->width - 1, static_cast<int>(x2));
                colXstart = interpolate_color(p1[1], p2[1], y, c0, c1);
                colXend = interpolate_color(p1[1], p3[1], y, c0, c2);
            }
            else {
                xStart = std::max(0, static_cast<int>(x2));
                xEnd = std::min(this->width - 1, static_cast<int>(x1));
                colXend = interpolate_color(p1[1], p2[1], y, c0, c1);
                colXstart = interpolate_color(p1[1], p3[1], y, c0, c2);
            }
        }
        else {
            if (x1 < x2) {
                xStart = std::max(0, static_cast<int>(x1));
                xEnd = std::min(this->width - 1, static_cast<int>(x2));
                colXstart = interpolate_color(p2[1], p3[1], y, c1, c2);
                colXend = interpolate_color(p1[1], p3[1], y, c0, c2);
            }
            else {
                xStart = std::max(0, static_cast<int>(x2));
                xEnd = std::min(this->width - 1, static_cast<int>(x1));
                colXend = interpolate_color(p2[1], p3[1], y, c1, c2);
                colXstart = interpolate_color(p1[1], p3[1], y, c0, c2);
            }
        }

        // Рисуем пиксели для текущей строки
        for (int x = xStart; x <= xEnd; x++) {
            std::vector<double> bary = barycentric(p1, p2, p3, x, y);

            // Проверяем, что точка внутри треугольника
            if (bary[0] < 0 || bary[1] < 0 || bary[2] < 0)
                continue;

            // Интерполируем цвет
            resCol = interpolate_color(xStart, xEnd, (float)x, colXstart, colXend);

            // Отрисовка пикселя
            //painter.setPen(QPen(QColor(resCol.getI_R(), resCol.getI_G(), resCol.getI_B()), Qt::DashLine));
            //painter.drawPoint(QPointF(x, yCount));
            double z = calculateZ(edge, x, yCount);
            if (this->zBuf[x][yCount] >= (z+EPS))
            {
                painter.setPen(QPen(QColor(resCol.getI_R(), resCol.getI_G(), resCol.getI_B()), Qt::DashLine));
                painter.drawPoint(QPointF(x, yCount));
                this->zBuf[x][yCount] = z;
            }
        }
    }
}

Color Renderer::calculate_phong_lighting(const Color &materialColor,
                                       const QVector4D &normal,
                                       const Light &light,
                                       const QVector4D &point) {
    // Нормализованные векторы для расчетов
    QVector4D N = normal.normalized();
    QVector4D L = (light.getPos() - point).normalized();

    // Коэффициенты для модели освещения
    const float ka = 0.1f;  // ambient coefficient
    const float kd = 0.2f;  // diffuse coefficient
    const float ks = 0.2f;  // specular coefficient
    const float shininess = 128.0f;

    // Ambient component
    float ambient = ka;

    // Diffuse component
    float diffuse = kd * std::max(0.0f, QVector4D::dotProduct(N, L));

    // Specular component
    QVector4D V = QVector4D(0, 0, 1, 0); // Вектор к наблюдателю (предполагаем, что камера смотрит вдоль оси Z)
    QVector4D R = (2.0f * QVector4D::dotProduct(N, L) * N - L).normalized();
    float specular = ks * std::pow(std::max(0.0f, QVector4D::dotProduct(R, V)), shininess);

    // Вычисляем итоговую интенсивность с учетом интенсивности источника света
    float intensity = (ambient + diffuse + specular) * light.getI();

    // Ограничиваем значения интенсивности
    intensity = std::min(1.0f, std::max(0.0f, intensity));

    // Применяем интенсивность к каждой компоненте цвета
    Color result(materialColor.getR(), materialColor.getG(), materialColor.getB());
    result.setI_R(materialColor.getR() * intensity);
    result.setI_G(materialColor.getG() * intensity);
    result.setI_B(materialColor.getB() * intensity);

    float lightIntensity = light.getI();
       result.setI_R(materialColor.getR() * intensity * lightIntensity);
       result.setI_G(materialColor.getG() * intensity * lightIntensity);
       result.setI_B(materialColor.getB() * intensity * lightIntensity);

    return result;
}

Color Renderer::calculate_intensity(const Color &color, float mProp, const QVector4D normal, const Light &light)
{
    /*Color col(color.getR(), color.getG(), color.getB());

    col.setI_R(mProp * color.getI_R());
    col.setI_G(mProp * color.getI_G());
    col.setI_B(mProp * color.getI_B());

    float dotProd = mth.scalarProduct(light.getDir(), normal);
    float kD = std::max(0.0f, dotProd);

    col.setI_R(std::min(255.0f, col.getI_R() + mProp * color.getR() * kD));
    col.setI_G(std::min(255.0f, col.getI_G() + mProp * color.getG() * kD));
    col.setI_B(std::min(255.0f, col.getI_B() + mProp * color.getB() * kD));

    return col;*/
    /*float ambientStrength = 0.3f;
       float diffuseStrength = 0.7f;
       float specularStrength = 0.5f;
       float shininess = 32.0f;

       QVector4D normalizedNormal = normal.normalized();
       QVector4D normalizedLightDir = light.getDir().normalized();

       // Ambient
       Color col(color.getR(), color.getG(), color.getB());
       col.setI_R(ambientStrength * color.getI_R());
       col.setI_G(ambientStrength * color.getI_G());
       col.setI_B(ambientStrength * color.getI_B());

       // Diffuse
       float diff = std::max(QVector4D::dotProduct(normalizedNormal, normalizedLightDir), 0.0f);

       // Specular
       QVector4D viewDir(0, 0, 1, 0);  // Направление взгляда
       QVector4D reflectDir = 2.0f * QVector4D::dotProduct(normalizedLightDir, normalizedNormal) * normalizedNormal - normalizedLightDir;
       float spec = std::pow(std::max(QVector4D::dotProduct(viewDir, reflectDir), 0.0f), shininess);

       // Комбинируем все компоненты
       float totalIntensity = ambientStrength + diff * diffuseStrength + spec * specularStrength;

       col.setI_R(std::min(255.0f, color.getR() * totalIntensity * light.getI()));
       col.setI_G(std::min(255.0f, color.getG() * totalIntensity * light.getI()));
       col.setI_B(std::min(255.0f, color.getB() * totalIntensity * light.getI()));

       return col;*/
    float ambientStrength = 0.7f;  // было 0.2
        float diffuseStrength = 0.9f;  // было не задано явно

        Color col(color.getR(), color.getG(), color.getB());

        // Ambient component (фоновое освещение)
        col.setI_R(ambientStrength * color.getI_R());
        col.setI_G(ambientStrength * color.getI_G());
        col.setI_B(ambientStrength * color.getI_B());

        // Diffuse component (рассеянное освещение)
        QVector4D normalizedNormal = normal.normalized();
        QVector4D normalizedLightDir = light.getDir().normalized();
        float dotProd = QVector4D::dotProduct(normalizedLightDir, normalizedNormal);
        float kD = std::max(0.0f, dotProd) * diffuseStrength;

        // Комбинируем ambient и diffuse компоненты
        col.setI_R(std::min(255.0f, col.getI_R() + color.getR() * kD * light.getI()));
        col.setI_G(std::min(255.0f, col.getI_G() + color.getG() * kD * light.getI()));
        col.setI_B(std::min(255.0f, col.getI_B() + color.getB() * kD * light.getI()));

        return col;
}

// Проверка пересечения сканирующей строки и граней треугольника
bool Renderer::do_intersect(const QVector4D & p0, const QVector4D & p1, const QVector4D & p2, float y, float& x1, float& x2, bool& below1)
{
    below1 = false;
    if (y < p0[1] || y > p2[1])
    {
        x1 = x2 = -1.0f;
        return false;
    }
    else if (y == p0[1] && y == p1[1] && y == p2[1])
    {
        x1 = x2 = p0[0] + (static_cast<double>(y - p0[0]) / static_cast<double>(p1[1] - p0[1])) * (p1[0] - p0[0]); //-1.0f;
        return true;
    }
    else if (y >= p0[1] && y < p1[1])
    {
        x1 = p0[0] + (static_cast<double>(y - p0[1]) / static_cast<double>(p1[1] - p0[1])) * (p1[0] - p0[0]);
        x2 = p0[0] + (static_cast<double>(y - p0[1]) / static_cast<double>(p2[1] - p0[1])) * (p2[0] - p0[0]);
        below1 = true;
        return true;
    }
    else
    {
        x1 = p2[0] + (static_cast<double>(y - p2[1]) / static_cast<double>(p1[1] - p2[1])) * (p1[0] - p2[0]);
        x2 = p2[0] + (static_cast<double>(y - p2[1]) / static_cast<double>(p0[1] - p2[1])) * (p0[0] - p2[0]);
        return true;
    }
}

std::vector<double> Renderer::barycentric(QVector4D &v0, QVector4D &v1, QVector4D &v2, double x, double y) {
    double denominator = (v1[1] - v2[1]) * (v0[0] - v2[0]) + (v2[0] - v1[0]) * (v0[1] - v2[1]);
    if (std::abs(denominator) < EPS) {
        return {-1, -1, -1}; // Вырожденный треугольник
    }

    double alpha = ((v1[1] - v2[1]) * (x - v2[0]) + (v2[0] - v1[0]) * (y - v2[1])) / denominator;
    double beta = ((v2[1] - v0[1]) * (x - v2[0]) + (v0[0] - v2[0]) * (y - v2[1])) / denominator;
    double gamma = 1.0 - alpha - beta;

    return {alpha, beta, gamma};
}

bool Renderer::isPointInsideTriangle(QVector4D &v0, QVector4D &v1, QVector4D &v2, double x, double y) {
   /*std::vector<double> bary = barycentric(v0, v1, v2, x, y);
    if (bary[0] < 0) return false; // Проверка на вырожденный треугольник

    const float EPSILON = -1e-4f; // Увеличьте значение epsilon
    return bary[0] >= EPSILON && bary[1] >= EPSILON && bary[2] >= EPSILON;*/
    std::vector<double> barCoords = barycentric(v0, v1, v2, x, y);
      double alpha = barCoords[0];
      double beta = barCoords[1];
      double gamma = barCoords[2];

      return alpha >= EPS && beta >= EPS && gamma >= EPS;
}

Color Renderer::interpolate_color(float x1, float x2, float x, const Color &col1, const Color &col2)
{
    Color col(col1.getR(), col1.getG(), col1.getB());

    if (fabs(x1 - x2) > EPS && x >= (int)x1 && x <= (int)x2)
    {
        col.setI_R(col1.getI_R() + (col2.getI_R() - col1.getI_R()) * ((x - x1) / (x2 - x1)));
        col.setI_G(col1.getI_G() + (col2.getI_G() - col1.getI_G()) * ((x - x1) / (x2 - x1)));
        col.setI_B(col1.getI_B() + (col2.getI_B() - col1.getI_B()) * ((x - x1) / (x2 - x1)));
    }

    col.setI_R(std::min(255.0f, col.getI_R()));
    col.setI_G(std::min(255.0f, col.getI_G()));
    col.setI_B(std::min(255.0f, col.getI_B()));

    return col;
}


//--------------------

void Renderer::draw_initial_image(QPixmap *pxmp, std::vector<Model3D> models, Light light)
{
    for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                zBuf[y][x] = std::numeric_limits<double>::max();
            }
        }

    this->render_all_models(pxmp, models, light);
}

