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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/mincostflow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n#include \"../atcoder/mincostflow\"\n\ntemplate <class Cap,\
    \ class Cost> struct min_cost_b_flow {\n    min_cost_b_flow() {}\n    explicit\
    \ min_cost_b_flow(int n) : n(n), graph(n + 2), b(n), sum(Cost{}) {}\n\n    int\
    \ add_edge(int from, int to, Cap lower, Cap upper, Cost cost) {\n        assert(0\
    \ <= from and from < n);\n        assert(0 <= to and to < n);\n        assert(lower\
    \ <= upper);\n        if (cost < 0) {\n            std::swap(from, to);\n    \
    \        std::swap(lower, upper);\n            lower *= -1;\n            upper\
    \ *= -1;\n            cost *= -1;\n        }\n        b[from] -= lower;\n    \
    \    b[to] += lower;\n        sum += cost * lower;\n        return graph.add_edge(from,\
    \ to, upper - lower, cost);\n    }\n\n    void add_supply(int v, Cap x) {\n  \
    \      assert(0 <= v and v < n);\n        b[v] += x;\n    }\n\n    void add_demand(int\
    \ v, Cap x) {\n        assert(0 <= v and v < n);\n        b[v] -= x;\n    }\n\n\
    \    std::pair<bool, Cost> flow() {\n        int source = n, sink = source + 1;\n\
    \        Cap positive{}, negative{};\n        for (int v = 0; v < n; v++) {\n\
    \            if (b[v] > 0) {\n                graph.add_edge(source, v, b[v],\
    \ 0);\n                positive += b[v];\n            } else if (b[v] < 0) {\n\
    \                graph.add_edge(v, sink, -b[v], 0);\n                negative\
    \ += -b[v];\n            }\n        }\n        if (positive != negative) return\
    \ std::make_pair(false, Cost{});\n        auto res = graph.flow(source, sink);\n\
    \        Cap flow = res.first;\n        Cost cost = res.second;\n        if (flow\
    \ < positive) return std::make_pair(false, Cost{});\n        return std::make_pair(true,\
    \ sum + cost);\n    }\n\n  private:\n    int n;\n    atcoder::mcf_graph<Cap, Cost>\
    \ graph;\n    std::vector<Cap> b;\n    Cost sum;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/min_cost_b_flow.hpp
  requiredBy: []
  timestamp: '2024-06-24 16:39:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/optimization/min_cost_b_flow.hpp
layout: document
title: Minimum Cost b-flow
---

## 概要

## 双対問題

## 出題例
- [AtCoder Regular Contest 137 E - Bakery](https://atcoder.jp/contests/arc137/tasks/arc137_e)
- [The 2nd Universal Cup. Stage 11: Nanjing E. Extending Distance](https://contest.ucup.ac/contest/1435/problem/7737)