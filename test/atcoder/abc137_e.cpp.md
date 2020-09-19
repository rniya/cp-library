---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/BellmanFord.hpp
    title: Bellman Ford
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/abc137/tasks/abc137_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/BellmanFord.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/abc137/tasks/abc137_e\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/BellmanFord.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M,P;\
    \ cin >> N >> M >> P;\n\n    BellmanFord<int> BF(N);\n    for (int i=0;i<M;++i){\n\
    \        int A,B,C; cin >> A >> B >> C;\n        BF.add_edge(--A,--B,P-C);\n \
    \   }\n\n    int neg;\n    int ans=BF.shortest_path(0,N-1,neg);\n    cout << (neg?-1:max(0,-ans))\
    \ << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/BellmanFord.hpp
  isVerificationFile: false
  path: test/atcoder/abc137_e.cpp
  requiredBy: []
  timestamp: '2020-09-20 00:58:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc137_e.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc137_e.cpp
- /library/test/atcoder/abc137_e.cpp.html
title: test/atcoder/abc137_e.cpp
---
