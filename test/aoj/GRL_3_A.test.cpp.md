---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/LowLink.hpp
    title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/LowLink.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/LowLink.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V,E; cin >> V >> E;\n\
    \n    LowLink L(V);\n    for (int i=0;i<E;++i){\n        int s,t; cin >> s >>\
    \ t;\n        L.add_edge(s,t);\n    }\n\n    L.build();\n    vector<int> ans=L.articulation;\n\
    \    sort(ans.begin(),ans.end());\n    for (int v:ans) cout << v << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/LowLink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-10 10:46:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_3_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_A.test.cpp
- /verify/test/aoj/GRL_3_A.test.cpp.html
title: test/aoj/GRL_3_A.test.cpp
---
