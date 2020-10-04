---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2871.test.cpp
    title: test/aoj/2871.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: dosc/tree/EulerTourforVertex.md
    document_title: "Euler Tour (\u90E8\u5206\u6728\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\
      )"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/EulerTourforVertex.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Euler Tour (\u90E8\u5206\u6728\u306B\u5BFE\u3059\u308B\u64CD\
    \u4F5C)\n * @docs dosc/tree/EulerTourforVertex.md\n */\n\n#pragma once\n\n#include\
    \ \"../base.hpp\"\n\nclass EulerTourforVertex{\n    vector<int> ls,rs;\n    int\
    \ time;\n    void dfs(int v,int p){\n        ls[v]=time++;\n        for (int u:G[v]){\n\
    \            if (u!=p) dfs(u,v);\n        }\n        rs[v]=time;\n    }\npublic:\n\
    \    vector<vector<int>> G;\n    EulerTourforVertex(int n):ls(n),rs(n),G(n){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    void build(int r=0){\n        time=0; dfs(r,-1);\n    }\n    int idx(int\
    \ v){return ls[v];}\n    template<typename F>\n    void exec(int v,F f){\n   \
    \     f(ls[v],rs[v]);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/EulerTourforVertex.hpp
  requiredBy: []
  timestamp: '2020-09-10 12:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2871.test.cpp
documentation_of: tree/EulerTourforVertex.hpp
layout: document
redirect_from:
- /library/tree/EulerTourforVertex.hpp
- /library/tree/EulerTourforVertex.hpp.html
title: "Euler Tour (\u90E8\u5206\u6728\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
---
