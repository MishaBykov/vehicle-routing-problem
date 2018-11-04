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

    static int distanse(Point p1, Point p2) {
        return abs(p1.x - p2.x) + abs(p1.y - p2.y);
    }
};

class Cluster {
    std::vector <Point> points;

    int curX, curY;//координаты текущего центроида
    int lastX, lastY;//координаты предыдущего центоида
    unsigned long Size();//получаем размер вектора
public:
    inline void Add(Point pt);//Добавляем пиксель к кластеру
    void SetCenter();

    void Clear();//Чистим вектор
    static Cluster *Bind(int k, Cluster *clusarr, std::vector <Point> &vpt);

    static void InitialCenter(int k, Cluster *clusarr, std::vector <Point> &vpt);;

    static void Start(int k, Cluster *clusarr, std::vector <Point> &vpt);

    inline Point &at(unsigned i) { return scores.at(i); }//Доступ  к элементам вектора
};


#endif //VEHICLE_ROUTING_PROBLEM_CLUSTER_H
