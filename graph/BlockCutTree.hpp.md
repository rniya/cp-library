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
    _deprecated_at_docs: docs/graph/BlockCutTree.md
    document_title: Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi
      Connected Components)
    links: []
  bundledCode: "#line 2 \"graph/BlockCutTree.hpp\"\n#include <cassert>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\nstruct BlockCutTree {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G;\n    std::vector<std::vector<int>> tecc_tree,    // tree that consists\
    \ of two-edge-connected-component\n        bct;                              \
    \      // tree that consists of bi-connected-component and articulation\n    std::vector<bool>\
    \ is_articulation,          // whether vertex i is articulation or not\n     \
    \   is_bridge;                              // whether edge i is bridge or not\n\
    \    std::vector<int> tecc_id;                   // id of two-edge-connected-component\
    \ vertex i belongs to\n    std::vector<std::vector<int>> tecc_groups;  // vertices\
    \ belongs to i-th two-edge-connected-component\n    std::vector<int> bcc_id; \
    \                   // id of bi-connected-component edge i belongs to\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bcc_groups;  // edges belongs to i-th bi-connected-component\n    std::vector<int>\
    \ bct_id;  // id of component on block-cut-tree vertex i belongs to (order : bcc\
    \ -> articulation)\n    std::vector<std::vector<int>> bct_groups;  // vertices\
    \ belongs to i-th component on block-cut-tree\n\n    BlockCutTree(int n)\n   \
    \     : G(n), is_articulation(n, false), n(n), m(0), time(0), bcc_num(0), order(n,\
    \ -1), lowlink(n, -1) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v,\
    \ m);\n        G[v].emplace_back(u, m);\n        if (u > v) std::swap(u, v);\n\
    \        edges.emplace_back(u, v);\n        is_bridge.emplace_back(false);\n \
    \       is_dfstree_edge.emplace_back(false);\n        bcc_id.emplace_back(-1);\n\
    \        m++;\n    }\n\n    void build() {\n        called_build = true;\n   \
    \     for (int i = 0; i < n; i++) {\n            if (order[i] == -1) {\n     \
    \           dfs_lowlink(i);\n            }\n        }\n        for (int i = 0;\
    \ i < m; i++) {\n            int u = edges[i].first, v = edges[i].second;\n  \
    \          if (order[u] > order[v]) std::swap(u, v);\n            if (order[u]\
    \ < lowlink[v]) is_bridge[i] = true;\n        }\n    }\n\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() {\n        assert(called_build);\n        called_two_connected_components\
    \ = true;\n        tecc_num = 0;\n        tecc_id.assign(n, -1);\n        for\
    \ (int i = 0; i < n; i++) {\n            if (tecc_id[i] >= 0) continue;\n    \
    \        tecc_id[i] = tecc_num;\n            std::queue<int> que;\n          \
    \  que.emplace(i);\n            while (!que.empty()) {\n                int v\
    \ = que.front();\n                que.pop();\n                for (const auto&\
    \ e : G[v]) {\n                    int u = e.first;\n                    if (tecc_id[u]\
    \ >= 0 || is_bridge[e.second]) continue;\n                    tecc_id[u] = tecc_num;\n\
    \                    que.emplace(u);\n                }\n            }\n     \
    \       tecc_num++;\n        }\n        tecc_groups.resize(tecc_num);\n      \
    \  for (int i = 0; i < n; i++) tecc_groups[tecc_id[i]].emplace_back(i);\n    \
    \    return tecc_groups;\n    }\n\n    std::vector<std::vector<int>> tecc_make_tree()\
    \ {\n        assert(called_two_connected_components);\n        tecc_tree.resize(tecc_num);\n\
    \        for (int i = 0; i < m; i++) {\n            if (!is_bridge[i]) continue;\n\
    \            int u = tecc_id[edges[i].first], v = tecc_id[edges[i].second];\n\
    \            tecc_tree[u].emplace_back(v);\n            tecc_tree[v].emplace_back(u);\n\
    \        }\n        return tecc_tree;\n    }\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bi_connected_components() {\n        assert(called_build);\n        called_bi_connected_components\
    \ = true;\n        bcc_groups.resize(bcc_num);\n        for (int i = 0; i < m;\
    \ i++) bcc_groups[bcc_id[i]].emplace_back(edges[i]);\n        return bcc_groups;\n\
    \    }\n\n    std::vector<std::vector<int>> block_cut_tree() {\n        assert(called_bi_connected_components);\n\
    \        int bct_num = bcc_num;\n        for (int i = 0; i < n; i++) {\n     \
    \       if (is_articulation[i]) {\n                bct_id[i] = bct_num++;\n  \
    \          }\n        }\n        bct.resize(bct_num);\n        std::vector<int>\
    \ last_adjacent(bct_num, -1);\n        for (int i = 0; i < bcc_num; i++) {\n \
    \           for (auto& e : bcc_groups[i]) {\n                for (auto& v : {e.first,\
    \ e.second}) {\n                    if (is_articulation[v]) {\n              \
    \          if (std::exchange(last_adjacent[bct_id[v]], i) != i) {\n          \
    \                  bct[i].emplace_back(bct_id[v]);\n                         \
    \   bct[bct_id[v]].emplace_back(i);\n                        }\n             \
    \       } else\n                        bct_id[v] = i;\n                }\n  \
    \          }\n        }\n        return bct;\n    }\n\nprivate:\n    int n, m,\
    \ time, tecc_num, bcc_num;\n    bool called_build, called_two_connected_components,\
    \ called_bi_connected_components;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> order;             // visiting order of dfs-tree\n    std::vector<int>\
    \ lowlink;           // min of order of u which can be visited from v by using\
    \ dfs-tree edge any\n                                        // times and back\
    \ edge at most once\n    std::vector<bool> is_dfstree_edge;  // whether edge is\
    \ used in dfs-tree or not\n\n    std::vector<int> edge_stack;\n\n    void dfs_lowlink(int\
    \ v, int pre_eid = -1) {\n        order[v] = lowlink[v] = time++;\n        for\
    \ (const auto& e : G[v]) {\n            int u = e.first;\n            if (e.second\
    \ != pre_eid) {\n                if (order[u] < order[v]) edge_stack.emplace_back(e.second);\n\
    \                if (order[u] >= 0)\n                    lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n                else {\n                    is_dfstree_edge[e.second]\
    \ = true;\n                    dfs_lowlink(u, e.second);\n                   \
    \ lowlink[v] = std::min(lowlink[v], lowlink[u]);\n                    if (pre_eid\
    \ == -1 && order[u] != order[v] + 1) is_articulation[v] = true;\n            \
    \        if (pre_eid != -1 && order[v] <= lowlink[u]) is_articulation[v] = true;\n\
    \                    if (order[v] <= lowlink[u]) {\n                        while\
    \ (true) {\n                            int cur = edge_stack.back();\n       \
    \                     edge_stack.pop_back();\n                            bcc_id[cur]\
    \ = bcc_num;\n                            if (edges[cur] == edges[e.second]) break;\n\
    \                        }\n                        bcc_num++;\n             \
    \       }\n                }\n            }\n        }\n    }\n};\n\n/**\n * @brief\
    \ Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected Components)\n\
    \ * @docs docs/graph/BlockCutTree.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nstruct BlockCutTree {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G;\n    std::vector<std::vector<int>> tecc_tree,    // tree that consists\
    \ of two-edge-connected-component\n        bct;                              \
    \      // tree that consists of bi-connected-component and articulation\n    std::vector<bool>\
    \ is_articulation,          // whether vertex i is articulation or not\n     \
    \   is_bridge;                              // whether edge i is bridge or not\n\
    \    std::vector<int> tecc_id;                   // id of two-edge-connected-component\
    \ vertex i belongs to\n    std::vector<std::vector<int>> tecc_groups;  // vertices\
    \ belongs to i-th two-edge-connected-component\n    std::vector<int> bcc_id; \
    \                   // id of bi-connected-component edge i belongs to\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bcc_groups;  // edges belongs to i-th bi-connected-component\n    std::vector<int>\
    \ bct_id;  // id of component on block-cut-tree vertex i belongs to (order : bcc\
    \ -> articulation)\n    std::vector<std::vector<int>> bct_groups;  // vertices\
    \ belongs to i-th component on block-cut-tree\n\n    BlockCutTree(int n)\n   \
    \     : G(n), is_articulation(n, false), n(n), m(0), time(0), bcc_num(0), order(n,\
    \ -1), lowlink(n, -1) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v,\
    \ m);\n        G[v].emplace_back(u, m);\n        if (u > v) std::swap(u, v);\n\
    \        edges.emplace_back(u, v);\n        is_bridge.emplace_back(false);\n \
    \       is_dfstree_edge.emplace_back(false);\n        bcc_id.emplace_back(-1);\n\
    \        m++;\n    }\n\n    void build() {\n        called_build = true;\n   \
    \     for (int i = 0; i < n; i++) {\n            if (order[i] == -1) {\n     \
    \           dfs_lowlink(i);\n            }\n        }\n        for (int i = 0;\
    \ i < m; i++) {\n            int u = edges[i].first, v = edges[i].second;\n  \
    \          if (order[u] > order[v]) std::swap(u, v);\n            if (order[u]\
    \ < lowlink[v]) is_bridge[i] = true;\n        }\n    }\n\n    std::vector<std::vector<int>>\
    \ two_edge_connected_components() {\n        assert(called_build);\n        called_two_connected_components\
    \ = true;\n        tecc_num = 0;\n        tecc_id.assign(n, -1);\n        for\
    \ (int i = 0; i < n; i++) {\n            if (tecc_id[i] >= 0) continue;\n    \
    \        tecc_id[i] = tecc_num;\n            std::queue<int> que;\n          \
    \  que.emplace(i);\n            while (!que.empty()) {\n                int v\
    \ = que.front();\n                que.pop();\n                for (const auto&\
    \ e : G[v]) {\n                    int u = e.first;\n                    if (tecc_id[u]\
    \ >= 0 || is_bridge[e.second]) continue;\n                    tecc_id[u] = tecc_num;\n\
    \                    que.emplace(u);\n                }\n            }\n     \
    \       tecc_num++;\n        }\n        tecc_groups.resize(tecc_num);\n      \
    \  for (int i = 0; i < n; i++) tecc_groups[tecc_id[i]].emplace_back(i);\n    \
    \    return tecc_groups;\n    }\n\n    std::vector<std::vector<int>> tecc_make_tree()\
    \ {\n        assert(called_two_connected_components);\n        tecc_tree.resize(tecc_num);\n\
    \        for (int i = 0; i < m; i++) {\n            if (!is_bridge[i]) continue;\n\
    \            int u = tecc_id[edges[i].first], v = tecc_id[edges[i].second];\n\
    \            tecc_tree[u].emplace_back(v);\n            tecc_tree[v].emplace_back(u);\n\
    \        }\n        return tecc_tree;\n    }\n\n    std::vector<std::vector<std::pair<int,\
    \ int>>> bi_connected_components() {\n        assert(called_build);\n        called_bi_connected_components\
    \ = true;\n        bcc_groups.resize(bcc_num);\n        for (int i = 0; i < m;\
    \ i++) bcc_groups[bcc_id[i]].emplace_back(edges[i]);\n        return bcc_groups;\n\
    \    }\n\n    std::vector<std::vector<int>> block_cut_tree() {\n        assert(called_bi_connected_components);\n\
    \        int bct_num = bcc_num;\n        for (int i = 0; i < n; i++) {\n     \
    \       if (is_articulation[i]) {\n                bct_id[i] = bct_num++;\n  \
    \          }\n        }\n        bct.resize(bct_num);\n        std::vector<int>\
    \ last_adjacent(bct_num, -1);\n        for (int i = 0; i < bcc_num; i++) {\n \
    \           for (auto& e : bcc_groups[i]) {\n                for (auto& v : {e.first,\
    \ e.second}) {\n                    if (is_articulation[v]) {\n              \
    \          if (std::exchange(last_adjacent[bct_id[v]], i) != i) {\n          \
    \                  bct[i].emplace_back(bct_id[v]);\n                         \
    \   bct[bct_id[v]].emplace_back(i);\n                        }\n             \
    \       } else\n                        bct_id[v] = i;\n                }\n  \
    \          }\n        }\n        return bct;\n    }\n\nprivate:\n    int n, m,\
    \ time, tecc_num, bcc_num;\n    bool called_build, called_two_connected_components,\
    \ called_bi_connected_components;\n    std::vector<std::pair<int, int>> edges;\n\
    \    std::vector<int> order;             // visiting order of dfs-tree\n    std::vector<int>\
    \ lowlink;           // min of order of u which can be visited from v by using\
    \ dfs-tree edge any\n                                        // times and back\
    \ edge at most once\n    std::vector<bool> is_dfstree_edge;  // whether edge is\
    \ used in dfs-tree or not\n\n    std::vector<int> edge_stack;\n\n    void dfs_lowlink(int\
    \ v, int pre_eid = -1) {\n        order[v] = lowlink[v] = time++;\n        for\
    \ (const auto& e : G[v]) {\n            int u = e.first;\n            if (e.second\
    \ != pre_eid) {\n                if (order[u] < order[v]) edge_stack.emplace_back(e.second);\n\
    \                if (order[u] >= 0)\n                    lowlink[v] = std::min(lowlink[v],\
    \ order[u]);\n                else {\n                    is_dfstree_edge[e.second]\
    \ = true;\n                    dfs_lowlink(u, e.second);\n                   \
    \ lowlink[v] = std::min(lowlink[v], lowlink[u]);\n                    if (pre_eid\
    \ == -1 && order[u] != order[v] + 1) is_articulation[v] = true;\n            \
    \        if (pre_eid != -1 && order[v] <= lowlink[u]) is_articulation[v] = true;\n\
    \                    if (order[v] <= lowlink[u]) {\n                        while\
    \ (true) {\n                            int cur = edge_stack.back();\n       \
    \                     edge_stack.pop_back();\n                            bcc_id[cur]\
    \ = bcc_num;\n                            if (edges[cur] == edges[e.second]) break;\n\
    \                        }\n                        bcc_num++;\n             \
    \       }\n                }\n            }\n        }\n    }\n};\n\n/**\n * @brief\
    \ Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected Components)\n\
    \ * @docs docs/graph/BlockCutTree.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/BlockCutTree.hpp
  requiredBy: []
  timestamp: '2021-10-04 21:58:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/aoj/GRL_3_A.test.cpp
documentation_of: graph/BlockCutTree.hpp
layout: document
redirect_from:
- /library/graph/BlockCutTree.hpp
- /library/graph/BlockCutTree.hpp.html
title: Block Cut Tree (with Lowlink, Two Edge Connected Components, Bi Connected Components)
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