#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.000001

#include <iomanip>
#include "geometry/circumcircle.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Point<double> a, b, c;
    std::cin >> a >> b >> c;
    auto res = circumcircle(a, b, c);
    std::cout << res << '\n';
}