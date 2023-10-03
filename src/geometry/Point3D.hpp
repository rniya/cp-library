#pragma once

namespace geometry {

template <typename T> struct Point3D {
    T x, y, z;

    Point3D() {}

    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}
};

}  // namespace geometry