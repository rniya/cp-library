---
title: Heavy Light Decomposition
documentation_of: //src/tree/HeavyLightDecomposition.hpp
---

## 概要

木構造を分解する手法の一つで，部分木やパスに対する更新・取得処理を効率的に行うことができる．

以下に記す内容について，時間計算量は区間 $\lbrack l, r)$ に対する更新や総積の取得といった操作が 1 区間あたり $\mathrm{O}(\log n)$ で行えるとしたうえでの計算量である．
また，各種クエリ操作についての関数において頂点についての情報を得たい際には引数の `vertex` を `true` にする必要がある（デフォルトでは `false` になっているので辺に情報が乗ったクエリ操作を扱うことになる）．

空間計算量は $\mathrm{O}(n)$ である（ただし，定数倍は重い）．

| メンバ関数                                   | 効果                                                                           | 時間計算量                                                             |
| -------------------------------------------- | ------------------------------------------------------------------------------ | ---------------------------------------------------------------------- |
| `HeavyLightDecomposition(n)`                 | 頂点数 $n$ の木として初期化する．                                              | $\mathrm{O}(n)$                                                        |
| `add_edge(u, v)`                             | 辺 $(u,v)$ を追加する．                                                        | $\mathrm{O}(1)$                                                        |
| `build()`                                    | 追加された辺情報をもとに Heavy edge, Light edge の情報を構築する．             | $\mathrm{O}(n)$                                                        |
| `idx(v)`                                     | 内部処理における頂点 $v$ の識別子を返す．一点更新や一点取得の際に必要となる．  | $\mathrm{O}(1)$                                                        |
| `la(v,k)`                                    | $v$ から根の方向に $k$ 回辺を辿った先の頂点を返す．                            | $\mathrm{O}(\log n)$                                                   |
| `lca(u, v)`                                  | 頂点 $u, v$ の最小共通祖先を返す．                                             | $\mathrm{O}(\log n)$                                                   |
| `jump(s, t, i)`                              | 頂点 $s$ から $t$ への木上の最短路上で $s$ から距離 $i$ 離れた頂点を返す．     | $\mathrm{O}(\log n)$                                                   |
| `distance(u, v)`                             | `add_edge` で追加された各辺の重みを 1 として，頂点 $u, v$ 間の距離を返す．     | $\mathrm{O}(\log n)$                                                   |
| `query_path(u, v, f, vertex)`                | 頂点 $u, v$ 間のパスに対してのクエリを処理する（演算が可換である必要がある）． | $\mathrm{O}(\log^2 n)$                                                 |
| `query_path_noncommutative(u, v, f, vertex)` | 頂点 $u, v$ 間のパスに対してのクエリを処理する（下記注意参照）．               | $\mathrm{O}(\log^2 n)$                                                 |
| `query_subtree(u, f, vertex)`                | 頂点 $u$ の部分木に対してのクエリを処理する．                                  | $\mathrm{O}(\log n)$                                                   |
| `query_subtree(vs)`                          | 頂点集合 $\textit{vs}$ に対する auxiliary tree を構築し、その情報と根を返す。  | $\vert \textit{vs} \vert = k$ として $\mathrm{O}(k (\log k + \log n))$ |

任意に根を取り dfs していき，現在見ている頂点とその子供の中で最も部分木のサイズが大きい頂点とを結ぶ edge を Heavy，それ以外を Light と分類する．
このとき，任意の頂点について根との間のパス上の Light edge の本数を $\mathrm{O}(\log n)$ で抑えることができる（Light edge を辿るごとに，もとの木における部分木のサイズが半分未満になっていくため）．

dfs において Heavy edge から優先的に探索していくようにすると，Heavy path 上の頂点群は dfs-order において連続するようになり，ある頂点からその先祖の頂点までのパスを dfs-order 上の $\mathrm{O}(\log n)$ 個の区間に分割することができる．
任意の 2 頂点間のパスは lowest common ancestor を経由することで $\mathrm{O}(\log n)$ 個の区間に分割でき，パスに対するクエリを他の列を扱うデータ構造と併せて効率的に処理することができる．
また，1 頂点に対する操作は言うまでもなく，部分木に対する操作も任意の頂点の部分木内の頂点は dfs-order において 1 つの区間を成すことから容易に扱うことが可能である．
頂点及び辺のどちらについてのクエリにも対応しており，辺の場合は子孫側の頂点に値を載せるとして処理している．

## 注意
`query_path_noncommutative` を呼ぶ際には，付随するデータ構造もそれに対応しうるものである必要がある．具体的な要件としては，区間 $[l, r)$ に対して演算が左結合か右結合かを区別して正しく処理できなければならない．逆に言えば左結合か右結合かだけが重要なので，それぞれを処理する 2 つのデータ構造を用意することで解決することも可能である．

## 出題例
- [Codeforces Round #299 (Div. 1) E. Tavas on the Path](https://codeforces.com/contest/536/problem/E)
  - `query_path_noncommutative` の辺属性クエリの verify．
- [Codeforces Round #285 (Div. 1) E. Misha and LCP on Tree](https://codeforces.com/contest/504/problem/E)
- [AtCoder Beginner Contest 269 Ex - Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)
  - heavy path 上の分割統治を適切にまとめていくことで解ける．各 heavy path の先頭の頂点の部分木の大きさの総和が $\mathrm{O}(N \log N)$ であること等を利用する．
- [Hokkaido University Competitive Programming Camp 2023 Day 1 G: Detour](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/G)
- [AtCoder Beginner Contest 311 Ex - Many Illumination Plans](https://atcoder.jp/contests/abc311/tasks/abc311_h)
  - 重軽再帰動的計画法（[参照](https://qiita.com/tmaehara/items/4b2735e56843bad89949)）

## Links
- [Easiest HLD with subtree queries - Codeforces](https://codeforces.com/blog/entry/53170)
- [Heavy-Light Decomposition - math314のブログ](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [マージテクと高さ $\mathrm{O}(\log n)$ のマージ過程との融合 \| Mathenachia](https://www.mathenachia.blog/mergetech-and-logn/#toc4)
