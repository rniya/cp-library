---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/CentroidDecomposition.md
    document_title: Centroid Decomposition
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/CentroidDecomposition.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Centroid Decomposition\n * @docs docs/tree/CentroidDecomposition.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nclass CentroidDecomposition{\n\
    \    vector<vector<int>> G;\n    vector<int> sub,centroid;\n    inline int dfs(int\
    \ v,int p){\n        sub[v]=1;\n        for (int u:G[v]){\n            if (u==p||centroid[u])\
    \ continue;\n            sub[v]+=dfs(u,v);\n        }\n        return sub[v];\n\
    \    }\n    inline int find(int v,int p,int mid){\n        for (int u:G[v]){\n\
    \            if (u==p||centroid[u]) continue;\n            if (sub[u]>mid) return\
    \ find(u,v,mid);\n        }\n        return v;\n    }\npublic:\n    CentroidDecomposition(int\
    \ n):G(n),sub(n),centroid(n){}\n    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    int build(int r){return find(r,-1,dfs(r,-1)>>1);}\n\
    \    void disable(int v){centroid[v]=true;}\n    void enable(int v){centroid[v]=false;}\n\
    \    int alive(int v){return !centroid[v];}\n    const vector<int> &operator[](int\
    \ v) const {return G[v];}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/CentroidDecomposition.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: tree/CentroidDecomposition.hpp
layout: document
redirect_from:
- /library/tree/CentroidDecomposition.hpp
- /library/tree/CentroidDecomposition.hpp.html
title: Centroid Decomposition
---
## 概要

## 計算量