---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../base.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../geometry/geometry.hpp\"\n\n\
    using namespace geometry;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    Point p_0, p_1;\n    cin >> p_0 >> p_1;\n    int q;\n    cin >> q;\n    for\
    \ (; q--;) {\n        Point p_2;\n        cin >> p_2;\n        int res = ccw(p_0,\
    \ p_1, p_2);\n        if (res == 1)\n            cout << \"COUNTER_CLOCKWISE\"\
    \ << '\\n';\n        else if (res == -1)\n            cout << \"CLOCKWISE\" <<\
    \ '\\n';\n        else if (res == 2)\n            cout << \"ONLINE_BACK\" << '\\\
    n';\n        else if (res == -2)\n            cout << \"ONLINE_FRONT\" << '\\\
    n';\n        else\n            cout << \"ON_SEGMENT\" << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_1_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_1_C.test.cpp
- /verify/test/aoj/CGL_1_C.test.cpp.html
title: test/aoj/CGL_1_C.test.cpp
---
