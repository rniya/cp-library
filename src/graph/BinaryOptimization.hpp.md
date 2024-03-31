---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1984.test.cpp
    title: test/yukicoder/1984.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow:\
    \ line -1: no such header\n"
  code: "#include <array>\n#include <tuple>\n#include \"atcoder/maxflow\"\n\ntemplate\
    \ <typename T> struct BinaryOptimization {\n    BinaryOptimization() = default;\n\
    \n    explicit BinaryOptimization(int n) : n(n), costs(n, std::vector<T>(2, 0))\
    \ {}\n\n    void add_cost_0(int x, T cost) {\n        assert(0 <= x and x < n);\n\
    \        assert(cost >= 0);\n        add_cost(x, {cost, 0});\n    }\n\n    void\
    \ add_cost_1(int x, T cost) {\n        assert(0 <= x and x < n);\n        assert(cost\
    \ >= 0);\n        add_cost(x, {0, cost});\n    }\n\n    void add_profit_0(int\
    \ x, T profit) {\n        assert(0 <= x and x < n);\n        assert(profit >=\
    \ 0);\n        add_cost(x, {-profit, 0});\n    }\n\n    void add_profit_1(int\
    \ x, T profit) {\n        assert(0 <= x and x < n);\n        assert(profit >=\
    \ 0);\n        add_cost(x, {0, -profit});\n    }\n\n    void add_cost_01(int x,\
    \ int y, T cost) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        assert(cost >= 0);\n        add_edge(x, y, cost);\n    }\n\n\
    \    void add_cost_10(int x, int y, T cost) { add_cost_01(y, x, cost); }\n\n \
    \   void add_profit_00(int x, int y, T profit) {\n        assert(0 <= x and x\
    \ < n);\n        assert(0 <= y and y < n);\n        assert(profit >= 0);\n   \
    \     add_cost(x, y, {-profit, 0, 0, 0});\n    }\n\n    void add_profit_11(int\
    \ x, int y, T profit) {\n        assert(0 <= x and x < n);\n        assert(0 <=\
    \ y and y < n);\n        assert(profit >= 0);\n        add_cost(x, y, {0, 0, 0,\
    \ -profit});\n    }\n\n    // void add_cost_for_3(int x, int y, int z, std::array<std::array<std::array<T,\
    \ 2>, 2>, 2> cost) {\n    //     add_cost(x, y, z, cost);\n    // }\n\n    void\
    \ add_profit_all_0(const std::vector<int>& v, T profit) {\n        assert(profit\
    \ >= 0);\n        if (v.size() == 0)\n            base_cost -= profit;\n     \
    \   else if (v.size() == 1)\n            add_profit_0(v[0], profit);\n       \
    \ else if (v.size() == 2)\n            add_profit_00(v[0], v[1], profit);\n  \
    \      else {\n            base_cost -= profit;\n            int nxt = n + aux++;\n\
    \            add_edge(source, nxt, profit);\n            for (const int& x : v)\
    \ add_edge(nxt, x, profit);\n        }\n    }\n\n    void add_profit_all_1(const\
    \ std::vector<int>& v, T profit) {\n        assert(profit >= 0);\n        if (v.size()\
    \ == 0)\n            base_cost -= profit;\n        else if (v.size() == 1)\n \
    \           add_profit_1(v[0], profit);\n        else if (v.size() == 2)\n   \
    \         add_profit_11(v[0], v[1], profit);\n        else {\n            base_cost\
    \ -= profit;\n            int nxt = n + aux++;\n            add_edge(nxt, sink,\
    \ profit);\n            for (const int& x : v) add_edge(x, nxt, profit);\n   \
    \     }\n    }\n\n    std::pair<T, std::vector<bool>> min_cost() {\n        for\
    \ (int i = 0; i < n; i++) {\n            auto& tmp = costs[i];\n            if\
    \ (tmp[0] <= tmp[1]) {\n                base_cost += tmp[0];\n               \
    \ add_edge(source, i, tmp[1] - tmp[0]);\n            } else {\n              \
    \  base_cost += tmp[1];\n                add_edge(i, sink, tmp[0] - tmp[1]);\n\
    \            }\n        }\n        atcoder::mf_graph<T> g(n + aux + 2);\n    \
    \    int s = n + aux, t = s + 1;\n        for (auto [u, v, w] : es) {\n      \
    \      u = (u == source ? s : u == sink ? t : u);\n            v = (v == source\
    \ ? s : v == sink ? t : v);\n            g.add_edge(u, v, w);\n        }\n   \
    \     auto sum = base_cost + g.flow(s, t);\n        auto x = g.min_cut(s);\n \
    \       x.resize(n);\n        for (int i = 0; i < n; i++) x[i] = not x[i];\n \
    \       return {sum, x};\n    }\n\n    std::pair<T, std::vector<bool>> max_profit()\
    \ {\n        auto res = min_cost();\n        res.first *= -1;\n        return\
    \ res;\n    }\n\n  private:\n    int n, aux = 0, source = -1, sink = -2;\n   \
    \ T base_cost = 0;\n    std::vector<std::vector<T>> costs;\n    std::vector<std::tuple<int,\
    \ int, T>> es;\n\n    void add_edge(int x, int y, T cost) {\n        assert(x\
    \ == source or x == sink or (0 <= x and x < n + aux));\n        assert(y == source\
    \ or y == sink or (0 <= y and y < n + aux));\n        if (cost == 0) return;\n\
    \        es.emplace_back(x, y, cost);\n    }\n\n    void add_cost(int x, std::array<T,\
    \ 2> cost) {\n        for (int i = 0; i < 2; i++) costs[x][i] += cost[i];\n  \
    \  }\n\n    void add_cost(int x, int y, std::array<std::array<T, 2>, 2> cost)\
    \ {\n        assert(cost[0][1] + cost[1][0] >= cost[0][0] + cost[1][1]);\n   \
    \     base_cost += cost[0][0];\n        add_cost(x, {0, cost[1][0] - cost[0][0]});\n\
    \        add_cost(y, {0, cost[1][1] - cost[1][0]});\n        add_cost_01(x, y,\
    \ (cost[0][1] - cost[0][0]) - (cost[1][1] - cost[1][0]));\n    }\n\n    // void\
    \ add_cost(int x, int y, std::array<std::array<std::array<T, 2>, 2>, 2> cost)\
    \ {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/BinaryOptimization.hpp
  requiredBy: []
  timestamp: '2024-03-31 19:30:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
  - test/yukicoder/1984.test.cpp
documentation_of: src/graph/BinaryOptimization.hpp
layout: document
redirect_from:
- /library/src/graph/BinaryOptimization.hpp
- /library/src/graph/BinaryOptimization.hpp.html
title: src/graph/BinaryOptimization.hpp
---
