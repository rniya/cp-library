---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/wildcard_pattern_matching.hpp
    title: Wildcard Pattern Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/wildcard_pattern_matching
    links:
    - https://judge.yosupo.jp/problem/wildcard_pattern_matching
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/wildcard_pattern_matching.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/wildcard_pattern_matching\"\
    \n\n#include \"string/wildcard_pattern_matching.hpp\"\n#include <iostream>\n\n\
    int main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n  \
    \  std::string S, T;\n    std::cin >> S >> T;\n\n    auto ans = wildcard_pattern_matching(S,\
    \ T, '*');\n    for (auto x : ans) std::cout << x;\n    std::cout << \"\\n\";\n\
    \    return 0;\n}"
  dependsOn:
  - src/string/wildcard_pattern_matching.hpp
  isVerificationFile: true
  path: test/yosupo/wildcard_pattern_matching.test.cpp
  requiredBy: []
  timestamp: '2024-05-26 15:33:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/wildcard_pattern_matching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/wildcard_pattern_matching.test.cpp
- /verify/test/yosupo/wildcard_pattern_matching.test.cpp.html
title: test/yosupo/wildcard_pattern_matching.test.cpp
---
