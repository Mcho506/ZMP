cmake_minimum_required(VERSION 4.3)
project(vector3d_przyklad)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(vector3d_przyklad
        g3dVector.hh
        geomVector.hh
        main.cpp
        main.cpp)
