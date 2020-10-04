## 概要
$n$について, 第2種スターリング数$S\left(n,k\right)\left(0\leq k \leq n\right)$を列挙する.
$$S\left(n,k\right)=\sum_{i=0}^k \dfrac{i^n}{i!}\cdot\dfrac{\left(-1\right)^{k-i}}{\left(k-i\right)!}$$
なので,
$$a_i=\dfrac{i^n}{i!},\ b_i=\dfrac{\left(-1\right)^i}{i!}$$
とすれば,
$$S\left(n,k\right)=\sum_{i=0}^k a_ib_{k-i}$$
であり, これはそのまま数列$\left\{a_i\right\}$と$\left\{b_i\right\}$の畳み込みにより計算可能である.

## 計算量
$O\left(n\log{n}\right)$

## 参照
[FFT (NTT) 関連](https://min-25.hatenablog.com/entry/2015/04/07/160154)