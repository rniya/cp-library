---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/XORconvolution.hpp
    title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../convolution/XORconvolution.hpp\"\n\nusing mint=modint<998244353>;\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N; cin\
    \ >> N;\n    vector<mint> a(1<<N),b(1<<N);\n    for (int i=0;i<(1<<N);++i) cin\
    \ >> a[i];\n    for (int i=0;i<(1<<N);++i) cin >> b[i];\n\n    vector<mint> c=XOR_convolution(a,b);\n\
    \    for (int i=0;i<(1<<N);++i) cout << c[i] << (i+1==(1<<N)?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - convolution/XORconvolution.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 20:12:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp.html
title: test/yosupo/bitwise_xor_convolution.test.cpp
---
