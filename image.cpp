#include "image.hpp"
#include <fstream>
#include <iostream>

Image::Image(uint16_t width, uint16_t height) : width(width), height(height) {
    buffer = std::vector<Pixel>(width * height, Pixel{0, 0, 0});
};

void Image::SetPixel(uint8_t x, uint8_t y, Pixel color) {
    buffer[y * width + x] = color;
}

bool Image::WriteTGAFile(const char *fileName) {
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

    outputFile.write(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(Pixel));

    outputFile.close();

    std::cout << "Write succeeded and file stream closed" << std::endl;

    return 1;
}


