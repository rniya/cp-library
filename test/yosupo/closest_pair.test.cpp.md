---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/closest_pair.hpp
    title: Closest Pair
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/closest_pair
    links:
    - https://judge.yosupo.jp/problem/closest_pair
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/closest_pair.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/closest_pair\"\n\n#include\
    \ \"geometry/closest_pair.hpp\"\n#include <iostream>\n\nusing namespace geometry;\n\
    \nvoid solve() {\n    int N;\n    std::cin >> N;\n    std::vector<Point<double>>\
    \ P;\n    for (int i = 0; i < N; i++) {\n        int x, y;\n        std::cin >>\
    \ x >> y;\n        P.emplace_back(x, y);\n    }\n\n    auto [i, j, val] = closest_pair(P);\n\
    \    std::cout << i << \" \" << j << \"\\n\";\n}\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int T;\n    std::cin >> T;\n    for\
    \ (; T--;) solve();\n}"
  dependsOn:
  - src/geometry/closest_pair.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/yosupo/closest_pair.test.cpp
  requiredBy: []
  timestamp: '2024-06-18 01:28:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/closest_pair.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/closest_pair.test.cpp
- /verify/test/yosupo/closest_pair.test.cpp.html
title: test/yosupo/closest_pair.test.cpp
---
