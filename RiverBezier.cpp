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

    Point p0(0, rand()%height);
    Point p1(rand()%width, 0);
    Point p2(width, rand()%height);
    Point p3(rand()%width, height);

    first_points.push_back(p0);
    first_points.push_back(p1);
    first_points.push_back(p2);
    first_points.push_back(p3);

    int first_id = rand()%4;
    int second_id = rand()%4;
    int third_id = 0;
    int fourth_id = 0;
    while(first_id==second_id )second_id = rand()%4;
    while(first_id==third_id or third_id==second_id)third_id = rand()%4;
    while(first_id==fourth_id or fourth_id==second_id or fourth_id== third_id) fourth_id = rand()%4;

    std::vector<Point> line_points;

    // first en second are different.
    for(int i{0};i<1000;i++){
        double t = (double)i/1000;
        double x_result, y_result;
        x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
        y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*t*first_points[second_id].getY())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
        Point a(std::round(x_result), std::round(y_result));
        line_points.push_back(a);
    }
    std::cout<<"ALL FINISHED"<<line_points.size()<<std::endl;
    for(auto& it:line_points){
        if(it.getX()<width and it.getY()<height){
            map[it.getY()][it.getX()] = '@';
        }
    }

    return map;
}
