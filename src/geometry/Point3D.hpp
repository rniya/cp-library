#pragma once

namespace geometry {

template <typename T> struct Point3D {
    static T EPS;

    static void set_eps(T eps) { EPS = eps; }

    T x, y, z;

    Point3D() {}

    Point3D(T x, T y, T z) : x(x), y(y), z(z) {}

    Point3D operator+(const Point3D& p) const { return Point(x + p.x, y + p.y, z + p.z); }

    Point3D operator-(const Point3D& p) const { return Point(x - p.x, y - p.y, z - p.z); }

    Point3D operator*(T t) const { return Point(x * t, y * t, z * t); }

    Point3D operator/(T t) const { return Point(x / t, y / t, z / t); }

    bool operator==(const Point3D& p) const { return x == p.x and y == p.y and z == p.z; }

    bool operator!=(const Point3D& p) const { return not((*this) == p); }

    bool operator<(const Point3D& p) const { return x != p.x ? x < p.x : y != p.y ? y < p.y : z < p.z; }

    friend std::istream& operator>>(std::istream& is, Point3D& p) { return is >> p.x >> p.y >> p.z; }

    friend std::ostream& operator<<(std::ostream& os, const Point3D& p) {
        return os << p.x << ' ' << p.y << ' ' << p.z;
    }

    T norm() { return std::sqrt(x * x + y * y + z * z); }

    T norm2() { return x * x + y * y + z * z; }

    T dot(const Point3D& p) { return x * p.x + y * p.y + z * p.z; }

    Point3D cross(const Point3D& p) { return Point3D(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }

    Point3D unit() { return *this / norm(); }
};

template <> double Point3D<double>::EPS = 1e-9;
template <> long double Point3D<long double>::EPS = 1e-12;
template <> int Point3D<int>::EPS = 0;
template <> long long Point3D<long long>::EPS = 0;

}  // namespace geometry