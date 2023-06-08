---
title: Offline Dynamic Connectivity
documentation_of: ./OfflineDynamicConnectivity.hpp
---

## 概要
辺を全くもたない $n$ 頂点の無向グラフに対し辺の追加削除及び 2 点が連結かの判定クエリが計 $q$ 個オフラインで与えられるときにこれを $\mathrm{O}(q \log q \log n)$ 時間で処理するデータ構造．
多重辺にも対応している．

| メンバ関数    | 効果                                                                              | 時間計算量                    |
| ------------- | --------------------------------------------------------------------------------- | ----------------------------- |
| `add(u, v)`   | 2 点 $u, v$ を結ぶ辺を 1 本追加する．                                             | $\mathrm{O}(\log q)$          |
| `del(u, v)`   | 2 点 $u, v$ を結ぶ辺を 1 本削除する．その際，辺が必ず存在していなくてはならない． | $\mathrm{O}(\log q)$          |
| `query(u, v)` | その時点で 2 点 $u, v$ が連結かどうか判定する．                                   | $\mathrm{O}(1)$               |
| `solve()`     | 連結性判定クエリの結果を格納した配列を返す．                                      | $\mathrm{O}(q \log q \log n)$ |

## Links
- [ちょっと変わったセグメント木の使い方 - ei1333の日記](https://ei1333.hateblo.jp/entry/2017/12/14/000000)

## 問題例
- [東京工業大学プログラミングコンテスト2022 I - XOR Reachable](https://atcoder.jp/contests/ttpc2022/tasks/ttpc2022_i)
- [AtCoder Beginner Contest 301 Ex - Difference of Distance](https://atcoder.jp/contests/abc301/tasks/abc301_h)