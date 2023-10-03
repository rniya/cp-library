#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include "crosspoint.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Circle<double> c, d;
    std::cin >> c >> d;
    std::cout << count_common_tangent(c, d) << '\n';
}