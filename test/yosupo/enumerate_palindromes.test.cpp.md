---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/Manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Manacher.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../string/Manacher.hpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string S; cin\
    \ >> S;\n\n    vector<int> ans=PalindromeTable(S);\n    for (int i=0;i<ans.size();++i)\
    \ cout << ans[i] << (i+1==ans.size()?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - string/Manacher.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 21:12:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_palindromes.test.cpp
- /verify/test/yosupo/enumerate_palindromes.test.cpp.html
title: test/yosupo/enumerate_palindromes.test.cpp
---
