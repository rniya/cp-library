---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/WarshallFloyd.hpp
    title: Warshall Floyd
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/WarshallFloyd.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/WarshallFloyd.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    const long\
    \ long inf=1e18;\n    int V,E; cin >> V >> E;\n    vector<vector<long long>> ans(V,vector<long\
    \ long>(V,inf));\n    for (int i=0;i<V;++i) ans[i][i]=0;\n    for (int i=0;i<E;++i){\n\
    \        int s,t,d; cin >> s >> t >> d;\n        ans[s][t]=d;\n    }\n\n    Warshall_Floyd(ans,inf);\n\
    \    for (int i=0;i<V;++i){\n        if (ans[i][i]<0){\n            cout << \"\
    NEGATIVE CYCLE\" << '\\n';\n            return 0;\n        }\n    }\n    for (int\
    \ i=0;i<V;++i){\n        for (int j=0;j<V;++j){\n            if (ans[i][j]==inf)\
    \ cout << \"INF\";\n            else cout << ans[i][j];\n            cout << (j+1==V?'\\\
    n':' ');\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/WarshallFloyd.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_C.test.cpp
- /verify/test/aoj/GRL_1_C.test.cpp.html
title: test/aoj/GRL_1_C.test.cpp
---
