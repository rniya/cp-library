---
title: Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected Components)
documentation_of: ./BlockCutTree.hpp
---

# TODO
Block Cut Tree の verify

## 概要
Lowlink による橋と関節点の列挙, その上での二重辺連結成分分解や二重頂点連結成分分解及び Block Cut Tree の構築といった無向グラフに対する分解手法を詰め込んだライブラリ.

### Lowlink
- 橋 (bridge) : 取り除くことで連結成分数が増加するような辺.
- 関節点 (articulation point) : 取り除くことで連結成分数が増加するような頂点.
- 後退辺 (back edge) : dfs の際に通過しなかった辺.

橋と関節点を dfs-tree を利用して頂点数及び辺数に対して線形時間で行うのが Lowlink である. 具体的には, dfs-tree での頂点 $v$ の訪問時刻を $ord_v$, $v$ から後退辺を高々一度だけ用いて到達できる頂点集合における $ord$ の最小値を $low_v$ と定義すると, 各辺の両端点におけるこれらの値のみから頂点が関節点であるかや辺が橋であるかを判定することが可能である.

### 二重辺連結成分分解
どの辺を取り除いても連結であるような連結グラフを二重辺連結成分という. 一般のグラフにおいて, 橋でないような辺のみを含むグラフの各連結成分は二重辺連結成分をなす. 元のグラフにおいて各二重辺連結成分を縮約してできるグラフは木構造をなす.

### 二重頂点連結成分分解
どの点とそれに接続する辺を取り除いても連結であるような連結グラフを二重頂点連結成分という. これも二重辺連結成分に比べると少し複雑だが, 関節点で区切ることで二重頂点連結成分をなす (関節点を倍化するとわかりやすいかもしれない) .

#### Block Cut Tree
二重頂点連結成分を縮約して一つの点とみなし, さらに関節点もそれとは独立した点と考えると, これらは木構造をなす. これが Block Cut Tree である.

| メンバ関数                        | 効果                                        | 時間計算量 |
| --------------------------------- | ------------------------------------------- | ---------- |
| `BlockCutTree(n)`                 | 頂点数 $n$ の無向グラフとして初期化する.    | $O(n)$     |
| `add_edge(u, v)`                  | 無向辺 $(u, v)$ を追加する.                 | $O(1)$     |
| `build()`                         | 関節点を列挙及び二重頂点連結成分分解を行う. | $O(n + m)$ |
| `two_edge_connected_components()` | 各二重辺連結成分の頂点集合を返す.           | $O(n + m)$ |
| `tecc_make_tree()`                | 二重辺連結成分がなす木構造を返す.           | $O(n + m)$ |
| `bi_connected_components()`       | 各二重頂点連結成分の辺集合を返す.           | $O(m)$     |
| `block_cut_tree()`                | Block Cut Tree を構築して返す.              | $O(n + m)$ |

## 問題例
- [AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)

## Links
- [橋と関節点, lowlink - Lilliput Steps](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)
- [Block-cut tree - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/03/25/010057)