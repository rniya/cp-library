---
title: Binomial Coefficients
documentation_of: //src/math/binomial.hpp
---

## 概要
$\mathbb{Z}/p\mathbb{Z}$ における二項係数を扱うライブラリ．
$n$ の上限等を指定する必要はなく，不十分な場合に適宜上限を $2$ 倍にしていくことで効率的に計算する．
上限 $n$，クエリ数 $q$ の際の時間計算量は $\mathrm{O}(q + n + \log n\log p)$，空間計算量は $\mathrm{O}(n)$ となる．

下記の時間計算量については構築にかかる時間計算量は含んでいない．

| メンバ関数                  | 効果                                                                                                                               | 時間計算量                   |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- |
| `fac(i)`                    | $i!$ を返す．                                                                                                                      | $\mathrm{O}(1)$              |
| `finv(i)`                   | $\frac{1}{i!}$ を返す．                                                                                                            | $\mathrm{O}(1)$              |
| `inv(i)`                    | $\frac{1}{i}$ を返す．                                                                                                             | $\mathrm{O}(1)$              |
| `P(n, r)`                   | ${}_n\mathrm{P}_r = \frac{n!}{r!}$ を返す．                                                                                        | $\mathrm{O}(1)$              |
| `C(n, r)`                   | ${}_n \mathrm{C}_r = \binom{n}{r} = \frac{n!}{(n - r)!r!}$ を返す．                                                                | $\mathrm{O}(1)$              |
| `H(n, r)`                   | ${}_n \mathrm{H}_r = \binom{n + r - 1}{r}$，すなわち $n$ 種類のものから重複を許して $r$ 個取り出す組み合わせの総数を返す．         | $\mathrm{O}(1)$              |
| `negative_binom(n, k)`      | $\lbrack x ^ n \rbrack \frac{1}{(1 - x) ^ k}$ を返す．                                                                             | $\mathrm{O}(1)$              |
| `C_naive(n, r)`             | $\binom{n}{r}$ を愚直に計算する．                                                                                                  | $\mathrm{O}(\min(r, n - r))$ |
| `catalan(n)`                | $n$ 番目の Catalan 数を返す．                                                                                                      | $\mathrm{O}(1)$              |
| `catalan1(n, m)`            | $+1$ が $n$ 個，$-1$ が $m$ 個からなる数列であって，累積和がどれも $0$ 以上であるようなものの個数を返す．                          | $\mathrm{O}(1)$              |
| `catalan2(n, m, k)`         | $+1$ が $n$ 個，$-1$ が $m$ 個からなる数列であって，累積和がどれも $- k$ より大きいようなものの個数を返す．                        | $\mathrm{O}(1)$              |
| `catalan_pow(n, k)`         | Catalan 数の母関数を $C(x)$ として，$\lbrack x ^ n \rbrack C ^ k (x)$ を返す．                                                     | $\mathrm{O}(1)$              |
| `narayana(n, k)`            | Narayana 数 $N(n, k)$ を返す．これは長さ $2 n$ の括弧列であって，連続部分列として `()` を丁度 $k$ 個含むようなものの個数に等しい． | $\mathrm{O}(1)$              |
| `grid_sum(x, y)`            | $\sum _ {i = 0} ^ x \sum _ {j = 0} ^ y \binom{i + j}{i}$ を返す．                                                                  | $\mathrm{O}(1)$              |
| `grid_sum2(xl, xr, yl, yr)` | $\sum _ {i = x _ l} ^ {x _ r - 1} \sum _ {j = y _ l} ^ {y _ r - 1} \binom{i + j}{i}$ を返す．                                      | $\mathrm{O}(1)$              |
