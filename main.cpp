#include "image.hpp"

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

void DrawLine(Image& img, Pixel color, uint8_t ax, uint8_t ay, uint8_t bx, uint8_t by) {
    float t = 0;

    while (t <= 1.0f) {
        uint8_t x = ax + t * (bx - ax);
        uint8_t y = ay + t * (by - ay);

        img.SetPixel(x, y, color);

        t += 0.0001;
    }
}

int main() {
    constexpr uint16_t width = 64;
    constexpr uint16_t height = 64;

    Image img(width, height);

    uint8_t ax = 7, ay = 3;
    uint8_t bx = 12, by = 37;
    uint8_t cx = 62, cy = 53;

    DrawLine(img, blue, ax, ay, bx, by);
    DrawLine(img, red, ax, ay, cx, cy);
    DrawLine(img, green, bx, by, cx, cy);

    img.WriteTGAFile("img.tga");
    return 0;
}

