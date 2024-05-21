---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/polynomial/coefficient_of_powers.hpp
    title: "\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\u306E\u51AA\u4E57\u306E\u4FC2\u6570\
      \u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: src/polynomial/difference_product.hpp
    title: "\u5DEE\u7A4D (Difference Product, Vandermonde's determinant)"
  - icon: ':heavy_check_mark:'
    path: src/polynomial/multipoint_evaluation.hpp
    title: multipoint evaluation
  - icon: ':heavy_check_mark:'
    path: src/polynomial/subset_sum.hpp
    title: $\#_p$ Subset Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
    title: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/product_of_polynomial_sequence.test.cpp
    title: test/yosupo/product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2513.test.cpp
    title: test/yukicoder/2513.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Exp of Formal Power Series
    links:
    - https://arxiv.org/pdf/1301.5804.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n#include \"../atcoder/convolution\"\
    \n\ntemplate <typename T> struct FormalPowerSeries : std::vector<T> {\n  private:\n\
    \    using std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n    void\
    \ shrink() {\n        while (this->size() and this->back() == T(0)) this->pop_back();\n\
    \    }\n\n    FPS pre(size_t sz) const { return FPS(this->begin(), this->begin()\
    \ + std::min(this->size(), sz)); }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        std::reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n\
    \    FPS operator>>(size_t sz) const {\n        if (this->size() <= sz) return\
    \ {};\n        return FPS(this->begin() + sz, this->end());\n    }\n\n    FPS\
    \ operator<<(size_t sz) const {\n        if (this->empty()) return {};\n     \
    \   FPS ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n        return\
    \ ret;\n    }\n\n  public:\n    FPS& operator+=(const FPS& r) {\n        if (r.size()\
    \ > this->size()) this->resize(r.size());\n        for (int i = 0; i < int(r.size());\
    \ i++) (*this)[i] += r[i];\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator+=(const T& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += v;\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (int i = 0; i < int(r.size()); i++) (*this)[i] -= r[i];\n       \
    \ shrink();\n        return *this;\n    }\n\n    FPS& operator-=(const T& v) {\n\
    \        if (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n     \
    \   shrink();\n        return *this;\n    }\n\n    FPS& operator*=(const FPS&\
    \ r) {\n        auto res = atcoder::convolution(*this, r);\n        return *this\
    \ = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const T& v) {\n  \
    \      for (auto& x : (*this)) x *= v;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS& operator/=(const FPS& r) {\n        if (this->size() < r.size())\
    \ {\n            this->clear();\n            return *this;\n        }\n      \
    \  int n = this->size() - r.size() + 1;\n        return *this = (rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n    }\n\n    FPS& operator%=(const FPS& r)\
    \ {\n        *this -= *this / r * r;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS operator+(const FPS& r) const { return FPS(*this) += r; }\n\n\
    \    FPS operator+(const T& v) const { return FPS(*this) += v; }\n\n    FPS operator-(const\
    \ FPS& r) const { return FPS(*this) -= r; }\n\n    FPS operator-(const T& v) const\
    \ { return FPS(*this) -= v; }\n\n    FPS operator*(const FPS& r) const { return\
    \ FPS(*this) *= r; }\n\n    FPS operator*(const T& v) const { return FPS(*this)\
    \ *= v; }\n\n    FPS operator/(const FPS& r) const { return FPS(*this) /= r; }\n\
    \n    FPS operator%(const FPS& r) const { return FPS(*this) %= r; }\n\n    FPS\
    \ operator-() const {\n        FPS ret = *this;\n        for (auto& v : ret) v\
    \ = -v;\n        return ret;\n    }\n\n    FPS differential() const {\n      \
    \  const int n = (int)this->size();\n        FPS ret(std::max(0, n - 1));\n  \
    \      for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    FPS integral() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = T(0);\n        if (n > 0) ret[1] =\
    \ T(1);\n        auto mod = T::mod();\n        for (int i = 2; i <= n; i++) ret[i]\
    \ = -ret[mod % i] * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != T(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        FPS ret{(*this)[0].inv()};\n       \
    \ ret.reserve(deg);\n        for (int d = 1; d < deg; d <<= 1) {\n           \
    \ FPS f(d << 1), g(d << 1);\n            std::copy(this->begin(), this->begin()\
    \ + std::min(n, d << 1), f.begin());\n            std::copy(ret.begin(), ret.end(),\
    \ g.begin());\n            atcoder::internal::butterfly(f);\n            atcoder::internal::butterfly(g);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            std::fill(f.begin(), f.begin() + d, T(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            T iz = T(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++) ret.push_back(f[i] * iz);\n    \
    \    }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg = -1) const\
    \ {\n        assert((*this)[0] == T(1));\n        if (deg == -1) deg = (int)this->size();\n\
    \        return (differential() * inv(deg)).pre(deg - 1).integral();\n    }\n\n\
    \    FPS sqrt(const std::function<T(T)>& get_sqrt, int deg = -1) const {\n   \
    \     const int n = this->size();\n        if (deg == -1) deg = n;\n        if\
    \ (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == T(0)) {\n   \
    \         for (int i = 1; i < n; i++) {\n                if ((*this)[i] != T(0))\
    \ {\n                    if (i & 1) return {};\n                    if (deg -\
    \ i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, T(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, T(0));\n        }\n        auto sqrtf0\
    \ = T(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        T inv2 = T(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1) ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \        return ret.pre(deg);\n    }\n\n    /**\n     * @brief Exp of Formal Power\
    \ Series\n     *\n     * @see https://arxiv.org/pdf/1301.5804.pdf\n     */\n \
    \   FPS exp(int deg = -1) const {\n        assert(this->empty() or (*this)[0]\
    \ == T(0));\n        if (this->size() <= 1) return {T(1)};\n        if (deg ==\
    \ -1) deg = (int)this->size();\n        FPS inv;\n        inv.reserve(deg + 1);\n\
    \        inv.push_back(T(0));\n        inv.push_back(T(1));\n        auto inplace_integral\
    \ = [&](FPS& F) -> void {\n            const int n = (int)F.size();\n        \
    \    auto mod = T::mod();\n            while ((int)inv.size() <= n) {\n      \
    \          int i = inv.size();\n                inv.push_back(-inv[mod % i] *\
    \ (mod / i));\n            }\n            F.insert(F.begin(), T(0));\n       \
    \     for (int i = 1; i <= n; i++) F[i] *= inv[i];\n        };\n        auto inplace_differential\
    \ = [](FPS& F) -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= T(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{T(1)}, g_fft{T(1), T(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const T iz1 = T(m).inv(), iz2 = T(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     // Step 2.a'\n                FPS _g(m);\n                for (int i = 0;\
    \ i < m; i++) _g[i] = f_fft[i] * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n\
    \                std::fill(_g.begin(), _g.begin() + (m >> 1), T(0));\n       \
    \         atcoder::internal::butterfly(_g);\n                for (int i = 0; i\
    \ < m; i++) _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\
    \ this->begin() + std::min((int)this->size(), m));\n            {\n          \
    \      // Step 2.b'\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(T(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                // Step 2.c'\n                for\
    \ (int i = 0; i < m; i++) x[i] *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.d' and 2.e'\n       \
    \         x -= f.differential();\n                x.resize(m << 1);\n        \
    \        for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = T(0);\n     \
    \           atcoder::internal::butterfly(x);\n                for (int i = 0;\
    \ i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.f'\n                x.pop_back();\n\
    \                inplace_integral(x);\n                for (int i = m; i < std::min((int)this->size(),\
    \ m << 1); i++) x[i] += (*this)[i];\n                std::fill(x.begin(), x.begin()\
    \ + m, T(0));\n            }\n            {\n                // Step 2.g' and\
    \ 2.h'\n                atcoder::internal::butterfly(x);\n                for\
    \ (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \                f.insert(f.end(), x.begin() + m, x.end());\n            }\n \
    \       }\n        return FPS{f.begin(), f.begin() + deg};\n    }\n\n    FPS pow(int64_t\
    \ k, int deg = -1) const {\n        const int n = (int)this->size();\n       \
    \ if (deg == -1) deg = n;\n        if (k == 0) {\n            auto res = FPS(deg,\
    \ T(0));\n            res[0] = T(1);\n            return res;\n        }\n   \
    \     for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0)) {\n \
    \               if (i >= (deg + k - 1) / k) return FPS(deg, T(0));\n         \
    \       T rev = (*this)[i].inv();\n                FPS ret = (((*this * rev) >>\
    \ i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n                ret = (ret\
    \ << (i * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ T(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n        T ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n\n    static FPS product_of_polynomial_sequence(const std::vector<FPS>&\
    \ fs) {\n        if (fs.empty()) return {T(1)};\n        auto comp = [](const\
    \ FPS& f, const FPS& g) { return f.size() > g.size(); };\n        std::priority_queue<FPS,\
    \ std::vector<FPS>, decltype(comp)> pq{comp};\n        for (const auto& f : fs)\
    \ pq.emplace(f);\n        while (pq.size() > 1) {\n            auto f = pq.top();\n\
    \            pq.pop();\n            auto g = pq.top();\n            pq.pop();\n\
    \            pq.emplace(f * g);\n        }\n        return pq.top();\n    }\n\n\
    \    static FPS pow_sparse(const std::vector<std::pair<int, T>>& f, int64_t k,\
    \ int n) {\n        assert(k >= 0);\n        int d = f.size(), offset = 0;\n \
    \       while (offset < d and f[offset].second == 0) offset++;\n        FPS res(n,\
    \ 0);\n        if (offset == d) {\n            if (k == 0) res[0]++;\n       \
    \     return res;\n        }\n        if (f[offset].first > 0) {\n           \
    \ int deg = f[offset].first;\n            if (k > (n - 1) / deg) return res;\n\
    \            std::vector<std::pair<int, T>> g(f.begin() + offset, f.end());\n\
    \            for (auto& p : g) p.first -= deg;\n            auto tmp = pow_sparse(g,\
    \ k, n - k * deg);\n            for (int i = 0; i < n - k * deg; i++) res[k *\
    \ deg + i] = tmp[i];\n            return res;\n        }\n        std::vector<T>\
    \ invs(n + 1);\n        invs[0] = T(0);\n        invs[1] = T(1);\n        auto\
    \ mod = T::mod();\n        for (int i = 2; i <= n; i++) invs[i] = -invs[mod %\
    \ i] * (mod / i);\n        res[0] = f[0].second.pow(k);\n        T coef = f[0].second.inv();\n\
    \        for (int i = 1; i < n; i++) {\n            for (int j = 1; j < d; j++)\
    \ {\n                if (i - f[j].first < 0) break;\n                res[i] +=\
    \ f[j].second * res[i - f[j].first] * (T(k) * f[j].first - (i - f[j].first));\n\
    \            }\n            res[i] *= invs[i] * coef;\n        }\n        return\
    \ res;\n    }\n\n    FPS taylor_shift(T c) const {\n        FPS f(*this);\n  \
    \      const int n = f.size();\n        std::vector<T> fac(n), finv(n);\n    \
    \    fac[0] = 1;\n        for (int i = 1; i < n; i++) {\n            fac[i] =\
    \ fac[i - 1] * i;\n            f[i] *= fac[i];\n        }\n        finv[n - 1]\
    \ = fac[n - 1].inv();\n        for (int i = n - 1; i > 0; i--) finv[i - 1] = finv[i]\
    \ * i;\n        std::reverse(f.begin(), f.end());\n        FPS g(n);\n       \
    \ g[0] = T(1);\n        for (int i = 1; i < n; i++) g[i] = g[i - 1] * c * finv[i]\
    \ * fac[i - 1];\n        f = (f * g).pre(n);\n        std::reverse(f.begin(),\
    \ f.end());\n        for (int i = 0; i < n; i++) f[i] *= finv[i];\n        return\
    \ f;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/polynomial/FormalPowerSeries.hpp
  requiredBy:
  - src/polynomial/multipoint_evaluation.hpp
  - src/polynomial/subset_sum.hpp
  - src/polynomial/coefficient_of_powers.hpp
  - src/polynomial/difference_product.hpp
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2513.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/product_of_polynomial_sequence.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
documentation_of: src/polynomial/FormalPowerSeries.hpp
layout: document
title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
---

## 概要
形式的冪級数 (Formal Power Series) を効率的に扱うためのライブラリ．
AC Library の convolution に準拠している．
`inv` 等の関数について特に $\mathbb{F} _ {998244353} \lbrack x \rbrack$ 等 $\text{mod}$ が NTT-friendly な場合を想定した高速化のもとに実装しているため，$\mathbb{F} _ {10^9 + 7} \lbrack x \rbrack$ 等を扱う際は注意が必要である．

以下では

$$
f(x) = \sum_{i = 0}^{N - 1} a_ix^i
$$

に対する操作を想定する．

| メンバ関数       | 効果                                                           | 時間計算量    |
| ---------------- | -------------------------------------------------------------- | ------------- |
| `differential()` | $f^\prime(x)$ を求める．                                       | $O(N)$        |
| `integral()`     | $\int f(x) \mathrm{d}x$ を求める．                             | $O(N)$        |
| `inv()`          | $\frac{1}{f(x)}$ を求める．                                    | $O(N \log N)$ |
| `log()`          | $\log (f(x))$ を求める．                                       | $O(N \log N)$ |
| `sqrt()`         | $\sqrt{f(x)}$ を求める．                                       | $O(N \log N)$ |
| `exp()`          | $\exp (f(x))$ を求める．                                       | $O(N \log N)$ |
| `pow(k)`         | $f(x)^k$ を求める．                                            | $O(N \log N)$ |
| `eval(x)`        | $f(x)$ について $x$ に実際に値を代入した際の式の値を計算する． | $O(N \log N)$ |

メンバ関数 `inv(), log(), sqrt(), exp(), pow()` については引数に `deg` を指定することでその次数で計算を打ち切ることが可能である．
これらの操作では高次の項がより次数の低い項に影響を及ぼすことはないため，打ち切りに問題はない．

### 各種アルゴリズムの詳細

#### 乗算
$f(x)g(x)$ を求める．
これは Number Theoretic Transform により $O(N \log N)$ で計算可能である．

#### （多項式としての）除算
多項式 $f(x), g(x)$ について $f(x) = q(x) g(x) + r(x)$ なる多項式 $q(x), r(x)\ (\deg r < \deg g)$ を求める．
以下，$\deg f = n - 1,\ \deg g = m - 1$ とすると $\deg q = n - m$ である．

$f$ について多項式 $f^R = f(x^{-1}) x^{n - 1}$ を定める．
商と余りの定義式を $x \gets x^{-1}$ として，両辺に $x^{n - 1}$ を掛けて，

$$
\begin{aligned}
    &&&f(x^{-1}) x^{n - 1} = q(x^{-1}) x^{n - m} \cdot g(x^{-1}) x^{m - 1} + r(x^{-1}) x^{m - 2} \cdot x^{n - m + 1} \\
    && \iff &f^R = q^R g^R + r^R x^{n - m + 1} \\
    && \implies & f^R = q^R g^R \pmod{x^{n - m + 1}}.
\end{aligned}
$$

$\deg q^R = n - m < n - m + 1$ より

$$
q^R = q^R \bmod x^{n - m + 1} = \frac{f^R}{g^R}.
$$

#### 微分・積分
$f^\prime(x), \int f(x) \mathrm{d}x$ を求める．
ただし，不定積分の積分定数は $0$ とする．
これは naive に計算可能である．
ここで，積分については $1$ から $N$ の $\mathbb{F}_p$ における逆元を求める必要があるが，これは愚直に求めようとすると時間計算量として $O(N \log \bmod)$ を要するが，$O(N)$ で求める方法がある．

$x$ の $\mathbb{F}_p$ における逆元を求めたい．
$p$ を $x$ で割ったときの商を $q$，余りを $r (r < x)$ とする．
$p = qx + r$ より，

$$
\begin{aligned}
    qx + r \equiv 0 \pmod{p}
    &\iff q + rx^{-1} \equiv 0 \pmod{p} \\
    &\iff r^{-1}q + x^{-1} \equiv 0 \pmod{p} \\
    &\iff x^{-1} \equiv -r^{-1}q \pmod{p}
\end{aligned}
$$

$r < x$ だから，上式に基づいて逆元テーブルを昇順に構築できる．

#### inv
$f(x)g(x) \equiv 1 \pmod{x^N}$ なる $g(x) = \sum_{i = 0}^{N - 1} b_ix^i$ を求める．
これを $\frac{1}{f(x)}$ とも表すことにする．

###### 補題
$fg_n \equiv 1 \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき，

$$
g_{2n} = 2g_n - fg_n^2
$$

が成立する．

###### 証明
$fg_n \equiv 1 \pmod{x^n}$ より，$fg_n - 1= hx^n$ と表せる．
このとき，$(fg_n - 1)^2 = h^2x^{2n}$ だから，

$$
\begin{aligned}
    (fg_n - 1)^2 \equiv 0 \pmod{x^{2n}}
    &\iff f^2g_n^2 -2fg_n + 1 \equiv 0 \pmod{x^{2n}} \\
    &\iff f(2g_n - fg_n^2) \equiv 1 \pmod{x^{2n}} \\
    &\iff fg_{2n} \equiv 1 \pmod{x^{2n}} \quad (g_{2n} = 2g_n - fg_n^2)
\end{aligned}
$$

となる．

$\blacksquare$

$a_0 \neq 0$ のとき，$g_1 = a_0^{-1}$ だから帰納的にダブリングの要領で計算することが可能となる．
計算量は

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．
また，$a_0 \neq 0$ が逆元の存在の必要条件にもなる．

ここで，以下の性質に注目する．

- $g_{2n}$ の $[0, n)$ 次の係数は $g_n$ のそれに一致する．
  よって，$g_{2n}$ の計算においては $fg_n^2$ の $[n, 2n)$ 次の係数が求まれば良い．
- $fg_n \equiv 1 \pmod{x^n}$ より $fg_n$ の $[1, n)$ 次の係数は $0$ であり，$fg_n$ の $n$ 次未満の部分の多項式を $h$ とすると，$h$ は $0$ 次の多項式となり，$g_n$ は $n - 1$ 次以下であるから $hg_n$ は $n - 1$ 次以下となり，$g_{2n}$ の計算においては無視して良い．

これらより，以下のより高速なアルゴリズムが提案される．
1. $f$ の $[0, n)$ 次の項を取り出したものを改めて $f$ と定める．
2. $h = fg_n \equiv x^{2n}$ を計算する．
3. $h$ の $[n, 2n)$ 次の項を取り出したものを改めて $h$ と定める．
4. $-hg_n$ を計算し，これの $[n, 2n)$ 次の係数が $g_{2n}$ のそれに一致する．

毎回畳み込むのではなく NTT と INTT をうまく組み合わせることで，高速化が可能である．

#### log
$\log (f(x))$，すなわち，

$$
f(x) \equiv \sum_{k = 0}^{N - 1} \frac{g(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$g(x)$ の定数項を $0$ とすると，$k \geq N$ については $g(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$f(x)$ の定数項が不定となり計算不可能である．
また，このとき $a_0 = 0^0 = 1$ である．

$\log(f(x))$ と $\int \frac{f^\prime(x)}{f(x)} \mathrm{d}x$ の $N$ 次未満の項は一致することが確認できる．
これを素直に実装すれば良い．

#### sqrt
$f(x) \equiv g(x)^2 \pmod{x^N}$ なる $g(x)$ を求める．
これを $\sqrt{f(x)}$ とも表すことにする．

これも inv と同様の考え方で計算可能である．

$g_n^2 \equiv f \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
$a_0 \neq 0$ であれば $g_n$ の 0 次の係数は $0$ ではないので $g_n$ には逆元が存在する．
このとき，

$$
\begin{aligned}
    (g_n^2 - f)^2 \equiv 0 \pmod{x^{2n}}
    &\iff g_n^4 - 2fg_n^2 + f^2 \equiv 0 \pmod{x^{2n}} \\
    &\iff g_n^2 - 2f + f^2g_n^{-2} \equiv 0 \pmod{x^{2n}} \\
    &\iff 4f \equiv g_n^2 + 2f + f^2g_n^{-2} \pmod{x^{2n}} \\
    &\iff f \equiv \left[\frac{1}{2}(g_n + fg_n^{-1})\right]^2 \pmod{x^{2n}} \\
\end{aligned}
$$

より，

$$
g_{2n} = \frac{1}{2}(g_n + fg_n^{-1})
$$

とすれば $g_{2n}^2 \equiv f \pmod{x^{2n}}$ が成立する．
$g_1$ については別途離散対数問題を解くことで計算可能である．
あとはダブリングの要領で計算でき，計算量は $g_n^{-1}$ の計算がネックとなり，

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．

次に $a_0 = 0$ の場合について考える．
$f$ の非零係数をもつ項の次数の最小値を $i$ とすると，$i$ が奇数であれば求めたい平方根が存在しないことは容易にわかる．
$i$ が偶数の場合は $[i, n)$ 次の項を抽出し $x^{-i}$ をかけて詰めた多項式を改めて $f$ と定めれば，上記のアルゴリズムを適用することができ，その結果得られた多項式に $x^{i/2}$ をかけたものが求めたい平方根となる．

#### exp
$\exp (f(x))$ ，すなわち，

$$
g(x) \equiv \sum_{k = 0}^{N - 1} \frac{f(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$a_0 = 0$ とすると，$k \geq N$ については $f(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$g(x)$ の定数項が不定となり計算不可能である．

$\exp (f) \equiv g_n \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき， inv や sqrt と同様にして，

$$
g_{2n} = g_n(1 + f - \log g_n)
$$

が成立する．
計算量は同じく $O(N \log N)$ である．

これは一般の場合に計算可能な方法だが，$\bmod$ が NTT-friendly な場合には別のより高速な手法を用いることができる [1] ．

#### pow
$f(x)^k \pmod{x^N}$ を求める．繰り返し二乗法を用いると $O(N \log N \log k)$ で計算可能であるが，$O(N \log N)$ で計算することができる．

$a_0 = 1$ のとき，

$$
f(x)^k \equiv \exp (k \log f(x)) \pmod{x^N}
$$

が成立することを利用する．
定数項が $1$ の多項式 $g(x)$ を用いて $f(x) = cx^lg(x)\ (l \geq 0)$ と表せる．
このとき，$f(x)^k = c^kx^{lk}g(x)^k$ であることを利用すれば良い．

#### inv（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$1 / f(x)$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$fg = 1$ より $f_0 g_0 = 1$ かつ $n \geq 1$ について $\sum_{i = 0}^n f_i g_{n - i} = 0$ より $f_0 g_n = - \sum_{i = 1}^n f_i g_{n - i}$ で $n$ の昇順に計算可能である．

より一般に $g$ を疎な $f$ で割った $g / f$ を求めることも同様の計算量で可能である．

#### log（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\log f$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$\log f = f^\prime / f$ であるから inv の場合と同様にして計算できる．
#### exp（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\exp f$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

疎でない場合の exp と同様に $f_0 = 0$ である．
$F = \exp f$ とすると，$F_0 = 1$ で，両辺微分して $F^\prime = F f^\prime$．
$f^\prime$ も疎であるから，$F_n$ までわかっているとき，右辺の $n$ 次の係数，すなわち $F^\prime$ の $n$ 次の係数が計算できるから $F$ の $n + 1$ 次の係数がわかる．

#### pow（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$f(x)^M$ の先頭 $N$ 項を $O(NK + \log M)$ で列挙することができる．

$f$ が定数項をもつ場合に帰着する．
$F = f^M$ とすると，両辺微分して $F^\prime = M f^{M - 1} f^\prime$ より $f F^\prime = M f^\prime F$．
$g = F^\prime$ として $n$ 次の係数について，$\sum_{i = 0}^n f_i g_{n - i} = M \sum_{i = 1}^n i F_{n - i + 1} f_i$ であり，$f_0 g_n = - \sum_{i = 1}^n f_i g_{n - i} + M \sum_{i = 1}^n i F_{n - i + 1} f_i$．$F_n$ までわかっているとき，右辺が計算可能であるから $g_n$ がわかり，$g = F^\prime$ より $F_{n + 1}  = \frac{g_n}{(n + 1) f_0}$．

#### sqrt（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\sqrt{f(x)}$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$f$ の定数項が $1$ の場合に帰着すると，$\sqrt{f} = f^{1 / 2}$ が成立し，pow と同様にして計算可能である．

以上の $f$ が sparse な場合の各種演算は Number Theoretic Transform による積の高速化を必要としないため，$\mathbb{F}_{10^9 + 7}[x]$ 等，**法が NTT-friendly でない場合にも適用可能である．**

## Polynomial Taylor Shift
与えられた多項式 $f(x)$ 及び定数 $c$ について，$f(x + c)$ を求める．

$$
\begin{aligned}
    f(x + c)
    & = \sum_{i = 0}^{N - 1} a_i (x + c)^i \\
    & = \sum_{i = 0}^{N - 1} x^i \sum_{j = i}^{N - 1} a_j \binom{j}{i} c^{j - i} \\
    & = \sum_{i = 0}^{N - 1} \frac{x^i}{i!} \sum_{j = i}^{N - 1} \frac{c^{j - i}}{(j - i)!} a_j j! \\
    & = \sum_{i = 0}^{N - 1} \frac{x^i}{i!} \sum_{j = 0}^{N - 1 - i} \frac{c^j}{j!} a_{i + j} (i + j)! \\
    & = \sum_{k = 0}^{N - 1} a_k k! \sum_{j = 0}^{k} \frac{c^j}{j!} \frac{x^{k - j}}{(k - j)!}
\end{aligned}
$$

となり，畳込みに帰着される．
計算量は $O(N \log N)$．

## 問題例
- [Codeforces Round #250 (Div. 1) E. The Child and Binary Tree](https://codeforces.com/contest/438/problem/E)

- [yukicoder No.1145 Sums of Powers](https://yukicoder.me/problems/no/1145)
  - 答えの母関数を考えると，

    $$ \begin{align*}
        \sum_{n = 0}^\infty x^n \sum_{i = 1}^N A_i^n
        &= \sum_{i = 1}^N \sum_{n = 0}^\infty (A_i x)^n \\
        &= \sum_{i = 1}^N \frac{1}{1 - A_i x}
    \end{align*} $$

    となり，これは分子と分母を二分木のように計算していくことで求めることができる．

    もしくは，

    $$ - \log (1 - x) = \sum_{n = 1}^\infty \frac{x^n}{n} $$

    を用いると


    $$ \begin{align*}
        - \log \prod_{i = 1}^N (1 - A_i x)
        &= \sum_{i = 1}^N - \log (1 - A_i x) \\
        &= \sum_{i = 1}^N \sum_{n = 0}^\infty \frac{(A_i x)^n}{n} \\
        &= \sum_{n = 0}^\infty \left(\sum_{i = 1}^N A_i^n \right) \frac{x^n}{n}
    \end{align*} $$

    となることからも計算可能である．

- [AtCoder Beginner Contest 222 H - Beautiful Binary Tree](https://atcoder.jp/contests/abc222/tasks/abc222_h)

- [AtCoder Beginner Contest 230 H - Bullion](https://atcoder.jp/contests/abc230/tasks/abc230_h)

- [AtCoder Beginner Contest 260 Ex - Colorfulness](https://atcoder.jp/contests/abc260/tasks/abc260_h)
  - 包除原理により $C(P) = n$ である $P$ の個数を求めた後，Sums of Powers と同様の考察により解くことができる．

- [灘校文化祭コンテスト 2022 Day1 K - Li](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_k)

- [AtCoder Regular Contest 154 F - Dice Game](https://atcoder.jp/contests/arc154/tasks/arc154_f)
  - $\sum_k a_k e^{b_k x}$ が計算できる．具体的には求める多項式を $f$ として $f$ の $i$ 次の係数を $i!$ 倍した多項式を $g$ とすると，これは $e^{b x} = \sum_{i \geq 0} \frac{(b x)^i}{i!}$ より $\sum_k a_k \sum_{i \geq 0} (b_k x)^i = \sum_k \frac{a_k}{1 - b_k x}$ に等しい．
  - このような計算テクニックは[ここ](https://maspypy.com/%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%83%bb%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0-%e9%ab%98%e9%80%9f%e3%81%ab%e8%a8%88%e7%ae%97%e3%81%a7%e3%81%8d%e3%82%8b%e3%82%82%e3%81%ae)に詳しい．

- [yukicoder No.2514 Twelvefold Way Returns](https://yukicoder.me/problems/no/2514)
  - $k$ の倍数次の係数を取り出したい際には $1$ の $k$ 乗根に注目すると良い（[参照 1 (Roots of Unity Filter)](https://codeforces.com/blog/entry/77551)，[参照 2](https://hackmd.io/@tko919/r1p17_-li)）．

## Reference
[1] [A simple and fast algorithm for computing exponentials of power series](https://arxiv.org/pdf/1301.5804.pdf)

## Links
- [Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)
- [Nyaan's Library](https://nyaannyaan.github.io/library/)
- [fpsのニュートン法高速化(簡易版) – Dropbox Paper](https://paper.dropbox.com/doc/fps-EoHXQDZxfduAB8wD1PMBW)
- [形式的べき級数解説 \| maspyのHP](https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac)
- [[Tutorial] Generating Functions in Competitive Programming (Part 1) - Codeforces](https://codeforces.com/blog/entry/77468)
- [[Tutorial] Generating Functions in Competitive Programming (Part 2) - Codeforces](https://codeforces.com/blog/entry/77551)
- [A problem collection of ODE and differential technique - Codeforces](https://codeforces.com/blog/entry/76447)
