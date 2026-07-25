#include "Image.hpp"
#include "Mesh.hpp"
#include <tuple>
#include <iostream>

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

int main(int argc, char* argv[]) {
    constexpr uint16_t width = 256;
    constexpr uint16_t height = 256;

    if (argc != 2) {
        std::cerr << "Only one argument is supported!" << std::endl;
        return 1;
    }

    const char* inputPath = argv[1];

    Mesh mesh( inputPath);

    Image img(width, height);

    for (Vec3& v : mesh.GetVertices()) {
        std::tuple proj = img.ProjectTo2D(v);
        img.SetPixel(std::get<0>(proj), std::get<1>(proj), red);
    }

    img.WriteTGAFile("diablo.tga");

    return 0;
}

