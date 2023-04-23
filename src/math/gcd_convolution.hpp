#pragma once
#include <cassert>
#include <vector>

namespace gcd_convolution {

// f(k) <- \sum_{k | i} f(i)
template <typename T> void divisor_transform(std::vector<T>& f) {
    int n = f.size();
    std::vector<bool> sieve(n, true);
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = (n - 1) / p; k > 0; k--) {
                sieve[k * p] = false;
                f[k] += f[k * p];
            }
        }
    }
    for (int i = 1; i < n; i++) f[i] += f[0];
}

// inverse of divisor transform
template <typename T> void inverse_divisor_transform(std::vector<T>& f) {
    int n = f.size();
    std::vector<bool> sieve(n, true);
    for (int i = 1; i < n; i++) f[i] -= f[0];
    for (int p = 2; p < n; p++) {
        if (sieve[p]) {
            for (int k = 1 / p; k * p < n; k++) {
                sieve[k * p] = false;
                f[k] -= f[k * p];
            }
        }
    }
}

template <typename T> std::vector<T> gcd_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    divisor_transform(f);
    divisor_transform(g);
    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];
    inverse_divisor_transform(f);
    return f;
}

}  // namespace gcd_convolution
