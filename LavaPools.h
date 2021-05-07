//
// Created by syntaxnoob on 5/7/21.
//

#ifndef PROCEDURAL_GENERATOR_LAVAPOOLS_H
#define PROCEDURAL_GENERATOR_LAVAPOOLS_H

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>

class LavaPools {
public:
    static std::vector<std::vector<char>> Lava(int height, int width, int lava_pits);
};


#endif //PROCEDURAL_GENERATOR_LAVAPOOLS_H
