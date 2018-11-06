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
