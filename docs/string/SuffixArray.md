## 概要
以下, 文字列 `s` の $l$ 番目から $r - 1$ 番目までの部分文字列を `s[l,r)` , $l$ 番目から末尾までの部分文字列を `s[l)` と表すことにする.

与えられた文字列 $S$ の Suffix Array を返す.
Suffix Array `sa` とは, 順列 $(0, 1, \cdots, n - 1)$ をその index から始まる接尾辞の辞書順によってソートしたものである.

これは SA-IS と呼ばれるアルゴリズムによって $O(|S|)$ で構築することができる.

また、先で得られた Suffix Array をもとに Lognest Common Prefix Array も構築できる。これは Suffix Array における隣同士の接尾辞において先頭何文字が共通しているかを表す長さ $n - 1$ の配列である。すなわち、 `lcp[i]` は接尾辞 `s[sa[i])` と `s[sa[i+1])` の LCP の長さに等しい。LCP Array を応用すると、隣り合う接尾辞だけでなく任意の接尾辞の LCP の長さを求めることができる。文字列 $S$ と $T$ の LCP の長さを $f(S, T)$ 、$S$ の位置 $i$ から始まる接尾辞を $S_i$ と表すとして、$l < r$ とすると、

$$\begin{aligned}
f(S_l, S_r) &= \min(f(S_l, S_{l+1}), f(S_{l+1}, S_{l+2}), \cdots, f(S_{r-1}, S_r)) \\
&= \min(LCP_l, LCP_{l+1}, \cdots, LCP_{r-1})
\end{aligned}$$

が成立する。これは Sparse Table 等を用いて効率的に扱うことも可能である。

## 計算量

## 問題例
- [CodeChef August Lunchtime 2021 Division 1 - Longest Spanning Substrings](https://www.codechef.com/LTIME99A/problems/LNGSUB)

## 参照
- [SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)
- [SA-IS 法のメモ - まめめも](https://mametter.hatenablog.com/entry/20180130/p1#f-1aedbc3e)
- [Two Efficient Algorithms for Linear Time Suffix Array Construction](https://ieeexplore.ieee.org/document/5582081)