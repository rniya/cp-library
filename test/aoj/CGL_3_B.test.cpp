#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"

#include "Polygon.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    Polygon<double> P(n);
    for (auto& p : P) std::cin >> p;
    std::cout << P.is_convex() << '\n';
}