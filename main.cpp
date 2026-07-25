#include "image.hpp"

constexpr Pixel white = {255, 255, 255};
constexpr Pixel red = {0, 0, 255};
constexpr Pixel green = {0, 255, 0};
constexpr Pixel blue = {255, 0, 0};

void DrawLine(Image& img, Pixel color, uint8_t ax, uint8_t ay, uint8_t bx, uint8_t by) {
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
            img.SetPixel(y, x, color);
        } else {
            img.SetPixel(x, y, color);
        }
    }
}

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

    DrawLine(img, blue, ax, ay, bx, by);
    DrawLine(img, red, ax, ay, cx, cy);
    DrawLine(img, green, bx, by, cx, cy);

    img.WriteTGAFile("img.tga");
    return 0;
}

