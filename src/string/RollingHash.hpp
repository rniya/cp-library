#pragma once
#include <algorithm>
#include <string>
#include "Hash.hpp"

struct RollingHash {
    using mint = hash_impl::modint;

    RollingHash() : power{mint(1)} {}

    template <typename T> std::vector<mint> build(const T& s) const {
        int n = s.size();
        std::vector<mint> hash(n + 1);
        hash[0] = 0;
        for (int i = 0; i < n; i++) hash[i + 1] = hash[i] * base + s[i];
        return hash;
    }

    template <typename T> mint get(const T& s) const {
        mint res = 0;
        for (const auto& x : s) res = res * base + x;
        return res;
    }

    mint query(const std::vector<mint>& hash, int l, int r) {
        assert(0 <= l && l <= r);
        extend(r - l);
        return hash[r] - hash[l] * power[r - l];
    }

    mint combine(mint h1, mint h2, int h2_len) {
        extend(h2_len);
        return h1 * power[h2_len] + h2;
    }

    int lcp(const std::vector<mint>& a, int l1, int r1, const std::vector<mint>& b, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int lb = 0, ub = len + 1;
        while (ub - lb > 1) {
            int mid = (lb + ub) >> 1;
            (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;
        }
        return lb;
    }

  private:
    const mint base = hash_impl::base;
    std::vector<mint> power;

    inline void extend(int len) {
        if (int(power.size()) > len) return;
        int pre = power.size();
        power.resize(len + 1);
        for (int i = pre - 1; i < len; i++) power[i + 1] = power[i] * base;
    }
};
