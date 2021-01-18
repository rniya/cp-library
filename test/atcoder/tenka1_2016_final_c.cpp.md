---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: string/Trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Trie.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/tenka1-2016-final-open/tasks/tenka1_2016_final_c\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../string/Trie.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string S; int M; cin >>\
    \ S >> M;\n    vector<string> P(M);\n    vector<int> W(M);\n    for (int i=0;i<M;++i)\
    \ cin >> P[i];\n    for (int i=0;i<M;++i) cin >> W[i];\n\n    Trie<26> trie([](char\
    \ c){return c-'a';});\n    for (int i=0;i<M;++i) trie.add(P[i],i);\n    int n=S.size();\n\
    \    vector<int> dp(n+1,0);\n\n    for (int i=0;i<n;++i){\n        dp[i+1]=max(dp[i+1],dp[i]);\n\
    \        auto f=[&](int idx){\n            dp[i+P[idx].size()]=max(dp[i+P[idx].size()],dp[i]+W[idx]);\n\
    \        };\n        trie.query(S,f,i);\n    }\n    cout << dp[n] << '\\n';\n}"
  dependsOn:
  - base.hpp
  - string/Trie.hpp
  isVerificationFile: false
  path: test/atcoder/tenka1_2016_final_c.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/tenka1_2016_final_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/tenka1_2016_final_c.cpp
- /library/test/atcoder/tenka1_2016_final_c.cpp.html
title: test/atcoder/tenka1_2016_final_c.cpp
---
