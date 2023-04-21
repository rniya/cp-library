---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/convolution/set_function.hpp
    title: set function (FZT, FMT, FWHT)
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
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/set_function.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"convolution/set_function.hpp\"\n#include \"util/modint.hpp\"\n\n\
    using mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n    std::vector<mint>\
    \ a(1 << N), b(1 << N);\n    for (int i = 0; i < (1 << N); i++) std::cin >> a[i];\n\
    \    for (int i = 0; i < (1 << N); i++) std::cin >> b[i];\n\n    std::vector<mint>\
    \ c = set_function::xor_convolution(a, b);\n    for (int i = 0; i < (1 << N);\
    \ i++) std::cout << c[i] << (i + 1 == (1 << N) ? '\\n' : ' ');\n    return 0;\n\
    }"
  dependsOn:
  - src/convolution/set_function.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp.html
title: test/yosupo/bitwise_xor_convolution.test.cpp
---
