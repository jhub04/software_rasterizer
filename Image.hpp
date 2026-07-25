#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>

#include "Types.hpp"

class Image {
    private:
        uint16_t width;
        uint16_t height;
        std::vector<Pixel> buffer;
    public:
        Image(uint16_t width, uint16_t height);
        void SetPixel(int x, int y, Pixel color);
        void DrawLine(int ax, int ay, int bx, int by, Pixel color);
        std::tuple<int, int> ProjectTo2D(Vec3f v);
        bool WriteTGAFile(const char* fileName);
};

#endif //IMAGE_HPP
