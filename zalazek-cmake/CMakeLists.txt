cmake_minimum_required(VERSION 3.0)

set(PROJ_NAME "cmds_interpreter")
project(${PROJ_NAME})

add_subdirectory(plugin)

include_directories(${PROJECT_SOURCE_DIR}/inc)
add_executable(${PROJECT_NAME} src/main.cpp
        plugin/src/Interp4Rotate.cpp
        plugin/inc/Interp4Rotate.h
        plugin/src/Interp4Set.cpp
        plugin/inc/Interp4Set.h
        plugin/src/Interp4Pause.cpp
        plugin/inc/Interp4Pause.h
        src/Set4LibInterfaces.cpp
        inc/Set4LibInterfaces.h
        src/LibInterfaces.cpp
        inc/LibInterfaces.h)
set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wl,-rpath=./plugin")
add_custom_command(TARGET ${PROJ_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E echo ""
    COMMAND ${CMAKE_COMMAND} -E echo " Utworzony zostal program:  ${PROJ_NAME}"
    COMMAND ${CMAKE_COMMAND} -E echo ""
  )
