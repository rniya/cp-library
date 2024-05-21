---
title: Union Find with Undo Operation
documentation_of: ./UndoUnionFind.hpp
---

## 概要
経路圧縮せずにマージテクにより集合を管理する際，1 回の `merge(x, y)` 操作で値が変更されるのは `x = find(x), y = find(y)` とした後の `data[x], data[y]` の 2 箇所のみであるから，操作前の値を記憶しておくことで $O(1)$ で操作を巻き戻すことが可能である．
これを踏まえて `snapshot` や `rollback` といった機能も搭載したデータ構造．

| メンバ関数         | 効果                                                                                                              | 時間計算量                                                                      |
| ------------------ | ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| `UndoUnionFind(n)` | 要素数 $n$ で初期化する．                                                                                         | $O(n)$                                                                          |
| `find(x)`          | 頂点 $x$ の属する集合の代表元を返す．                                                                             | $O(\log n)$                                                                     |
| `merge(x, y)`      | 頂点 $x, y$ が属する集合を併合する．                                                                              | $O(\log n)$                                                                     |
| `same(x, y)`       | 頂点 $x, y$ が同一の集合に属するか判定する．                                                                      | $O(\log n)$                                                                     |
| `size(x)`          | 頂点 $x$ が属する集合の要素数を返す．                                                                             | $O(\log n)$                                                                     |
| `undo()`           | `merge` 1 回分の処理を巻き戻す．                                                                                  | $O(1)$                                                                          |
| `snapshot()`       | 現在の集合の状態を保存する．                                                                                      | 前回 `snapshot` が呼び出されて以降に `merge` が行われた回数を $m$ として $O(m)$ |
| `rollback()`       | 前回 `snapshot` が呼び出されたときの状態まで巻き戻す．`snapshot` が一度も呼ばれていない場合には初期状態まで戻る． | $O(m)$                                                                          |
| `operator[x]`      | 頂点 $x$ の属する集合の代表元を返す．                                                                             | $O(\log n)$                                                                     |

## 問題例
- [Codeforces Round 319 (Div. 1) E. Painting Edges](https://codeforces.com/contest/576/problem/E)
- [Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad) C. Team-Building](https://codeforces.com/contest/1444/problem/C)

## 参照
- [Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)
