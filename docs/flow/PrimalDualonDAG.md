## 概要
負辺を含む最小費用流を計算する際に, 各頂点のポテンシャルの初期値さえ計算できれば後は Dijkstra 法で問題ない. このポテンシャルの初期値の計算について, 負辺があったとしても Bellman-Ford 法を用いれば負閉路がない限りは $O(nm)$ で問題なく計算できる. ここで, 最小費用流において負辺が登場するのはグラフが特殊な形状, 特に DAG であるケースが多く, この場合はさらに高速に $O(n + m)$ で前計算が可能となる.

## 問題例
- [AtCoder Beginner Contest 214 H - Collecting](https://atcoder.jp/contests/abc214/tasks/abc214_h)

## Links
- [負辺を含む最小費用流について(Attack the Moles) - sigma425のブログ](https://sigma425.hatenablog.com/entry/2014/10/12/122018?utm_source=pocket_mylist)