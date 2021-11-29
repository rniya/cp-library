---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Exp of Formal Power Series
    links:
    - https://arxiv.org/pdf/1301.5804.pdf
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <vector>\n\n#include \"atcoder/convolution\"\n\ntemplate <typename T> struct\
    \ FormalPowerSeries : std::vector<T> {\nprivate:\n    using std::vector<T>::vector;\n\
    \    using FPS = FormalPowerSeries;\n    void shrink() {\n        while (this->size()\
    \ and this->back() == T(0)) this->pop_back();\n    }\n\n    FPS pre(size_t sz)\
    \ const { return FPS(this->begin(), this->begin() + std::min(this->size(), sz));\
    \ }\n\n    FPS operator>>(size_t sz) const {\n        if (this->size() <= sz)\
    \ return {};\n        return FPS(this->begin() + sz, this->end());\n    }\n\n\
    \    FPS operator<<(size_t sz) const {\n        if (this->empty()) return {};\n\
    \        FPS ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n       \
    \ return ret;\n    }\n\npublic:\n    FPS& operator+=(const FPS& r) {\n       \
    \ if (r.size() > this->size()) this->resize(r.size());\n        for (size_t i\
    \ = 0; i < r.size(); i++) (*this)[i] += r[i];\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator+=(const T& v) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] += v;\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator-=(const FPS& r) {\n        if (r.size() >\
    \ this->size()) this->resize(r.size());\n        for (size_t i = 0; i < r.size();\
    \ i++) (*this)[i] -= r[i];\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const T& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] -= v;\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator*=(const FPS& r) {\n        auto res = atcoder::convolution(*this,\
    \ r);\n        return *this = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const\
    \ T& v) {\n        for (auto& x : (*this)) x *= v;\n        shrink();\n      \
    \  return *this;\n    }\n\n    FPS operator+(const FPS& r) const { return FPS(*this)\
    \ += r; }\n\n    FPS operator+(const T& v) const { return FPS(*this) += v; }\n\
    \n    FPS operator-(const FPS& r) const { return FPS(*this) -= r; }\n\n    FPS\
    \ operator-(const T& v) const { return FPS(*this) -= v; }\n\n    FPS operator*(const\
    \ FPS& r) const { return FPS(*this) *= r; }\n\n    FPS operator*(const T& v) const\
    \ { return FPS(*this) *= v; }\n\n    FPS operator-() const {\n        FPS ret\
    \ = *this;\n        for (auto& v : ret) v = -v;\n        return ret;\n    }\n\n\
    \    FPS differential() const {\n        const int n = (int)this->size();\n  \
    \      FPS ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) ret[i\
    \ - 1] = (*this)[i] * T(i);\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        const int n = (int)this->size();\n        FPS ret(n + 1);\n\
    \        ret[0] = T(0);\n        if (n > 0) ret[1] = T(1);\n        auto mod =\
    \ T::mod();\n        for (int i = 2; i <= n; i++) ret[i] = -ret[mod % i] * (mod\
    \ / i);\n        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n     \
    \   return ret;\n    }\n\n    FPS inv(int deg = -1) const {\n        assert((*this)[0]\
    \ != T(0));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        FPS ret{(*this)[0].inv()};\n        ret.reserve(deg);\n  \
    \      for (int d = 1; d < deg; d <<= 1) {\n            FPS f(d << 1), g(d <<\
    \ 1);\n            std::copy(this->begin(), this->begin() + std::min(n, d << 1),\
    \ f.begin());\n            std::copy(ret.begin(), ret.end(), g.begin());\n   \
    \         atcoder::internal::butterfly(f);\n            atcoder::internal::butterfly(g);\n\
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
    \ == T(0));\n        if (this->size() == 0) return {};\n        if (this->size()\
    \ == 1) return {T(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(T(0));\n \
    \       inv.push_back(T(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = T::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), T(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
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
    \ if (deg == -1) deg = n;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((*this)[i] != T(0)) {\n                if (i * k > deg) return FPS(deg,\
    \ T(0));\n                T rev = (*this)[i].inv();\n                FPS ret =\
    \ (((*this * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n      \
    \          ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, T(0));\n                return ret;\n            }\n\
    \        }\n        return FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n\
    \        T ret = 0, w = 1;\n        for (const auto& v : *this) ret += w * v,\
    \ w *= x;\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/FormalPowerSeries.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: polynomial/FormalPowerSeries.hpp
layout: document
title: "Formal Power Series (\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570)"
---

## 概要
形式的冪級数 (Formal Power Series) を効率的に扱うためのライブラリ。 AC Library の convolution に準拠している。 `inv` 等の関数について特に $\mathbb{F}_{998244353}[x]$ 等 $\bmod$ が NTT-friendly な場合を想定した高速化を行っているため、 $\mathbb{F}_{10^9+7}[x]$ 等を扱う際は注意が必要である。

以下では

$$
f(x) = \sum_{i = 0}^{N - 1} a_ix^i
$$

に対する操作を想定する。

| メンバ関数       | 効果                                                           | 時間計算量    |
| ---------------- | -------------------------------------------------------------- | ------------- |
| `differential()` | $f^\prime(x)$ を求める。                                       | $O(N)$        |
| `integral()`     | $\int f(x) \mathrm{d}x$ を求める。                             | $O(N)$        |
| `inv()`          | $\frac{1}{f(x)}$ を求める。                                    | $O(N \log N)$ |
| `log()`          | $\log (f(x))$ を求める。                                       | $O(N \log N)$ |
| `sqrt()`         | $\sqrt{f(x)}$ を求める。                                       | $O(N \log N)$ |
| `exp()`          | $\exp (f(x))$ を求める。                                       | $O(N \log N)$ |
| `pow(k)`         | $f(x)^k$ を求める。                                            | $O(N \log N)$ |
| `eval(x)`        | $f(x)$ について $x$ に実際に値を代入した際の式の値を計算する。 | $O(N \log N)$ |

メンバ関数 `inv(), log(), sqrt(), exp(), pow()` については引数に `deg` を指定することでその次数で計算を打ち切ることが可能である。これらの操作では高次の項がより次数の低い項に影響を及ぼすことはないため、打ち切りに問題はない。

### 各種アルゴリズムの詳細

#### 乗算
$f(x)g(x)$ を求める。これは Number Theoretic Transform により $O(N \log N)$ で計算可能である。

#### 微分・積分
$f^\prime(x), \int f(x) \mathrm{d}x$ を求める。ただし、不定積分の積分定数は $0$ とする。これは naive に計算可能である。ここで、積分については $1$ から $N$ の $\mathbb{F}_p$ における逆元を求める必要があるが、これを $O(N)$ で求める方法がある。

$x$ の $\mathbb{F}_p$ における逆元を求めたい。 $p$ を $x$ で割ったときの商を $q$ 、余りを $r (r < x)$ とする。$p = qx + r$ より、

$$
\begin{aligned}
    qx + r \equiv 0 \pmod{p}
    &\iff q + rx^{-1} \equiv 0 \pmod{p} \\
    &\iff r^{-1}q + x^{-1} \equiv 0 \pmod{p} \\
    &\iff x^{-1} \equiv -r^{-1}q \pmod{p}
\end{aligned}
$$

$r < x$ だから、上式に基づいて逆元テーブルを昇順に構築できる。

#### inv
$f(x)g(x) \equiv 1 \pmod{x^N}$ なる $g(x) = \sum_{i = 0}^{N - 1} b_ix^i$ を求める。これを $\frac{1}{f(x)}$ とも表すことにする。

###### 補題
$fg_n \equiv 1 \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める。このとき、

$$
g_{2n} = 2g_n - fg_n^2
$$

が成立する。

###### 証明
$fg_n \equiv 1 \pmod{x^n}$ より、 $fg_n - 1= hx^n$ と表せる。このとき、 $(fg_n - 1)^2 = h^2x^{2n}$ だから、

$$
\begin{aligned}
    (fg_n - 1)^2 \equiv 0 \pmod{x^{2n}}
    &\iff f^2g_n^2 -2fg_n + 1 \equiv 0 \pmod{x^{2n}} \\
    &\iff f(2g_n - fg_n^2) \equiv 1 \pmod{x^{2n}} \\
    &\iff fg_{2n} \equiv 1 \pmod{x^{2n}} \quad (g_{2n} = 2g_n - fg_n^2)
\end{aligned}
$$

となる。

$\blacksquare$

$a_0 \neq 0$ のとき、 $g_1 = a_0^{-1}$ だから帰納的にダブリングの要領で計算することが可能となる。計算量は

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る。また、 $a_0 \neq 0$ が逆元の存在の必要条件となる。

ここで、以下の性質に注目する。

- $g_{2n}$ の $[0, n)$ 次の係数は $g_n$ のそれに一致する。よって、 $g_{2n}$ の計算においては $fg_n^2$ の $[n, 2n)$ 次の係数が求まれば良い。
- $fg_n \equiv 1 \pmod{x^n}$ より $fg_n$ の $[1, n)$ 次の係数は 0 であり、 $fg_n$ の $n$ 次未満の部分の多項式を $h$ とすると、 $h$ は $0$ 次の多項式となり、 $g_n$ は $n - 1$ 次以下であるから $hg_n$ は $n - 1$ 次以下となり、 $g_{2n}$ の計算においては無視して良い。

これらより、以下のより高速なアルゴリズムが提案される。
1. $f$ の $[0, n)$ 次の項を取り出したものを改めて $f$ と定める。
2. $h = fg_n \equiv x^{2n}$ を計算する。
3. $h$ の $[n, 2n)$ 次の項を取り出したものを改めて $h$ と定める。
4. $-hg_n$ を計算し、これの $[n, 2n)$ 次の係数が $g_{2n}$ のそれに一致する。

NTT と INTT をうまく組み合わせることで高速化が可能である。

#### log
$\log (f(x))$ 、すなわち、

$$
f(x) \equiv \sum_{k = 0}^{N - 1} \frac{g(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める。 $g(x)$ の定数項を $0$ とすると、 $k \geq N$ については $g(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない。逆にそうでなければ、 $f(x)$ の定数項が不定となり計算不可能である。また、このとき $a_0 = 0^0 = 1$ である。

$\log(f(x))$ と $\int \frac{f^\prime(x)}{f(x)} \mathrm{d}x$ の $N$ 次未満の項は一致することが確認できる。これを素直に実装すれば良い。

#### sqrt
$f(x) \equiv g(x)^2 \pmod{x^N}$ なる $g(x)$ を求める。これを $\sqrt{f(x)}$ とも表すことにする。

これも inv と同様の考え方で計算可能である。

$g_n^2 \equiv f \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める。 $a_0 \neq 0$ であれば $g_n$ の 0 次の係数は $0$ ではないので $g_n$ には逆元が存在する。このとき、

$$
\begin{aligned}
    (g_n^2 - f)^2 \equiv 0 \pmod{x^{2n}}
    &\iff g_n^4 - 2fg_n^2 + f^2 \equiv 0 \pmod{x^{2n}} \\
    &\iff g_n^2 - 2f + f^2g_n^{-2} \equiv 0 \pmod{x^{2n}} \\
    &\iff 4f \equiv g_n^2 + 2f + f^2g_n^{-2} \pmod{x^{2n}} \\
    &\iff f \equiv \left[\frac{1}{2}(g_n + fg_n^{-1})\right]^2 \pmod{x^{2n}} \\
\end{aligned}
$$

より、

$$
g_{2n} = \frac{1}{2}(g_n + fg_n^{-1})
$$

とすれば $g_{2n}^2 \equiv f \pmod{x^{2n}}$ が成立する。 $g_1$ については別途離散対数問題を解くことで計算可能である。あとはダブリングの要領で計算でき、計算量は $g_n^{-1}$ の計算がネックとなり、

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る。

次に $a_0 = 0$ の場合について考える。 $f$ の非零係数をもつ項の次数の最小値を $i$ とすると、 $i$ が奇数であれば求めたい平方根が存在しないことは容易にわかる。 $i$ が偶数の場合は $[i, n)$ 次の項を抽出し $x^{-i}$ をかけて詰めた多項式を改めて $f$ と定めれば、上記のアルゴリズムを適用することができ、その結果得られた多項式に $x^{i/2}$ をかけたものが求めたい平方根となる。

#### exp
$\exp (f(x))$ 、すなわち、

$$
g(x) \equiv \sum_{k = 0}^{N - 1} \frac{f(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める。 $a_0 = 0$ とすると、 $k \geq N$ については $f(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない。逆にそうでなければ、 $g(x)$ の定数項が不定となり計算不可能である。

$\exp (f) \equiv g_n \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める。このとき、 inv や sqrt と同様にして、

$$
g_{2n} = g_n(1 + f - \log g_n)
$$

が成立する。計算量は同じく $O(N \log N)$ である。

これは一般の場合に計算可能な方法だが、 $\bmod$ が NTT-friendly な場合には別のより高速な手法を用いることができる [1] 。

#### pow
$f(x)^k \pmod{x^N}$ を求める。繰り返し二乗法を用いると $O(N \log N \log k)$ で計算可能であるが、 $O(N \log N)$ で計算することができる。

$a_0 = 1$ のとき、

$$
f(x)^k \equiv \exp (k \log f(x)) \pmod{x^N}
$$

が成立することを利用する。定数項が $1$ の多項式 $g(x)$ を用いて $f(x) = cx^lg(x)\ (l \geq 0)$ と表せる。このとき、 $f(x)^k = c^kx^{lk}g(x)^k$ であることを利用すれば良い。

## 問題例
- [Codeforces Round #250 (Div. 1) E. The Child and Binary Tree](https://codeforces.com/contest/438/problem/E)

## Reference
[1] [A simple and fast algorithm for computing exponentials of power series](https://arxiv.org/pdf/1301.5804.pdf)

## Links
- [Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)
- [fpsのニュートン法高速化(簡易版) – Dropbox Paper](https://paper.dropbox.com/doc/fps-EoHXQDZxfduAB8wD1PMBW)
