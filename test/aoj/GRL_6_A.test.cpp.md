---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/FordFulkerson.hpp
    title: Ford Fulkerson
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/FordFulkerson.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../flow/FordFulkerson.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V,E; cin\
    \ >> V >> E;\n\n    FordFulkerson<int,true> FF(V);\n\n    for (int i=0;i<E;++i){\n\
    \        int u,v,c; cin >> u >> v >> c;\n        FF.add_edge(u,v,c);\n    }\n\n\
    \    cout << FF.max_flow(0,V-1) << '\\n';\n}"
  dependsOn:
  - base.hpp
  - flow/FordFulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
