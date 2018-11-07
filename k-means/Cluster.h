//
// Created by misha on 04.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_CLUSTER_H
#define VEHICLE_ROUTING_PROBLEM_CLUSTER_H

#include <vector>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include "../core/Point.h"

class Cluster {
    std::vector <Point> points;

    const double eps = 0.00001;
    Point center;

    bool updateCenter = false;

public:
    explicit Cluster();

    unsigned long Size();//получаем размер вектора

    void Add(Point pt);//Добавляем пиксель к кластеру
    void insertBegin(Point p);
    void UpdateCenter();

    void Clear(); //Чистим вектор

//    Point &at(unsigned i) { return points.at(i); }//Доступ  к элементам вектора
    Point GetCenter() {
        return center;
    }

    std::vector<Point>& getPoints();

    void SetCenter(double x, double y) {
        center.x = x;
        center.y = y;
    }

    bool IsUpdateCenter() { return updateCenter; }
};


#endif //VEHICLE_ROUTING_PROBLEM_CLUSTER_H
