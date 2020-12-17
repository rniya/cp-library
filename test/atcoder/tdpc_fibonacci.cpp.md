---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  - icon: ':warning:'
    path: polynomial/Kitamasa.hpp
    title: Kitamasa
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../polynomial/Kitamasa.hpp\"\n\nusing mint=modint<1000000007>;\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int K,N; cin >> K >> N;\n\
    \n    vector<mint> A(K,1);\n    Kitamasa<mint> Ki(A);\n\n    cout << Ki.calc(A,--N)\
    \ << endl;\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - polynomial/Kitamasa.hpp
  isVerificationFile: false
  path: test/atcoder/tdpc_fibonacci.cpp
  requiredBy: []
  timestamp: '2020-11-19 21:51:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/tdpc_fibonacci.cpp
layout: document
redirect_from:
- /library/test/atcoder/tdpc_fibonacci.cpp
- /library/test/atcoder/tdpc_fibonacci.cpp.html
title: test/atcoder/tdpc_fibonacci.cpp
---
