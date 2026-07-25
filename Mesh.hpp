#ifndef MESH_HPP
#define MESH_HPP

#include "Types.hpp"
#include <vector>

class Mesh {
    private:
        std::vector<Vec3f> vertices;
        std::vector<Face> faces;
    public:
        Mesh(const char* fPath);
        std::vector<Vec3f>& GetVertices() {return vertices;}
        std::vector<Face>& GetFaces() {return faces;}
};



#endif //MESH_HPP
