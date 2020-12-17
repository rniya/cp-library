---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SlidingWindowAggregation.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SlidingWindowAggregation.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,L;\
    \ cin >> N >> L;\n    vector<int> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    SlidingWindowAggregation<int> SWAG([](int a,int b){return min(a,b);},INT_MAX);\n\
    \n    for (int i=0;i<L-1;++i) SWAG.push(a[i]);\n    for (int i=L-1;i<N;++i){\n\
    \        SWAG.push(a[i]);\n        cout << SWAG.fold() << (i+1==N?'\\n':' ');\n\
    \        SWAG.pop();\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SlidingWindowAggregation.hpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 22:21:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
- /verify/test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp.html
title: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
---
