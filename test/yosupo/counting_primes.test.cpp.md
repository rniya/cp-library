---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/math/counting_primes.hpp
    title: Counting Primes
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/counting_primes.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"math/counting_primes.hpp\"\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\n    long long\
    \ N;\n    std::cin >> N;\n\n    std::cout << counting_primes(N) << \"\\n\";\n\
    \    return 0;\n}"
  dependsOn:
  - src/math/counting_primes.hpp
  isVerificationFile: true
  path: test/yosupo/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2024-08-25 02:56:03+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/counting_primes.test.cpp
- /verify/test/yosupo/counting_primes.test.cpp.html
title: test/yosupo/counting_primes.test.cpp
---
