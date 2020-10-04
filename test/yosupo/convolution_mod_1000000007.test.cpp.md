---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/ArbitaryModConvolution.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/ArbitaryModConvolution.hpp\"\
    \n\nusing mint=modint<1000000007>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N,M; cin >> N >> M;\n    vector<mint> a(N),b(M);\n    for (int i=0;i<N;++i)\
    \ cin >> a[i];\n    for (int i=0;i<M;++i) cin >> b[i];\n\n    vector<mint> c=ArbitaryModConvolution(a,b);\n\
    \    for (int i=0;i<N+M-1;++i) cout << c[i] << (i==N+M-2?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/ArbitaryModConvolution.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 23:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
