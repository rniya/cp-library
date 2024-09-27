---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/convolution_arbitary_mod.hpp
    title: Convolution (Arbitary mod)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/convolution_arbitary_mod.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include <iostream>\n#include \"convolution/convolution_arbitary_mod.hpp\"\
    \n\nusing mint = atcoder::modint1000000007;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, M;\n    std::cin >> N >> M;\n    std::vector<mint>\
    \ a(N), b(M);\n    for (int i = 0; i < N; i++) {\n        int x;\n        std::cin\
    \ >> x;\n        a[i] = x;\n    }\n    for (int i = 0; i < M; i++) {\n       \
    \ int x;\n        std::cin >> x;\n        b[i] = x;\n    }\n\n    auto c = convolution_arbitary_mod(a,\
    \ b);\n    for (int i = 0; i < N + M - 1; i++) std::cout << c[i].val() << (i +\
    \ 1 == N + M - 1 ? '\\n' : ' ');\n}"
  dependsOn:
  - src/convolution/convolution_arbitary_mod.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
