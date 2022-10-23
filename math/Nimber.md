---
title: Nimber
documentation_of: ./Nimber.hpp
---

## 概要
排他的論理和 (XOR) $\oplus$ を加法，Nim product $\otimes$ を乗法とすると $2^{2^n}$ 未満の非負整数の上に体を成す．

Nim product については $n \otimes 2^{2^k} = n 2^{2^k}\ (n < 2^{2^k})$ 及び $2^{2^k} \otimes 2^{2^k} = (3 / 2) 2^{2^k}$ が成立することから，$a \oplus b$ について $a = a_u 2^{32} + a_l,\ b = b_u 2^{32} + b_l$ とすると，

$$
\begin{aligned}
  &&& a \otimes b
  &=&& (a_u 2^{32} + a_l) \otimes (b_u 2^{32} + b_l) \\
  &=&& (a_u \otimes 2^{32} \oplus a_l) \otimes (b_u \otimes 2^{32} \oplus b_l) \quad (\because n 2^{2^k} = n \otimes 2^{2^k}) \\
  &=&& (a_u \otimes 2^{32} \otimes b_u \otimes 2^{32}) \oplus (a_u \otimes 2^{32} \otimes b_l) \oplus (a_l \otimes b_u \otimes 2^{32}) \oplus (a_l \otimes b_l) \\
  &=&& (a_u \otimes b_u \otimes (2^{32} + 2^{31})) \oplus ((a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_l \otimes b_l) \quad (\because 2^{2^k} \otimes 2^{2^k} = (3 / 2) 2^{2^k}) \\
  &=&& (a_u \otimes b_u \otimes (2^{32} \oplus 2^{31})) \oplus ((a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_l \otimes b_l) \\
  &=&& ((a_u \otimes b_u \oplus a_u \otimes b_l \oplus a_l \otimes b_u) \otimes 2^{32}) \oplus (a_u \otimes b_u \otimes 2^{31}) \oplus (a_l \otimes b_l) \\
  &=&& ((a_u \otimes b_u \oplus a_u \otimes b_l \oplus a_l \otimes b_u) \times 2^{32}) \oplus (a_u \otimes b_u \otimes 2^{31}) \oplus (a_l \otimes b_l) \\
\end{aligned}
$$

が成立するから再帰的に計算可能である．

## 問題例
- [AtCoder Beginner Contest 274 Ex - XOR Sum of Arrays](https://atcoder.jp/contests/abc274/tasks/abc274_h)

## Links
- [Nim product - kyopro_friends’ diary](https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850)
  - 代数的性質の証明について詳しい．
