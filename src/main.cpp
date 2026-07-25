#include "../include/Image.hpp"
#include "../include/Mesh.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    constexpr uint16_t width = 1620;
    constexpr uint16_t height = 1620;

    if (argc < 3) {
        std::cerr << "Two arguments is required!" << std::endl;
        return 1;
    }

    const char* srcPath = argv[1];
    const char* dstPath = argv[2];

    Camera camera(width, height);

    Mesh mesh(srcPath);

    Image img(camera);

    img.DrawMesh(mesh);

    img.WriteTGAFile(dstPath);

    return 0;
}

