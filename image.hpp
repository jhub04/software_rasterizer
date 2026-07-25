#ifndef IMAGE_HPP
#define IMAGE_HPP
#include <vector>

struct Color {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

class Image {
    private:
        uint16_t width;
        uint16_t height;
        std::vector<Color> buffer;
    public:
        Image(uint16_t width, uint16_t height);
        void SetPixel(uint8_t x, uint8_t y, Color color);
        bool WriteTGAFile(const char* fileName);
};

#endif //IMAGE_HPP
