---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/datastructure/CumulativeSum2D.hpp
    title: "2 \u6B21\u5143\u7D2F\u7A4D\u548C"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B\"\
    \n\n#include \"base.hpp\"\n#include \"datastructure/CumulativeSum2D.hpp\"\n\n\
    const int MAX_X = 1010;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N;\n    cin >> N;\n    vector<vector<int>> v(MAX_X, vector<int>(MAX_X,\
    \ 0));\n    for (; N--;) {\n        int a, b, c, d;\n        cin >> a >> b >>\
    \ c >> d;\n        ++v[a][b];\n        ++v[c][d];\n        --v[a][d];\n      \
    \  --v[c][b];\n    }\n\n    CumulativeSum2D<int> CS(v);\n    int ans = 0;\n  \
    \  for (int i = 0; i < MAX_X; i++) {\n        for (int j = 0; j < MAX_X; j++)\
    \ {\n            ans = max(ans, CS.query(0, i, 0, j));\n        }\n    }\n\n \
    \   cout << ans << '\\n';\n}"
  dependsOn:
  - src/base.hpp
  - src/datastructure/CumulativeSum2D.hpp
  isVerificationFile: true
  path: test/aoj/DSL_5_B.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_5_B.test.cpp
- /verify/test/aoj/DSL_5_B.test.cpp.html
title: test/aoj/DSL_5_B.test.cpp
---
