#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "geometry/crosspoint.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    for (; q--;) {
        Line<int> s, t;
        std::cin >> s >> t;
        std::cout << (is_parallel(s, t) ? 2 : is_orthogonal(s, t) ? 1 : 0) << '\n';
    }
    return 0;
}