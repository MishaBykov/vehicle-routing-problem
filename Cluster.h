//
// Created by misha on 04.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_CLUSTER_H
#define VEHICLE_ROUTING_PROBLEM_CLUSTER_H

#include <vector>
#include <cstdio>

struct POINT {
    int x;
    int y;
};

class Cluster {
    std::vector <POINT> scores;
public:
    int curX, curY;//координаты текущего центроида
    int lastX, lastY;//координаты предыдущего центоида
    unsigned long Size();//получаем размер вектора
    inline void Add(POINT pt);//Добавляем пиксель к кластеру
    void SetCenter();

    void Clear();//Чистим вектор
    static Cluster *Bind(int k, Cluster *clusarr, std::vector <POINT> &vpt);

    static void InitialCenter(int k, Cluster *clusarr, std::vector <POINT> &vpt);;

    static void Start(int k, Cluster *clusarr, std::vector <POINT> &vpt);

    inline POINT &at(unsigned i) { return scores.at(i); }//Доступ  к элементам вектора
};


#endif //VEHICLE_ROUTING_PROBLEM_CLUSTER_H
