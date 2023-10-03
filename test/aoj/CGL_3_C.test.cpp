#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C"

#include "geometry/contain.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    Polygon<int> P(n);
    for (auto& p : P) std::cin >> p;
    int q;
    std::cin >> q;
    for (; q--;) {
        Point<int> p;
        std::cin >> p;
        auto res = contain(P, p);
        std::cout << (res == Containment::IN ? 2 : res == Containment::ON ? 1 : 0) << '\n';
    }
}