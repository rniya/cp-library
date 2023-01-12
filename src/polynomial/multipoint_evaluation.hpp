#pragma once
#include <vector>
#include "FormalPowerSeries.hpp"

template <typename T> struct subproduct_tree {
    using poly = FormalPowerSeries<T>;
    int m;
    std::vector<poly> prod;
    subproduct_tree(const std::vector<T>& x) : m(x.size()) {
        int k = 1;
        while (k < m) k <<= 1;
        prod.assign(k << 1, {1});
        for (int i = 0; i < m; i++) prod[k + i] = {-x[i], 1};
        for (int i = k - 1; i > 0; i--) prod[i] = prod[i << 1] * prod[i << 1 | 1];
    }

    int size() const { return prod.size() >> 1; }

    poly mid_prod(const poly& a, const poly& b) const {}

    std::vector<T> multipoint_evaluation(poly f) const {
        std::vector<poly> rem(size() << 1);
        rem[1] = f % prod[1];
        for (int i = 2; i < size() + m; i++) rem[i] = rem[i >> 1] % prod[i];
        std::vector<T> res(m);
        for (int i = 0; i < m; i++) res[i] = (rem[size() + i].empty() ? 0 : rem[size() + i][0]);
        return res;
    }
};