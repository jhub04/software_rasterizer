#include "Mesh.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Mesh::Mesh(const char* path) {
    std::ifstream inputFile(path);

    if (!inputFile.is_open()) {
        std::cerr << "Failed to open file: " << path << std::endl;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        std::stringstream ss(line);
        std::string prefix;
        ss >> prefix;

        if (prefix == "v") {
            Vec3 vert;
            ss >> vert.x >> vert.y >> vert.z;
            vertices.push_back(vert);
        }
    }

    std::cout << "Num vertices: " << vertices.size() << std::endl;
};