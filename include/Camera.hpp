#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Types.hpp"

class Camera {
    private:
        uint16_t width;
        uint16_t height;
    public:
        Camera(uint16_t width, uint16_t height) : width(width), height(height) {};
        Vec2i ProjectTo2D(const Vec3f& v) const;
        uint16_t GetWidth() const {return width;}
        uint16_t GetHeight() const {return height;}
};

#endif //CAMERA_HPP
