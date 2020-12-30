---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/combination.hpp
    title: combination
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../combinatorics/combination.hpp\"\n\nusing mint=modint<1000000007>;\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    Combination<mint>\
    \ COM(1010);\n    int n,k; cin >> n >> k;\n\n    cout << COM.P(k,n) << '\\n';\n\
    }"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - combinatorics/combination.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_B.test.cpp
  requiredBy: []
  timestamp: '2020-11-19 21:51:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_B.test.cpp
- /verify/test/aoj/DPL_5_B.test.cpp.html
title: test/aoj/DPL_5_B.test.cpp
---
