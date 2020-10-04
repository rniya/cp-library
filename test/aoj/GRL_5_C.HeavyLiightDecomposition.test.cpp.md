---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/HeavyLightDecomposition.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../tree/HeavyLightDecomposition.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\
    \ cin >> n;\n\n    HeavyLightDecomposition HLD(n);\n    for (int i=0;i<n;++i){\n\
    \        int k; cin >> k;\n        for (;k--;){\n            int c; cin >> c;\n\
    \            HLD.add_edge(i,c);\n        }\n    }\n    HLD.build();\n\n    int\
    \ q; cin >> q;\n    for (;q--;){\n        int u,v; cin >> u >> v;\n        cout\
    \ << HLD.lca(u,v) << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
- /verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp.html
title: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
---
