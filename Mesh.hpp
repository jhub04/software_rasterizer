#ifndef MESH_HPP
#define MESH_HPP

#include <vector>

struct Vec3 {
    float x, y, z;
};

struct Face {
    uint8_t vIndices[3];
};

class Mesh {
    private:
        std::vector<Vec3> vertices;
        std::vector<Face> faces;
    public:
        Mesh(const char* fPath);
};



#endif //MESH_HPP
