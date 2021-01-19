#pragma once
#include "../base.hpp"

/**
 * @brief Formal Power Series
 * @docs docs/polynomial/FormalPowerSeries.md
 */
template <typename M> struct FormalPowerSeries : vector<M> {
    using vector<M>::vector;
    using Poly = FormalPowerSeries;
    using MUL = function<Poly(Poly, Poly)>;
    static MUL& get_mul() {
        static MUL mul = nullptr;
        return mul;
    }
    static void set_mul(MUL f) { get_mul() = f; }
    void shrink() {
        while (this->size() && this->back() == M(0)) this->pop_back();
    }
    Poly pre(int deg) const { return Poly(this->begin(), this->begin() + min((int)this->size(), deg)); }
    Poly operator+(const M& v) const { return Poly(*this) += v; }
    Poly operator+(const Poly& p) const { return Poly(*this) += p; }
    Poly operator-(const M& v) const { return Poly(*this) -= v; }
    Poly operator-(const Poly& p) const { return Poly(*this) -= p; }
    Poly operator*(const M& v) const { return Poly(*this) *= v; }
    Poly operator*(const Poly& p) const { return Poly(*this) *= p; }
    Poly operator/(const Poly& p) const { return Poly(*this) /= p; }
    Poly operator%(const Poly& p) const { return Poly(*this) %= p; }
    Poly& operator+=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        return *this;
    }
    Poly& operator+=(const Poly& p) {
        if (p.size() > this->size()) this->resize(p.size());
        for (int i = 0; i < p.size(); i++) (*this)[i] += p[i];
        return *this;
    }
    Poly& operator-=(const M& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        return *this;
    }
    Poly& operator-=(const Poly& p) {
        if (p.size() > this->size()) this->resize(p.size());
        for (int i = 0; i < p.size(); i++) (*this)[i] -= p[i];
        return *this;
    }
    Poly& operator*=(const M& v) {
        for (int i = 0; i < this->size(); i++) (*this)[i] *= v;
        return *this;
    }
    Poly& operator*=(const Poly& p) {
        if (this->empty() || p.empty()) {
            this->clear();
            return *this;
        }
        assert(get_mul() != nullptr);
        return *this = get_mul()(*this, p);
    }
    Poly& operator/=(const Poly& p) {
        if (this->size() < p.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - p.size() - 1;
        return *this = (rev().pre(n) * p.rev().inv(n)).pre(n).rev(n);
    }
    Poly& operator%=(const Poly& p) { return *this -= *this / p * p; }
    Poly operator<<(const int deg) {
        Poly res(*this);
        res.insert(res.begin(), deg, M(0));
        return res;
    }
    Poly operator>>(const int deg) {
        if (this->size() <= deg) return {};
        Poly res(*this);
        res.erase(res.begin(), res.begin() + deg);
        return res;
    }
    Poly operator-() const {
        Poly res(this->size());
        for (int i = 0; i < this->size(); i++) res[i] = -(*this)[i];
        return res;
    }
    Poly rev(int deg = -1) const {
        Poly res(*this);
        if (~deg) res.resize(deg, M(0));
        reverse(res.begin(), res.end());
        return res;
    }
    Poly diff() const {
        Poly res(max(0, (int)this->size() - 1));
        for (int i = 1; i < this->size(); i++) res[i - 1] = (*this)[i] * M(i);
        return res;
    }
    Poly integral() const {
        Poly res(this->size() + 1);
        res[0] = M(0);
        for (int i = 0; i < this->size(); i++) res[i + 1] = (*this)[i] / M(i + 1);
        return res;
    }
    Poly inv(int deg = -1) const {
        assert((*this)[0] != M(0));
        if (deg < 0) deg = this->size();
        Poly res({M(1) / (*this)[0]});
        for (int i = 1; i < deg; i <<= 1) {
            res = (res + res - res * res * pre(i << 1)).pre(i << 1);
        }
        return res.pre(deg);
    }
    Poly log(int deg = -1) const {
        assert((*this)[0] == M(1));
        if (deg < 0) deg = this->size();
        return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
    }
    Poly sqrt(int deg = -1) const {
        assert((*this)[0] == M(1));
        if (deg == -1) deg = this->size();
        Poly res({M(1)});
        M inv2 = M(1) / M(2);
        for (int i = 1; i < deg; i <<= 1) {
            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;
        }
        return res.pre(deg);
    }
    Poly exp(int deg = -1) {
        assert((*this)[0] == M(0));
        if (deg < 0) deg = this->size();
        Poly res({M(1)});
        for (int i = 1; i < deg; i <<= 1) {
            res = (res * (pre(i << 1) + M(1) - res.log(i << 1))).pre(i << 1);
        }
        return res.pre(deg);
    }
    Poly pow(long long k, int deg = -1) const {
        if (deg < 0) deg = this->size();
        for (int i = 0; i < this->size(); i++) {
            if ((*this)[i] == M(0)) continue;
            if (k * i > deg) return Poly(deg, M(0));
            M inv = M(1) / (*this)[i];
            Poly res = (((*this * inv) >> i).log() * k).exp() * (*this)[i].pow(k);
            res = (res << (i * k)).pre(deg);
            if (res.size() < deg) res.resize(deg, M(0));
            return res;
        }
        return *this;
    }
    Poly pow_mod(long long k, const Poly& mod) const {
        Poly x(*this), res = {M(1)};
        while (k > 0) {
            if (k & 1) res = res * x % mod;
            x = x * x % mod;
            k >>= 1;
        }
        return res;
    }
    Poly linear_mul(const M& a, const M& b) {
        Poly res(this->size() + 1);
        for (int i = 0; i < this->size() + 1; i++) {
            res[i] = (i - 1 >= 0 ? (*this)[i - 1] * a : M(0)) + (i < this->size() ? (*this)[i] * b : M(0));
        }
        return res;
    }
    Poly linear_div(const M& a, const M& b) {
        Poly res(this->size() - 1);
        M inv_b = M(1) / b;
        for (int i = 0; i + 1 < this->size(); i++) {
            res[i] = ((*this)[i] - (i - 1 >= 0 ? res[i - 1] * a : M(0))) * inv_b;
        }
        return res;
    }
    Poly sparse_mul(const M& c, const M& d) {
        Poly res(*this);
        res.resize(this->size() + d, M(0));
        for (int i = 0; i < this->size(); i++) {
            res[i + d] += (*this)[i] * c;
        }
        return res;
    }
    Poly sparse_div(const M& c, const M& d) {
        Poly res(*this);
        for (int i = 0; i < res.size() - d; i++) {
            res[i + d] -= res[i] * c;
        }
        return res;
    }
    M operator()(const M& x) const {
        M res = 0, power = 1;
        for (int i = 0; i < this->size(); i++, power *= x) {
            res += (*this)[i] * power;
        }
        return res;
    }
};