---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/subset_convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/subset_convolution.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\n\
    #include \"convolution/subset_convolution.hpp\"\n#include <iostream>\n#include\
    \ \"atcoder/modint\"\n\nusing mint = atcoder::modint998244353;\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int N;\n\
    \    std::cin >> N;\n    std::vector<mint> a(1 << N), b(1 << N);\n    for (int\
    \ i = 0; i < 1 << N; i++) {\n        int x;\n        std::cin >> x;\n        a[i]\
    \ = mint::raw(x);\n    }\n    for (int i = 0; i < 1 << N; i++) {\n        int\
    \ x;\n        std::cin >> x;\n        b[i] = mint::raw(x);\n    }\n\n    auto\
    \ c = subset_convolution(a, b);\n    for (int i = 0; i < 1 << N; i++) std::cout\
    \ << c[i].val() << (i + 1 == (1 << N) ? '\\n' : ' ');\n}"
  dependsOn:
  - src/convolution/subset_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/subset_convolution.test.cpp
  requiredBy: []
  timestamp: '2024-06-24 04:02:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/subset_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/subset_convolution.test.cpp
- /verify/test/yosupo/subset_convolution.test.cpp.html
title: test/yosupo/subset_convolution.test.cpp
---
