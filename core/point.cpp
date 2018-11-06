//
// Created by misha on 06.11.18.
//

#include "point.h"

bool Point::operator==(Point point) {
    return this->x == point.x && this->y == point.y;
}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() {
    x = 0;
    y = 0;
}

std::vector<Point> Point::read_points(const std::string &file_name) {
    std::ifstream fin(file_name);
    unsigned long n;
    fin >> n;
    std::vector <Point> result;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        result.emplace_back(x, y);
    }
    return result;
}
