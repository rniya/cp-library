---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../atcoder/convolution\"\n\ntemplate <class mint>\n\
    std::vector<mint> convolution_arbitary_mod(const std::vector<mint>& a, const std::vector<mint>&\
    \ b) {\n    int n = a.size(), m = b.size();\n    if (n == 0 or m == 0) return\
    \ {};\n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n  \
    \  static constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static\
    \ constexpr unsigned long long MOD3 = 469762049;  // 2^26\n    using mint1 = atcoder::static_modint<MOD1>;\n\
    \    using mint2 = atcoder::static_modint<MOD2>;\n    using mint3 = atcoder::static_modint<MOD3>;\n\
    \n    const mint2 i1 = mint2(MOD1).inv();\n    const mint3 i2 = mint3(MOD2).inv();\n\
    \    const mint3 i1i2 = mint3(MOD1).inv() * i2;\n    const mint m1 = MOD1, m1m2\
    \ = m1 * MOD2;\n\n    std::vector<mint1> a1(n), b1(m);\n    std::vector<mint2>\
    \ a2(n), b2(m);\n    std::vector<mint3> a3(n), b3(m);\n    for (int i = 0; i <\
    \ n; i++) {\n        a1[i] = a[i].val();\n        a2[i] = a[i].val();\n      \
    \  a3[i] = a[i].val();\n    }\n    for (int i = 0; i < m; i++) {\n        b1[i]\
    \ = b[i].val();\n        b2[i] = b[i].val();\n        b3[i] = b[i].val();\n  \
    \  }\n    auto c1 = convolution(a1, b1);\n    auto c2 = convolution(a2, b2);\n\
    \    auto c3 = convolution(a3, b3);\n\n    std::vector<mint> c(n + m - 1);\n \
    \   for (int i = 0; i < n + m - 1; i++) {\n        int v1 = c1[i].val();\n   \
    \     int v2 = (i1 * (c2[i] - v1)).val();\n        int v3 = (i1i2 * (c3[i] - v1)\
    \ - i2 * v2).val();\n        c[i] = v1 + m1 * v2 + m1m2 * v3;\n    }\n\n    return\
    \ c;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/convolution_arbitary_mod.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod_1000000007.test.cpp
documentation_of: src/math/convolution_arbitary_mod.hpp
layout: document
title: "\u4EFB\u610F mod \u7573\u307F\u8FBC\u307F"
---
