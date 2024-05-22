---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: Convex Hull
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geometry/convex_hull.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_convex_hull\"\n\n\
    #include <iostream>\n#include \"geometry/convex_hull.hpp\"\n\nusing namespace\
    \ geometry;\n\nvoid solve() {\n    int N;\n    std::cin >> N;\n    std::vector<Point<long\
    \ long>> P;\n    for (int i = 0; i < N; i++) {\n        int x, y;\n        std::cin\
    \ >> x >> y;\n        P.emplace_back(x, y);\n    }\n\n    auto res = convex_hull(P);\n\
    \    std::cout << res.size() << \"\\n\";\n    for (int i : res) std::cout << P[i].x\
    \ << \" \" << P[i].y << \"\\n\";\n}\n\nint main() {\n    std::cin.tie(0);\n  \
    \  std::ios::sync_with_stdio(false);\n    int T;\n    std::cin >> T;\n    for\
    \ (; T--;) solve();\n    return 0;\n}"
  dependsOn:
  - src/geometry/convex_hull.hpp
  - src/geometry/Point.hpp
  isVerificationFile: true
  path: test/yosupo/static_convex_hull.test.cpp
  requiredBy: []
  timestamp: '2024-05-22 03:00:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_convex_hull.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_convex_hull.test.cpp
- /verify/test/yosupo/static_convex_hull.test.cpp.html
title: test/yosupo/static_convex_hull.test.cpp
---
