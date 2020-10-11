---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/HopcroftKarp.hpp
    title: Hopcroft Karp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/HopcroftKarp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../flow/HopcroftKarp.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int X,Y,E; cin >> X >>\
    \ Y >> E;\n\n    HopcroftKarp HK(X,Y);\n    for (int i=0;i<E;++i){\n        int\
    \ x,y; cin >> x >> y;\n        HK.add_edge(x,y);\n    }\n\n    cout << HK.max_matching().size()\
    \ << '\\n';\n}"
  dependsOn:
  - base.hpp
  - flow/HopcroftKarp.hpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 12:22:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.HopcroftKarp.test.cpp
- /verify/test/aoj/GRL_7_A.HopcroftKarp.test.cpp.html
title: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
---
