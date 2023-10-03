#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "ccw.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Point<long long> a, b;
    std::cin >> a >> b;
    int q;
    std::cin >> q;
    for (; q--;) {
        Point<long long> c;
        std::cin >> c;
        int res = ccw(a, b, c);
        if (res == 1)
            std::cout << "COUNTER_CLOCKWISE" << '\n';
        else if (res == -1)
            std::cout << "CLOCKWISE" << '\n';
        else if (res == 2)
            std::cout << "ONLINE_BACK" << '\n';
        else if (res == -2)
            std::cout << "ONLINE_FRONT" << '\n';
        else
            std::cout << "ON_SEGMENT" << '\n';
    }
    return 0;
}