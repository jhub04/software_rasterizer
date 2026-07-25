#include <iostream>
#include <fstream>
#include <vector>

struct Pixel {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

bool WriteTGA(const char* fileName, uint16_t width, uint16_t height) {
    uint8_t header[18] = {};

    // Image type
    header[2] = 2;

    header[12] = width & 0xFF;
    header[13] = (width >> 8) & 0xFF;
    header[14] = height & 0xFF;
    header[15] = (height >> 8) & 0xFF;

    // Bits per pixel
    header[16] = 24;

    std::ofstream outputFile(fileName, std::ios::binary);

    if (!outputFile) {
        std::cerr << "Failed to open or create file" << std::endl;
        return 0;
    }

    outputFile.write(reinterpret_cast<char*>(&header), sizeof(header));

    std::vector<Pixel> pixels(width * height, red);

    outputFile.write(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(Pixel));

    outputFile.close();

    return 1;
}

int main() {
    uint16_t width = 64;
    uint16_t height = 64;

    WriteTGA("file.tga", width, height);
}

