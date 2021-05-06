//
// Created by syntaxnoob on 4/3/21.
//

#include <cmath>
#include "RiverBezier.h"

std::vector<std::vector<char>> RiverBezier::River(int height, int width) {
    int k=time(nullptr);

    std::srand(k);

    std::vector<std::vector<char>> map;

    std::vector<char> tmp;
    tmp.resize(width, '-');
    map.resize(height, tmp);

    // generate all point positions and push back on first_points vector.
    // first = y = height,
    // second = x = width.
    std::vector<Point> first_points;

    Point p0(0, rand()%(height-2)+1);
    Point p1(rand()%(width-2)+1, 0);
    Point p2(width, rand()%(height-2)+1);
    Point p3(rand()%(width-2)+1, height);

    first_points.push_back(p0);
    first_points.push_back(p1);
    first_points.push_back(p2);
    first_points.push_back(p3);

    int random_start = rand()%4;
    int first_id{random_start}, second_id, third_id, fourth_id;
    if(random_start%2 == 0){
        second_id = (random_start+1)%4;
        third_id = (random_start+2)%4;
        fourth_id = (random_start+3)%4;
    }
    else{
        second_id = (random_start+1)%4;
        third_id = (random_start+3)%4;
        fourth_id = (random_start+2)%4;
    }

    std::vector<Point> line_points;

    // first en second are different.
    for(int i{0};i<500;i++){
        double t = (double)i/500;
        double x_result, y_result;
        x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
        y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*t*first_points[second_id].getY())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
        Point a(std::round(x_result), std::round(y_result));
        x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX()+1)+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
        Point b(std::round(x_result), std::round(y_result));
        line_points.push_back(a);
        line_points.push_back(b);
    }
    // second layer for thickness
    for(std::vector<Point>::iterator it = line_points.begin();it!=line_points.end();it++){
        if(it->getX()<width and it->getY()<height){
            map[it->getY()][it->getX()] = 'w'; // w stand for water obstacle
        }
    }

    return map;
}
