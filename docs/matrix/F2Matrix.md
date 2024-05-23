---
title: Matrix on $\mathbb{F}_2$
documentation_of: //src/matrix/F2Matrix.hpp
---

## 概要
`std::bitset<>` を利用して $\mathbb{F}_2$ 上での各種行列処理を高速化したライブラリ。
固定長の都合上、列数以上の値を引数 `MAX_W` として渡す必要がある。

下表ではワードサイズを $w = 64$ とする。

| メンバ関数                      | 効果                                                                                                                                                                                                                                   | 時間計算量                                       |
| ------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------ |
| `empty()`                       | 行列が空か否かを返す．                                                                                                                                                                                                                 | $\mathrm{O}(1)$                                  |
| `size()`                        | 行数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `height()`                      | 行数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `width()`                       | 列数を返す．                                                                                                                                                                                                                           | $\mathrm{O}(1)$                                  |
| `identity(N)`                   | $N \times N$ 単位行列を返す．                                                                                                                                                                                                          | $\mathrm{O} \left( \frac{N^2}{w} \right)$        |
| 加算                            | $N \times M$ 行列 $A$ に $B$ を加算する．                                                                                                                                                                                              | $\mathrm{O} \left( \frac{N M}{w} \right)$        |
| 減算                            | $N \times M$ 行列 $A$ に $B$ を減算する．                                                                                                                                                                                              | $\mathrm{O} \left( \frac{N M}{w} \right)$        |
| 乗算                            | $N \times M$ 行列 $A$ に $M \times L$ 行列 $B$ を減算する．                                                                                                                                                                            | $\mathrm{O} \left( \frac{N M L}{w} \right)$      |
| `pow(n)`                        | $N \times N$ 正方行列 $A$ を $n$ 乗した行列を返す．                                                                                                                                                                                    | $\mathrm{O} \left( \frac{N^3 \log n}{w} \right)$ |
| `rank()`                        | $N \times M$ 行列 $A$ の rank を返す．                                                                                                                                                                                                 | $\mathrm{O} \left( \frac{N M^2}{w} \right)$      |
| `det()`                         | $N \times N$ 正方行列 $A$ の determinant を返す．                                                                                                                                                                                      | $\mathrm{O} \left( \frac{N^3}{w} \right)$        |
| `system_of_linear_equations(b)` | $N \times M$ 行列 $A$ と長さ $N$ のｔ縦ベクトル $b$ について $A x = b$ という線形方程式系を考える．この方程式系に解が存在しない場合は空配列を返し，存在する場合は解のうちの 1 つ及び解空間の基底ベクトルをこの順にまとめた配列を返す． | $\mathrm{O} \left( \frac{N M^2}{w} \right)$      |


## 出題例
- [yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)
- [AtCoder Beginner Contest 276 Ex - Construct a Matrix](https://atcoder.jp/contests/abc276/tasks/abc276_h)