cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME "plugins_4_program")
project(${PROJ_NAME})

include_directories(${PROJECT_SOURCE_DIR}/inc ${PROJECT_SOURCE_DIR}/../inc)

add_library(Interp4Move   MODULE src/Interp4Move.cpp)
add_library(Interp4Set    MODULE src/Interp4Set.cpp)
add_library(Interp4Rotate MODULE src/Interp4Rotate.cpp)
add_library(Interp4Pause  MODULE src/Interp4Pause.cpp)