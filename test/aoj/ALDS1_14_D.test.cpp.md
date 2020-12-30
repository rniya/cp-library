---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/SuffixArray.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_D\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../string/SuffixArray.hpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string T; int\
    \ Q; cin >> T >> Q;\n\n    SuffixArray SA(T);\n\n    for (;Q--;){\n        string\
    \ P; cin >> P;\n        cout << (SA.count(P)>0) << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - string/SuffixArray.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_D.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_D.test.cpp
- /verify/test/aoj/ALDS1_14_D.test.cpp.html
title: test/aoj/ALDS1_14_D.test.cpp
---
