---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: datastructure/PartiallyPersistentUnionFind.hpp
    title: Partially Persistent UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/PartiallyPersistentUnionFind.hpp: line 6: #pragma once found in\
    \ a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/PartiallyPersistentUnionFind.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M;\
    \ cin >> N >> M;\n\n    PartiallyPersistentUnionFind UF(N);\n\n    for (int i=0;i<M;++i){\n\
    \        int a,b; cin >> a >> b;\n        UF.merge(--a,--b);\n    }\n\n    int\
    \ Q; cin >> Q;\n    for (;Q--;){\n        int x,y,z; cin >> x >> y >> z; --x,--y;\n\
    \        int lb=0,ub=M+1;\n        while(ub-lb>1){\n            int mid=(ub+lb)>>1;\n\
    \            int s=UF.size(mid,x);\n            if (!UF.same(mid,x,y)) s+=UF.size(mid,y);\n\
    \            (s>=z?ub:lb)=mid;\n        }\n        cout << ub << '\\n';\n    }\n\
    }"
  dependsOn:
  - base.hpp
  - datastructure/PartiallyPersistentUnionFind.hpp
  isVerificationFile: false
  path: test/atcoder/agc002_d.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/agc002_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/agc002_d.cpp
- /library/test/atcoder/agc002_d.cpp.html
title: test/atcoder/agc002_d.cpp
---
