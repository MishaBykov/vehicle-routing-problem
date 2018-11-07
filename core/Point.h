//
// Created by misha on 06.11.18.
//

#ifndef VEHICLE_ROUTING_PROBLEM_POINT_H
#define VEHICLE_ROUTING_PROBLEM_POINT_H


#include <cmath>
#include <fstream>
#include <vector>

class Point {
public:
    double x;
    double y;

    Point();

    Point(double x, double y);

    bool operator==(Point point);

    static double distance(Point p1, Point p2) {
        return fabs(p1.x - p2.x) + fabs(p1.y - p2.y);
    }

    static std::vector<Point> read_points(const std::string &file_name);
};


#endif //VEHICLE_ROUTING_PROBLEM_POINT_H
