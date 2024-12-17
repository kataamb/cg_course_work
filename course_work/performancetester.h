#ifndef PERFORMANCETESTER_H
#define PERFORMANCETESTER_H

#include <chrono>
#include <vector>
#include <iostream>
#include <fstream>
#include "renderer.h"
#include "model3d.h"
#include "modelbuilder.h"

class PerformanceTester {
public:
    PerformanceTester(Renderer& renderer, QPixmap* pxmp, Light& light)
        : renderer(renderer), pxmp(pxmp), light(light) {}

    void measure_render_time(const std::string& filename) {
        std::ofstream csvFile(filename); // Открываем файл для записи
        if (!csvFile.is_open()) {
            std::cerr << "Ошибка открытия файла!" << std::endl;
            return;
        }

        // Записываем заголовки
        csvFile << "Edges,Time (ms)\n";

        int number;

        for (int numEdges = 3; numEdges <= 100; numEdges += 10) { // Увеличиваем количество граней
            std::vector<Model3D> models;

            // Создаем модели с numEdges гранями
            for (int i = 0; i < 1; ++i) { // Создаем 1 моделей для каждого количества граней
                Model3D model = createModelWithEdges(numEdges); // Функция, создающая модель с заданным количеством граней
                models.push_back(model);
                number = model._edges.size();
            }

            // Измеряем время выполнения
            auto start = std::chrono::high_resolution_clock::now();
            renderer.render_all_models(pxmp, models, light);
            auto end = std::chrono::high_resolution_clock::now();

            // Вычисляем время в миллисекундах
            std::chrono::duration<double, std::milli> duration = end - start;


            // Записываем данные в CSV
            csvFile << number << "," << duration.count() << "\n";
        }

        csvFile.close(); // Закрываем файл
    }

private:
    Model3D createModelWithEdges(int numEdges) {
        ModelCheckBuilder bld;
        QColor color_body = Qt::white;
        float check_height = 50;  // увеличиваем высоту
        float check_radius = 100/2.5;  // увеличиваем радиус
        Model3D model = bld.build_check(check_radius,
            check_radius/4, check_height, numEdges, numEdges,
            color_body, color_body);

        return model;
    }

    Renderer& renderer; // Ссылка на объект Renderer
    QPixmap* pxmp; // Указатель на QPixmap
    Light& light; // Ссылка на объект Light
};

#endif // PERFORMANCETESTER_H
