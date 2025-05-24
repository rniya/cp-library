---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/tree_path_composite_sum.test.cpp
    title: test/yosupo/tree_path_composite_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/Rerooting.hpp\"\n#include <cassert>\n#include <map>\n\
    #include <vector>\n\ntemplate <class TreeDP, bool STORE_SUBTREE = false> struct\
    \ Rerooting {\n    using T = TreeDP::T;\n\n    struct edge {\n        int to,\
    \ e;\n        T dp, ndp;\n        edge(int to, int e, T dp, T ndp) : to(to), e(e),\
    \ dp(dp), ndp(ndp) {}\n    };\n\n    std::vector<std::vector<edge>> G;\n    std::unordered_map<long\
    \ long, T> mp;\n\n    Rerooting(int n, const TreeDP& treedp) : n(n), m(0), G(n),\
    \ treedp(treedp), sub(n), dp(n) {}\n\n    void add_edge(int u, int v) {\n    \
    \    assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v,\
    \ m, treedp.e(), treedp.e());\n        G[v].emplace_back(u, m, treedp.e(), treedp.e());\n\
    \        m++;\n    }\n\n    std::vector<T> solve() {\n        dfs_sub(0, -1);\n\
    \        dfs_all(0, -1, treedp.e());\n        return dp;\n    }\n\n    T get(int\
    \ u, int v) {\n        assert(STORE_SUBTREE);\n        return mp[1LL * n * u +\
    \ v];\n    }\n\n  private:\n    int n, m;\n    TreeDP treedp;\n    std::vector<T>\
    \ sub, dp;\n\n    void dfs_sub(int v, int p) {\n        sub[v] = treedp.e();\n\
    \        for (auto& e : G[v]) {\n            if (e.to == p) continue;\n      \
    \      dfs_sub(e.to, v);\n            sub[v] = treedp.op(sub[v], treedp.add_edge(sub[e.to],\
    \ e.e));\n        }\n        sub[v] = treedp.add_vertex(sub[v], v);\n    }\n\n\
    \    void dfs_all(int v, int p, const T& top) {\n        T cur = treedp.e();\n\
    \        for (int i = 0; i < int(G[v].size()); i++) {\n            auto& e = G[v][i];\n\
    \            e.ndp = cur;\n            e.dp = treedp.add_edge(e.to == p ? top\
    \ : sub[e.to], e.e);\n            cur = treedp.op(cur, e.dp);\n        }\n   \
    \     dp[v] = treedp.add_vertex(cur, v);\n        cur = treedp.e();\n        for\
    \ (int i = int(G[v].size()) - 1; i >= 0; i--) {\n            auto& e = G[v][i];\n\
    \            e.ndp = treedp.add_vertex(treedp.op(e.ndp, cur), v);\n          \
    \  if (e.to != p) {\n                if (STORE_SUBTREE) {\n                  \
    \  mp[1LL * n * v + e.to] = e.ndp;\n                    mp[1LL * n * e.to + v]\
    \ = sub[e.to];\n                }\n                dfs_all(e.to, v, e.ndp);\n\
    \            }\n            cur = treedp.op(cur, e.dp);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <map>\n#include <vector>\n\ntemplate\
    \ <class TreeDP, bool STORE_SUBTREE = false> struct Rerooting {\n    using T =\
    \ TreeDP::T;\n\n    struct edge {\n        int to, e;\n        T dp, ndp;\n  \
    \      edge(int to, int e, T dp, T ndp) : to(to), e(e), dp(dp), ndp(ndp) {}\n\
    \    };\n\n    std::vector<std::vector<edge>> G;\n    std::unordered_map<long\
    \ long, T> mp;\n\n    Rerooting(int n, const TreeDP& treedp) : n(n), m(0), G(n),\
    \ treedp(treedp), sub(n), dp(n) {}\n\n    void add_edge(int u, int v) {\n    \
    \    assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v,\
    \ m, treedp.e(), treedp.e());\n        G[v].emplace_back(u, m, treedp.e(), treedp.e());\n\
    \        m++;\n    }\n\n    std::vector<T> solve() {\n        dfs_sub(0, -1);\n\
    \        dfs_all(0, -1, treedp.e());\n        return dp;\n    }\n\n    T get(int\
    \ u, int v) {\n        assert(STORE_SUBTREE);\n        return mp[1LL * n * u +\
    \ v];\n    }\n\n  private:\n    int n, m;\n    TreeDP treedp;\n    std::vector<T>\
    \ sub, dp;\n\n    void dfs_sub(int v, int p) {\n        sub[v] = treedp.e();\n\
    \        for (auto& e : G[v]) {\n            if (e.to == p) continue;\n      \
    \      dfs_sub(e.to, v);\n            sub[v] = treedp.op(sub[v], treedp.add_edge(sub[e.to],\
    \ e.e));\n        }\n        sub[v] = treedp.add_vertex(sub[v], v);\n    }\n\n\
    \    void dfs_all(int v, int p, const T& top) {\n        T cur = treedp.e();\n\
    \        for (int i = 0; i < int(G[v].size()); i++) {\n            auto& e = G[v][i];\n\
    \            e.ndp = cur;\n            e.dp = treedp.add_edge(e.to == p ? top\
    \ : sub[e.to], e.e);\n            cur = treedp.op(cur, e.dp);\n        }\n   \
    \     dp[v] = treedp.add_vertex(cur, v);\n        cur = treedp.e();\n        for\
    \ (int i = int(G[v].size()) - 1; i >= 0; i--) {\n            auto& e = G[v][i];\n\
    \            e.ndp = treedp.add_vertex(treedp.op(e.ndp, cur), v);\n          \
    \  if (e.to != p) {\n                if (STORE_SUBTREE) {\n                  \
    \  mp[1LL * n * v + e.to] = e.ndp;\n                    mp[1LL * n * e.to + v]\
    \ = sub[e.to];\n                }\n                dfs_all(e.to, v, e.ndp);\n\
    \            }\n            cur = treedp.op(cur, e.dp);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-10-28 15:43:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/tree_path_composite_sum.test.cpp
