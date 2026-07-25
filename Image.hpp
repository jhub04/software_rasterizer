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
        void SetPixel(const Vec2i& v, Pixel color);
        void DrawLine(const Vec2i& a, const Vec2i& b, Pixel color);
        Vec2i ProjectTo2D(Vec3f v);
        bool WriteTGAFile(const char* fileName);
};

#endif //IMAGE_HPP
