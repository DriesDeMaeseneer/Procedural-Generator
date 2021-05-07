//
// Created by syntaxnoob on 4/3/21.
//

#ifndef PROCEDURAL_GENERATOR_RIVERBEZIER_H
#define PROCEDURAL_GENERATOR_RIVERBEZIER_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cmath>

class Point {
    int x{}, y{};
public:
    Point()= default;
    Point(int in_x, int in_y): x(in_x), y(in_y){}
    int getX() const{return x;}
    int getY() const{return y;}

    template<typename T>
    void operator*(const T& scalar){x = std::round(x*scalar); y = std::round(y*scalar);}

    Point operator*(const Point& in_point) const;
    Point operator+(Point& other_point) const;

};

class RiverBezier {
public:
    static std::vector<std::vector<char>> River(int height, int width, int bridge_amount);
};


#endif //PROCEDURAL_GENERATOR_RIVERBEZIER_H
