#pragma once
#include <numeric>
#include <vector>

namespace elementary_math {

template <typename T> std::vector<T> divisor(T n) {
    std::vector<T> res;
    for (T i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.emplace_back(i);
            if (i * i != n) res.emplace_back(n / i);
        }
    }
    return res;
}

template <typename T> std::vector<std::pair<T, int>> prime_factor(T n) {
    std::vector<std::pair<T, int>> res;
    for (T p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            res.emplace_back(p, 0);
            while (n % p == 0) {
                res.back().second++;
                n /= p;
            }
        }
    }
    if (n > 1) res.emplace_back(n, 1);
    return res;
}

std::vector<int> osa_k(int n) {
    std::vector<int> min_factor(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (min_factor[i]) continue;
        for (int j = i; j <= n; j += i) {
            if (!min_factor[j]) {
                min_factor[j] = i;
            }
        }
    }
    return min_factor;
}

std::vector<int> prime_factor(const std::vector<int>& min_factor, int n) {
    std::vector<int> res;
    while (n > 1) {
        res.emplace_back(min_factor[n]);
        n /= min_factor[n];
    }
    return res;
}

long long modpow(long long x, long long n, long long mod) {
    assert(0 <= n && 1 <= mod && mod < (1LL << 31));
    if (mod == 1) return 0;
    x %= mod;
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

long long extgcd(long long a, long long b, long long& x, long long& y) {
    long long d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else
        x = 1, y = 0;
    return d;
}

long long inv_mod(long long a, long long mod) {
    assert(1 <= mod);
    long long x, y;
    if (extgcd(a, mod, x, y) != 1) return -1;
    return (mod + x % mod) % mod;
}

template <typename T> T euler_phi(T n) {
    auto pf = prime_factor(n);
    T res = n;
    for (const auto& p : pf) {
        res /= p.first;
        res *= p.first - 1;
    }
    return res;
}

std::vector<int> euler_phi_table(int n) {
    std::vector<int> res(n + 1, 0);
    iota(res.begin(), res.end(), 0);
    for (int i = 2; i <= n; i++) {
        if (res[i] != i) continue;
        for (int j = i; j <= n; j += i) res[j] = res[j] / i * (i - 1);
    }
    return res;
}

// minimum i > 0 s.t. x^i \equiv 1 \pmod{m}
template <typename T> T order(T x, T m) {
    T n = euler_phi(m);
    auto cand = divisor(n);
    sort(cand.begin(), cand.end());
    for (auto& i : cand) {
        if (modpow(x, i, m) == 1) {
            return i;
        }
    }
    return -1;
}

}  // namespace elementary_math

/**
 * @brief elementary math
 * @docs docs/math/elementary_math.md
 */
