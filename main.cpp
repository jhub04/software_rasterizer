#include "Image.hpp"
#include "Mesh.hpp"
#include <iostream>

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

int main(int argc, char* argv[]) {
    constexpr uint16_t width = 64;
    constexpr uint16_t height = 64;

    std::cout << "Program start" << std::endl;

    if (argc == 1) {
        std::cerr << "No arguments found" << std::endl;
        return 1;
    }

    if (argc == 2) {
        std::cout << argv[1] << std::endl;

        const char* inputPath = argv[1];

        Mesh mesh( inputPath);
    }

    return 0;
}

