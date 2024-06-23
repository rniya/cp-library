#pragma once
#include <algorithm>
#include "../convolution/subset_convolution.hpp"

template <typename T, int LIM = 20> std::vector<T> exp_of_set_power_series(std::vector<T>& a) {
    int n = __builtin_ctz(a.size());
    assert(int(a.size()) == 1 << n and a[0] == T(0));
    std::vector<T> res(1 << n);
    res[0] = T(1);
    for (int i = 0; i < n; i++) {
        std::vector<T> f(begin(a) + (1 << i), begin(a) + (2 << i));
        std::vector<T> g(begin(res), begin(res) + (1 << i));
        auto h = subset_convolution<T, LIM>(f, g);
        std::copy(begin(h), end(h), begin(res) + (1 << i));
    }
    return res;
}