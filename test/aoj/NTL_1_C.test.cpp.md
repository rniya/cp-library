---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binary_gcd.hpp
    title: binary gcd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/binary_gcd.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_C\"\
    \n\n#include <iostream>\n#include \"math/binary_gcd.hpp\"\n\nint main() {\n  \
    \  std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int n;\n    std::cin\
    \ >> n;\n    int ans = 1;\n    for (; n--;) {\n        int a;\n        std::cin\
    \ >> a;\n        ans = ans * a / binary_gcd(ans, a);\n    }\n    std::cout <<\
    \ ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/math/binary_gcd.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-05-24 23:58:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_C.test.cpp
- /verify/test/aoj/NTL_1_C.test.cpp.html
title: test/aoj/NTL_1_C.test.cpp
---
