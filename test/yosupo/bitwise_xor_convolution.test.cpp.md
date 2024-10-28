---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/set_function.hpp
    title: Set Function (FZT, FMT, FWHT)
  - icon: ':heavy_check_mark:'
    path: src/util/modint.hpp
    title: modint (input/output)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/set_function.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"math/set_function.hpp\"\n#include \"util/modint.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n   \
    \ std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<mint>\
    \ a(1 << N), b(1 << N);\n    for (int i = 0; i < (1 << N); i++) std::cin >> a[i];\n\
    \    for (int i = 0; i < (1 << N); i++) std::cin >> b[i];\n\n    std::vector<mint>\
    \ c = set_function::xor_convolution(a, b);\n    for (int i = 0; i < (1 << N);\
    \ i++) std::cout << c[i] << (i + 1 == (1 << N) ? '\\n' : ' ');\n    return 0;\n\
    }"
  dependsOn:
  - src/math/set_function.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp.html
title: test/yosupo/bitwise_xor_convolution.test.cpp
---
