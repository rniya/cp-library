---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/Mo.hpp
    title: Mo's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/fenwicktree:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n#include \"atcoder/fenwicktree\"\n#include \"datastructure/Mo.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> A(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> A[i];\n\n    Mo mo(N);\n    for (int i = 0; i\
    \ < Q; i++) {\n        int l, r;\n        std::cin >> l >> r;\n        mo.add(l,\
    \ r);\n    }\n\n    std::vector<int> B = A;\n    sort(B.begin(), B.end());\n \
    \   B.erase(unique(B.begin(), B.end()), B.end());\n    for (int i = 0; i < N;\
    \ i++) A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();\n    int n =\
    \ B.size();\n    atcoder::fenwick_tree<int> FT(n);\n    std::vector<long long>\
    \ ans(Q);\n    long long inv = 0;\n    int sum = 0;\n\n    auto add_left = [&](int\
    \ idx) {\n        inv += FT.sum(0, A[idx]);\n        sum++;\n        FT.add(A[idx],\
    \ 1);\n    };\n    auto add_right = [&](int idx) {\n        inv += FT.sum(A[idx]\
    \ + 1, n);\n        sum++;\n        FT.add(A[idx], 1);\n    };\n    auto del_left\
    \ = [&](int idx) {\n        inv -= FT.sum(0, A[idx]);\n        sum--;\n      \
    \  FT.add(A[idx], -1);\n    };\n    auto del_right = [&](int idx) {\n        inv\
    \ -= FT.sum(A[idx] + 1, n);\n        sum--;\n        FT.add(A[idx], -1);\n   \
    \ };\n    auto rem = [&](int idx) { ans[idx] = inv; };\n\n    mo.run(add_left,\
    \ add_right, del_left, del_right, rem);\n\n    for (int i = 0; i < Q; i++) std::cout\
    \ << ans[i] << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/datastructure/Mo.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
