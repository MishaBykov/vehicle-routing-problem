//
// Created by misha on 06.11.18.
//

#include <iostream>
#include "Point.h"

bool Point::operator==(Point point) {
    return this->x == point.x && this->y == point.y;
}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point() {
    x = 0;
    y = 0;
}

std::vector<Point> Point::read_points(const std::string &file_name) {
    std::vector <Point> result;
    std::ifstream fin;
    fin.open(file_name);
    if (!fin.is_open()) {
        std::cout << "Файл не найден" << std::endl;
        return result;
    }
    unsigned long n;
    fin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        fin >> x >> y;
        result.emplace_back(x, y);
    }
    return result;
}
