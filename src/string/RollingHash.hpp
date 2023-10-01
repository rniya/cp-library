#pragma once
#include <cassert>
#include <chrono>
#include <random>
#include <string>
#include <vector>

struct RollingHash {
    static inline uint64_t generate_base() {
        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<uint64_t> rand(2, RollingHash::mod - 1);
        return rand(mt);
    }

    RollingHash(uint64_t base = generate_base()) : base(base), power{1} {}

    template <typename T> std::vector<uint64_t> build(const T& s) const {
        int n = s.size();
        std::vector<uint64_t> hash(n + 1);
        hash[0] = 0;
        for (int i = 0; i < n; i++) hash[i + 1] = add(mul(hash[i], base), s[i]);
        return hash;
    }

    template <typename T> uint64_t get(const T& s) const {
        uint64_t res = 0;
        for (const auto& x : s) res = add(mul(res, base), x);
        return res;
    }

    uint64_t query(const std::vector<uint64_t>& hash, int l, int r) {
        assert(0 <= l && l <= r);
        extend(r - l);
        return add(hash[r], mod - mul(hash[l], power[r - l]));
    }

    uint64_t combine(uint64_t h1, uint64_t h2, size_t h2_len) {
        extend(h2_len);
        return add(mul(h1, power[h2_len]), h2);
    }

    int lcp(const std::vector<uint64_t>& a, int l1, int r1, const std::vector<uint64_t>& b, int l2, int r2) {
        int len = std::min(r1 - l1, r2 - l2);
        int lb = 0, ub = len + 1;
        while (ub - lb > 1) {
            int mid = (lb + ub) >> 1;
            (query(a, l1, l1 + mid) == query(b, l2, l2 + mid) ? lb : ub) = mid;
        }
        return lb;
    }

  private:
    static constexpr uint64_t mod = (1ULL << 61) - 1;
    const uint64_t base;
    std::vector<uint64_t> power;

    static inline uint64_t add(uint64_t a, uint64_t b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline uint64_t mul(uint64_t a, uint64_t b) {
        __uint128_t c = (__uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    inline void extend(size_t len) {
        if (power.size() > len) return;
        size_t pre = power.size();
        power.resize(len + 1);
        for (size_t i = pre - 1; i < len; i++) power[i + 1] = mul(power[i], base);
    }
};
