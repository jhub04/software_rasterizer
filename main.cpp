#include "Image.hpp"
#include "Mesh.hpp"
#include <tuple>
#include <iostream>

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

int main(int argc, char* argv[]) {
    constexpr uint16_t width = 800;
    constexpr uint16_t height = 800;

    if (argc != 2) {
        std::cerr << "Only one argument is supported!" << std::endl;
        return 1;
    }

    const char* inputPath = argv[1];

    Mesh mesh( inputPath);

    Image img(width, height);

    for (Vec3f& v : mesh.GetVertices()) {
        std::tuple proj = img.ProjectTo2D(v);
        img.SetPixel(std::get<0>(proj), std::get<1>(proj), red);
    }

    for (Face& f : mesh.GetFaces()) {
        std::vector<Vec3f>& vertices= mesh.GetVertices();

        Vec3f v1 = vertices[f.vIndices[0]];
        Vec3f v2 = vertices[f.vIndices[1]];
        Vec3f v3 = vertices[f.vIndices[2]];

        std::tuple projV1 = img.ProjectTo2D(v1);
        std::tuple projV2 = img.ProjectTo2D(v2);
        std::tuple projV3 = img.ProjectTo2D(v3);

        img.DrawLine(std::get<0>(projV1), std::get<1>(projV1), std::get<0>(projV2), std::get<1>(projV2), red);
        img.DrawLine(std::get<0>(projV1), std::get<1>(projV1), std::get<0>(projV3), std::get<1>(projV3), red);
        img.DrawLine(std::get<0>(projV2), std::get<1>(projV2), std::get<0>(projV3), std::get<1>(projV3), red);
    }

    img.WriteTGAFile("diablo.tga");

    return 0;
}

