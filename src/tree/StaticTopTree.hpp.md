---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/StaticTopTree.hpp\"\n#include <cassert>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\nstruct StaticTopTree {\n \
    \   enum Type { Vertex, Compress, Add_Vertex, Rake, Add_Edge };\n    struct Node\
    \ {\n        Type type;\n        int l, r, p;\n        Node() {}\n        Node(Type\
    \ type, int l = -1, int r = -1, int p = -1) : type(type), l(l), r(r), p(p) {}\n\
    \    };\n    int n, stt_root;\n    std::vector<std::vector<int>> G;\n    std::vector<Node>\
    \ nodes;\n\n    StaticTopTree(int n) : n(n), stt_root(-1), G(n), nodes(n) {}\n\
    \n    void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n     \
    \   assert(0 <= v and v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int r = 0) {\n        assert(0 <= r and r < n);\n   \
    \     dfs(r, -1);\n        auto [i, s] = _compress(r);\n        assert(s == n);\n\
    \        stt_root = i;\n    }\n\n    int size() const { return nodes.size(); }\n\
    \n  private:\n    int dfs(int v, int p) {\n        for (int& u : G[v]) {\n   \
    \         if (u == p) {\n                std::swap(u, G[v].back());\n        \
    \        G[v].pop_back();\n                break;\n            }\n        }\n\
    \        int sum = 1, best = 0;\n        for (int& u : G[v]) {\n            int\
    \ ch = dfs(u, v);\n            sum += ch;\n            if (best < ch) {\n    \
    \            best = ch;\n                std::swap(u, G[v].front());\n       \
    \     }\n        }\n        return sum;\n    }\n\n    int add(int l, int r, Type\
    \ t) {\n        int v = nodes.size();\n        nodes.emplace_back(t, l, r);\n\
    \        if (l != -1) {\n            assert(l < v);\n            nodes[l].p =\
    \ v;\n        }\n        if (r != -1) {\n            assert(r < v);\n        \
    \    nodes[r].p = v;\n        }\n        return v;\n    }\n\n    int Add(int v,\
    \ int l, int r, Type t) {\n        assert(v < n);\n        nodes[v].type = t,\
    \ nodes[v].l = l, nodes[v].r = r, nodes[v].p = -1;\n        if (l != -1) {\n \
    \           assert(l < int(nodes.size()));\n            nodes[l].p = v;\n    \
    \    }\n        if (r != -1) {\n            assert(r < int(nodes.size()));\n \
    \           nodes[r].p = v;\n        }\n        return v;\n    }\n\n    std::pair<int,\
    \ int> merge(const std::vector<std::pair<int, int>>& a, Type t) {\n        if\
    \ (a.size() == 1) return a[0];\n        int sum = 0;\n        for (const auto&\
    \ [_, s] : a) sum += s;\n        std::vector<std::pair<int, int>> b, c;\n    \
    \    for (const auto& [i, s] : a) {\n            (sum > s ? b : c).emplace_back(i,\
    \ s);\n            sum -= s * 2;\n        }\n        auto [l, sl] = merge(b, t);\n\
    \        auto [r, sr] = merge(c, t);\n        return {add(l, r, t), sl + sr};\n\
    \    }\n\n    std::pair<int, int> _compress(int v) {\n        std::vector<std::pair<int,\
    \ int>> chs{_add_vertex(v)};\n        while (not G[v].empty()) chs.emplace_back(_add_vertex(v\
    \ = G[v][0]));\n        return merge(chs, Type::Compress);\n    }\n\n    std::pair<int,\
    \ int> _add_vertex(int v) {\n        auto [i, s] = _rake(v);\n        return {Add(v,\
    \ i, -1, i == -1 ? Type::Vertex : Type::Add_Vertex), s + 1};\n    }\n\n    std::pair<int,\
    \ int> _rake(int v) {\n        std::vector<std::pair<int, int>> chs;\n       \
    \ for (int i = 1; i < int(G[v].size()); i++) chs.emplace_back(_add_edge(G[v][i]));\n\
    \        return chs.empty() ? std::make_pair(-1, 0) : merge(chs, Type::Rake);\n\
    \    }\n\n    std::pair<int, int> _add_edge(int v) {\n        auto [i, s] = _compress(v);\n\
    \        return {add(i, -1, Type::Add_Edge), s};\n    }\n};\n\ntemplate <class\
    \ TreeDP> struct DynamicDPonStaticTopTree {\n    using Path = typename TreeDP::Path;\n\
    \    using Point = typename TreeDP::Point;\n    const StaticTopTree& stt;\n  \
    \  TreeDP& treedp;\n    std::vector<Path> paths;\n    std::vector<Point> points;\n\
    \    DynamicDPonStaticTopTree(const StaticTopTree& stt, TreeDP& treedp)\n    \
    \    : stt(stt), treedp(treedp), paths(stt.size()), points(stt.size()) {\n   \
    \     init(stt.stt_root);\n    }\n\n    void set(int k) {\n        for (; k !=\
    \ -1; k = stt.nodes[k].p) {\n            update(k);\n        }\n    }\n\n    Path\
    \ all_prod() const { return paths[stt.stt_root]; }\n\n  private:\n    void init(int\
    \ k) {\n        const auto& node = stt.nodes[k];\n        if (node.l != -1) init(node.l);\n\
    \        if (node.r != -1) init(node.r);\n        update(k);\n    }\n\n    void\
    \ update(int k) {\n        const auto& node = stt.nodes[k];\n        if (node.type\
    \ == StaticTopTree::Type::Vertex) {\n            paths[k] = treedp.vertex(k);\n\
    \        } else if (node.type == StaticTopTree::Type::Compress) {\n          \
    \  paths[k] = treedp.compress(paths[node.l], paths[node.r]);\n        } else if\
    \ (node.type == StaticTopTree::Type::Add_Vertex) {\n            paths[k] = treedp.add_vertex(points[node.l],\
    \ k);\n        } else if (node.type == StaticTopTree::Type::Rake) {\n        \
    \    points[k] = treedp.rake(points[node.l], points[node.r]);\n        } else\
    \ if (node.type == StaticTopTree::Type::Add_Edge) {\n            points[k] = treedp.add_edge(paths[node.l]);\n\
    \        } else {\n            assert(false);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\nstruct StaticTopTree {\n    enum Type { Vertex, Compress,\
    \ Add_Vertex, Rake, Add_Edge };\n    struct Node {\n        Type type;\n     \
    \   int l, r, p;\n        Node() {}\n        Node(Type type, int l = -1, int r\
    \ = -1, int p = -1) : type(type), l(l), r(r), p(p) {}\n    };\n    int n, stt_root;\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<Node> nodes;\n\n    StaticTopTree(int\
    \ n) : n(n), stt_root(-1), G(n), nodes(n) {}\n\n    void add_edge(int u, int v)\
    \ {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n  \
    \      G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    void\
    \ build(int r = 0) {\n        assert(0 <= r and r < n);\n        dfs(r, -1);\n\
    \        auto [i, s] = _compress(r);\n        assert(s == n);\n        stt_root\
    \ = i;\n    }\n\n    int size() const { return nodes.size(); }\n\n  private:\n\
    \    int dfs(int v, int p) {\n        for (int& u : G[v]) {\n            if (u\
    \ == p) {\n                std::swap(u, G[v].back());\n                G[v].pop_back();\n\
    \                break;\n            }\n        }\n        int sum = 1, best =\
    \ 0;\n        for (int& u : G[v]) {\n            int ch = dfs(u, v);\n       \
    \     sum += ch;\n            if (best < ch) {\n                best = ch;\n \
    \               std::swap(u, G[v].front());\n            }\n        }\n      \
    \  return sum;\n    }\n\n    int add(int l, int r, Type t) {\n        int v =\
    \ nodes.size();\n        nodes.emplace_back(t, l, r);\n        if (l != -1) {\n\
    \            assert(l < v);\n            nodes[l].p = v;\n        }\n        if\
    \ (r != -1) {\n            assert(r < v);\n            nodes[r].p = v;\n     \
    \   }\n        return v;\n    }\n\n    int Add(int v, int l, int r, Type t) {\n\
    \        assert(v < n);\n        nodes[v].type = t, nodes[v].l = l, nodes[v].r\
    \ = r, nodes[v].p = -1;\n        if (l != -1) {\n            assert(l < int(nodes.size()));\n\
    \            nodes[l].p = v;\n        }\n        if (r != -1) {\n            assert(r\
    \ < int(nodes.size()));\n            nodes[r].p = v;\n        }\n        return\
    \ v;\n    }\n\n    std::pair<int, int> merge(const std::vector<std::pair<int,\
    \ int>>& a, Type t) {\n        if (a.size() == 1) return a[0];\n        int sum\
    \ = 0;\n        for (const auto& [_, s] : a) sum += s;\n        std::vector<std::pair<int,\
    \ int>> b, c;\n        for (const auto& [i, s] : a) {\n            (sum > s ?\
    \ b : c).emplace_back(i, s);\n            sum -= s * 2;\n        }\n        auto\
    \ [l, sl] = merge(b, t);\n        auto [r, sr] = merge(c, t);\n        return\
    \ {add(l, r, t), sl + sr};\n    }\n\n    std::pair<int, int> _compress(int v)\
    \ {\n        std::vector<std::pair<int, int>> chs{_add_vertex(v)};\n        while\
    \ (not G[v].empty()) chs.emplace_back(_add_vertex(v = G[v][0]));\n        return\
    \ merge(chs, Type::Compress);\n    }\n\n    std::pair<int, int> _add_vertex(int\
    \ v) {\n        auto [i, s] = _rake(v);\n        return {Add(v, i, -1, i == -1\
    \ ? Type::Vertex : Type::Add_Vertex), s + 1};\n    }\n\n    std::pair<int, int>\
    \ _rake(int v) {\n        std::vector<std::pair<int, int>> chs;\n        for (int\
    \ i = 1; i < int(G[v].size()); i++) chs.emplace_back(_add_edge(G[v][i]));\n  \
    \      return chs.empty() ? std::make_pair(-1, 0) : merge(chs, Type::Rake);\n\
    \    }\n\n    std::pair<int, int> _add_edge(int v) {\n        auto [i, s] = _compress(v);\n\
    \        return {add(i, -1, Type::Add_Edge), s};\n    }\n};\n\ntemplate <class\
    \ TreeDP> struct DynamicDPonStaticTopTree {\n    using Path = typename TreeDP::Path;\n\
    \    using Point = typename TreeDP::Point;\n    const StaticTopTree& stt;\n  \
    \  TreeDP& treedp;\n    std::vector<Path> paths;\n    std::vector<Point> points;\n\
    \    DynamicDPonStaticTopTree(const StaticTopTree& stt, TreeDP& treedp)\n    \
    \    : stt(stt), treedp(treedp), paths(stt.size()), points(stt.size()) {\n   \
    \     init(stt.stt_root);\n    }\n\n    void set(int k) {\n        for (; k !=\
    \ -1; k = stt.nodes[k].p) {\n            update(k);\n        }\n    }\n\n    Path\
    \ all_prod() const { return paths[stt.stt_root]; }\n\n  private:\n    void init(int\
    \ k) {\n        const auto& node = stt.nodes[k];\n        if (node.l != -1) init(node.l);\n\
    \        if (node.r != -1) init(node.r);\n        update(k);\n    }\n\n    void\
    \ update(int k) {\n        const auto& node = stt.nodes[k];\n        if (node.type\
    \ == StaticTopTree::Type::Vertex) {\n            paths[k] = treedp.vertex(k);\n\
    \        } else if (node.type == StaticTopTree::Type::Compress) {\n          \
    \  paths[k] = treedp.compress(paths[node.l], paths[node.r]);\n        } else if\
    \ (node.type == StaticTopTree::Type::Add_Vertex) {\n            paths[k] = treedp.add_vertex(points[node.l],\
    \ k);\n        } else if (node.type == StaticTopTree::Type::Rake) {\n        \
    \    points[k] = treedp.rake(points[node.l], points[node.r]);\n        } else\
    \ if (node.type == StaticTopTree::Type::Add_Edge) {\n            points[k] = treedp.add_edge(paths[node.l]);\n\
    \        } else {\n            assert(false);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/StaticTopTree.hpp
  requiredBy: []
  timestamp: '2024-06-04 01:15:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: src/tree/StaticTopTree.hpp
layout: document
title: Static Top Tree
---

## 概要
以下の関数をもつ構造体 `TreeDP` が必要となる。
ここで、`compress(l, r)` においては `l` の方が根寄りの cluster である。
詳細は verify code や問題例での提出を参照。

```C++
struct TreeDP {
    struct Path {};

    struct Point {};

    Path vertex(int v) {}

    Path compress(const Path& l, const Path& r) {}

    Path add_vertex(const Point& p, int v) {}

    Point rake(const Point& l, const Point& r) {}

    Point add_edge(const Path& p) {}
};
```

## 問題例
- [AtCoder Beginner Contest 351 G - Hash on Tree](https://atcoder.jp/contests/abc351/tasks/abc351_g)