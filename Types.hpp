#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>

template <typename T>
struct Vec3 {
    T x, y, z;
};

template <typename T>
struct Vec2 {
    T x, y;
};

using Vec3f = Vec3<float>;
using Vec3i = Vec3<int>;
using Vec2f = Vec2<float>;
using Vec2i = Vec2<int>;
using Pixel = Vec3<uint8_t>;

struct Face {
    int vIndices[3];
};

#endif //TYPES_HPP
