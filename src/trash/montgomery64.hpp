#pragma once
#include "../base.hpp"

/**
 * @brief montgomery modint (64 bit)
 * @docs docs/modulo/montgomery64.md
 */
struct montgomery64 {
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    static u64 mod, r, n2;

    static u64 get_r() {
        u64 res = mod;
        for (int _ = 0; _ < 5; _++) res *= 2 - mod * res;
        return -res;
    }

    static void set_mod(u64 m) {
        assert(m < (1ULL << 62));
        assert((m & 1) == 1);
        mod = m;
        n2 = -u128(m) % m;
        r = get_r();
        assert(r * mod == -1ULL);
    }
    static u64 get_mod() { return mod; }

    static u64 reduce(const u128& x) noexcept { return (x + u128(u64(x) * r) * mod) >> 64; }

    u64 v;
    montgomery64() : v(0) {}
    montgomery64(const i64& v) : v(reduce((u128(v) + mod) * n2)) {}
    u64 value() const {
        u64 res = reduce(v);
        return res >= mod ? res - mod : res;
    }
    montgomery64& operator+=(const montgomery64& rhs) {
        if (i64(v += rhs.v - (mod << 1)) < 0) v += mod << 1;
        return *this;
    }
    montgomery64& operator-=(const montgomery64& rhs) {
        if (i64(v -= rhs.v) < 0) v += mod << 1;
        return *this;
    }
    montgomery64& operator*=(const montgomery64& rhs) {
        v = reduce(u128(v) * rhs.v);
        return *this;
    }
    montgomery64& operator/=(const montgomery64& rhs) { return *this *= rhs.inverse(); }
    montgomery64 operator+(const montgomery64& rhs) const { return montgomery64(*this) += rhs; }
    montgomery64 operator-(const montgomery64& rhs) const { return montgomery64(*this) -= rhs; }
    montgomery64 operator*(const montgomery64& rhs) const { return montgomery64(*this) *= rhs; }
    montgomery64 operator/(const montgomery64& rhs) const { return montgomery64(*this) /= rhs; }
    bool operator==(const montgomery64& rhs) const {
        return (v >= mod ? v - mod : v) == (rhs.v >= mod ? rhs.v - mod : rhs.v);
    }
    bool operator!=(const montgomery64& rhs) const {
        return (v >= mod ? v - mod : v) != (rhs.v >= mod ? rhs.v - mod : rhs.v);
    }
    montgomery64 operator-() const { return montgomery64() - montgomery64(*this); }
    montgomery64 pow(u64 n) const {
        montgomery64 self(*this), res(1);
        while (n > 0) {
            if (n & 1) res *= self;
            self *= self;
            n >>= 1;
        }
        return res;
    }
    montgomery64 inverse() const { return pow(mod - 2); }
    friend istream& operator>>(istream& s, montgomery64& rhs) {
        i64 v;
        rhs = montgomery64{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const montgomery64& rhs) { return s << rhs.v; }
};