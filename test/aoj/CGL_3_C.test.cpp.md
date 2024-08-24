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
    path: src/geometry/Polygon.hpp
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  - icon: ':heavy_check_mark:'
    path: src/geometry/contain.hpp
    title: Contain
  - icon: ':heavy_check_mark:'
    path: src/geometry/crosspoint.hpp
    title: Crosspoint
  - icon: ':heavy_check_mark:'
    path: src/geometry/distance.hpp
    title: Distance
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/contain.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_C\"\
    \n\n#include \"geometry/contain.hpp\"\n\nusing namespace geometry;\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int\
    \ n;\n    std::cin >> n;\n    Polygon<int> P(n);\n    for (auto& p : P) std::cin\
    \ >> p;\n    int q;\n    std::cin >> q;\n    for (; q--;) {\n        Point<int>\
    \ p;\n        std::cin >> p;\n        auto res = contain(P, p);\n        std::cout\
    \ << (res == Containment::IN ? 2 : res == Containment::ON ? 1 : 0) << '\\n';\n\
    \    }\n}"
  dependsOn:
  - src/geometry/contain.hpp
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  - src/geometry/Polygon.hpp
  - src/geometry/ccw.hpp
  - src/geometry/distance.hpp
  - src/geometry/crosspoint.hpp
  - src/geometry/projection.hpp
  - src/geometry/Line.hpp
  isVerificationFile: true
  path: test/aoj/CGL_3_C.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 02:39:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_3_C.test.cpp
- /verify/test/aoj/CGL_3_C.test.cpp.html
title: test/aoj/CGL_3_C.test.cpp
---
