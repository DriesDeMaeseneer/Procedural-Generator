//
// Created by syntaxnoob on 4/3/21.
//

#ifndef PROCEDURAL_GENERATOR_RIVERBEZIER_H
#define PROCEDURAL_GENERATOR_RIVERBEZIER_H

#include <iostream>
#include "Point.h"
#include <cstdlib>
#include <vector>
#include <ctime>

class RiverBezier {
public:
    static std::vector<std::vector<char>> River(int height, int width);
};


#endif //PROCEDURAL_GENERATOR_RIVERBEZIER_H
