---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/gcd_convolution.hpp
    title: GCD Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/gcd_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"convolution/gcd_convolution.hpp\"\n#include <iostream>\n#include \"atcoder/modint\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<mint>\
    \ a(N + 1), b(N + 1);\n    for (int i = 1; i <= N; i++) {\n        int val;\n\
    \        std::cin >> val;\n        a[i] = val;\n    }\n    for (int i = 1; i <=\
    \ N; i++) {\n        int val;\n        std::cin >> val;\n        b[i] = val;\n\
    \    }\n\n    auto c = gcd_convolution(a, b);\n    for (int i = 1; i <= N; i++)\
    \ std::cout << c[i].val() << (i == N ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/convolution/gcd_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-24 04:02:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_convolution.test.cpp
- /verify/test/yosupo/gcd_convolution.test.cpp.html
title: test/yosupo/gcd_convolution.test.cpp
---
