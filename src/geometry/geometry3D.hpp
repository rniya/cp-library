#pragma once
#include <cmath>
#include <iostream>

namespace geometry3D {

using Real = double;
constexpr Real EPS = 1e-8;
constexpr Real PI = 3.14159265358979323846L;

inline int sgn(Real x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }

inline int compare(Real a, Real b) { return sgn(a - b); }

inline bool equals(Real a, Real b) { return compare(a, b) == 0; }

struct Point3D {
    Real x, y, z;

    Point3D() {}

    Point3D(Real x, Real y, Real z) : x(x), y(y), z(z) {}

    Point3D& operator+=(const Point3D& p) {
        x += p.x, y += p.y, z += p.z;
        return *this;
    }

    Point3D& operator-=(const Point3D& p) {
        x -= p.x, y -= p.y, z -= p.z;
        return *this;
    }

    Point3D& operator*=(const Real& k) {
        x *= k, y *= k, z *= k;
        return *this;
    }

    Point3D& operator/=(const Real& k) {
        x /= k, y /= k, z /= k;
        return *this;
    }

    Point3D operator+(const Point3D& p) const { return Point3D(*this) += p; }

    Point3D operator-(const Point3D& p) const { return Point3D(*this) -= p; }

    Point3D operator*(const Real& k) const { return Point3D(*this) *= k; }

    Point3D operator/(const Real& k) const { return Point3D(*this) /= k; }

    Point3D operator-() const { return Point3D(-x, -y, -z); }

    bool operator==(const Point3D& p) const { return equals(x, p.x) and equals(y, p.y) and equals(z, p.z); }

    bool operator!=(const Point3D& p) const { return !((*this) == p); }

    bool operator<(const Point3D& p) const { return !equals(x, p.x) ? x < p.x : !equals(y, p.y) ? y < p.y : z < p.z; }

    bool operator>(const Point3D& p) const { return !equals(x, p.x) ? x > p.x : !equals(y, p.y) ? y > p.y : z > p.z; }

    friend std::istream& operator>>(std::istream& is, Point3D& p) { return is >> p.x >> p.y >> p.z; }

    friend std::ostream& operator<<(std::ostream& os, const Point3D& p) {
        return os << p.x << ' ' << p.y << ' ' << p.z;
    }

    Real norm() const { return x * x + y * y + z * z; }

    Real abs() const { return sqrt(norm()); }

    Point3D unit() const { return *this / abs(); }
};

Real dot(const Point3D& p, const Point3D& q) { return p.x * q.x + p.y * q.y + p.z * q.z; }

Point3D cross(const Point3D& p, const Point3D& q) {
    return Point3D(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x * q.y - p.y * q.x);
}

struct Segment3D {
    Point3D a, b;

    Segment3D() {}

    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}

    friend std::istream& operator>>(std::istream& is, Segment3D& s) { return is >> s.a >> s.b; }

    friend std::ostream& operator<<(std::ostream& os, const Segment3D& s) { return os << s.a << " to " << s.b; }
};

struct Sphere {
    Point3D center;
    Real radius;

    Sphere() {}

    Sphere(const Point3D& center, const Real& radius) : center(center), radius(radius) {}

    friend std::istream& operator>>(std::istream& is, Sphere& c) { return is >> c.center >> c.radius; }

    friend std::ostream& operator<<(std::ostream& os, Sphere& c) { return os << c.center << ' ' << c.radius; }
};

}  // namespace geometry3D

/**
 * @brief 3 次元幾何ライブラリ
 */