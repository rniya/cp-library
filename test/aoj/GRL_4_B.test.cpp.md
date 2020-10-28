---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/TopologicalSort.hpp
    title: Topological Sort
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TopologicalSort.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/TopologicalSort.hpp\"\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V,E;\
    \ cin >> V >> E;\n\n    TopologicalSort TS(V);\n    for (int i=0;i<E;++i){\n \
    \       int s,t; cin >> s >> t;\n        TS.add_edge(s,t);\n    }\n\n    vector<int>\
    \ ans=TS.build();\n    for (int v:ans) cout << v << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/TopologicalSort.hpp
  isVerificationFile: true
  path: test/aoj/GRL_4_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-10 10:46:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_4_B.test.cpp
- /verify/test/aoj/GRL_4_B.test.cpp.html
title: test/aoj/GRL_4_B.test.cpp
---
