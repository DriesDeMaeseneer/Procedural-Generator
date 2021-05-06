//
// Created by syntaxnoob on 4/3/21.
//

#ifndef PROCEDURAL_GENERATOR_HILLGENERATOR_H
#define PROCEDURAL_GENERATOR_HILLGENERATOR_H

#include <vector>
#include <iostream>
#include "Point.h"
#include <cstdlib>
#include <ctime>

class HillGenerator {
    public:
    static std::vector<std::vector<int>> generatePerlin(const int height, const int width);

};


#endif //PROCEDURAL_GENERATOR_HILLGENERATOR_H
