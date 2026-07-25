cmake_minimum_required(VERSION 3.31)
project(software_rasterizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(software_rasterizer main.cpp
        image.hpp
        image.cpp
        Mesh.cpp
        Mesh.hpp
        Types.hpp)
