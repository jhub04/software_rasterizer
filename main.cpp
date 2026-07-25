#include "Image.hpp"
#include "Mesh.hpp"
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
        Vec2i proj = img.ProjectTo2D(v);
        img.SetPixel(proj, red);
    }

    for (Face& f : mesh.GetFaces()) {
        std::vector<Vec3f>& vertices= mesh.GetVertices();

        Vec3f v1 = vertices[f.vIndices[0]];
        Vec3f v2 = vertices[f.vIndices[1]];
        Vec3f v3 = vertices[f.vIndices[2]];

        Vec2i a = img.ProjectTo2D(v1);
        Vec2i b = img.ProjectTo2D(v2);
        Vec2i c = img.ProjectTo2D(v3);

        img.DrawLine(a, b, red);
        img.DrawLine(a, c, red);
        img.DrawLine(b, c, red);
    }

    img.WriteTGAFile("diablo.tga");

    return 0;
}

