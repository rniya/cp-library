## 概要
有向/無向グラフが与えられたときに, オイラー路/準オイラー路を構築する.
- `add_edge(u, v)`：辺$(u,v)$を追加する.
- `build()`：各連結成分についてオイラー路を構築する. オイラー路が存在しない連結成分があれば空列を返す.
- `build_semi()`：各連結成分について準オイラー路を構築する. 準オイラー路が存在しない連結成分があれば空列を返す.
- `operator[]`：$i$番目に追加した辺の情報$(u,v)$を返す.

## 計算量
どれも$O(V+E)$

## 問題例
- [Codeforces Round #647 (Div. 1) - Thanks, Algo Muse! C. Johnny and Megan's Necklace](https://codeforces.com/contest/1361/problem/C)
  - 無向グラフにおけるオイラー路の復元.

## 参照
- [競プロにおけるオイラー路とその応用について - Learning Algorithms](https://kokiymgch.hatenablog.com/entry/2017/12/07/193238)