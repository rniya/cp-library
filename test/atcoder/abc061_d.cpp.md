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
    links:
    - https://atcoder.jp/contests/abc137/tasks/abc137_e
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/BellmanFord.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/abc137/tasks/abc137_e\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/BellmanFord.hpp\"\n\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M; cin\
    \ >> N >> M;\n\n    BellmanFord<long long> BF(N);\n    for (int i=0;i<M;++i){\n\
    \        int a,b,c; cin >> a >> b >> c;\n        BF.add_edge(--a,--b,-c);\n  \
    \  }\n\n    int neg;\n    long long ans=BF.shortest_path(0,N-1,neg);\n    if (neg)\
    \ cout << \"inf\" << '\\n';\n    else cout << -ans << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/BellmanFord.hpp
  isVerificationFile: false
  path: test/atcoder/abc061_d.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/abc061_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/abc061_d.cpp
- /library/test/atcoder/abc061_d.cpp.html
title: test/atcoder/abc061_d.cpp
---
