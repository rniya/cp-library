#pragma once
#include <string>
#include "Hash.hpp"

struct RollingHash2D {
    using mint = hash_impl::modint;

    static inline uint64_t generate_base() {
        std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<uint64_t> rand(2, hash_impl::mod - 1);
        return rand(mt);
    }

    RollingHash2D(uint64_t base0 = generate_base(), uint64_t base1 = generate_base()) {
        basis[0] = base0;
        basis[1] = base1;
        power[0].assign(1, 1);
        power[1].assign(1, 1);
    }

    template <typename T> std::vector<std::vector<mint>> build(const T& s) const {
        int n = s.size(), m = s[0].size();
        std::vector<std::vector<mint>> hash(n + 1, std::vector<mint>(m + 1, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                hash[i + 1][j + 1] =
                    hash[i][j + 1] * basis[0] + hash[i + 1][j] * basis[1] - hash[i][j] * basis[0] * basis[1] + s[i][j];
            }
        }
        return hash;
    }

    template <typename T> mint get(const T& s) const {
        mint res = 0;
        for (int i = 0; i < int(s.size()); i++) {
            mint sum = 0;
            for (const auto& x : s[i]) sum = sum * basis[1] + x;
            res = res * basis[0] + sum;
        }
        return res;
    }

    mint query(const std::vector<std::vector<mint>>& hash, int xl, int xr, int yl, int yr) {
        assert(0 <= xl and xl <= xr and 0 <= yl and yl <= yr);
        extend(0, xr - xl);
        extend(1, yr - yl);
        return hash[xr][yr] - hash[xl][yr] * power[0][xr - xl] - hash[xr][yl] * power[1][yr - yl] +
               hash[xl][yl] * power[0][xr - xl] * power[1][yr - yl];
    }

  private:
    mint basis[2];
    std::vector<mint> power[2];

    inline void extend(int x, int len) {
        if (int(power[x].size()) > len) return;
        int pre = power[x].size();
        power[x].resize(len + 1);
        for (int i = pre - 1; i < len; i++) power[x][i + 1] = power[x][i] * basis[x];
    }
};
