#include <vector>
#include "binomial.hpp"

/**
 * @brief ベル数
 * @docs docs/combinatorics/BellNumber.md
 */
template <typename T> T bell_number(int n, int k) {
    if (n == 0) return 1;
    k = std::min(k, n);
    Binomial<T> BINOM(k);
    std::vector<T> sum(k + 1);
    sum[0] = 1;
    for (int i = 1; i <= k; i++) {
        if (i & 1)
            sum[i] = sum[i - 1] - BINOM.finv(i);
        else
            sum[i] = sum[i - 1] + BINOM.finv(i);
    }
    T res = 0;
    for (int i = 1; i <= k; i++) {
        res += T(i).pow(n) * BINOM.finv(i) * sum[k - i];
    }
    return res;
}