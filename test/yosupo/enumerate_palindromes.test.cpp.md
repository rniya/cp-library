---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Manacher.hpp
    title: Manacher (Lonegest Palindromic Substring)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Manacher.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include <iostream>\n#include \"string/Manacher.hpp\"\n\nint main() {\n  \
    \  std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    std::string S;\n\
    \    std::cin >> S;\n\n    std::vector<int> ans = PalindromeTable(S);\n    for\
    \ (int i = 0; i < ans.size(); i++) std::cout << ans[i] << (i + 1 == ans.size()\
    \ ? '\\n' : ' ');\n}"
  dependsOn:
  - src/string/Manacher.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_palindromes.test.cpp
- /verify/test/yosupo/enumerate_palindromes.test.cpp.html
title: test/yosupo/enumerate_palindromes.test.cpp
---
