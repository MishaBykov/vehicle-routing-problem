//
// Created by misha on 04.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_CLUSTER_H
#define VEHICLE_ROUTING_PROBLEM_CLUSTER_H

#include <vector>
#include <cstdio>
#include <cstdlib>

struct Point {
    int x;
    int y;

    bool operator==(Point point);

    static int distance(Point p1, Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
};

class Cluster {
    std::vector <Point> points;

    Point center;
    Point oldCenter;

    bool isUpdateCenter = false;

public:
    explicit Cluster();

    unsigned long Size();//получаем размер вектора

    void Add(Point pt);//Добавляем пиксель к кластеру
    void updateCenter();

    void Clear(); //Чистим вектор

    Point &at(unsigned i) { return points.at(i); }//Доступ  к элементам вектора
    Point getCenter() { return center; }
    Point getOldCenter() { return oldCenter; }

    bool isUpadteCenter() { return isUpdateCenter; }
};


#endif //VEHICLE_ROUTING_PROBLEM_CLUSTER_H
