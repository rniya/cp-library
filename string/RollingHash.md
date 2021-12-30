---
title: Rolling Hash
documentation_of: ./Rolling Hash.hpp
---

## 概要
$\bmod\ 2^{61}-1$ で基数は $\left[2, 2^{61}-1\right)$ の乱数によるRolling Hash.

| メンバ関数                  | 効果                                                                                                                               | 時間計算量                          |
| --------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------- |
| `build(s)`                  | 文字列もしくは数列 $s$ に対する hash table を返す.                                                                                 | $O(\|S\|)$                          |
| `get(s)`                    | 文字列もしくは数列 $s$ 全体の hash 値をを返す.                                                                                     | $O(\|S\|)$                          |
| `query(hash, l, r)`         | `build` で生成された hash table である `hash` をもとにこの列の区間 $[l, r)$ に対応する hash 値を返す.                              | $O(1)$                              |
| `combine(h1, h2, h2_len)`   | 前半の hash 値が $h_1$, 後半のそれが $h_2$ で後半の長さが `h2_len` のときに列全体の hash 値を返す.                                 | $O(1)$                              |
| `lcp(a, l1, r1, b, l2, r2)` | hash table $a$ からなる列の $[l_1, r_1)$ の部分文字列と, hash table $b$ からなる列の $[l_2, r_2)$ の部分文字列の LCP の長さを返す. | $O(\log\max(r_1 - l_1, r_2 - l_2))$ |

## 問題例
- [Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C)
  - $\bmod$ の値が小さいとかなりの確率で衝突し, hash 値を 2 つもとうとすると TLE にハマるので, この Rolling Hash が特に有効.

## 参照
- [安全で爆速なRollingHashの話 - Qiita](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)
