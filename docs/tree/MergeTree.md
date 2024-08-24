---
title: Merge Process Tree
documentation_of: //src/tree/MergeTree.hpp
---

## 概要

マージ過程を表す木．

| メンバ関数     | 効果                                                                                                                                                                                                                     | 時間計算量                      |
| -------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ | ------------------------------- |
| `MergeTree(n)` | $n$ 要素について初期化する．                                                                                                                                                                                             | $\mathrm{O}(n)$                 |
| `build(qs)`    | タイプ `0` のクエリでは $2$ 要素 $u, v$ が含まれるグループを併合し，タイプ `1` のクエリではその時点での要素 $u$ の含まれるグループの成す区間 $\lbrack l, r)$ を求めたい．このとき，タイプ `1` のクエリの返り値を求める． | $\mathrm{O}((n + q) \alpha(n))$ |
| `operator[i]`  | 列の中で頂点 $i$ に対応する位置を返す．                                                                                                                                                                                  | $\mathrm{O}(1)$                 |



## 出題例
- [Codeforces Round 317 [AimFund Thanks-Round] (Div. 1) D. Campus](https://codeforces.com/contest/571/problem/D)
- [AtCoder Beginner Contest 314 F - A Certain Game](https://atcoder.jp/contests/abc314/tasks/abc314_f)