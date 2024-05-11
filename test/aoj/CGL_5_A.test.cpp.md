---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: "Point \u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: src/geometry/closest_pair.hpp
    title: "\u6700\u8FD1\u70B9\u5BFE"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    ERROR: '0.000001'
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/closest_pair.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A\"\
    \n#define ERROR 0.000001\n\n#include <iomanip>\n#include \"geometry/closest_pair.hpp\"\
    \n\nusing namespace geometry;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    std::cout << std::fixed << std::setprecision(15);\n\
    \    int n;\n    std::cin >> n;\n    std::vector<Point<double>> ps(n);\n    for\
    \ (auto& p : ps) std::cin >> p;\n    auto res = std::get<2>(closest_pair(ps));\n\
    \    std::cout << res << '\\n';\n}"
  dependsOn:
  - src/geometry/closest_pair.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/aoj/CGL_5_A.test.cpp
  requiredBy: []
  timestamp: '2023-10-04 02:39:30+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_5_A.test.cpp
- /verify/test/aoj/CGL_5_A.test.cpp.html
title: test/aoj/CGL_5_A.test.cpp
---
