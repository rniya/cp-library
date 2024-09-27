---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1615.test.cpp
    title: test/aoj/1615.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../atcoder/maxflow\"\n\ntemplate <class Cap> struct\
    \ maxflow_lowerbound {\n    maxflow_lowerbound() {}\n    maxflow_lowerbound(int\
    \ n) : n(n), graph(n + 2), in(n, 0) {}\n\n    int add_edge(int from, int to, Cap\
    \ lower, Cap upper) {\n        assert(0 <= from and from < n);\n        assert(0\
    \ <= to and to < n);\n        assert(0 <= lower and lower <= upper);\n       \
    \ in[from] -= lower;\n        in[to] += lower;\n        lows.emplace_back(lower);\n\
    \        return graph.add_edge(from, to, upper - lower);\n    }\n\n    Cap flow(int\
    \ s, int t) {\n        assert(0 <= s and s < n);\n        assert(0 <= t and t\
    \ < n);\n        assert(s != t);\n        Cap sum = 0;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (in[i] > 0) graph.add_edge(n, i, in[i]), sum +=\
    \ in[i];\n            if (in[i] < 0) graph.add_edge(i, n + 1, -in[i]);\n     \
    \   }\n        graph.add_edge(t, s, std::numeric_limits<Cap>::max());\n      \
    \  if (graph.flow(n, n + 1) < sum) return -1;\n        return graph.flow(s, t);\n\
    \    }\n\n    typename atcoder::mf_graph<Cap>::edge get_edge(int i) {\n      \
    \  auto res = graph.get_edge(i);\n        res.cap += lows[i];\n        res.flow\
    \ += lows[i];\n        return res;\n    }\n\n    std::vector<typename atcoder::mf_graph<Cap>::edge>\
    \ edges() {\n        std::vector<typename atcoder::mf_graph<Cap>::edge> res;\n\
    \        for (int i = 0; i < int(lows.size()); i++) res.emplace_back(get_edge(i));\n\
    \        return res;\n    }\n\n  private:\n    int n;\n    atcoder::mf_graph<Cap>\
    \ graph;\n    std::vector<Cap> in, lows;\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/maxflow_lowerbound.hpp
  requiredBy: []
  timestamp: '2024-06-24 16:39:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1615.test.cpp
documentation_of: src/optimization/maxflow_lowerbound.hpp
layout: document
title: Max Flow (Lower Bound Constraints)
---

## 概要
流量下限制約付きの最大流を解く．
infeasible な場合は `-1` を返す．

## 出題例
- [AtCoder Beginner Contest 285 G - Tatami](https://atcoder.jp/contests/abc285/tasks/abc285_g)