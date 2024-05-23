---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/matrix/characteristic_polynomial.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T> std::vector<T>\
    \ characteristic_polynomial(std::vector<std::vector<T>> M) {\n    assert(M.empty()\
    \ or M.size() == M[0].size());\n    int n = M.size();\n    // reduce M to upper\
    \ Hessenberg form\n    for (int j = 0; j < n - 2; j++) {\n        for (int i =\
    \ j + 2; i < n; i++) {\n            if (M[i][j] != 0) {\n                std::swap(M[j\
    \ + 1], M[i]);\n                for (int k = 0; k < n; k++) std::swap(M[k][j +\
    \ 1], M[k][i]);\n                break;\n            }\n        }\n        if\
    \ (M[j + 1][j] == 0) continue;\n        auto inv = T(1) / M[j + 1][j];\n     \
    \   for (int i = j + 2; i < n; i++) {\n            auto coef = M[i][j] * inv;\n\
    \            for (int k = j; k < n; k++) M[i][k] -= coef * M[j + 1][k];\n    \
    \        for (int k = 0; k < n; k++) M[k][j + 1] += coef * M[k][i];\n        }\n\
    \    }\n\n    // compute the characteristic polynomial of upper Hessenberg matrix\
    \ M\n    std::vector<std::vector<T>> p(n + 1);\n    p[0] = {T(1)};\n    for (int\
    \ i = 0; i < n; i++) {\n        p[i + 1].resize(i + 2);\n        for (int j =\
    \ 0; j <= i; j++) {\n            p[i + 1][j + 1] += p[i][j];\n            p[i\
    \ + 1][j] -= p[i][j] * M[i][i];\n        }\n        T betas = 1;\n        for\
    \ (int j = i - 1; j >= 0; j--) {\n            betas *= M[j + 1][j];\n        \
    \    T coef = -betas * M[j][i];\n            for (int k = 0; k <= j; k++) p[i\
    \ + 1][k] += coef * p[j][k];\n        }\n    }\n    return p[n];\n}\n\ntemplate\
    \ <typename T>\nstd::vector<T> determinant_polynomial(std::vector<std::vector<T>>\
    \ M0, std::vector<std::vector<T>> M1) {\n    assert(M0.size() == M1.size());\n\
    \    assert(M0.size() == M0[0].size());\n    assert(M1.size() == M1[0].size());\n\
    \    int n = M0.size(), off = 0;\n    T prod = 1;\n\n    for (int p = 0; p < n;\
    \ p++) {\n        int pivot = -1;\n        for (int i = p; i < n; i++) {\n   \
    \         if (M1[i][p] != 0) {\n                pivot = i;\n                break;\n\
    \            }\n        }\n        if (pivot == -1) {\n            if (++off >\
    \ n) return std::vector<T>(n + 1, 0);\n            for (int i = 0; i < p; i++)\
    \ {\n                for (int k = 0; k < n; k++) M0[k][p] -= M1[i][p] * M0[k][i];\n\
    \                M1[i][p] = 0;\n            }\n            for (int i = 0; i <\
    \ n; i++) std::swap(M0[i][p], M1[i][p]);\n            p--;\n            continue;\n\
    \        }\n        if (pivot != p) {\n            std::swap(M0[p], M0[pivot]);\n\
    \            std::swap(M1[p], M1[pivot]);\n            prod *= -1;\n        }\n\
    \        prod *= M1[p][p];\n        auto inv = T(1) / M1[p][p];\n        for (int\
    \ j = 0; j < n; j++) {\n            M0[p][j] *= inv;\n            M1[p][j] *=\
    \ inv;\n        }\n        for (int i = 0; i < n; i++) {\n            if (i ==\
    \ p) continue;\n            auto coef = M1[i][p];\n            for (int j = 0;\
    \ j < n; j++) {\n                M0[i][j] -= M0[p][j] * coef;\n              \
    \  M1[i][j] -= M1[p][j] * coef;\n            }\n        }\n    }\n\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n            M0[i][j]\
    \ *= -1;\n        }\n    }\n    auto poly = characteristic_polynomial(M0);\n \
    \   std::vector<T> res(n + 1, 0);\n    for (int i = 0; i + off <= n; i++) res[i]\
    \ = prod * poly[i + off];\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>>\
    \ M) {\n    assert(M.empty() or M.size() == M[0].size());\n    int n = M.size();\n\
    \    // reduce M to upper Hessenberg form\n    for (int j = 0; j < n - 2; j++)\
    \ {\n        for (int i = j + 2; i < n; i++) {\n            if (M[i][j] != 0)\
    \ {\n                std::swap(M[j + 1], M[i]);\n                for (int k =\
    \ 0; k < n; k++) std::swap(M[k][j + 1], M[k][i]);\n                break;\n  \
    \          }\n        }\n        if (M[j + 1][j] == 0) continue;\n        auto\
    \ inv = T(1) / M[j + 1][j];\n        for (int i = j + 2; i < n; i++) {\n     \
    \       auto coef = M[i][j] * inv;\n            for (int k = j; k < n; k++) M[i][k]\
    \ -= coef * M[j + 1][k];\n            for (int k = 0; k < n; k++) M[k][j + 1]\
    \ += coef * M[k][i];\n        }\n    }\n\n    // compute the characteristic polynomial\
    \ of upper Hessenberg matrix M\n    std::vector<std::vector<T>> p(n + 1);\n  \
    \  p[0] = {T(1)};\n    for (int i = 0; i < n; i++) {\n        p[i + 1].resize(i\
    \ + 2);\n        for (int j = 0; j <= i; j++) {\n            p[i + 1][j + 1] +=\
    \ p[i][j];\n            p[i + 1][j] -= p[i][j] * M[i][i];\n        }\n       \
    \ T betas = 1;\n        for (int j = i - 1; j >= 0; j--) {\n            betas\
    \ *= M[j + 1][j];\n            T coef = -betas * M[j][i];\n            for (int\
    \ k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];\n        }\n    }\n    return\
    \ p[n];\n}\n\ntemplate <typename T>\nstd::vector<T> determinant_polynomial(std::vector<std::vector<T>>\
    \ M0, std::vector<std::vector<T>> M1) {\n    assert(M0.size() == M1.size());\n\
    \    assert(M0.size() == M0[0].size());\n    assert(M1.size() == M1[0].size());\n\
    \    int n = M0.size(), off = 0;\n    T prod = 1;\n\n    for (int p = 0; p < n;\
    \ p++) {\n        int pivot = -1;\n        for (int i = p; i < n; i++) {\n   \
    \         if (M1[i][p] != 0) {\n                pivot = i;\n                break;\n\
    \            }\n        }\n        if (pivot == -1) {\n            if (++off >\
    \ n) return std::vector<T>(n + 1, 0);\n            for (int i = 0; i < p; i++)\
    \ {\n                for (int k = 0; k < n; k++) M0[k][p] -= M1[i][p] * M0[k][i];\n\
    \                M1[i][p] = 0;\n            }\n            for (int i = 0; i <\
    \ n; i++) std::swap(M0[i][p], M1[i][p]);\n            p--;\n            continue;\n\
    \        }\n        if (pivot != p) {\n            std::swap(M0[p], M0[pivot]);\n\
    \            std::swap(M1[p], M1[pivot]);\n            prod *= -1;\n        }\n\
    \        prod *= M1[p][p];\n        auto inv = T(1) / M1[p][p];\n        for (int\
    \ j = 0; j < n; j++) {\n            M0[p][j] *= inv;\n            M1[p][j] *=\
    \ inv;\n        }\n        for (int i = 0; i < n; i++) {\n            if (i ==\
    \ p) continue;\n            auto coef = M1[i][p];\n            for (int j = 0;\
    \ j < n; j++) {\n                M0[i][j] -= M0[p][j] * coef;\n              \
    \  M1[i][j] -= M1[p][j] * coef;\n            }\n        }\n    }\n\n    for (int\
    \ i = 0; i < n; i++) {\n        for (int j = 0; j < n; j++) {\n            M0[i][j]\
    \ *= -1;\n        }\n    }\n    auto poly = characteristic_polynomial(M0);\n \
    \   std::vector<T> res(n + 1, 0);\n    for (int i = 0; i + off <= n; i++) res[i]\
    \ = prod * poly[i + off];\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/matrix/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2023-04-23 18:55:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1907.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: src/matrix/characteristic_polynomial.hpp
layout: document
title: Characteristic Polynomial / $\det(M_0 + x M_1)$
---

# `characteristic_polynomial`

## 入力

$n \times n$ 行列 $M$

## 出力

$\det (x I - M) = \sum _ {i = 0}^{n} c \lbrack i \rbrack x ^ i$ を満たす長さ $n + 1$ の配列 $c$

## 計算量

時間計算量 $\mathrm{O}(n ^ 3)$

# `determinant_polynomial`

## 入力

$n \times n$ 行列 $M _ 0, M _ 1$

## 出力

$\det (M _ 0 + M _ 1 x) = \sum _ {i = 0}^{n} c \lbrack i \rbrack x ^ i$ を満たす長さ $n + 1$ の配列 $c$

## 計算量

時間計算量 $\mathrm{O}(n ^ 3)$

## 概要

ここでは `characteristic_polynomial(M)` について説明する．
`determinant_polynomial(M0, M1)` については，[この問題](https://yukicoder.me/problems/no/1907) の解説において詳しく説明されている．

アルゴリズムは大きく分けて 2 つのステップに分かれており，まず行列を upper Hessenberg form に変形する．upper Hessenberg form とは対角要素より 2 列以上下にある要素がすべて零な行列，すなわち

$$ \forall i, j,\ a _ {i,j} = 0\ (i \gt j + 1) $$

を満たすものである．
この変形については参照した論文には Householder transform を用いるものとして書かれているが，$\mathbb{Z} / p \mathbb{Z}$ 上のような誤差を気にしなくても良い場合には計算回数を $1 / 2$ 倍に抑えたより良い手法があり，こちらの方が実装も単純である [2]．

### 補題
相似変換は特性多項式を保存する．
すなわち，2 つの $n$ 次正方行列 $A, B$ について，$B = P ^ {-1} A P$ を満たす $n$ 次正則行列 $P$ が存在するとき,

$$ \det(x I - A) = \det(x I - B) $$

が成立する．

#### 証明
$$ \begin{aligned}
  \det(x I - B)
  &= \det(x P ^ {-1} P - P ^ {-1} A P) \\
  &= \det(P ^ {-1} (x I - A) P) \\
  &= \det(P ^ {-1}) \cdot \det(x I - A) \cdot \det(P) \\
  &= \det(x I - A)
\end{aligned} $$

$\blacksquare$

よって，特性多項式を求めるに際し $M$ に対して相似変換はいくら施しても構わない．
ここまでは Householder transform にも通じる考え方である．


$j$ 次の leading principal submatrix まで変形が完了しているとして，次に第 $j + 1$ 列に関して変形することを考える．
まずは Gaussian Elimination と同様に該当行の第 $j + 1$ 列より下において絶対値最大 ($\mathbb{Z} / p \mathbb{Z}$ においては誤差を気にしなくても良いので非負という条件だけで良い) の要素が第 $i$ 行にあるとする．
$j + 2 \neq i$ ならば左からこの 2 行を入れ替える基本行列 $P _ {j + 2, i}$ をかけ，さらにこれが相似変換となるように右からその逆行列 $P _ {j + 2, i} ^ {-1}$ をかける．
明らかに $P _ {j + 2, i} ^ {-1} = P _ {j + 2, i}$ であり，これを右からかけるのは第 $j + 2$ 列と第 $i$ 列を入れ替える操作に対応する．
そして第 $j + 1$ 列の第 $i\ (j + 1 \lt i \leq n)$ 列の要素を零にするために $c = M _ {i, j + 1} / M _ {j + 2, j + 1}$ として，左から第 $i$ 行に第 $j + 2$ 行の $-c$ 倍を加算する行列 $R _ {i, j + 2, -c}$ をかけ，先と同様に右からこの逆行列を同時にかける．
逆操作を考えれば $R _ {i, j + 2, -c} ^ {-1} = R _ {i, j + 2, c}$ であり，これを右からかけるのは第 $j + 2$ 列に第 $i$ 行の $c$ 倍を加算する操作に対応する．
以上で第 $j + 1$ 列に関する変形が完了するのでこれを $0 \leq j \lt n - 1$ について施せば良い．


次のステップとして実際に変換された upper Hessenberg matrix $H$ の特性多項式を求める．

$$ H = \begin{pmatrix}
    \alpha _ 1    & h _ {12}    & \cdots    & \cdots    & h _ {1n} \\
    \beta _ 2     & \alpha _ 2  & h_{23}    & \cdots    & h _ {2n} \\
                & \beta _ 3   & \alpha _ 3  &           & \vdots \\
                &           & \ddots    & \ddots    & h _ {n - 1, n} \\
                &           &           & \beta _ n   & \alpha _ n
\end{pmatrix}$$

として，$i$ 次の leading principal submatrix の特性多項式を $p _ i(x)$ と表す．
求めるべきは $p _ n(x)$ である．
このとき,

$$ \begin{aligned}
    p _ 0(x) &= 1 \\
    p _ {i + 1}(x) &= (x - \alpha _ {i + 1}) p _ i(x) - \sum _ {j = 1} ^ {i} \left( \prod _ {k = i + 2 - j} ^ {i + 1} \beta _ k \right) h _ {i + 1 - j, i + 1} p _ {i - j}(x) \quad (0 \leq i \lt n)
\end{aligned} $$

というような関係が成立する．
漸化式の右辺第 2 項については最後の第 $i + 1$ 行において $\alpha _ {i + 1}$ を選択しない場合には $\beta _ {k + 1}$ を選択せざるを得ず，より上の行について非零要素を選択していく際，帰納的に考えると $\beta _ k$ を選択しない場合には $h _ {k, k + 1}$ を選択せざるを得ないことによる．
この関係式を基に各次数の係数を管理することで $\mathrm{O}(n^3)$ で $H$ の特性多項式を計算することが可能である．

## 出題例
- [2020-2021 Summer Petrozavodsk Camp, Day 6: Korean Contest K. Determinant](https://codeforces.com/gym/102984/problem/K)
- [AtCoder Beginner Contest 323 G - Inversion of Tree](https://atcoder.jp/contests/abc323/tasks/abc323_g)

## References
[1] [R. Rehman, I. Ipsen (2011).  La Budde's Method for Computing Characteristic Polynomials](https://arxiv.org/abs/1104.3769)
[2] J. Stoer, R. Bulirsch (1980). Introduction to Numerical Analysis, Springer-Verlag, 351-370
