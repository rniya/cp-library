#pragma once
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

namespace hash_impl {

static constexpr unsigned long long mod = (1ULL << 61) - 1;

struct modint {
    modint() : _v(0) {}
    modint(unsigned long long v) {
        v = (v >> 61) + (v & mod);
        if (v >= mod) v -= mod;
        _v = v;
    }

    unsigned long long val() const { return _v; }

    modint& operator+=(const modint& rhs) {
        _v += rhs._v;
        if (_v >= mod) _v -= mod;
        return *this;
    }
    modint& operator-=(const modint& rhs) {
        if (_v < rhs._v) _v += mod;
        _v -= rhs._v;
        return *this;
    }
    modint& operator*=(const modint& rhs) {
        __uint128_t t = __uint128_t(_v) * rhs._v;
        t = (t >> 61) + (t & mod);
        if (t >= mod) t -= mod;
        _v = t;
        return *this;
    }
    modint& operator/=(const modint& rhs) { return *this = *this * rhs.inv(); }

    modint operator-() const { return modint() - *this; }

    modint pow(long long n) const {
        assert(0 <= n);
        modint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    modint inv() const { return pow(mod - 2); }

    friend modint operator+(const modint& lhs, const modint& rhs) { return modint(lhs) += rhs; }
    friend modint operator-(const modint& lhs, const modint& rhs) { return modint(lhs) -= rhs; }
    friend modint operator*(const modint& lhs, const modint& rhs) { return modint(lhs) *= rhs; }
    friend modint operator/(const modint& lhs, const modint& rhs) { return modint(lhs) /= rhs; }
    friend bool operator==(const modint& lhs, const modint& rhs) { return lhs._v == rhs._v; }
    friend bool operator!=(const modint& lhs, const modint& rhs) { return lhs._v != rhs._v; }
    friend std::ostream& operator<<(std::ostream& os, const modint& rhs) { os << rhs._v; }

  private:
    unsigned long long _v;
};

uint64_t generate_base() {
    std::mt19937_64 mt(std::chrono::steady_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<uint64_t> rand(2, mod - 1);
    return rand(mt);
}

modint base(generate_base());
std::vector<modint> power{1};

modint get_pow(int n) {
    if (n < int(power.size())) return power[n];
    int m = power.size();
    power.resize(n + 1);
    for (int i = m; i <= n; i++) power[i] = power[i - 1] * base;
    return power[n];
}

};  // namespace hash_impl

struct Hash {
    using mint = hash_impl::modint;
    mint x;
    int len;

    Hash() : x(0), len(0) {}
    Hash(mint x, int len) : x(x), len(len) {}

    Hash& operator+=(const Hash& rhs) {
        x = x * hash_impl::get_pow(rhs.len) + rhs.x;
        len += rhs.len;
        return *this;
    }
    Hash operator+(const Hash& rhs) { return *this += rhs; }
    bool operator==(const Hash& rhs) { return x == rhs.x and len == rhs.len; }
};

struct ReversibleHash {
    using mint = hash_impl::modint;
    mint x, rx;
    int len;

    ReversibleHash() : x(0), rx(0), len(0) {}
    ReversibleHash(mint x) : x(x), rx(x), len(1) {}
    ReversibleHash(mint x, mint rx, int len) : x(x), rx(rx), len(len) {}

    ReversibleHash rev() const { return ReversibleHash(rx, x, len); }

    ReversibleHash operator+=(const ReversibleHash& rhs) {
        x = x * hash_impl::get_pow(rhs.len) + rhs.x;
        rx = rx + rhs.rx * hash_impl::get_pow(len);
        len += rhs.len;
        return *this;
    }
    ReversibleHash operator+(const ReversibleHash& rhs) { return *this += rhs; }
    bool operator==(const ReversibleHash& rhs) { return x == rhs.x and rx == rhs.rx and len == rhs.len; }
};
