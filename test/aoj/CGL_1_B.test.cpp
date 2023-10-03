#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_B"
#define ERROR 0.00000001

#include <iomanip>
#include "geometry/reflection.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Line<double> l;
    std::cin >> l;
    int q;
    std::cin >> q;
    for (; q--;) {
        Point<double> p;
        std::cin >> p;
        std::cout << reflection(l, p) << '\n';
    }
    return 0;
}