#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

struct Vec3 {
    float x, y, z;
};

struct Face {
    int vIndices[3];
};

class Mesh {
    private:
        std::vector<Vec3> vertices;
        std::vector<Face> faces;
    public:
        Mesh(const char* fPath);
        std::vector<Vec3>& GetVertices() {return vertices;}
        std::vector<Face>& GetFaces() {return faces;}
};



#endif //MESH_HPP
