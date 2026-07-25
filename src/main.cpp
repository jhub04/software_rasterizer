#include "../include/Image.hpp"
#include "../include/Mesh.hpp"
#include <iostream>
#include <filesystem>

int main(int argc, char* argv[]) {
    constexpr uint16_t width = 1620;
    constexpr uint16_t height = 1620;

    if (argc < 3) {
        std::cerr << "Two arguments is required!" << std::endl;
        return 1;
    }

    const char* srcPath = argv[1];
    const char* dstPath = argv[argc - 1];

    Camera camera(width, height);

    std::vector<Mesh> meshes;

    if (std::filesystem::is_directory(srcPath)) {
        for (auto const& dirEntry : std::filesystem::directory_iterator(srcPath)) {
            if (dirEntry.path().extension() != ".obj") {
                continue;
            }
            Mesh mesh(dirEntry);
            meshes.push_back(mesh);
        }
    }

    Image img(camera);

    std::cout << "Num meshes: " << meshes.size() << std::endl;

    for (const Mesh& mesh : meshes) {
        img.DrawMesh(mesh);
    }

    img.WriteTGAFile(dstPath);

    return 0;
}

