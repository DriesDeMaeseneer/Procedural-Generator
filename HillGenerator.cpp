//
// Created by syntaxnoob on 4/3/21.
//

#include "HillGenerator.h"

double IntegerNoise (int n)
{
    n = (n >> 13) ^ n;
    int nn = (n * (n * n * 60493 + 19990303) + 1376312589) & 0x7fffffff;
    return 1.0 - ((double)nn / 1073741824.0);
}


std::vector<std::vector<int>> HillGenerator::generatePerlin(const int height, const int width) {
    std::vector<std::vector<int>> pixels;
    std::vector<int> tmp;
    tmp.resize(width, 0);
    pixels.resize(height, tmp);

    return pixels;
}
