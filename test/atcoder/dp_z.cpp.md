---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/ConvexHullTrick.hpp
    title: Convex Hull Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/dp/tasks/dp_z
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/ConvexHullTrick.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/dp/tasks/dp_z\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/ConvexHullTrick.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\
    \ long long C; cin >> N >> C;\n    vector<long long> h(N);\n    for (int i=0;i<N;++i)\
    \ cin >> h[i];\n\n    ConvexHullTrick<long long> CHT;\n\n    vector<long long>\
    \ dp(N,0);\n    for (int i=0;i<N;++i){\n        if (i) dp[i]=CHT.query_monotone_inc(h[i])+h[i]*h[i]+C;\n\
    \        CHT.add(-2*h[i],h[i]*h[i]+dp[i]);\n    }\n\n    cout << dp[N-1] << '\\\
    n';\n}"
  dependsOn:
  - base.hpp
  - datastructure/ConvexHullTrick.hpp
  isVerificationFile: false
  path: test/atcoder/dp_z.cpp
  requiredBy: []
  timestamp: '2020-09-20 00:58:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/dp_z.cpp
layout: document
redirect_from:
- /library/test/atcoder/dp_z.cpp
- /library/test/atcoder/dp_z.cpp.html
title: test/atcoder/dp_z.cpp
---
