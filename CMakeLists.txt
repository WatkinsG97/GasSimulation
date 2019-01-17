cmake_minimum_required(VERSION 3.6)
project(Ex3_3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector.cpp Vector.h functions.cpp functions.h random.h random.cpp Particle.cpp Particle.h Box.cpp Box.h)
add_executable(Ex3_3 ${SOURCE_FILES})