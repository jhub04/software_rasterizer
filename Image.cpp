#include "Image.hpp"
#include <fstream>
#include <iostream>

Image::Image(uint16_t width, uint16_t height) : width(width), height(height) {
    buffer = std::vector<Pixel>(width * height, Pixel{0, 0, 0});
};

void Image::SetPixel(const Vec2i& v, Pixel color) {
    buffer[v.y * width + v.x] = color;
}

void Image::DrawLine(const Vec2i& a, const Vec2i& b, Pixel color) {
    int ax = a.x, ay = a.y, bx = b.x, by = b.y;

    // Allow for drawing lines both ways
    bool steep = std::abs(b.y - a.y) / std::abs(static_cast<float>(b.x - a.x)) >= 1;

    // Transpose if too steep
    if (steep) {
        std::swap(ax, ay);
        std::swap(bx, by);
    }

    if (ax > bx) {
        std::swap(ax, bx);
        std::swap(ay, by);
    }

    for (int x = ax; x <= bx; x++) {
        float t = (x - ax) / static_cast<float>(bx - ax);
        int y = std::round(ay + t * (by - ay));

        if (steep) {
            Vec2i v(y, x);
            SetPixel(v, color);
        } else {
            Vec2i v(x, y);
            SetPixel(v, color);
        }
    }
}

Vec2i Image::ProjectTo2D(const Vec3f& v) {
    int x_proj = (v.x + 1.0) * width / 2;
    int y_proj = (v.y + 1.0) * height / 2;
    return Vec2i(x_proj, y_proj);
}

void Image::DrawMesh(const Mesh& mesh) {
    for (const Vec3f& v : mesh.GetVertices()) {
        Vec2i proj = ProjectTo2D(v);
        SetPixel(proj, red);
    }

    for (const Face& f : mesh.GetFaces()) {
        const std::vector<Vec3f>& vertices= mesh.GetVertices();

        Vec3f v1 = vertices[f.vIndices[0]];
        Vec3f v2 = vertices[f.vIndices[1]];
        Vec3f v3 = vertices[f.vIndices[2]];

        Vec2i a = ProjectTo2D(v1);
        Vec2i b = ProjectTo2D(v2);
        Vec2i c = ProjectTo2D(v3);

        DrawLine(a, b, red);
        DrawLine(a, c, red);
        DrawLine(b, c, red);
    }
}



bool Image::WriteTGAFile(const char *fileName) {
    uint8_t header[18] = {};

    // Image type
    header[2] = 2;

    header[12] = width & 0xFF;
    header[13] = (width >> 8) & 0xFF;
    header[14] = height & 0xFF;
    header[15] = (height >> 8) & 0xFF;

    // Bits per pixel
    header[16] = 24;

    std::ofstream outputFile(fileName, std::ios::binary);

    if (!outputFile) {
        std::cerr << "Failed to open or create file" << std::endl;
        return 0;
    }

    outputFile.write(reinterpret_cast<char*>(&header), sizeof(header));

    outputFile.write(reinterpret_cast<char*>(buffer.data()), buffer.size() * sizeof(Pixel));

    outputFile.close();

    std::cout << "Write succeeded and file stream closed" << std::endl;

    return 1;
}


