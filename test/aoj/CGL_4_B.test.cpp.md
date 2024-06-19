---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/Polygon.hpp
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_diameter.hpp
    title: Convex Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/convex_diameter.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B\"\
    \n#define ERROR 0.000001\n\n#include <iomanip>\n#include \"geometry/convex_diameter.hpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    int n;\n    std::cin >> n;\n    Polygon<double> P(n);\n    for (auto& p :\
    \ P) std::cin >> p;\n    auto [i, j] = convex_diameter(P);\n    auto d = P[i]\
    \ - P[j];\n    double res = std::sqrt(d.x * d.x + d.y * d.y);\n    std::cout <<\
    \ res << '\\n';\n}"
  dependsOn:
  - src/geometry/convex_diameter.hpp
  - src/geometry/Polygon.hpp
  - src/geometry/ccw.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_4_B.test.cpp
  requiredBy: []
  timestamp: '2024-06-20 02:02:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_B.test.cpp
- /verify/test/aoj/CGL_4_B.test.cpp.html
title: test/aoj/CGL_4_B.test.cpp
---
