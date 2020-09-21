---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: util/compress.hpp
    title: compress
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: other/Mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/compress.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../util/compress.hpp\"\n#include\
    \ \"../../datastructure/BinaryIndexedTree.hpp\"\n#include \"../../other/Mo.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> A(N);\n    for (int i=0;i<N;++i) cin >> A[i];\n\
    \n    Mo mo(N);\n    for (int i=0;i<Q;++i){\n        int l,r; cin >> l >> r;\n\
    \        mo.insert(l,r);\n    }\n\n    map<int,int> mp=compress(A);\n    for (int\
    \ i=0;i<N;++i) A[i]=mp[A[i]];\n    int n=mp.size();\n    BinaryIndexedTree<int>\
    \ BIT(n+1);\n    vector<long long> ans(Q);\n    long long inv=0; int sum=0;\n\
    \    auto add_left=[&](int idx){\n        inv+=BIT.sum0(A[idx]-1);\n        ++sum;\
    \ BIT.add0(A[idx],1);\n    };\n    auto add_right=[&](int idx){\n        inv+=sum-BIT.sum0(A[idx]);\n\
    \        ++sum; BIT.add0(A[idx],1);\n    };\n    auto del_left=[&](int idx){\n\
    \        inv-=BIT.sum0(A[idx]-1);\n        --sum; BIT.add0(A[idx],-1);\n    };\n\
    \    auto del_right=[&](int idx){\n        inv-=sum-BIT.sum0(A[idx]);\n      \
    \  --sum; BIT.add0(A[idx],-1);\n    };\n    auto rem=[&](int idx){\n        ans[idx]=inv;\n\
    \    };\n\n    mo.build(add_left,add_right,del_left,del_right,rem);\n\n    for\
    \ (int i=0;i<Q;++i) cout << ans[i] << '\\n';\n}"
  dependsOn:
  - base.hpp
  - util/compress.hpp
  - datastructure/BinaryIndexedTree.hpp
  - other/Mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2020-09-15 16:01:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
