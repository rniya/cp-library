#pragma once
#include "../base.hpp"

/**
 * @brief monotone minima
 * @docs docs/dp/monotone_minima.md
 */
template <class Select> vector<size_t> monotone_minima(const size_t H, const size_t W, const Select& select) {
    auto solve = [&](auto self, const vector<size_t>& v) -> vector<size_t> {
        const size_t n = v.size();
        if (n == 0) return {};
        vector<size_t> u;
        for (size_t i = 1; i < n; i += 2) u.emplace_back(v[i]);
        const vector<size_t> ch = self(self, u);
        vector<size_t> res(n);
        for (size_t i = 0; i < ch.size(); i++) res[i << 1 | 1] = ch[i];
        for (size_t i = 0, cur = 0; i < n; i += 2) {
            size_t nxt = (i + 1 == n ? W - 1 : res[i + 1]);
            for (res[i] = cur; cur < nxt;) {
                if (select(v[i], res[i], ++cur)) {
                    res[i] = cur;
                }
            }
        }
        return res;
    };

    vector<size_t> dp(H);
    iota(dp.begin(), dp.end(), 0);
    return solve(solve, dp);
};