//
// Created by syntaxnoob on 4/3/21.
//

#include "Point.h"

Point Point::operator+(Point &other_point) const {
    return {x+other_point.getX(), y+other_point.getY()};
}

Point Point::operator*(const Point &in_point) const {
    return {x*in_point.getX(), y*in_point.getY()};
}
