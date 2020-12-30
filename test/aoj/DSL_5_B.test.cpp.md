---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/CumulativeSum2D.hpp
    title: "2\u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/CumulativeSum2D.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/CumulativeSum2D.hpp\"\
    \n\nconst int MAX_X=1010;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N; cin >> N;\n    vector<vector<int>> v(MAX_X,vector<int>(MAX_X,0));\n\
    \    for (;N--;){\n        int a,b,c,d; cin >> a >> b >> c >> d;\n        ++v[a][b];\
    \ ++v[c][d]; --v[a][d]; --v[c][b];\n    }\n\n    CumulativeSum2D<int> CS(v);\n\
    \    int ans=0;\n    for (int i=0;i<MAX_X;++i){\n        for (int j=0;j<MAX_X;++j){\n\
    \            ans=max(ans,CS.query(0,i,0,j));\n        }\n    }\n\n    cout <<\
    \ ans << '\\n';\n}"
  dependsOn:
  - base.hpp
  - datastructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: test/aoj/DSL_5_B.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_5_B.test.cpp
- /verify/test/aoj/DSL_5_B.test.cpp.html
title: test/aoj/DSL_5_B.test.cpp
---
