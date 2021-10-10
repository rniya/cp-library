#pragma once
#include <algorithm>
#include <cassert>
#include <cstdint>
#include <unordered_map>

int64_t discrete_logarithm(int64_t x, int64_t y, int64_t m) {
    assert(0 <= x and x < m);
    assert(0 <= y and y < m);
    assert(0 < m);
    int64_t g = 1;
    for (int64_t i = m; i > 0; i >>= 1) (g *= x) %= m;
    auto my_gcd = [](auto self, int64_t a, int64_t b) -> int64_t { return b != 0 ? self(self, b, a % b) : a; };
    g = my_gcd(my_gcd, g, m);
    int64_t t = 1, c = 0;
    for (; t % g != 0; c++) {
        if (t == y) return c;
        (t *= x) %= m;
    }
    if (y % g != 0) return -1;
    t /= g, y /= g, m /= g;
    int64_t n = 0, giant_step = 1;
    for (; n * n < m; n++) (giant_step *= x) %= m;
    std::unordered_map<int64_t, int64_t> baby_step;
    for (int64_t i = 0, cur = y; i < n; baby_step[cur] = ++i) (cur *= x) %= m;
    for (int64_t i = 0, cur = t; i < m; i += n) {
        (cur *= giant_step) %= m;
        if (baby_step.count(cur)) return c + (i + n) - baby_step[cur];
    }
    return -1;
}

/**
 * @brief Discrete Logarithm (離散対数)
 * @docs docs/math/discrete_logarithm.md
 */
