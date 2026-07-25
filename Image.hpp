#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>

#include "Mesh.hpp"

struct Pixel {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

class Image {
    private:
        uint16_t width;
        uint16_t height;
        std::vector<Pixel> buffer;
    public:
        Image(uint16_t width, uint16_t height);
        void SetPixel(uint8_t x, uint8_t y, Pixel color);
        void DrawLine(uint8_t ax, uint8_t ay, uint8_t bx, uint8_t by, Pixel color);
        std::tuple<int, int> ProjectTo2D(Vec3 v);
        bool WriteTGAFile(const char* fileName);
};

#endif //IMAGE_HPP
