---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: convolution/FastFourierTransform.hpp
    title: Fast Fourier Transform
  - icon: ':x:'
    path: tree/CentroidDecomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ convolution/FastFourierTransform.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/FastFourierTransform.hpp\"\
    \n#include \"../../tree/CentroidDecomposition.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N; cin >> N;\n\n    CentroidDecomposition\
    \ CD(N);\n    for (int i=0;i<N-1;++i){\n        int a,b; cin >> a >> b;\n    \
    \    CD.add_edge(a,b);\n    }\n\n    vector<long long> ans(N,0);\n    auto calc=[&](auto\
    \ self,int v,int p,int d,vector<int> &cnt)->void{\n        while(cnt.size()<=d)\
    \ cnt.emplace_back(0);\n        ++cnt[d];\n        for (int u:CD[v]){\n      \
    \      if (u==p||!CD.alive(u)) continue;\n            self(self,u,v,d+1,cnt);\n\
    \        }\n    };\n    auto dfs=[&](auto self,int v)->void{\n        int c=CD.build(v);\n\
    \        CD.disable(c);\n        vector<int> sum{1};\n        for (int u:CD[c]){\n\
    \            if (!CD.alive(u)) continue;\n            self(self,u);\n        \
    \    vector<int> cnt;\n            calc(calc,u,c,1,cnt);\n            while(sum.size()<cnt.size())\
    \ sum.emplace_back(0);\n            for (int i=0;i<cnt.size();++i) sum[i]+=cnt[i];\n\
    \            auto mul=FastFourierTransform::multiply(cnt,cnt);\n            for\
    \ (int i=0;i<mul.size();++i) ans[i]-=mul[i];\n        }\n        auto ret=FastFourierTransform::multiply(sum,sum);\n\
    \        for (int i=0;i<ret.size();++i) ans[i]+=ret[i];\n        CD.enable(c);\n\
    \    };\n\n    dfs(dfs,0);\n    for (int i=1;i<N;++i) cout << ans[i]/2 << (i+1==N?'\\\
    n':' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/FastFourierTransform.hpp
  - tree/CentroidDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
