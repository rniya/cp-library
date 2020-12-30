---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/HopcroftKarp.hpp
    title: Hopcroft Karp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/HopcroftKarp.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../flow/HopcroftKarp.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int L,R,M; cin >> L >>\
    \ R >> M;\n\n    HopcroftKarp HK(L,R);\n    for (;M--;){\n        int a,b; cin\
    \ >> a >> b;\n        HK.add_edge(a,b);\n    }\n\n    auto ans=HK.max_matching();\n\
    \    cout << ans.size() << '\\n';\n    for (auto p:ans) cout << p.first << ' '\
    \ << p.second << '\\n';\n}"
  dependsOn:
  - base.hpp
  - flow/HopcroftKarp.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 19:09:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
