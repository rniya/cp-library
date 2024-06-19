---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/ccw.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#include \"geometry/ccw.hpp\"\n\nusing namespace geometry;\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    Point<long\
    \ long> a, b;\n    std::cin >> a >> b;\n    int q;\n    std::cin >> q;\n    for\
    \ (; q--;) {\n        Point<long long> c;\n        std::cin >> c;\n        int\
    \ res = ccw(a, b, c);\n        if (res == 1)\n            std::cout << \"COUNTER_CLOCKWISE\"\
    \ << '\\n';\n        else if (res == -1)\n            std::cout << \"CLOCKWISE\"\
    \ << '\\n';\n        else if (res == 2)\n            std::cout << \"ONLINE_BACK\"\
    \ << '\\n';\n        else if (res == -2)\n            std::cout << \"ONLINE_FRONT\"\
    \ << '\\n';\n        else\n            std::cout << \"ON_SEGMENT\" << '\\n';\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - src/geometry/ccw.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 02:39:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_C.test.cpp
- /verify/test/aoj/CGL_1_C.test.cpp.html
title: test/aoj/CGL_1_C.test.cpp
---
