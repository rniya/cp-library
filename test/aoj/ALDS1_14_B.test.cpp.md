---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Hash.hpp
    title: "Hash \u69CB\u9020\u4F53 (reversible)"
  - icon: ':heavy_check_mark:'
    path: src/string/RollingHash.hpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/RollingHash.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B\"\
    \n\n#include \"string/RollingHash.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    std::string T, P;\n    std::cin >>\
    \ T >> P;\n\n    RollingHash RH;\n    auto a = RH.build(T), b = RH.build(P);\n\
    \    int s = T.size(), t = P.size();\n\n    for (int i = 0; i + t <= s; i++) {\n\
    \        if (RH.query(a, i, i + t) == RH.query(b, 0, t)) {\n            std::cout\
    \ << i << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/string/RollingHash.hpp
  - src/string/Hash.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.test.cpp
  requiredBy: []
  timestamp: '2023-10-17 23:13:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.test.cpp
- /verify/test/aoj/ALDS1_14_B.test.cpp.html
title: test/aoj/ALDS1_14_B.test.cpp
---
