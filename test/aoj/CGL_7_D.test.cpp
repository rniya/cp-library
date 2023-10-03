#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"
#define ERROR 0.000001

#include <algorithm>
#include <iomanip>
#include "geometry/crosspoint.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    Circle<double> c;
    std::cin >> c;
    int q;
    std::cin >> q;
    for (; q--;) {
        Line<double> l;
        std::cin >> l;
        auto res = crosspoint(c, l);
        if (int(res.size()) < 2) res.emplace_back(res[0]);
        std::sort(begin(res), end(res));
        for (int i = 0; i < 2; i++) std::cout << res[i] << (i + 1 == 2 ? '\n' : ' ');
    }
}