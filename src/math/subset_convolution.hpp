#include <array>
#include <cassert>
#include <vector>

namespace internal {

template <typename T, int LIM> std::vector<std::array<T, LIM + 1>> ranked_zeta(const std::vector<T>& a) {
    int n = a.size(), len = __builtin_ctz(n);
    assert((n & (n - 1)) == 0);
    std::vector<std::array<T, LIM + 1>> res(n);
    for (int i = 0; i < n; i++) res[i][__builtin_popcount(i)] = a[i];
    for (int step = 1; step < n; step <<= 1) {
        for (int start = 0; start < n; start += 2 * step) {
            for (int i = start; i < start + step; i++) {
                for (int j = 0; j <= len; j++) {
                    res[i | step][j] += res[i][j];
                }
            }
        }
    }
    return res;
}

template <typename T, int LIM> std::vector<T> ranked_mobius(std::vector<std::array<T, LIM + 1>>& ranked) {
    int n = ranked.size(), len = __builtin_ctz(n);
    assert((n & (n - 1)) == 0);
    for (int step = 1; step < n; step <<= 1) {
        for (int start = 0; start < n; start += 2 * step) {
            for (int i = start; i < start + step; i++) {
                for (int j = 0; j <= len; j++) {
                    ranked[i | step][j] -= ranked[i][j];
                }
            }
        }
    }
    std::vector<T> res(n);
    for (int i = 0; i < n; i++) res[i] = ranked[i][__builtin_popcount(i)];
    return res;
}

}  // namespace internal

template <typename T, int LIM = 20>
std::vector<T> subset_convolution(const std::vector<T>& a, const std::vector<T>& b) {
    auto ra = internal::ranked_zeta<T, LIM>(a);
    auto rb = internal::ranked_zeta<T, LIM>(b);
    int n = ra.size(), len = __builtin_ctz(n);
    for (int i = 0; i < n; i++) {
        auto &f = ra[i], &g = rb[i];
        for (int j = len; j >= 0; j--) {
            T sum = 0;
            for (int k = 0; k <= j; k++) sum += f[k] * g[j - k];
            f[j] = sum;
        }
    }
    return internal::ranked_mobius<T, LIM>(ra);
}
