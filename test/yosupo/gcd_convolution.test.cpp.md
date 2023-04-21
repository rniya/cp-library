---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/convolution/gcd_convolution.hpp
    title: "$\\gcd$ convolution\uFF08\u6DFB\u5B57 $\\gcd$ \u7573\u307F\u8FBC\u307F\
      \uFF09"
  - icon: ':question:'
    path: src/util/modint.hpp
    title: src/util/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_convolution
    links:
    - https://judge.yosupo.jp/problem/gcd_convolution
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/gcd_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_convolution\"\n\n#include\
    \ \"convolution/gcd_convolution.hpp\"\n#include <iostream>\n#include \"util/modint.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<mint>\
    \ a(N + 1), b(N + 1);\n    for (int i = 1; i <= N; i++) std::cin >> a[i];\n  \
    \  for (int i = 1; i <= N; i++) std::cin >> b[i];\n\n    auto c = gcd_convolution::gcd_convolution(a,\
    \ b);\n    for (int i = 1; i <= N; i++) std::cout << c[i] << (i == N ? '\\n' :\
    \ ' ');\n    return 0;\n}"
  dependsOn:
  - src/convolution/gcd_convolution.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/gcd_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/gcd_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_convolution.test.cpp
- /verify/test/yosupo/gcd_convolution.test.cpp.html
title: test/yosupo/gcd_convolution.test.cpp
---
