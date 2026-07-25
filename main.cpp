#include "image.hpp"

constexpr Color white = {255, 255, 255};
constexpr Color red = {0, 0, 255};
constexpr Color green = {0, 255, 0};
constexpr Color blue = {255, 0, 0};

int main() {
    constexpr uint16_t width = 64;
    constexpr uint16_t height = 64;

    Image img(width, height);

    uint8_t ax = 7, ay = 3;
    uint8_t bx = 12, by = 37;
    uint8_t cx = 62, cy = 53;

    img.SetPixel(ax, ay, white);
    img.SetPixel(bx, by, white);
    img.SetPixel(cx, cy, white);

    img.WriteTGAFile("img.tga");
    return 0;
}

