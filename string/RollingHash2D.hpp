#pragma once
#include <cassert>
#include <chrono>
#include <random>
#include <string>
#include <vector>

struct RollingHash2D {
    static inline uint64_t generate_base() {
        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<uint64_t> rand(2, RollingHash2D::mod - 1);
        return rand(mt);
    }

    RollingHash2D(uint64_t base0 = generate_base(), uint64_t base1 = generate_base()) {
        basis[0] = base0;
        basis[1] = base1;
        power[0].assign(1, 1);
        power[1].assign(1, 1);
    }

    template <typename T> std::vector<std::vector<uint64_t>> build(const T& s) const {
        int n = s.size(), m = s[0].size();
        std::vector<std::vector<uint64_t>> hash(n + 1, std::vector<uint64_t>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hash[i + 1][j + 1] = add(sub(add(mul(hash[i][j + 1], basis[0]), mul(hash[i + 1][j], basis[1])),
                                             mul(hash[i][j], mul(basis[0], basis[1]))),
                                         s[i][j]);
            }
        }
        return hash;
    }

    template <typename T> uint64_t get(const T& s) const {
        uint64_t res = 0;
        for (size_t i = 0; i < s.size(); i++) {
            uint64_t sum = 0;
            for (const auto& x : s[i]) sum = add(mul(sum, basis[1]), x);
            res = add(mul(res, basis[0]), sum);
        }
        return res;
    }

    uint64_t query(const std::vector<std::vector<uint64_t>>& hash, int xl, int xr, int yl, int yr) {
        assert(0 <= xl and xl <= xr and 0 <= yl and yl <= yr);
        extend(0, xr - xl);
        extend(1, yr - yl);
        return add(sub(sub(hash[xr][yr], mul(hash[xl][yr], power[0][xr - xl])), mul(hash[xr][yl], power[1][yr - yl])),
                   mul(hash[xl][yl], mul(power[0][xr - xl], power[1][yr - yl])));
    }

private:
    static constexpr uint64_t mod = (1ULL << 61) - 1;
    uint64_t basis[2];
    std::vector<uint64_t> power[2];

    static inline uint64_t add(uint64_t a, uint64_t b) {
        if ((a += b) >= mod) a -= mod;
        return a;
    }

    static inline uint64_t sub(uint64_t a, uint64_t b) { return b == 0 ? a : add(a, mod - b); }

    static inline uint64_t mul(uint64_t a, uint64_t b) {
        __uint128_t c = (__uint128_t)a * b;
        return add(c >> 61, c & mod);
    }

    inline void extend(int x, size_t len) {
        if (power[x].size() > len) return;
        size_t pre = power[x].size();
        power[x].resize(len + 1);
        for (size_t i = pre - 1; i < len; i++) power[x][i + 1] = mul(power[x][i], basis[x]);
    }
};

/**
 * @brief Rolling Hash 2D
 * @docs docs/string/RollingHash2D.md
 */
