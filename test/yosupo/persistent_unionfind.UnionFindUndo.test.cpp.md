---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFindUndo.hpp
    title: "UnionFind (Undo\u53EF\u80FD)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/UnionFindUndo.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/UnionFindUndo.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> t(Q),u(Q),v(Q);\n    vector<vector<int>> G(Q+1);\n\
    \    for (int i=0;i<Q;++i){\n        int k; cin >> t[i] >> k >> u[i] >> v[i];\n\
    \        G[++k].emplace_back(i+1);\n    }\n\n    UnionFindUndo UF(N);\n    vector<int>\
    \ ans(Q,-1);\n    auto dfs=[&](auto self,int cur)->void{\n        if (cur){\n\
    \            if (!t[cur-1]) UF.merge(u[cur-1],v[cur-1]);\n            else ans[cur-1]=UF.same(u[cur-1],v[cur-1]);\n\
    \        }\n        for (int nxt:G[cur]) self(self,nxt);\n        if (cur&&!t[cur-1])\
    \ UF.undo();\n    };\n    dfs(dfs,0);\n    for (int i=0;i<Q;++i){\n        if\
    \ (~ans[i]){\n            cout << ans[i] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/UnionFindUndo.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
- /verify/test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp.html
title: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
---
