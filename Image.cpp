#include "Image.hpp"
#include <fstream>
#include <iostream>

Image::Image(uint16_t width, uint16_t height) : width(width), height(height) {
    buffer = std::vector<Pixel>(width * height, Pixel{0, 0, 0});
};

void Image::SetPixel(uint8_t x, uint8_t y, Pixel color) {
    buffer[y * width + x] = color;
}

void Image::DrawLine(uint8_t ax, uint8_t ay, uint8_t bx, uint8_t by, Pixel color) {
    // Allow for drawing lines both ways
    if (ax > bx) {
        std::swap(ax, bx);
        std::swap(ay, by);
    }

    bool steep = (by - ay) / static_cast<float>(bx - ax) >= 1;

    // Transpose if too steep
    if (steep) {
        std::swap(ax, ay);
        std::swap(bx, by);
    }

    for (uint8_t x = ax; x <= bx; x++) {
        float t = (x - ax) / static_cast<float>(bx - ax);
        uint8_t y = std::round(ay + t * (by - ay));

        if (steep) {
            SetPixel(y, x, color);
        } else {
            SetPixel(x, y, color);
        }
    }
}

std::tuple<int, int> Image::ProjectTo2D(Vec3 v) {
    uint8_t x_proj = (v.x + 1.0) * width / 2;
    uint8_t y_proj = (v.y + 1.0) * height / 2;
    return { x_proj, y_proj };
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


