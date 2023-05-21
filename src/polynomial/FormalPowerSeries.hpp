#pragma once
#include <algorithm>
#include <cassert>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

#include "atcoder/convolution"

template <typename T> struct FormalPowerSeries : std::vector<T> {
  private:
    using std::vector<T>::vector;
    using FPS = FormalPowerSeries;
    void shrink() {
        while (this->size() and this->back() == T(0)) this->pop_back();
    }

    FPS pre(size_t sz) const { return FPS(this->begin(), this->begin() + std::min(this->size(), sz)); }

    FPS rev() const {
        FPS ret(*this);
        std::reverse(ret.begin(), ret.end());
        return ret;
    }

    FPS operator>>(size_t sz) const {
        if (this->size() <= sz) return {};
        return FPS(this->begin() + sz, this->end());
    }

    FPS operator<<(size_t sz) const {
        if (this->empty()) return {};
        FPS ret(*this);
        ret.insert(ret.begin(), sz, T(0));
        return ret;
    }

  public:
    FPS& operator+=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < int(r.size()); i++) (*this)[i] += r[i];
        shrink();
        return *this;
    }

    FPS& operator+=(const T& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] += v;
        shrink();
        return *this;
    }

    FPS& operator-=(const FPS& r) {
        if (r.size() > this->size()) this->resize(r.size());
        for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];
        shrink();
        return *this;
    }

    FPS& operator-=(const T& v) {
        if (this->empty()) this->resize(1);
        (*this)[0] -= v;
        shrink();
        return *this;
    }

    FPS& operator*=(const FPS& r) {
        auto res = atcoder::convolution(*this, r);
        return *this = {res.begin(), res.end()};
    }

    FPS& operator*=(const T& v) {
        for (auto& x : (*this)) x *= v;
        shrink();
        return *this;
    }

    FPS& operator/=(const FPS& r) {
        if (this->size() < r.size()) {
            this->clear();
            return *this;
        }
        int n = this->size() - r.size() + 1;
        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();
    }

    FPS& operator%=(const FPS& r) {
        *this -= *this / r * r;
        shrink();
        return *this;
    }

    FPS operator+(const FPS& r) const { return FPS(*this) += r; }

    FPS operator+(const T& v) const { return FPS(*this) += v; }

    FPS operator-(const FPS& r) const { return FPS(*this) -= r; }

    FPS operator-(const T& v) const { return FPS(*this) -= v; }

    FPS operator*(const FPS& r) const { return FPS(*this) *= r; }

    FPS operator*(const T& v) const { return FPS(*this) *= v; }

    FPS operator/(const FPS& r) const { return FPS(*this) /= r; }

    FPS operator%(const FPS& r) const { return FPS(*this) %= r; }

    FPS operator-() const {
        FPS ret = *this;
        for (auto& v : ret) v = -v;
        return ret;
    }

    FPS differential() const {
        const int n = (int)this->size();
        FPS ret(std::max(0, n - 1));
        for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);
        return ret;
    }

    FPS integral() const {
        const int n = (int)this->size();
        FPS ret(n + 1);
        ret[0] = T(0);
        if (n > 0) ret[1] = T(1);
        auto mod = T::mod();
        for (int i = 2; i <= n; i++) ret[i] = -ret[mod % i] * (mod / i);
        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];
        return ret;
    }

    FPS inv(int deg = -1) const {
        assert((*this)[0] != T(0));
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        FPS ret{(*this)[0].inv()};
        ret.reserve(deg);
        for (int d = 1; d < deg; d <<= 1) {
            FPS f(d << 1), g(d << 1);
            std::copy(this->begin(), this->begin() + std::min(n, d << 1), f.begin());
            std::copy(ret.begin(), ret.end(), g.begin());
            atcoder::internal::butterfly(f);
            atcoder::internal::butterfly(g);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            atcoder::internal::butterfly_inv(f);
            std::fill(f.begin(), f.begin() + d, T(0));
            atcoder::internal::butterfly(f);
            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];
            atcoder::internal::butterfly_inv(f);
            T iz = T(d << 1).inv();
            iz *= -iz;
            for (int i = d; i < std::min(d << 1, deg); i++) ret.push_back(f[i] * iz);
        }
        return ret.pre(deg);
    }

    FPS log(int deg = -1) const {
        assert((*this)[0] == T(1));
        if (deg == -1) deg = (int)this->size();
        return (differential() * inv(deg)).pre(deg - 1).integral();
    }

    FPS sqrt(const std::function<T(T)>& get_sqrt, int deg = -1) const {
        const int n = this->size();
        if (deg == -1) deg = n;
        if (this->empty()) return FPS(deg, 0);
        if ((*this)[0] == T(0)) {
            for (int i = 1; i < n; i++) {
                if ((*this)[i] != T(0)) {
                    if (i & 1) return {};
                    if (deg - i / 2 <= 0) break;
                    auto ret = (*this >> i).sqrt(get_sqrt, deg - i / 2);
                    if (ret.empty()) return {};
                    ret = ret << (i / 2);
                    if ((int)ret.size() < deg) ret.resize(deg, T(0));
                    return ret;
                }
            }
            return FPS(deg, T(0));
        }
        auto sqrtf0 = T(get_sqrt((*this)[0]));
        if (sqrtf0 * sqrtf0 != (*this)[0]) return {};
        FPS ret{sqrtf0};
        T inv2 = T(2).inv();
        for (int i = 1; i < deg; i <<= 1) ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;
        return ret.pre(deg);
    }

    /**
     * @brief Exp of Formal Power Series
     *
     * @see https://arxiv.org/pdf/1301.5804.pdf
     */
    FPS exp(int deg = -1) const {
        assert(this->empty() or (*this)[0] == T(0));
        if (this->size() <= 1) return {T(1)};
        if (deg == -1) deg = (int)this->size();
        FPS inv;
        inv.reserve(deg + 1);
        inv.push_back(T(0));
        inv.push_back(T(1));
        auto inplace_integral = [&](FPS& F) -> void {
            const int n = (int)F.size();
            auto mod = T::mod();
            while ((int)inv.size() <= n) {
                int i = inv.size();
                inv.push_back(-inv[mod % i] * (mod / i));
            }
            F.insert(F.begin(), T(0));
            for (int i = 1; i <= n; i++) F[i] *= inv[i];
        };
        auto inplace_differential = [](FPS& F) -> void {
            if (F.empty()) return;
            F.erase(F.begin());
            for (size_t i = 0; i < F.size(); i++) F[i] *= T(i + 1);
        };
        FPS f{1, (*this)[1]}, g{T(1)}, g_fft{T(1), T(1)};
        for (int m = 2; m < deg; m <<= 1) {
            const T iz1 = T(m).inv(), iz2 = T(m << 1).inv();
            auto f_fft = f;
            f_fft.resize(m << 1);
            atcoder::internal::butterfly(f_fft);
            {
                // Step 2.a'
                FPS _g(m);
                for (int i = 0; i < m; i++) _g[i] = f_fft[i] * g_fft[i];
                atcoder::internal::butterfly_inv(_g);
                std::fill(_g.begin(), _g.begin() + (m >> 1), T(0));
                atcoder::internal::butterfly(_g);
                for (int i = 0; i < m; i++) _g[i] *= -g_fft[i] * iz1 * iz1;
                atcoder::internal::butterfly_inv(_g);
                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());

                g_fft = g;
                g_fft.resize(m << 1);
                atcoder::internal::butterfly(g_fft);
            }
            FPS x(this->begin(), this->begin() + std::min((int)this->size(), m));
            {
                // Step 2.b'
                x.resize(m);
                inplace_differential(x);
                x.push_back(T(0));
                atcoder::internal::butterfly(x);
            }
            {
                // Step 2.c'
                for (int i = 0; i < m; i++) x[i] *= f_fft[i] * iz1;
                atcoder::internal::butterfly_inv(x);
            }
            {
                // Step 2.d' and 2.e'
                x -= f.differential();
                x.resize(m << 1);
                for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = T(0);
                atcoder::internal::butterfly(x);
                for (int i = 0; i < (m << 1); i++) x[i] *= g_fft[i] * iz2;
                atcoder::internal::butterfly_inv(x);
            }
            {
                // Step 2.f'
                x.pop_back();
                inplace_integral(x);
                for (int i = m; i < std::min((int)this->size(), m << 1); i++) x[i] += (*this)[i];
                std::fill(x.begin(), x.begin() + m, T(0));
            }
            {
                // Step 2.g' and 2.h'
                atcoder::internal::butterfly(x);
                for (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;
                atcoder::internal::butterfly_inv(x);
                f.insert(f.end(), x.begin() + m, x.end());
            }
        }
        return FPS{f.begin(), f.begin() + deg};
    }

    FPS pow(int64_t k, int deg = -1) const {
        const int n = (int)this->size();
        if (deg == -1) deg = n;
        if (k == 0) {
            auto res = FPS(deg, T(0));
            res[0] = T(1);
            return res;
        }
        for (int i = 0; i < n; i++) {
            if ((*this)[i] != T(0)) {
                if (i >= (deg + k - 1) / k) return FPS(deg, T(0));
                T rev = (*this)[i].inv();
                FPS ret = (((*this * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));
                ret = (ret << (i * k)).pre(deg);
                if ((int)ret.size() < deg) ret.resize(deg, T(0));
                return ret;
            }
        }
        return FPS(deg, T(0));
    }

    T eval(T x) const {
        T ret = 0, w = 1;
        for (const auto& v : *this) ret += w * v, w *= x;
        return ret;
    }

    static FPS product_of_polynomial_sequence(const std::vector<FPS>& fs) {
        if (fs.empty()) return {T(1)};
        auto comp = [](const FPS& f, const FPS& g) { return f.size() > g.size(); };
        std::priority_queue<FPS, std::vector<FPS>, decltype(comp)> pq{comp};
        for (const auto& f : fs) pq.emplace(f);
        while (pq.size() > 1) {
            auto f = pq.top();
            pq.pop();
            auto g = pq.top();
            pq.pop();
            pq.emplace(f * g);
        }
        return pq.top();
    }

    static FPS pow_sparse(const std::vector<std::pair<int, T>>& f, int64_t k, int n) {
        assert(k >= 0);
        int d = f.size(), offset = 0;
        while (offset < d and f[offset].second == 0) offset++;
        FPS res(n, 0);
        if (offset == d) {
            if (k == 0) res[0]++;
            return res;
        }
        if (f[offset].first > 0) {
            int deg = f[offset].first;
            if (k > (n - 1) / deg) return res;
            std::vector<std::pair<int, T>> g(f.begin() + offset, f.end());
            for (auto& p : g) p.first -= deg;
            auto tmp = pow_sparse(g, k, n - k * deg);
            for (int i = 0; i < n - k * deg; i++) res[k * deg + i] = tmp[i];
            return res;
        }
        std::vector<T> invs(n + 1);
        invs[0] = T(0);
        invs[1] = T(1);
        auto mod = T::mod();
        for (int i = 2; i <= n; i++) invs[i] = -invs[mod % i] * (mod / i);
        res[0] = f[0].second.pow(k);
        T coef = f[0].second.inv();
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < d; j++) {
                if (i - f[j].first < 0) break;
                res[i] += f[j].second * res[i - f[j].first] * (T(k) * f[j].first - (i - f[j].first));
            }
            res[i] *= invs[i] * coef;
        }
        return res;
    }

    FPS taylor_shift(T c) const {
        FPS f(*this);
        const int n = f.size();
        std::vector<T> fac(n), finv(n);
        fac[0] = 1;
        for (int i = 1; i < n; i++) {
            fac[i] = fac[i - 1] * i;
            f[i] *= fac[i];
        }
        finv[n - 1] = fac[n - 1].inv();
        for (int i = n - 1; i > 0; i--) finv[i - 1] = finv[i] * i;
        std::reverse(f.begin(), f.end());
        FPS g(n);
        g[0] = T(1);
        for (int i = 1; i < n; i++) g[i] = g[i - 1] * c * finv[i] * fac[i - 1];
        f = (f * g).pre(n);
        std::reverse(f.begin(), f.end());
        for (int i = 0; i < n; i++) f[i] *= finv[i];
        return f;
    }
};
