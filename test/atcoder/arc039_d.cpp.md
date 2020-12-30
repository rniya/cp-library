---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/TwoEdgeConnectedComponents.hpp
    title: Two Edge Connected Components
  - icon: ':heavy_check_mark:'
    path: tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc039/tasks/arc039_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TwoEdgeConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/arc039/tasks/arc039_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/TwoEdgeConnectedComponents.hpp\"\
    \n#include \"../../tree/LowestCommonAncestor.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N,M; cin >> N >> M;\n\n    TwoEdgeConnectedComponents\
    \ TECC(N);\n    for (int i=0;i<M;++i){\n        int X,Y; cin >> X >> Y;\n    \
    \    TECC.add_edge(--X,--Y);\n    }\n    int n=TECC.build();\n\n    LowestCommonAncestor\
    \ LCA(n);\n    for (int v=0;v<n;++v){\n        for (int u:TECC.T[v]){\n      \
    \      if (v<u) LCA.add_edge(v,u);\n        }\n    }\n    LCA.build();\n\n   \
    \ int Q; cin >> Q;\n    for (;Q--;){\n        int A,B,C; cin >> A >> B >> C;\n\
    \        A=TECC[--A],B=TECC[--B],C=TECC[--C];\n        cout << (LCA.distance(A,C)==LCA.distance(A,B)+LCA.distance(B,C)?\"\
    OK\":\"NG\") << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/TwoEdgeConnectedComponents.hpp
  - tree/LowestCommonAncestor.hpp
  isVerificationFile: false
  path: test/atcoder/arc039_d.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/arc039_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/arc039_d.cpp
- /library/test/atcoder/arc039_d.cpp.html
title: test/atcoder/arc039_d.cpp
---
