#ifndef MESH_HPP
#define MESH_HPP

#include "Types.hpp"
#include <vector>
#include <filesystem>

class Mesh {
    private:
        std::vector<Vec3f> vertices;
        std::vector<Face> faces;
    public:
        Mesh(const std::filesystem::path path);
        const std::vector<Vec3f>& GetVertices() const {return vertices;}
        const std::vector<Face>& GetFaces() const {return faces;}
};



#endif //MESH_HPP
