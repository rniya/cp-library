#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
#define ERROR 0.000001

#include <iomanip>
#include "convex_cut.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    int n;
    std::cin >> n;
    Polygon<double> P(n);
    for (auto& p : P) std::cin >> p;
    int q;
    std::cin >> q;
    for (; q--;) {
        Line<double> l;
        std::cin >> l;
        auto Q = convex_cut(P, l);
        auto res = Q.area();
        std::cout << res << '\n';
    }
}