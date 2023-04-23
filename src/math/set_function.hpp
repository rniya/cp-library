#pragma once
#include <cassert>
#include <vector>

namespace set_function {

// subset sum : f(S) <- \sum_{T \subseteq S} f(T)
template <typename T> void subset_zeta_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] += f[j];
            }
        }
    }
}

// inverse of subset sum
// g = FZT(f) \iff f = FMT(g)
template <typename T> void subset_mobius_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j | i] -= f[j];
            }
        }
    }
}

// superset sum : f(S) <- \sum_{T \supseteq S} f(T)
template <typename T> void superset_zeta_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] += f[j | i];
            }
        }
    }
}

// inverse of superset sum
// g = FZT(f) \iff f = FMT(g)
template <typename T> void superset_mobius_transform(std::vector<T>& f) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                f[j] -= f[j | i];
            }
        }
    }
}

template <typename T> void walsh_hadamard_transform(std::vector<T>& f, bool inv = false) {
    int n = f.size();
    assert((n & (n - 1)) == 0);
    for (int i = 1; i < n; i <<= 1) {
        for (int j = 0; j < n; j++) {
            if ((j & i) == 0) {
                T x = f[j], y = f[j | i];
                f[j] = x + y, f[j | i] = x - y;
            }
        }
    }
    if (inv) {
        if (std::is_integral<T>::value) {
            for (auto& x : f) x /= n;
        } else {
            T inv_n = T(1) / f.size();
            for (auto& x : f) x *= inv_n;
        }
    }
}

template <typename T> std::vector<T> and_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    superset_zeta_transform(f);
    superset_zeta_transform(g);
    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];
    superset_mobius_transform(f);
    return f;
}

template <typename T> std::vector<T> or_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    subset_zeta_transform(f);
    subset_zeta_transform(g);
    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];
    subset_mobius_transform(f);
    return f;
}

template <typename T> std::vector<T> xor_convolution(std::vector<T> f, std::vector<T> g) {
    assert(f.size() == g.size());
    walsh_hadamard_transform(f);
    walsh_hadamard_transform(g);
    for (int i = 0; i < int(f.size()); i++) f[i] *= g[i];
    walsh_hadamard_transform(f, true);
    return f;
}

}  // namespace set_function
