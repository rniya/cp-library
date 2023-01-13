---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/base.hpp: line 7: unable to process #include in #if / #ifdef / #ifndef other\
    \ than include guards\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T> struct Dijkstra\
    \ {\n    struct edge {\n        int to;\n        T cost;\n        edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n        bool operator<(const edge& e) const\
    \ { return cost > e.cost; }\n    };\n    vector<vector<edge>> G;\n    vector<T>\
    \ dp;\n    vector<int> pre;\n    Dijkstra(int n) : G(n), dp(n), pre(n) {}\n  \
    \  void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }\n    vector<T>\
    \ build(int s) {\n        int n = G.size();\n        fill(dp.begin(), dp.end(),\
    \ numeric_limits<T>::max());\n        fill(pre.begin(), pre.end(), -1);\n    \
    \    priority_queue<edge> pq;\n        dp[s] = 0;\n        pq.emplace(s, dp[s]);\n\
    \        while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.to;\n            if (dp[v] < p.cost) continue;\n      \
    \      for (auto e : G[v]) {\n                if (dp[v] + e.cost < dp[e.to]) {\n\
    \                    dp[e.to] = dp[v] + e.cost;\n                    pre[e.to]\
    \ = v;\n                    pq.emplace(e.to, dp[e.to]);\n                }\n \
    \           }\n        }\n        return dp;\n    }\n    vector<int> restore(int\
    \ t) {\n        vector<int> res;\n        if (pre[t] < 0) return res;\n      \
    \  while (~t) {\n            res.emplace_back(t);\n            t = pre[t];\n \
    \       }\n        reverse(res.begin(), res.end());\n        return res;\n   \
    \ }\n    T operator[](int to) { return dp[to]; }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
documentation_of: src/graph/Dijkstra.hpp
layout: document
title: Dijkstra
---

## 概要
