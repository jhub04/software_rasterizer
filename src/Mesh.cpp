#include "../include/Mesh.hpp"
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
            Vec3f vert;
            ss >> vert.x >> vert.y >> vert.z;
            vertices.push_back(vert);
        }
        else if (prefix == "f") {
            Face face;
            for (int i = 0; i < 3; i++) {
                std::string group;
                ss >> group;

                std::istringstream iss(group);
                std::string token;
                std::getline(iss, token, '/');
                face.vIndices[i] = std::stoi(token) - 1;
            }
            faces.push_back(face);
        }
    }

    std::cout << "Num vertices: " << vertices.size() << std::endl;
    std::cout << "Num faces: " << faces.size() << std::endl;
};