---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/string/RollingHash2D.hpp
    title: Rolling Hash 2D
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C\"\n\
    \n#include \"base.hpp\"\n#include \"string/RollingHash2D.hpp\"\n\nint main() {\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int H, W;\n    cin >>\
    \ H >> W;\n    vector<string> S(H);\n    for (auto& s : S) cin >> s;\n    int\
    \ R, C;\n    cin >> R >> C;\n    vector<string> T(R);\n    for (auto& t : T) cin\
    \ >> t;\n\n    RollingHash2D RH;\n    auto a = RH.build(S);\n    auto correct\
    \ = RH.get(T);\n\n    for (int i = 0; i + R <= H; i++) {\n        for (int j =\
    \ 0; j + C <= W; j++) {\n            if (RH.query(a, i, i + R, j, j + C) == correct)\
    \ {\n                cout << i << ' ' << j << '\\n';\n            }\n        }\n\
    \    }\n    return 0;\n}"
  dependsOn:
  - src/base.hpp
  - src/string/RollingHash2D.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_C.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_C.test.cpp
- /verify/test/aoj/ALDS1_14_C.test.cpp.html
title: test/aoj/ALDS1_14_C.test.cpp
---
