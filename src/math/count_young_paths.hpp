#include "atcoder/convolution"
#include "math/binomial.hpp"

template <class T>
std::vector<T> count_young_paths(const std::vector<int>& h, const std::vector<T>& a, Binomial<T>& binom) {
    assert(h.size() == a.size());
    assert(std::is_sorted(begin(h), end(h)));
    int n = h.size(), m = n >> 1;
    if (n == 0) return {};
    if (n == 1) return std::vector<T>(h.front(), a.front());
    assert(h[0] >= 0);
    if (h[0] == 0) {
        int l = 0;
        while (l < n and h[l] == 0) l++;
        return count_young_paths(std::vector<int>(begin(h) + l, end(h)), std::vector<T>(begin(a) + l, end(a)), binom);
    }
    int x = n - m, y = h[m - 1];
    auto b = count_young_paths(std::vector<int>(begin(h), begin(h) + m), std::vector<T>(begin(a), begin(a) + m), binom);
    std::vector<T> c(x, 0), d(y, 0);
    // a: down, b: left, c: up, d: right
    {
        // a -> c
        std::vector<T> f(x), g(x);
        for (int i = 0; i < x; i++) f[i] = a[m + i];
        for (int i = 0; i < x; i++) g[i] = binom.C(y - 1 + i, i);
        f = atcoder::convolution(f, g);
        for (int i = 0; i < x; i++) c[i] += f[i];
    }
    {
        // a -> d
        std::vector<T> f(x), g(x + y - 1);
        for (int i = 0; i < x; i++) f[i] = a[m + i] * binom.finv(x - 1 - i);
        for (int i = 0; i < x + y - 1; i++) g[i] = binom.fac(i);
        f = atcoder::convolution(f, g);
        for (int i = 0; i < y; i++) d[i] += f[x - 1 + i] * binom.finv(i);
    }
    {
        // b -> c
        std::vector<T> f(y), g(x + y - 1);
        for (int i = 0; i < y; i++) f[i] = b[i] * binom.finv(y - 1 - i);
        for (int i = 0; i < x + y - 1; i++) g[i] = binom.fac(i);
        f = atcoder::convolution(f, g);
        for (int i = 0; i < x; i++) c[i] += f[y - 1 + i] * binom.finv(i);
    }
    {
        // b -> d
        std::vector<T> f(y), g(y);
        for (int i = 0; i < y; i++) f[i] = b[i];
        for (int i = 0; i < y; i++) g[i] = binom.C(x - 1 + i, i);
        f = atcoder::convolution(f, g);
        for (int i = 0; i < y; i++) d[i] += f[i];
    }
    std::vector<T> res(h.back());
    for (int i = 0; i < y; i++) res[i] = d[i];
    std::vector<int> nh(x);
    for (int i = 0; i < x; i++) nh[i] = h[m + i] - y;
    auto nd = count_young_paths(nh, c, binom);
    for (int i = 0; i < int(nd.size()); i++) res[y + i] = nd[i];
    return res;
}
