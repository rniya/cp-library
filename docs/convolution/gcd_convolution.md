## 概要
数列を添字の $\gcd$ 演算に関して畳み込む.

| 関数                           | 効果                                                                                                         | 時間計算量          |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------ | ------------------- |
| `divisor_transform(f)`         | $f(k) \leftarrow \sum_{k \| i} f(i)$ と変換する。                                                            | $O(n \log(\log n))$ |
| `inverse_divisor_transform(f)` | `divisor_transform` の逆変換を施す。                                                                         | $O(n \log(\log n))$ |
| `gcd_convolution(f, g)`        | 列 $f, g$ を $\gcd$ 演算に関して畳み込む. すなわち,  $h_k = \sum_{\gcd(i, j) = k} f_ig_j$ なる列 $h$ を返す. | $O(n \log(\log n))$ |

## 問題例
- [AtCoder Grand Contest 038 C - LCMs](https://atcoder.jp/contests/agc038/tasks/agc038_c)
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) G. GCD Festival](https://codeforces.com/contest/1575/problem/G)

## Links
- [約数集合でのゼータ変換・メビウス変換的なやつと畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)
- [添え字 gcd での畳み込みで AGC038-C を解く - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/09/23/002445)
- [高速ゼータ変換の約数版 $O(N \log(\log(N)))$ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
