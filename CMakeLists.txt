cmake_minimum_required(VERSION 3.17)
project(Procedural_Generator)

set(CMAKE_CXX_STANDARD 14)

add_executable(Procedural_Generator main.cpp Point.cpp Point.h RiverBezier.cpp RiverBezier.h HillGenerator.cpp HillGenerator.h)
