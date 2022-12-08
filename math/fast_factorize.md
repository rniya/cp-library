---
title: 高速素因数分解 (Miller-Rabin primality test + Pollard's rho algorithm)
documentation_of: ./fast_factorize.hpp
---

## 概要
#### Miller-Rabin の素数判定法
与えられた $n$ の素数判定を高速に行う乱択（ただし $2^64$ 未満の数については決定的に行うことが可能）アルゴリズム。

偶数については自明だから以下では $n$ は奇数とする。
また、合同式は全て $p$ を法とする。

#### 補題
任意の奇素数 $p$ について、
$$
x^2 \equiv 1 \iff  \equiv \pm 1.
$$

###### 証明

$\blacksquare$

自然数 $s$ 及び奇数 $d$ を用いて $p - 1 = 2^s d$ とすると、Fermat の小定理から自然数 $a$ が $p$ と互いに素であるならば、
$$
a^{2^s d} \equiv 1.
$$
このとき、上の補題より、
$$
a^d \equiv 1 \lor (\exists r \in \Z \cap [0, s - 1],\ a^{2^r d} \equiv - 1)
$$
が成立する。
この対偶を取ることで
$p \not| a$ かつ $a^d \not\equiv 1$ かつ $\forall r \in \Z \cap [0, s - 1],\ a^{2^r d} \not\equiv - 1$ ならば $a$ は $p$ と互いに素ではなく、$p$ は合成数であることがわかる。
この $a$ をランダムに選び合成数であるかを判定していき最後まで決まらなかった場合に $p$ は素数であるとするのがアルゴリズムの概要である。

ここで、$a < 2^{64}$ 未満の $n$ については決まった高々 7 個の $a$ を用いることで決定的に判定可能であることがわかっている。

#### Pollard の $\rho$ 法

## 計算量
$O(n^{1/4})$

## 問題例
- [2019-2020 Winter Petrozavodsk Camp, Day 8: Almost Algorithmic Contest D. FFT Algorithm](https://codeforces.com/gym/103261/problem/D)

## 参照
- [素因数分解の高速なアルゴリズム（ロー法） | 高校数学の美しい物語](https://manabitimes.jp/math/1192)
- [素因数分解を $O(n^{1/4})$ でする - Qiita](https://qiita.com/Kiri8128/items/eca965fe86ea5f4cbb98)
