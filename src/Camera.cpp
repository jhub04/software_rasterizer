#include "../include/Camera.hpp"

Vec2i Camera::ProjectTo2D(const Vec3f& v) const {
    int x_proj = (v.x + 1.0) * width / 2;
    int y_proj = (v.y + 1.0) * height / 2;
    return Vec2i(x_proj, y_proj);
}
