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

struct Point {
    int x;
    int y;

    Point();
    Point(int x, int y);

    bool operator==(Point point);

    static int distance(Point p1, Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }

    static std::vector<Point> read_points(const std::string &file_name){
        std::ifstream fin(file_name);
        unsigned long n;
        fin >> n;
        std::vector<Point> result;
        for (int i=0; i<n; i++){
            int x, y;
            fin >> x >> y;
            result.emplace_back(x, y);
        }
        return result;
    }
};

class Cluster {
    std::vector <Point> points;

    Point center = Point(0, 0);

    bool updateCenter = false;

public:
    explicit Cluster();

    unsigned long Size();//получаем размер вектора

    void Add(Point pt);//Добавляем пиксель к кластеру
    void UpdateCenter();

    void Clear(); //Чистим вектор

//    Point &at(unsigned i) { return points.at(i); }//Доступ  к элементам вектора
    Point GetCenter() { return center; }

    bool IsUpdateCenter() { return updateCenter; }
};


#endif //VEHICLE_ROUTING_PROBLEM_CLUSTER_H
