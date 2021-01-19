#pragma once
#include "../base.hpp"

/**
 * @brief 実行時 modint
 * @docs docs/modulo/modint.md
 */
class dynamic_modint {
    using i64 = int64_t;
    using u32 = uint32_t;
    using u64 = uint64_t;
    static u32& mod() {
        static u32 mod_ = 0;
        return mod_;
    }

public:
    u32 v;
    static void set_mod(const u32 x) {
        assert(x < (u32(1) << 31));
        mod() = x;
    }
    static u32 get_mod() { return mod(); }
    dynamic_modint(const i64 x = 0) : v(x < 0 ? get_mod() - 1 - (-(x + 1) % get_mod()) : x % get_mod()) {}
    u32& value() noexcept { return v; }
    const u32& value() const noexcept { return v; }
    dynamic_modint operator+(const dynamic_modint& rhs) const { return dynamic_modint(*this) += rhs; }
    dynamic_modint operator-(const dynamic_modint& rhs) const { return dynamic_modint(*this) -= rhs; }
    dynamic_modint operator*(const dynamic_modint& rhs) const { return dynamic_modint(*this) *= rhs; }
    dynamic_modint operator/(const dynamic_modint& rhs) const { return dynamic_modint(*this) /= rhs; }
    dynamic_modint& operator+=(const dynamic_modint& rhs) {
        v += rhs.v;
        if (v >= get_mod()) v -= get_mod();
        return *this;
    }
    dynamic_modint& operator-=(const dynamic_modint& rhs) {
        if (v < rhs.v) v += get_mod();
        v -= rhs.v;
        return *this;
    }
    dynamic_modint& operator*=(const dynamic_modint& rhs) {
        v = (u64)v * rhs.v % get_mod();
        return *this;
    }
    dynamic_modint& operator/=(const dynamic_modint& rhs) { return *this *= rhs.pow(get_mod() - 2); }
    dynamic_modint pow(u64 exp) const {
        dynamic_modint self(*this), res(1);
        while (exp > 0) {
            if (exp & 1) res *= self;
            self *= self;
            exp >>= 1;
        }
        return res;
    }
    dynamic_modint& operator++() {
        if (++v == get_mod()) v = 0;
        return *this;
    }
    dynamic_modint& operator--() {
        if (v == 0) v = get_mod();
        return --v, *this;
    }
    dynamic_modint operator++(int) {
        dynamic_modint t = *this;
        return ++*this, t;
    }
    dynamic_modint operator--(int) {
        dynamic_modint t = *this;
        return --*this, t;
    }
    dynamic_modint operator-() { return dynamic_modint(get_mod() - v); }
    template <class T> friend dynamic_modint operator+(T x, dynamic_modint y) { return dynamic_modint(x) + y; }
    template <class T> friend dynamic_modint operator-(T x, dynamic_modint y) { return dynamic_modint(x) - y; }
    template <class T> friend dynamic_modint operator*(T x, dynamic_modint y) { return dynamic_modint(x) * y; }
    template <class T> friend dynamic_modint operator/(T x, dynamic_modint y) { return dynamic_modint(x) / y; }
    bool operator==(const dynamic_modint& rhs) { return v == rhs.v; }
    bool operator!=(const dynamic_modint& rhs) { return v != rhs.v; }
    bool operator!() { return !v; }
    friend istream& operator>>(istream& s, dynamic_modint& rhs) {
        i64 v;
        rhs = dynamic_modint{(s >> v, v)};
        return s;
    }
    friend ostream& operator<<(ostream& s, const dynamic_modint& rhs) { return s << rhs.v; }
};