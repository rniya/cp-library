---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linearalgebra/characteristic_polynomial.hpp\"\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>>\
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
    \ p[n];\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T> std::vector<T> characteristic_polynomial(std::vector<std::vector<T>> M) {\n\
    \    assert(M.empty() or M.size() == M[0].size());\n    int n = M.size();\n  \
    \  // reduce M to upper Hessenberg form\n    for (int j = 0; j < n - 2; j++) {\n\
    \        for (int i = j + 2; i < n; i++) {\n            if (M[i][j] != 0) {\n\
    \                std::swap(M[j + 1], M[i]);\n                for (int k = 0; k\
    \ < n; k++) std::swap(M[k][j + 1], M[k][i]);\n                break;\n       \
    \     }\n        }\n        if (M[j + 1][j] == 0) continue;\n        auto inv\
    \ = T(1) / M[j + 1][j];\n        for (int i = j + 2; i < n; i++) {\n         \
    \   auto coef = M[i][j] * inv;\n            for (int k = j; k < n; k++) M[i][k]\
    \ -= coef * M[j + 1][k];\n            for (int k = 0; k < n; k++) M[k][j + 1]\
    \ += coef * M[k][i];\n        }\n    }\n\n    // compute the characteristic polynomial\
    \ of upper Hessenberg matrix M\n    std::vector<std::vector<T>> p(n + 1);\n  \
    \  p[0] = {T(1)};\n    for (int i = 0; i < n; i++) {\n        p[i + 1].resize(i\
    \ + 2);\n        for (int j = 0; j <= i; j++) {\n            p[i + 1][j + 1] +=\
    \ p[i][j];\n            p[i + 1][j] -= p[i][j] * M[i][i];\n        }\n       \
    \ T betas = 1;\n        for (int j = i - 1; j >= 0; j--) {\n            betas\
    \ *= M[j + 1][j];\n            T coef = -betas * M[j][i];\n            for (int\
    \ k = 0; k <= j; k++) p[i + 1][k] += coef * p[j][k];\n        }\n    }\n    return\
    \ p[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/characteristic_polynomial.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/characteristic_polynomial.test.cpp
documentation_of: linearalgebra/characteristic_polynomial.hpp
layout: document
title: Characteristic Polynomial
---

## 概要
$n$ 次正方行列 $M$ の特性多項式 $p(x) = \det(xI - M)$ を $O(n^3)$ で計算する.

アルゴリズムは大きく分けて 2 つのステップに分かれており, まず行列を upper Hessenberg form に変形する. upper Hessenberg form とは対角要素より 2 列以上下にある要素がすべて零な行列, すなわち

$$ \forall i, j,\ a_{i,j} = 0\ (i > j + 1) $$

を満たすものである. この変形については参照した論文には Householder transform を用いるものとして書かれているが, $\mathbb{Z}/p\mathbb{Z}$ 上のような誤差を気にしなくても良い場合には計算回数を $1/2$ 倍に抑えたより良い手法があり, こちらの方が実装も単純である [2].

### 補題
相似変換は特性多項式を保存する. すなわち, 2 つの $n$ 次正方行列 $A, B$について, $B = P^{-1}AP$ を満たす $n$ 次正則行列 $P$ が存在するとき,

$$ \det(xI - A) = \det(xI - B) $$

が成立する.

#### 証明
$$ \begin{aligned}
  \det(xI - B)
  &= \det(xP^{-1}P - P^{-1}AP) \\
  &= \det(P^{-1}(xI - A)P) \\
  &= \det(P^{-1}) \cdot \det(xI - A) \cdot \det(P) \\
  &= \det(xI - A)
\end{aligned} $$

$\blacksquare$

よって, 特性多項式を求めるに際し $M$ に対して相似変換はいくら施しても構わない. ここまでは Householder transform にも通じる考え方である.


$j$ 次の leading principal submatrix まで変形が完了しているとして, 次に第 $j + 1$ 列に関して変形することを考える. まずは Gaussian Elimination と同様に該当行の第 $j + 1$ 列より下において絶対値最大 ($\mathbb{Z}/p\mathbb{Z}$ においては誤差を気にしなくても良いので非負という条件だけで良い) の要素が第 $i$ 行にあるとする. $j + 2 \neq i$ ならば左からこの 2 行を入れ替える基本行列 $P_{j + 2, i}$ をかけ, さらにこれが相似変換となるように右からその逆行列 $P_{j + 2, i}^{-1}$ をかける. 明らかに $P_{j + 2, i}^{-1} = P_{j + 2, i}$ であり, これを右からかけるのは第 $j + 2$ 列と第 $i$ 列を入れ替える操作に対応する. そして第 $j + 1$ 列の第 $i\ (j + 1 < i \leq n)$ 列の要素を零にするために $c = M_{i, j + 1}/M_{j + 2, j + 1}$ として, 左から第 $i$ 行に第 $j + 2$ 行の $-c$ 倍を加算する行列 $R_{i, j + 2, -c}$ をかけ, 先と同様に右からこの逆行列を同時にかける. 逆操作を考えれば $R_{i, j + 2, -c}^{-1} = R_{i, j + 2, c}$ であり, これを右からかけるのは第 $j + 2$ 列に第 $i$ 行の $c$ 倍を加算する操作に対応する. 以上で第 $j + 1$ 列に関する変形が完了するのでこれを $0 \leq j < n - 1$ について施せば良い.


次のステップとして実際に変換された upper Hessenberg matrix $H$ の特性多項式を求める.

$$ H = \begin{pmatrix}
    \alpha_1    & h_{12}    & \cdots    & \cdots    & h_{1n} \\
    \beta_2     & \alpha_2  & h_{23}    & \cdots    & h_{2n} \\
                & \beta_3   & \alpha_3  &           & \vdots \\
                &           & \ddots    & \ddots    & h_{n - 1, n} \\
                &           &           & \beta_n   & \alpha_n
\end{pmatrix}$$

として, $i$ 次の leading principal submatrix の特性多項式を $p_i(x)$ と表す. 求めるべきは $p_n(x)$ である. このとき,

$$ \begin{aligned}
    p_0(x) &= 1 \\
    p_{i+1}(x) &= (x - \alpha_{i+1})p_i(x) - \sum_{j = 1}^{i} \left(\prod_{k = i + 2 - j}^{i + 1} \beta_k\right) h_{i + 1 - j, i + 1} p_{i - j}(x) \quad (0 \leq i < n)
\end{aligned} $$

というような関係が成立する. 漸化式の右辺第 2 項については最後の第 $i + 1$ 行において $\alpha_{i + 1}$ を選択しない場合には $\beta_{k + 1}$ を選択せざるを得ず, より上の行について非零要素を選択していく際, 帰納的に考えると $\beta_k$ を選択しない場合には $h_{k,k + 1}$ を選択せざるを得ないことによる. この関係式を基に各次数の係数を管理することで $O(n^3)$ で $H$ の特性多項式を計算することが可能である.

## 問題例
- [2020-2021 Summer Petrozavodsk Camp, Day 6: Korean Contest K. Determinant](https://codeforces.com/gym/102984/problem/K)
  - この問題で初めて必要になり特性多項式が $O(n^3)$ で計算できることを知った. とはいってもライブラリさえ持っていれば本当に貼るだけ….

## References
[1] [R. Rehman, I. Ipsen (2011).  La Budde's Method for Computing Characteristic Polynomials](https://arxiv.org/abs/1104.3769)

[2] J. Stoer, R. Bulirsch (1980). Introduction to Numerical Analysis, Springer-Verlag, 351-370
