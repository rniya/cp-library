---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/LowLink.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nstruct LowLink {\n    int n, m = 0, t = 0, b = 0;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<std::pair<int, int>> es;\n    std::vector<int> ord, low,\
    \ tecc, bcc, tmp;\n    std::vector<bool> is_articulation, is_bridge;\n\n    LowLink(int\
    \ n) : n(n), G(n), ord(n, -1), low(n), tecc(n, -1), is_articulation(n, false)\
    \ {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n\
    \        assert(0 <= v and v < n);\n        G[u].emplace_back(m);\n        G[v].emplace_back(m);\n\
    \        es.emplace_back(u, v);\n        is_bridge.emplace_back(false);\n    \
    \    bcc.emplace_back();\n        m++;\n    }\n\n    void build() {\n        for\
    \ (int i = 0; i < n; i++) {\n            if (ord[i] != -1) continue;\n       \
    \     dfs1(i, 0, -1);\n            dfs2(i, -1);\n        }\n    }\n\n    std::pair<int,\
    \ int> operator[](int k) const { return es[k]; }\n\nprivate:\n    void dfs1(int\
    \ v, int k, int pre) {\n        ord[v] = k++, low[v] = ord[v];\n        int cnt\
    \ = 0;\n        for (int& e : G[v]) {\n            if (e == pre) continue;\n \
    \           int u = es[e].first ^ es[e].second ^ v;\n            if (ord[u] ==\
    \ -1) {\n                cnt++;\n                dfs1(u, k, e);\n            \
    \    low[v] = std::min(low[v], low[u]);\n                if (pre != -1 and ord[v]\
    \ <= low[u]) is_articulation[v] = true;\n                if (ord[v] < low[u])\
    \ is_bridge[e] = true;\n            } else\n                low[v] = std::min(low[v],\
    \ ord[u]);\n        }\n        if (pre == -1 and cnt > 1) is_articulation[v] =\
    \ true;\n    }\n\n    void dfs2(int v, int pre) {\n        if (pre == -1) tecc[v]\
    \ = t++;\n        for (int& e : G[v]) {\n            if (e == pre) continue;\n\
    \            int u = es[e].first ^ es[e].second ^ v;\n            if (tecc[u]\
    \ == -1 or ord[u] < ord[v]) tmp.emplace_back(e);\n            if (tecc[u] >= 0)\
    \ continue;\n            if (ord[v] >= low[u])\n                tecc[u] = tecc[v];\n\
    \            else\n                tecc[u] = t++;\n            dfs2(u, e);\n \
    \           if (ord[v] <= low[u]) {\n                while (true) {\n        \
    \            int ne = tmp.back();\n                    tmp.pop_back();\n     \
    \               bcc[ne] = b;\n                    if (ne == e) break;\n      \
    \          }\n                b++;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nstruct LowLink {\n    int n, m = 0, t = 0, b = 0;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<std::pair<int, int>> es;\n    std::vector<int> ord, low,\
    \ tecc, bcc, tmp;\n    std::vector<bool> is_articulation, is_bridge;\n\n    LowLink(int\
    \ n) : n(n), G(n), ord(n, -1), low(n), tecc(n, -1), is_articulation(n, false)\
    \ {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n\
    \        assert(0 <= v and v < n);\n        G[u].emplace_back(m);\n        G[v].emplace_back(m);\n\
    \        es.emplace_back(u, v);\n        is_bridge.emplace_back(false);\n    \
    \    bcc.emplace_back();\n        m++;\n    }\n\n    void build() {\n        for\
    \ (int i = 0; i < n; i++) {\n            if (ord[i] != -1) continue;\n       \
    \     dfs1(i, 0, -1);\n            dfs2(i, -1);\n        }\n    }\n\n    std::pair<int,\
    \ int> operator[](int k) const { return es[k]; }\n\nprivate:\n    void dfs1(int\
    \ v, int k, int pre) {\n        ord[v] = k++, low[v] = ord[v];\n        int cnt\
    \ = 0;\n        for (int& e : G[v]) {\n            if (e == pre) continue;\n \
    \           int u = es[e].first ^ es[e].second ^ v;\n            if (ord[u] ==\
    \ -1) {\n                cnt++;\n                dfs1(u, k, e);\n            \
    \    low[v] = std::min(low[v], low[u]);\n                if (pre != -1 and ord[v]\
    \ <= low[u]) is_articulation[v] = true;\n                if (ord[v] < low[u])\
    \ is_bridge[e] = true;\n            } else\n                low[v] = std::min(low[v],\
    \ ord[u]);\n        }\n        if (pre == -1 and cnt > 1) is_articulation[v] =\
    \ true;\n    }\n\n    void dfs2(int v, int pre) {\n        if (pre == -1) tecc[v]\
    \ = t++;\n        for (int& e : G[v]) {\n            if (e == pre) continue;\n\
    \            int u = es[e].first ^ es[e].second ^ v;\n            if (tecc[u]\
    \ == -1 or ord[u] < ord[v]) tmp.emplace_back(e);\n            if (tecc[u] >= 0)\
    \ continue;\n            if (ord[v] >= low[u])\n                tecc[u] = tecc[v];\n\
    \            else\n                tecc[u] = t++;\n            dfs2(u, e);\n \
    \           if (ord[v] <= low[u]) {\n                while (true) {\n        \
    \            int ne = tmp.back();\n                    tmp.pop_back();\n     \
    \               bcc[ne] = b;\n                    if (ne == e) break;\n      \
    \          }\n                b++;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/LowLink.hpp
  requiredBy: []
  timestamp: '2022-12-30 22:22:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/LowLink.hpp
layout: document
title: LowLink (with Two Edge Connected Components, Bi Connected Components)
---

# TODO
Block Cut Tree

## 概要
Lowlink による橋と関節点の列挙，その上で二重辺連結成分分解や二重頂点連結成分分解の構成を行う．

### Lowlink
- 橋 (bridge) : 取り除くことで連結成分数が増加するような辺．
- 関節点 (articulation point) : 取り除くことで連結成分数が増加するような頂点．
- 後退辺 (back edge) : dfs の際に通過しなかった辺．

橋と関節点を dfs-tree を利用して頂点数及び辺数に対して線形時間で行うのが Lowlink である．
具体的には，dfs-tree での頂点 $v$ の訪問時刻を $ord_v$，$v$ から後退辺を高々一度だけ用いて到達できる頂点集合における $ord$ の最小値を $low_v$ と定義すると，各辺の両端点におけるこれらの値のみから頂点が関節点であるかや辺が橋であるかを判定することが可能である．

### 二重辺連結成分分解
どの辺を取り除いても連結であるような連結グラフを二重辺連結成分という．
一般のグラフにおいて，橋でないような辺のみを含むグラフの各連結成分は二重辺連結成分をなす．
元のグラフにおいて各二重辺連結成分を縮約してできるグラフは木構造をなす．

### 二重頂点連結成分分解
どの点とそれに接続する辺を取り除いても連結であるような連結グラフを二重頂点連結成分という．
これも二重辺連結成分に比べると少し複雑だが，関節点で区切ることで二重頂点連結成分をなす（関節点を倍化するとわかりやすいかもしれない）．

#### Block Cut Tree
二重頂点連結成分を縮約して一つの点とみなし，さらに関節点もそれとは独立した点と考えると，これらは木構造をなす．
これが Block Cut Tree である．

| メンバ関数       | 効果                                      | 時間計算量 |
| ---------------- | ----------------------------------------- | ---------- |
| `LowLink(n)`     | $n$ 頂点 $0$ 辺のグラフとして初期化する． | $O(n)$     |
| `add_edge(u, v)` | 頂点 $u$ と頂点 $v$ を結ぶ辺を追加する．  | $O(1)$     |
| `build()`        | 各種構成を行う．                          | $O(n + m)$ |

## 問題例
- [AtCoder Regular Contest 062 F - AtCoDeerくんとグラフ色塗り](https://atcoder.jp/contests/arc062/tasks/arc062_d)

## Links
- [橋と関節点, lowlink - Lilliput Steps](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)
- [Block-cut tree - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/03/25/010057)