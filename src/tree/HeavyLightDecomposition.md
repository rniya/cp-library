---
title: Heavy Light Decomposition
documentation_of: ./HeavyLightDecomposition.hpp
---

## 概要
木構造を分解する手法の一つ．
任意に根を取り dfs していき，各 edge を現在見ている頂点と結ばれている子供の中で最も部分木のサイズが大きい頂点とを結ぶ edge を Heavy，それ以外を Light と分類する．
このとき，Heavy edge を縮約して頂点群を一つにまとめるとみなして新たな木を構築すると，任意の頂点の深さを高々 $O(\log n)$ で抑えることができる（Heavy edge の取り方から，子供の方向に向かって辺を辿るごとに，もとの木における部分木のサイズが半分未満になっていくため）．
実装において Heavy edge から優先的に探索していくようにすると，この頂点群は dfs-order において連続するようになり，ある頂点からその先祖の頂点までのパスを新たに生成された木において $O(\log n)$ 個の連続する頂点群の集合とみなすことができる．
結果的に任意の 2 頂点間のパスを lowest common ancestor を経由することで $O(\log n)$ 個の連続する頂点群の集合に分解できる（必要があれば順序を保持することも可能）ので，パスに対するクエリを連続部分列に対して操作を適用するデータ構造と併せて効率的に処理することができる．
また，1 頂点に対する操作は言うまでもなく，部分木に対する操作も任意の頂点の部分木内の頂点は dfs-order において必ず連続していることから容易に扱うことが可能である．
頂点及び辺のどちらについてのクエリにも対応しており，辺の場合は子孫側の頂点に値を載せるとして処理している．

以下に記す内容について，時間計算量は区間 $[l,r)$ に対する更新や総積の取得といった操作が 1 区間あたり $O(\log n)$ で行えるとしたうえでの計算量である．
また，各種クエリ操作についての関数において頂点についての情報を得たい際には引数の `vertex` を `true` にする必要がある（デフォルトでは `false` になっているので辺についてのクエリ操作を扱うことになる）．

| メンバ関数                                   | 効果                                                                                                       | 時間計算量      |
| -------------------------------------------- | ---------------------------------------------------------------------------------------------------------- | --------------- |
| `HeavyLightDecomposition(n)`                 | 頂点数 $n$ の木として初期化する．                                                                          | $O(n)$          |
| `add_edge(u, v)`                             | 辺 $(u,v)$ を追加する．                                                                                    | $O(1)$          |
| `build()`                                    | 追加された辺情報をもとに Heavy edge, Light edge の情報を構築する．                                         | $O(n)$          |
| `idx(v)`                                     | 内部処理における頂点 $v$ の識別子を返す．一点更新や一点取得の際に必要となる．                              | $O(1)$          |
| `la(v,k)`                                    | $v$ から根の方向に $k$ 回辺を辿った先の頂点を返す．                                                        | $O(\log n)$     |
| `lca(u, v)`                                  | 頂点 $u, v$ の最小共通祖先を返す．                                                                         | $O(\log n)$     |
| `jump(s, t, i)`                              | 頂点 $s$ から $t$ への木上の最短路上で $s$ から距離 $i$ 離れた頂点を返す．                                 | $O(\log n)$     |
| `distance(u, v)`                             | `add_edge` で追加された各辺の重みを 1 として，頂点 $u, v$ 間の距離を返す．                                 | $O(\log n)$     |
| `query_path(u, v, f, vertex)`                | 頂点 $u, v$ 間のパスに対してのクエリを処理する（演算が可換，すなわち扱う対象がモノイドである必要がある）． | $O((\log n)^2)$ |
| `query_path_noncommutative(u, v, f, vertex)` | 頂点 $u, v$ 間のパスに対してのクエリを処理する（Remark 参照）．                                            | $O((\log n)^2)$ |
| `query_subtree(u, f, vertex)`                | 頂点 $u$ の部分木に対してのクエリを処理する．                                                              | $O(\log n)$     |

#### Remark
`query_path_noncommutative` を呼ぶ際には，付随するデータ構造もそれに対応しうるものである必要がある．具体的な要件としては，区間 $[l,r)$ に対して演算が左結合か右結合かを区別して正しく処理できなければならない．逆に言えば左結合か右結合かだけが重要なので，それぞれを処理する 2 つのデータ構造を用意することで解決することも可能である．

## 問題例
- [Codeforces Round #299 (Div. 1) E. Tavas on the Path](https://codeforces.com/contest/536/problem/E)
  - `query_path_noncommutative` の辺属性クエリの verify．
- [Codeforces Round #285 (Div. 1) E. Misha and LCP on Tree](https://codeforces.com/contest/504/problem/E)
- [AtCoder Beginner Contest 269 Ex - Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)
  - heavy path 上の分割統治を適切にまとめていくことで解ける．各 heavy path の先頭の頂点の部分木の大きさの総和が $O(N \log N)$ であること等を利用する．

## Links
- [Easiest HLD with subtree queries - Codeforces](https://codeforces.com/blog/entry/53170)
- [Heavy-Light Decomposition - math314のブログ](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [マージテクと高さ O(logn) のマージ過程との融合 \| Mathenachia](https://www.mathenachia.blog/mergetech-and-logn/#toc4)
