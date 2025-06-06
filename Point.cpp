//
// Created by matgiedr on 4/15/24.
//

#include <iostream>
#include "Point.h"

int Point::getY() const {
    return y;
}

int Point::getX() const {
    return x;
}

void Point::setY(int par) {
    this->y = par;
}

void Point::setX(int par) {
    this->x = par;
}

Point::Point(int x, int y): x(x), y(y) {}

bool Point::operator==(const Point &other) const {
    return (x == other.getX() && y == other.getY());
}

std::string Point::pointString(){
    std::string msg;
    msg = "X: "+std::to_string(getX())+", Y: "+std::to_string(getY());
    return msg;
}


