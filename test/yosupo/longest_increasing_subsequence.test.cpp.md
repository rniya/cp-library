---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/longest_increasing_subsequence.hpp
    title: Longest Increasing Subsequence (LIS)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo/longest_increasing_subsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#line 2 \"algorithm/longest_increasing_subsequence.hpp\"\n#include <algorithm>\n\
    #include <iterator>\n#include <vector>\n\ntemplate <typename T> int longest_increasing_subsequence(const\
    \ std::vector<T>& a, bool strict = true) {\n    std::vector<T> lis;\n    for (const\
    \ auto& x : a) {\n        auto it = (strict ? lower_bound(lis.begin(), lis.end(),\
    \ x) : upper_bound(lis.begin(), lis.end(), x));\n        if (it == lis.end())\n\
    \            lis.emplace_back(x);\n        else\n            *it = x;\n    }\n\
    \    return lis.size();\n}\n\ntemplate <typename T>\nstd::vector<int> longest_increasing_subsequence_restore(const\
    \ std::vector<T>& a, bool strict = true) {\n    int n = a.size();\n    std::vector<T>\
    \ lis;\n    std::vector<int> pre(n, -1);\n    lis.reserve(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        auto it = (strict ? lower_bound(lis.begin(), lis.end(),\
    \ i, [&](int x, int y) { return a[x] < a[y]; })\n                          : upper_bound(lis.begin(),\
    \ lis.end(), i, [&](int x, int y) { return a[x] < a[y]; }));\n        if (it ==\
    \ lis.end())\n            lis.emplace_back(i);\n        else\n            *it\
    \ = i;\n        if (it != lis.begin()) pre[i] = *std::prev(it);\n    }\n    std::vector<int>\
    \ res;\n    for (int cur = lis.back(); cur != -1; cur = pre[cur]) res.emplace_back(cur);\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n}\n#line 4 \"test/yosupo/longest_increasing_subsequence.test.cpp\"\
    \n#include <iostream>\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<int> A(N);\n    for (int& x :\
    \ A) std::cin >> x;\n\n    auto ans = longest_increasing_subsequence_restore(A);\n\
    \    int K = longest_increasing_subsequence(A);\n    std::cout << K << '\\n';\n\
    \    for (int i = 0; i < K; i++) std::cout << ans[i] << (i + 1 == K ? '\\n' :\
    \ ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"algorithm/longest_increasing_subsequence.hpp\"\n#include <iostream>\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<int> A(N);\n    for (int& x :\
    \ A) std::cin >> x;\n\n    auto ans = longest_increasing_subsequence_restore(A);\n\
    \    int K = longest_increasing_subsequence(A);\n    std::cout << K << '\\n';\n\
    \    for (int i = 0; i < K; i++) std::cout << ans[i] << (i + 1 == K ? '\\n' :\
    \ ' ');\n}"
  dependsOn:
  - algorithm/longest_increasing_subsequence.hpp
  isVerificationFile: true
  path: test/yosupo/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2022-11-06 19:55:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/longest_increasing_subsequence.test.cpp
- /verify/test/yosupo/longest_increasing_subsequence.test.cpp.html
title: test/yosupo/longest_increasing_subsequence.test.cpp
---
