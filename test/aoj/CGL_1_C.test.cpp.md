---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/geometry.hpp
    title: "2 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#include \"base.hpp\"\n#include \"geometry/geometry.hpp\"\n\nusing namespace\
    \ geometry;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    Point p_0, p_1;\n    cin >> p_0 >> p_1;\n    int q;\n    cin >> q;\n    for\
    \ (; q--;) {\n        Point p_2;\n        cin >> p_2;\n        int res = ccw(p_0,\
    \ p_1, p_2);\n        if (res == 1)\n            cout << \"COUNTER_CLOCKWISE\"\
    \ << '\\n';\n        else if (res == -1)\n            cout << \"CLOCKWISE\" <<\
    \ '\\n';\n        else if (res == 2)\n            cout << \"ONLINE_BACK\" << '\\\
    n';\n        else if (res == -2)\n            cout << \"ONLINE_FRONT\" << '\\\
    n';\n        else\n            cout << \"ON_SEGMENT\" << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - src/base.hpp
  - src/geometry/geometry.hpp
  isVerificationFile: true
  path: test/aoj/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '2023-02-14 22:43:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_C.test.cpp
- /verify/test/aoj/CGL_1_C.test.cpp.html
title: test/aoj/CGL_1_C.test.cpp
---
