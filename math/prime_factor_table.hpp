#pragma once
#include "../base.hpp"

/**
 * @brief osa_k法
 * @docs docs/math/prime_factor_table.md
 */
vector<int> prime_factor_table(int n) {
    vector<int> res(n + 1, 0);
    for (int i = 2; i <= n; i++)
        if (!res[i]) {
            for (int j = i; j <= n; j += i) {
                if (!res[j]) res[j] = i;
            }
        }
    return res;
}