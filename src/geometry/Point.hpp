#pragma once
#include <cassert>
#include <cmath>
#include <iostream>
#include <type_traits>

namespace geometry {

template <typename T> struct Point {
    static T EPS;

    static void set_eps(T eps) { EPS = eps; }

    T x, y;

    Point() {}

    Point(T x, T y) : x(x), y(y) {}

    Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }

    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }

    Point operator*(T t) const { return Point(x * t, y * t); }

    Point operator/(T t) const { return Point(x / t, y / t); }

    bool operator==(const Point& p) const { return x == p.x and y == p.y; }

    bool operator!=(const Point& p) const { return not((*this) == p); }

    bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y; }

    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x << ' ' << p.y; }

    T norm() { return std::sqrt(x * x + y * y); }

    T norm2() { return x * x + y * y; }

    T arg() { return std::atan2(y, x); }

    T dot(const Point& p) { return x * p.x + y * p.y; }

    T det(const Point& p) { return x * p.y - y * p.x; }

    Point perp() { return Point(-y, x); }

    Point unit() { return *this / norm(); }

    Point normal() { return perp().unit(); }

    Point rotate(T rad) { return Point(std::cos(rad) * x - std::sin(rad) * y, std::sin(rad) * x + std::cos(rad) * y); }
};

template <> double Point<double>::EPS = 1e-9;
template <> long double Point<long double>::EPS = 1e-12;
template <> int Point<int>::EPS = 0;
template <> long long Point<long long>::EPS = 0;

template <typename T> int sgn(T x) { return x < -Point<T>::EPS ? -1 : x > Point<T>::EPS ? 1 : 0; }

}  // namespace geometry