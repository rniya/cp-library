---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/PotentializedUnionFind.hpp
    title: Potentialized Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/PotentializedUnionFind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include <iostream>\n#include \"datastructure/PotentializedUnionFind.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int n, q;\n    std::cin >> n >> q;\n\n    PotentializedUnionFind<int> UF(n);\n\
    \n    for (; q--;) {\n        int c, x, y, z;\n        std::cin >> c >> x >> y;\n\
    \        if (!c) {\n            std::cin >> z;\n            UF.merge(x, y, z);\n\
    \        } else {\n            if (UF.same(x, y))\n                std::cout <<\
    \ UF.diff(x, y) << '\\n';\n            else\n                std::cout << '?'\
    \ << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - src/datastructure/PotentializedUnionFind.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:12:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---
