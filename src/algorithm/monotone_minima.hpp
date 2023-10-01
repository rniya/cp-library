#pragma once
#include <vector>

template <class Select> std::vector<int> monotone_minima(int n, int m, const Select& select) {
    std::vector<int> res(n);
    auto dfs = [&](auto self, int u, int d, int l, int r) -> void {
        if (u == d) return;
        int m = (u + d) >> 1;
        int argmin = l;
        for (int col = l + 1; col < r; col++) {
            if (select(m, argmin, col)) {
                argmin = col;
            }
        }
        res[m] = argmin;
        self(self, u, m, l, argmin + 1);
        self(self, m + 1, d, argmin, r);
    };
    dfs(dfs, 0, n, 0, m);
    return res;
}