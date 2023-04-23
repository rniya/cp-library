## 概要

性質まとめ
- 各点までの最短路の距離は $O(\sqrt{m})$ である。
  - ある点までの距離が $x$ とすると、最短経路においてその直前の点を除いた $x - 1$ 点と隣接している必要があることからわかる。
- 各点までの最短路の距離の合計は $O(m)$ である。
  - これも先の性質より明らか。
- もとのグラフが非連結ならばその補グラフは連結。

## Links
- [BPC 1 S5 - Temple](https://dmoj.ca/problem/bpc1s5)
- https://twitter.com/noshi91/status/1383110660796518401?s=20&t=6NELIs3eDe0fVQxuwfwvow
- [Educational Codeforces Round 142 (Rated for Div. 2) F2. Graph Coloring (hard version)](https://codeforces.com/contest/1792/problem/F2)

<blockquote class=”twitter-tweet” data-conversation=”none”><a href=”https://twitter.com/noshi91/status/1383110660796518401?s=20&t=6NELIs3eDe0fVQxuwfwvow”></a></blockquote>