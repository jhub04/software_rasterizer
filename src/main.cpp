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

    std::vector<Mesh> meshes;

    for (int i = 1; i < argc - 1; i++) {
        const char* path = argv[i];

        if (std::filesystem::is_directory(path)) {
            for (auto const& dirEntry : std::filesystem::directory_iterator(path)) {
                if (dirEntry.path().extension() != ".obj") {
                    continue;
                }
                Mesh mesh(dirEntry);
                meshes.push_back(mesh);
            }
            break;
        }

        Mesh mesh(path);
        meshes.push_back(mesh);
    }

    const char* dstPath = argv[argc - 1];

    Camera camera(width, height);

    Image img(camera);

    std::cout << "Num meshes: " << meshes.size() << std::endl;

    for (const Mesh& mesh : meshes) {
        img.DrawMesh(mesh);
    }

    img.WriteTGAFile(dstPath);

    return 0;
}

