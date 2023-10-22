---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: "\u51F8\u5305"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.00000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.6/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/convex_hull.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A\"\
    \n#define ERROR 0.00000001\n\n#include \"geometry/convex_hull.hpp\"\n\nusing namespace\
    \ geometry;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<Point<int>> P(n);\n    for (auto&\
    \ p : P) std::cin >> p;\n    auto res = convex_hull(P, true);\n    int start =\
    \ 0;\n    for (int i = 1; i < int(res.size()); i++) {\n        if (P[res[i]].y\
    \ == P[res[start]].y ? P[res[i]].x < P[res[start]].x : P[res[i]].y < P[res[start]].y)\
    \ {\n            start = i;\n        }\n    }\n    std::rotate(begin(res), begin(res)\
    \ + start, end(res));\n    std::cout << res.size() << '\\n';\n    for (int& i\
    \ : res) std::cout << P[i].x << ' ' << P[i].y << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/geometry/convex_hull.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 02:39:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_A.test.cpp
- /verify/test/aoj/CGL_4_A.test.cpp.html
title: test/aoj/CGL_4_A.test.cpp
---
