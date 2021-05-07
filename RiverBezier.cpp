//
// Created by syntaxnoob on 4/3/21.
//

#include <cmath>
#include "RiverBezier.h"

Point Point::operator+(Point &other_point) const {
    return {x+other_point.getX(), y+other_point.getY()};
}

Point Point::operator*(const Point &in_point) const {
    return {x*in_point.getX(), y*in_point.getY()};
}

std::vector<std::vector<char>> RiverBezier::River(int height, int width, int bridge_amount) {
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
    int presision = height*width;
    // plot presision points for high resolution bezier curve
    for(int i{0};i<presision;i++){
        double x_result, y_result, t;
        if(bridge_amount!=0 and i%(presision/bridge_amount)==(presision/(bridge_amount*2))){
            // generate presision/35 bridge elements + .
            for(int j=0;j<presision/30;j++){
                t = (double)(i+j)/presision;
                x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*(t)*first_points[second_id].getX())+(3*std::pow((t), 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
                y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*(t)*first_points[second_id].getY())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
                Point a(std::round(x_result), std::round(y_result));
                x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX()+1)+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
                y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*t*first_points[second_id].getY()+0.5)+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
                Point b(std::round(x_result), std::round(y_result));
                if(a.getX()<width and a.getY()<height) map[a.getY()][a.getX()] = 'b'; // b stand for bridge
                if(b.getX()<width and b.getY()<height) map[b.getY()][b.getX()] = 'b'; // b stand for bridge
            }
        }
        else{
            t = (double)i/presision;
            // calculate x and y value of points
            x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
            y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*t*first_points[second_id].getY())+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
            Point a(std::round(x_result), std::round(y_result));
            // calculate new x value with the 2nd control point moved by 1 x value(impossible to be out of bounds).
            x_result = (std::pow(1-t, 3)*first_points[first_id].getX())+(3*std::pow(1-t, 2)*t*first_points[second_id].getX()+1)+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getX())+(std::pow(t,3)*first_points[fourth_id].getX());
            y_result = std::pow(1-t, 3)*first_points[first_id].getY()+(3*std::pow(1-t, 2)*t*first_points[second_id].getY()+0.5)+(3*std::pow(t, 2)*(1-t)*first_points[third_id].getY())+(std::pow(t,3)*first_points[fourth_id].getY());
            Point b(std::round(x_result), std::round(y_result));

            if(a.getX()<width and a.getY()<height and map[a.getY()][a.getX()]!='b'){
                map[a.getY()][a.getX()] = 'w'; // w stand for water obstacle
            }
            if(b.getX()<width and b.getY()<height and map[b.getY()][b.getX()]!='b'){
                map[b.getY()][b.getX()] = 'w'; // w stand for water obstacle
            }
        }
    }

    return map;
}
