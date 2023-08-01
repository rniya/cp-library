---
title: 森上のスケジューリング問題
documentation_of: ./ForestScheduling.hpp
---

## 概要

根付き森が与えられ，頂点を先祖が子孫の頂点の右側に置かれないように並べ替えるときに頂点に書かれた値の列のスコアを最大（最小）化する問題を $\mathrm{O}(n \log n)$ 時間で解く．
この際，値の列の優先関係について，反射律と推移律，完全律が成立する弱順序となっている必要がある．
`S` に単位元と `<` の演算子，マージ関数 `op` が定義されている必要がある．

## 問題例
- [AtCoder Grand Contest 023 F - 01 on Tree](https://atcoder.jp/contests/agc023/tasks/agc023_f)
- [Toyota Programming Contest 2023 Spring Final G - Git Gud](https://atcoder.jp/contests/toyota2023spring-final/tasks/toyota2023spring_final_g)
- [The 1st Universal Cup. Stage 19: America D. Fail Fast](https://qoj.ac/contest/1248/problem/6561?v=1)