documentation_of: src/tree/Rerooting.hpp
layout: document
title: Rerooting
---

## 概要
全方位木 dp を計算する．

使用する際には，以下の関数をもつ構造体 `TreeDP` が必要となる．

- `T e()`: 単位元（根が virtual で辺のない 1 頂点の木）を返す．
- `T op(const T& l, const T& r)`: 根が virtual な木 $l, r$ の合成を返す．
- `T add_vertex(const T& t, int v)`: 根が virtual な木 $t$ の根に $v$ を代入した木を返す．
- `T add_edge(const T& t, int e)`: 木 $t$ の根に枝 $e$ を接続してできる，根が virtual な木を返す．

```C++
struct TreeDP {
    struct T {};

    T e() {}

    T op(const T& l, const T& r) {}

    T add_vertex(const T& t, int v) {}

    T add_edge(const T& t, int e) {}
};
```

計算量は時間・空間計算量ともに $\mathrm{O}(n)$．

引数の `STORES_SUBTREE` を `true` にすることで，木全体から辺 $(u, v)$ を取り除いた際の $u$ を根とする部分木の情報を $get(u, v)$ で得ることができる．
この場合，時間計算量は $\mathrm{O}(n \log n)$ となる．

## Links
- [全方位木DP (ReRooting) の抽象化について - メモ帳](https://null-mn.hatenablog.com/entry/2020/04/14/124151)

## 出題例
- [The 2022 ICPC Asia Hangzhou Regional Programming Contest M. Please Save Pigeland](https://codeforces.com/gym/104090/problem/M)
- [AtCoder Regular Contest 179 D - Portable Gate](https://atcoder.jp/contests/arc179/tasks/arc179_d)