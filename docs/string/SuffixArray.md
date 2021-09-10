## 概要
以下, 文字列 `s` の $l$ 番目から $r - 1$ 番目までの部分文字列を `s[l,r)` , $l$ 番目から末尾までの部分文字列を `s[l)` と表すことにする.

与えられた文字列 $S$ の Suffix Array を返す.
Suffix Array `sa` とは, 順列 $(0, 1, \cdots, n-1)$ をその index から始まる接尾辞の辞書順によってソートしたものである.

これは SA-IS と呼ばれるアルゴリズムによって $O(|S|)$ で構築することができる.

- `SuffixArray(s)` : Suffix Array を構築する.
- `comp(t, i, j)` : 部分文字列 `s[i)` が `t[j)` よりも strict に小さければ `true` を, そうでなければ `false` を返す.
- `lower_bound(t)` : 接尾辞が辞書順において `t` 以上となるような Suffix Array の index の最小値を返す.
- `lower_upper_bound(t)` : 接尾辞が辞書順において `t` 以上及び strict に大きくなるような Suffix Array の index の最小値のペアを返す.
- `count(t)` : 文字列 `s` 内の部分文字列 `t` の個数を返す.

## 計算量
- `SuffixArray(s)` : $O(|S|)$
- `lower_bound(t)` : $O(|T| \log |S|)$
- `lower_upper_bound(t)` : $O(|T| \log |S|)$
- `count(t)` : $O(|T| \log |S|)$

## 問題例
[CodeChef August Lunchtime 2021 Division 1 - Longest Spanning Substrings](https://www.codechef.com/LTIME99A/problems/LNGSUB)

## 参照
[SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)
[SA-IS 法のメモ - まめめも](https://mametter.hatenablog.com/entry/20180130/p1#f-1aedbc3e)
[Two Efficient Algorithms for Linear Time Suffix Array Construction](https://ieeexplore.ieee.org/document/5582081)