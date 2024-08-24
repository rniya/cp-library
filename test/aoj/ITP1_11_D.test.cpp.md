---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/util/Dice.hpp
    title: Dice
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: util/Dice.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D\"\n\
    \n#include <iostream>\n#include <set>\n#include \"util/Dice.hpp\"\n\nint main()\
    \ {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int n;\n\
    \    std::cin >> n;\n    std::set<Dice> s;\n    std::vector<int> v(6);\n    for\
    \ (size_t i = 0; i < n; i++) {\n        for (int j = 0; j < 6; j++) std::cin >>\
    \ v[j];\n        Dice d(v);\n        s.emplace(d.identifier());\n    }\n    std::cout\
    \ << (s.size() == n ? \"Yes\" : \"No\") << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/util/Dice.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_D.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:12:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_D.test.cpp
- /verify/test/aoj/ITP1_11_D.test.cpp.html
title: test/aoj/ITP1_11_D.test.cpp
---
