---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/BipartiteMatching.md
    document_title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/BipartiteMatching.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief 2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\n * @docs docs/flow/BipartiteMatching.md\n */\n\n#pragma once\n\n\
    #include \"../base.hpp\"\n\nstruct BipartiteMatching{\n    vector<vector<int>>\
    \ G;\n    vector<int> match,alive,used;\n    int time=0;\n    BipartiteMatching(int\
    \ n):G(n),match(n,-1),alive(n,1),used(n,0){}\n    void add_edge(int u,int v){\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    bool\
    \ dfs(int v){\n        used[v]=time;\n        for (int u:G[v]){\n            int\
    \ w=match[u];\n            if (!alive[u]) continue;\n            if (w<0||(used[w]!=time&&dfs(w))){\n\
    \                match[v]=u; match[u]=v;\n                return true;\n     \
    \       }\n        }\n        return false;\n    }\n    int build(){\n       \
    \ int res=0;\n        for (int i=0;i<G.size();++i){\n            if (!alive[i])\
    \ continue;\n            if (~match[i]) continue;\n            ++time; res+=dfs(i);\n\
    \        }\n        return res;\n    }\n    int enable(int v){\n        alive[v]=1;\n\
    \        ++time;\n        return dfs(v);\n    }\n    int disable(int v){\n   \
    \     alive[v]=0;\n        if (match[v]<0) return 0;\n        match[v]=-1; match[match[v]]=-1;\n\
    \        ++time;\n        int res=dfs(match[v]);\n        return res-1;\n    }\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
documentation_of: flow/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/flow/BipartiteMatching.hpp
- /library/flow/BipartiteMatching.hpp.html
title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
## 概要
2部グラフの最大マッチングを求める. 基本的にはHopcroft-Karpのアルゴリズムの方が高速なのでそちらを使うのが良い. 頂点番号の振り方に注意.

- `add_edge(u,v)`：$u$と$v$の間に辺を張る.
- `build()`：最大マッチングの大きさを求める.

## 計算量
$O(EV)$