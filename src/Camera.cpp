#include "../include/Camera.hpp"

Vec2i Camera::ProjectTo2D(const Vec3f& v) const {
    auto x_proj = static_cast<int>((v.x + 1.0) * width / 2);
    auto y_proj = static_cast<int>((v.y + 1.0) * height / 2);
    return Vec2i{x_proj, y_proj};
}
