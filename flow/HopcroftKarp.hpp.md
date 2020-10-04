---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
    title: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/HopcroftKarp
    document_title: Hopcroft Karp
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/HopcroftKarp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Hopcroft Karp\n * @docs docs/flow/HopcroftKarp\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n\nstruct HopcroftKarp{\nprivate:\n    int\
    \ n,m,time;\n    vector<vector<int>> G,rG;\n    vector<int> match_l,match_r,level,used;\n\
    \    void bfs(){\n        fill(level.begin(),level.end(),-1);\n        queue<int>\
    \ que;\n        for (int i=0;i<n;++i){\n            if (match_l[i]==-1){\n   \
    \             level[i]=0;\n                que.emplace(i);\n            }\n  \
    \      }\n        while(!que.empty()){\n            int v=que.front(); que.pop();\n\
    \            for (int u:G[v]){\n                int w=match_r[u];\n          \
    \      if (~w&&level[w]<0){\n                    level[w]=level[v]+1;\n      \
    \              que.emplace(w);\n                }\n            }\n        }\n\
    \    }\n    bool dfs(int v){\n        used[v]=time;\n        for (int u:G[v]){\n\
    \            int w=match_r[u];\n            if (w<0||(used[w]!=time&&level[w]==level[v]+1&&dfs(w))){\n\
    \                match_r[u]=v; match_l[v]=u;\n                return true;\n \
    \           }\n        }\n        return false;\n    }\npublic:\n    HopcroftKarp(int\
    \ n,int m):n(n),m(m),G(n),rG(m),match_l(n,-1),match_r(m,-1),level(n),used(n){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n\
    \    }\n    vector<pair<int,int>> max_matching(){\n        while(1){\n       \
    \     bfs(); ++time;\n            int f=0;\n            for (int i=0;i<n;++i){\n\
    \                if (match_l[i]<0){\n                    f+=dfs(i);\n        \
    \        }\n            }\n            if (!f) break;\n        }\n        vector<pair<int,int>>\
    \ res;\n        for (int i=0;i<n;++i){\n            if (match_l[i]>=0){\n    \
    \            res.emplace_back(i,match_l[i]);\n            }\n        }\n     \
    \   return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/HopcroftKarp.hpp
  requiredBy: []
  timestamp: '2020-09-12 12:22:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.HopcroftKarp.test.cpp
documentation_of: flow/HopcroftKarp.hpp
layout: document
redirect_from:
- /library/flow/HopcroftKarp.hpp
- /library/flow/HopcroftKarp.hpp.html
title: Hopcroft Karp
---
