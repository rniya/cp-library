## 概要
$\mathbb{F}_2$ 上での掃き出し法を行うためのライブラリ. $\mathbb{F}_2$ に特化させるために内部では `bitset` でデータを保持している.
- `gauss_jordan(extended)` : 掃き出し法を行い, その結果得られた $\operatorname{rank}$ を返す. `extended` は `linear_equtation(b)` などで最後の行を除外して掃き出す機会があるのでそのための変数.
- `linear_equation(b)` : $\forall i,\ \otimes_{j=1}^m a_{ij}x_j = b_i$ を満たすような数列 $\{x_j\}_{j=1}^m$ を求める. 解を構成することが不可能な場合には -1 を返す. 行列 $A$ の列方向のサイズには 1 だけ余分をもたせておく必要があることに注意.

## 計算量
$O\left(\dfrac{n^2m}{64}\right)$

## 問題例
[yukicoder No.803 Very Limited Xor Subset](https://yukicoder.me/problems/no/803)