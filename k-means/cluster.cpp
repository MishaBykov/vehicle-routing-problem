//
// Created by misha on 04.11.18.
//

#include <cmath>
#include "cluster.h"

void Cluster::updateCenter(){
    Point oldCenter;
    unsigned long size = Size();
    Point point_max{0, 0}, point_min{0, 0};
    if (size > 0) {
        point_min.x = points[0].x;
        point_min.y = points[0].y;
        point_max.x = points[0].x;
        point_max.y = points[0].y;
    }
    else
        return;

    for(int i = 1; i < size; i++) {
        if ( point_min.x > points[i].x )
            point_min.x = points[i].x;

        if ( point_min.y > points[i].y )
            point_min.y = points[i].y;

        if ( point_max.x < points[i].x )
            point_max.x = points[i].x;

        if ( point_max.y < points[i].y )
            point_max.y = points[i].y;
    }
    oldCenter = center;
    center.x = (point_min.x + point_max.x) / 2;
    center.y = (point_min.y + point_max.y)/ 2;
    isUpdateCenter = !(oldCenter == center);
}

void Cluster::Clear(){
    points.clear();
}

unsigned long Cluster::Size() {
    return points.size();
}

void Cluster::Add(Point point) { points.push_back(point); }

Cluster::Cluster() {}

bool Point::operator==(Point point) {
    return this->x == point.x && this->y == point.y;
}
