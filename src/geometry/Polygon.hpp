#pragma once
#include <vector>
#include "ccw.hpp"

namespace geometry {

template <typename T> struct Polygon : std::vector<Point<T>> {
    using std::vector<Point<T>>::vector;

    Polygon(int n) : std::vector<Point<T>>(n) {}

    T area2() {
        T sum = 0;
        int n = this->size();
        for (int i = 0; i < n; i++) sum += (*this)[i].det((*this)[i + 1 == n ? 0 : i + 1]);
        return sum < 0 ? -sum : sum;
    }

    T area() { return area2() / 2; }

    bool is_convex() {
        int n = this->size();
        for (int j = 0; j < n; j++) {
            int i = (j == 0 ? n - 1 : j - 1), k = (j == n - 1 ? 0 : j + 1);
            if (ccw((*this)[i], (*this)[j], (*this)[k]) == CLOCKWISE) return false;
        }
        return true;
    }
};

}  // namespace geometry