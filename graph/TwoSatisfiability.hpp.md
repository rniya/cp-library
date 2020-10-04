---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/TwoSatisfiability
    document_title: 2-SAT
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TwoSatisfiability.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief 2-SAT\n * @docs docs/graph/TwoSatisfiability\n */\n\n#pragma\
    \ once\n\n#include \"../base.hpp\"\n#include \"StronglyConnectedComponents.hpp\"\
    \n\nstruct TwoSatisfiability{\n    int n;\n    StronglyConnectedComponents SCC;\n\
    \    TwoSatisfiability(int n):n(n),SCC(n*2){}\n    int neg(int v){return (n+v)%(n*2);}\n\
    \    void add_if(int u,int v){\n        SCC.add_edge(u,v);\n        SCC.add_edge(neg(v),neg(u));\n\
    \    }\n    void add_or(int u,int v){\n        add_if(neg(u),v);\n    }\n    void\
    \ add_nand(int u,int v){\n        add_if(u,neg(v));\n    }\n    void set_true(int\
    \ v){\n        SCC.add_edge(neg(v),v);\n    }\n    void set_false(int v){\n  \
    \      SCC.add_edge(v,neg(v));\n    }\n    vector<int> build(){\n        SCC.build();\n\
    \        vector<int> res(n);\n        for (int i=0;i<n;++i){\n            if (SCC[i]==SCC[n+i])\
    \ return {};\n            res[i]=SCC[i]>SCC[n+i];\n        }\n        return res;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: graph/TwoSatisfiability.hpp
  requiredBy: []
  timestamp: '2020-09-10 12:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/TwoSatisfiability.hpp
layout: document
redirect_from:
- /library/graph/TwoSatisfiability.hpp
- /library/graph/TwoSatisfiability.hpp.html
title: 2-SAT
---
