//
// Created by Jonathan Hübertz on 25/07/2026.
//

#ifndef TYPES_HPP
#define TYPES_HPP

#include <cstdint>

struct Pixel {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

struct Vec3 {
    float x, y, z;
};

struct Face {
    int vIndices[3];
};

#endif //TYPES_HPP
