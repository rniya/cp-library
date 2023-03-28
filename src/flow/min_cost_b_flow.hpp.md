---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/mincostflow:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include \"atcoder/mincostflow\"\n\ntemplate <class Cap, class\
    \ Cost> struct min_cost_b_flow {\n    min_cost_b_flow() {}\n    explicit min_cost_b_flow(int\
    \ n) : n(n), graph(n + 2), b(n), sum(Cost{}) {}\n\n    int add_edge(int from,\
    \ int to, Cap lower, Cap upper, Cost cost) {\n        assert(0 <= from and from\
    \ < n);\n        assert(0 <= to and to < n);\n        assert(lower <= upper);\n\
    \        if (cost < 0) {\n            std::swap(from, to);\n            std::swap(lower,\
    \ upper);\n            lower *= -1;\n            upper *= -1;\n            cost\
    \ *= -1;\n        }\n        b[from] -= lower;\n        b[to] += lower;\n    \
    \    sum += cost * lower;\n        return graph.add_edge(from, to, upper - lower,\
    \ cost);\n    }\n\n    void add_supply(int v, Cap x) {\n        assert(0 <= v\
    \ and v < n);\n        b[v] += x;\n    }\n\n    void add_demand(int v, Cap x)\
    \ {\n        assert(0 <= v and v < n);\n        b[v] -= x;\n    }\n\n    std::pair<bool,\
    \ Cost> flow() {\n        int source = n, sink = source + 1;\n        Cap positive{},\
    \ negative{};\n        for (int v = 0; v < n; v++) {\n            if (b[v] > 0)\
    \ {\n                graph.add_edge(source, v, b[v], 0);\n                positive\
    \ += b[v];\n            } else if (b[v] < 0) {\n                graph.add_edge(v,\
    \ sink, -b[v], 0);\n                negative += -b[v];\n            }\n      \
    \  }\n        if (positive != negative) return make_pair(false, Cost{});\n   \
    \     auto res = graph.flow(source, sink);\n        Cap flow = res.first;\n  \
    \      Cost cost = res.second;\n        if (flow < positive) return make_pair(false,\
    \ Cost{});\n        return make_pair(true, sum + cost);\n    }\n\nprivate:\n \
    \   int n;\n    atcoder::mcf_graph<Cap, Cost> graph;\n    std::vector<Cap> b;\n\
    \    Cost sum;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/flow/min_cost_b_flow.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/flow/min_cost_b_flow.hpp
layout: document
title: Minimum Cost b-flow
---

## 概要
Minimum Cost b-flow を解くための補助ライブラリ．
この考え方に従うと容量下限や負のコストの辺が存在するような最小費用流のグラフを簡単に構成できる．

## 双対問題

## 問題例
- [AtCoder Regular Contest 137 E - Bakery](https://atcoder.jp/contests/arc137/tasks/arc137_e)