---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/UndoUnionFind.hpp
    title: Union Find with Undo Operation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/OfflineDynamicConnectivity.hpp\"\n#include\
    \ <algorithm>\n#include <map>\n#include <tuple>\n#include <utility>\n#line 2 \"\
    src/datastructure/UndoUnionFind.hpp\"\n#include <cassert>\n#include <stack>\n\
    #include <vector>\n\nstruct UndoUnionFind {\n    UndoUnionFind() {}\n\n    UndoUnionFind(int\
    \ n) : n(n), data(n, -1) {}\n\n    int find(int x) const {\n        assert(0 <=\
    \ x && x < n);\n        return data[x] < 0 ? x : find(data[x]);\n    }\n\n   \
    \ bool merge(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        x = find(x), y = find(y);\n        history.emplace(x,\
    \ data[x]);\n        history.emplace(y, data[y]);\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) const {\n        assert(0 <= x && x < n);\n        assert(0 <= y &&\
    \ y < n);\n        return find(x) == find(y);\n    }\n\n    int size(int x) const\
    \ {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n    }\n\
    \n    void undo() {\n        assert(!history.empty());\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n    }\n\n    void snapshot()\
    \ {\n        while (!history.empty()) history.pop();\n    }\n\n    void rollback()\
    \ {\n        while (!history.empty()) undo();\n    }\n\n    int operator[](int\
    \ x) const { return find(x); }\n\n  private:\n    int n;\n    std::vector<int>\
    \ data;\n    std::stack<std::pair<int, int>> history;\n};\n#line 7 \"src/datastructure/OfflineDynamicConnectivity.hpp\"\
    \n\nstruct OfflineDynamicConnectivity {\n    OfflineDynamicConnectivity(int n)\
    \ : n(n) {}\n\n    void add(int u, int v) {\n        assert(0 <= u and u < n);\n\
    \        assert(0 <= v and v < n);\n        time.emplace(std::minmax(u, v), qs.size());\n\
    \    }\n\n    void del(int u, int v) {\n        assert(0 <= u and u < n);\n  \
    \      assert(0 <= v and v < n);\n        auto it = time.find(std::minmax(u, v));\n\
    \        assert(it != time.end());\n        es.emplace_back(u, v, it->second,\
    \ qs.size());\n        time.erase(it);\n    }\n\n    void query(int u, int v)\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      qs.emplace_back(u, v);\n    }\n\n    std::vector<bool> solve() {\n    \
    \    int q = qs.size();\n        if (q == 0) return {};\n        for (auto it\
    \ = time.begin(); it != time.end(); it = time.erase(it)) {\n            const\
    \ auto& [u, v] = it->first;\n            es.emplace_back(u, v, it->second, q);\n\
    \        }\n        std::vector<std::vector<std::pair<int, int>>> seg(2 * q);\n\
    \        for (auto [u, v, l, r] : es) {\n            for (l += q, r += q; l <\
    \ r; l >>= 1, r >>= 1) {\n                if (l & 1) seg[l++].emplace_back(u,\
    \ v);\n                if (r & 1) seg[--r].emplace_back(u, v);\n            }\n\
    \        }\n        UndoUnionFind uf(n);\n        std::vector<bool> res(q);\n\
    \        auto dfs = [&](auto self, int k) -> void {\n            for (const auto&\
    \ [u, v] : seg[k]) uf.merge(u, v);\n            if (k >= q) {\n              \
    \  const auto& [u, v] = qs[k - q];\n                res[k - q] = uf.same(u, v);\n\
    \            } else {\n                self(self, k << 1);\n                self(self,\
    \ k << 1 | 1);\n            }\n            for (int i = 0; i < int(seg[k].size());\
    \ i++) uf.undo();\n        };\n        dfs(dfs, 1);\n        return res;\n   \
    \ }\n\n  private:\n    int n;\n    std::multimap<std::pair<int, int>, int> time;\n\
    \    std::vector<std::pair<int, int>> qs;\n    std::vector<std::tuple<int, int,\
    \ int, int>> es;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <tuple>\n#include\
    \ <utility>\n#include \"UndoUnionFind.hpp\"\n\nstruct OfflineDynamicConnectivity\
    \ {\n    OfflineDynamicConnectivity(int n) : n(n) {}\n\n    void add(int u, int\
    \ v) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        time.emplace(std::minmax(u, v), qs.size());\n    }\n\n    void del(int\
    \ u, int v) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v\
    \ < n);\n        auto it = time.find(std::minmax(u, v));\n        assert(it !=\
    \ time.end());\n        es.emplace_back(u, v, it->second, qs.size());\n      \
    \  time.erase(it);\n    }\n\n    void query(int u, int v) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        qs.emplace_back(u,\
    \ v);\n    }\n\n    std::vector<bool> solve() {\n        int q = qs.size();\n\
    \        if (q == 0) return {};\n        for (auto it = time.begin(); it != time.end();\
    \ it = time.erase(it)) {\n            const auto& [u, v] = it->first;\n      \
    \      es.emplace_back(u, v, it->second, q);\n        }\n        std::vector<std::vector<std::pair<int,\
    \ int>>> seg(2 * q);\n        for (auto [u, v, l, r] : es) {\n            for\
    \ (l += q, r += q; l < r; l >>= 1, r >>= 1) {\n                if (l & 1) seg[l++].emplace_back(u,\
    \ v);\n                if (r & 1) seg[--r].emplace_back(u, v);\n            }\n\
    \        }\n        UndoUnionFind uf(n);\n        std::vector<bool> res(q);\n\
    \        auto dfs = [&](auto self, int k) -> void {\n            for (const auto&\
    \ [u, v] : seg[k]) uf.merge(u, v);\n            if (k >= q) {\n              \
    \  const auto& [u, v] = qs[k - q];\n                res[k - q] = uf.same(u, v);\n\
    \            } else {\n                self(self, k << 1);\n                self(self,\
    \ k << 1 | 1);\n            }\n            for (int i = 0; i < int(seg[k].size());\
    \ i++) uf.undo();\n        };\n        dfs(dfs, 1);\n        return res;\n   \
    \ }\n\n  private:\n    int n;\n    std::multimap<std::pair<int, int>, int> time;\n\
    \    std::vector<std::pair<int, int>> qs;\n    std::vector<std::tuple<int, int,\
    \ int, int>> es;\n};\n"
  dependsOn:
  - src/datastructure/UndoUnionFind.hpp
  isVerificationFile: false
  path: src/datastructure/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2024-05-21 23:41:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/OfflineDynamicConnectivity.hpp
layout: document
title: Offline Dynamic Connectivity
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