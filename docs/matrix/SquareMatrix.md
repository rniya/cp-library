---
title: Square Matrix
documentation_of: //src/matrix/SquareMatrix.hpp
---

主としてサイズの固定された行列群を扱う際に `std::array` を用いることで各処理を高速化したライブラリ。

下表では扱う行列の行数（列数）を $N$ とする。

| メンバ関数    | 効果                               | 時間計算量               |
| ------------- | ---------------------------------- | ------------------------ |
| `size()`      | 行数を返す．                       | $\mathrm{O}(1)$          |
| `identity()`  | 単位行列を返す．                   | $\mathrm{O}(N^2)$        |
| 加算          | 行列 $A$ に $B$ を加算する．       | $\mathrm{O}(N^2)$        |
| 減算          | 行列 $A$ に $B$ を減算する．       | $\mathrm{O}(N^2)$        |
| 乗算          | 行列 $A$ に $B$ を減算する．       | $\mathrm{O}(N^3)$        |
| スカラー倍    | 行列 $A$ をスカラー倍する．        | $\mathrm{O}(N^2)$        |
| `pow(n)`      | 行列 $A$ を $n$ 乗した行列を返す． | $\mathrm{O}(N^3 \log n)$ |
| `transpose()` | 行列 $A$ を転置した行列を返す．    | $\mathrm{O}(N^2)$        |
| `rank()`      | 行列 $A$ の rank を返す．          | $\mathrm{O}(N^3)$        |
| `det()`       | 行列 $A$ の determinant を返す．   | $\mathrm{O}(N^3)$        |
| `inv()`       | 行列 $A$ の逆行列を返す．          | $\mathrm{O}(N^3)$        |
