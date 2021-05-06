//
// Created by syntaxnoob on 4/3/21.
//

#include "RiverBezier.h"
#include "HillGenerator.h"


int main(){
//    std::vector<std::vector<int>> map = HillGenerator::generatePerlin(20, 20);
    auto map = RiverBezier::River(20,20);
    for(auto it:map){
        for(auto it2:it){
            std::cout<<it2<<' ';
        }
        std::cout<<std::endl;
    }
}