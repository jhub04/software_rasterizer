#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>

#include "Types.hpp"
#include "Mesh.hpp"

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

class Image {
    private:
        uint16_t width;
        uint16_t height;
        std::vector<Pixel> buffer;
        void SetPixel(const Vec2i& v, Pixel color);
        void DrawLine(const Vec2i& a, const Vec2i& b, Pixel color);
        Vec2i ProjectTo2D(const Vec3f& v);
    public:
        Image(uint16_t width, uint16_t height);
        void DrawMesh(const Mesh& mesh);
        bool WriteTGAFile(const char* fileName);
};

#endif //IMAGE_HPP
