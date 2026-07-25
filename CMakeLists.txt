cmake_minimum_required(VERSION 3.31)
project(software_rasterizer)

set(CMAKE_CXX_STANDARD 20)

add_executable(software_rasterizer src/main.cpp
        include/Image.hpp
        src/Image.cpp
        src/Mesh.cpp
        include/Mesh.hpp
        include/Types.hpp)
