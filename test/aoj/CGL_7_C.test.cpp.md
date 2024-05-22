---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: src/geometry/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/circumcircle.hpp
    title: src/geometry/circumcircle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/circumcircle.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C\"\
    \n#define ERROR 0.000001\n\n#include <iomanip>\n#include \"geometry/circumcircle.hpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    Point<double> a, b, c;\n    std::cin >> a >> b >> c;\n    auto res = circumcircle(a,\
    \ b, c);\n    std::cout << res << '\\n';\n}"
  dependsOn:
  - src/geometry/circumcircle.hpp
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_C.test.cpp
  requiredBy: []
  timestamp: '2023-10-07 00:10:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_C.test.cpp
- /verify/test/aoj/CGL_7_C.test.cpp.html
title: test/aoj/CGL_7_C.test.cpp
---
