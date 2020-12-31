---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: graph/RangeEdgeGraph.hpp
    title: graph/RangeEdgeGraph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/RangeEdgeGraph.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/RangeEdgeGraph.hpp\"\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M;\
    \ cin >> N >> M;\n\n    RangeEdgeGraph<long long> REG(N);\n    for (;M--;){\n\
    \        int L,R,C; cin >> L >> R >> C; --L;\n        REG.add_edge(L,R,L,R,C);\n\
    \    }\n\n    long long ans=REG.build(0)[N-1];\n    cout << (ans>1e15?-1:ans)\
    \ << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/RangeEdgeGraph.hpp
  isVerificationFile: false
  path: test/atcoder/nikkei2019_2_qual_d.cpp
  requiredBy: []
  timestamp: '2020-12-31 12:31:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/nikkei2019_2_qual_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/nikkei2019_2_qual_d.cpp
- /library/test/atcoder/nikkei2019_2_qual_d.cpp.html
title: test/atcoder/nikkei2019_2_qual_d.cpp
---
