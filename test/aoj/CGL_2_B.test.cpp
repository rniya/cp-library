#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "crosspoint.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int q;
    std::cin >> q;
    for (; q--;) {
        Segment<int> s, t;
        std::cin >> s >> t;
        std::cout << has_crosspoint(s, t) << '\n';
    }
}