---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: Circle
  - icon: ':heavy_check_mark:'
    path: src/geometry/Line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  - icon: ':heavy_check_mark:'
    path: src/geometry/crosspoint.hpp
    title: Crosspoint
  - icon: ':heavy_check_mark:'
    path: src/geometry/projection.hpp
    title: projection
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/crosspoint.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D\"\
    \n#define ERROR 0.000001\n\n#include <algorithm>\n#include <iomanip>\n#include\
    \ \"geometry/crosspoint.hpp\"\n\nusing namespace geometry;\n\nint main() {\n \
    \   std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    std::cout\
    \ << std::fixed << std::setprecision(15);\n    Circle<double> c;\n    std::cin\
    \ >> c;\n    int q;\n    std::cin >> q;\n    for (; q--;) {\n        Line<double>\
    \ l;\n        std::cin >> l;\n        auto res = crosspoint(c, l);\n        if\
    \ (int(res.size()) < 2) res.emplace_back(res[0]);\n        std::sort(begin(res),\
    \ end(res));\n        for (int i = 0; i < 2; i++) std::cout << res[i] << (i +\
    \ 1 == 2 ? '\\n' : ' ');\n    }\n}"
  dependsOn:
  - src/geometry/crosspoint.hpp
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  - src/geometry/ccw.hpp
  - src/geometry/projection.hpp
  - src/geometry/Line.hpp
  isVerificationFile: true
  path: test/aoj/CGL_7_D.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 02:39:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_7_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_D.test.cpp
- /verify/test/aoj/CGL_7_D.test.cpp.html
title: test/aoj/CGL_7_D.test.cpp
---
