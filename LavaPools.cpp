//
// Created by syntaxnoob on 5/7/21.
//

#include "LavaPools.h"

std::vector<std::vector<char>> LavaPools::Lava(int height, int width, int lava_pits) {
    int k=time(nullptr);
    std::srand(k);

    std::vector<std::vector<char>> map;

    std::vector<char> tmp;
    tmp.resize(width, '-');
    map.resize(height, tmp);




    return map;
}
