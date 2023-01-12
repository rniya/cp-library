---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/longest_increasing_subsequence.test.cpp
    title: test/yosupo/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/algorithm/longest_increasing_subsequence.hpp\"\n#include\
    \ <algorithm>\n#include <iterator>\n#include <vector>\n\ntemplate <typename T>\
    \ int longest_increasing_subsequence(const std::vector<T>& a, bool strict = true)\
    \ {\n    std::vector<T> lis;\n    for (const auto& x : a) {\n        auto it =\
    \ (strict ? lower_bound(lis.begin(), lis.end(), x) : upper_bound(lis.begin(),\
    \ lis.end(), x));\n        if (it == lis.end())\n            lis.emplace_back(x);\n\
    \        else\n            *it = x;\n    }\n    return lis.size();\n}\n\ntemplate\
    \ <typename T>\nstd::vector<int> longest_increasing_subsequence_restore(const\
    \ std::vector<T>& a, bool strict = true) {\n    int n = a.size();\n    std::vector<T>\
    \ lis;\n    std::vector<int> pre(n, -1);\n    lis.reserve(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        auto it = (strict ? lower_bound(lis.begin(), lis.end(),\
    \ i, [&](int x, int y) { return a[x] < a[y]; })\n                          : upper_bound(lis.begin(),\
    \ lis.end(), i, [&](int x, int y) { return a[x] < a[y]; }));\n        if (it ==\
    \ lis.end())\n            lis.emplace_back(i);\n        else\n            *it\
    \ = i;\n        if (it != lis.begin()) pre[i] = *std::prev(it);\n    }\n    std::vector<int>\
    \ res;\n    for (int cur = lis.back(); cur != -1; cur = pre[cur]) res.emplace_back(cur);\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <iterator>\n#include <vector>\n\
    \ntemplate <typename T> int longest_increasing_subsequence(const std::vector<T>&\
    \ a, bool strict = true) {\n    std::vector<T> lis;\n    for (const auto& x :\
    \ a) {\n        auto it = (strict ? lower_bound(lis.begin(), lis.end(), x) : upper_bound(lis.begin(),\
    \ lis.end(), x));\n        if (it == lis.end())\n            lis.emplace_back(x);\n\
    \        else\n            *it = x;\n    }\n    return lis.size();\n}\n\ntemplate\
    \ <typename T>\nstd::vector<int> longest_increasing_subsequence_restore(const\
    \ std::vector<T>& a, bool strict = true) {\n    int n = a.size();\n    std::vector<T>\
    \ lis;\n    std::vector<int> pre(n, -1);\n    lis.reserve(n);\n    for (int i\
    \ = 0; i < n; i++) {\n        auto it = (strict ? lower_bound(lis.begin(), lis.end(),\
    \ i, [&](int x, int y) { return a[x] < a[y]; })\n                          : upper_bound(lis.begin(),\
    \ lis.end(), i, [&](int x, int y) { return a[x] < a[y]; }));\n        if (it ==\
    \ lis.end())\n            lis.emplace_back(i);\n        else\n            *it\
    \ = i;\n        if (it != lis.begin()) pre[i] = *std::prev(it);\n    }\n    std::vector<int>\
    \ res;\n    for (int cur = lis.back(); cur != -1; cur = pre[cur]) res.emplace_back(cur);\n\
    \    std::reverse(res.begin(), res.end());\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/longest_increasing_subsequence.test.cpp
documentation_of: src/algorithm/longest_increasing_subsequence.hpp
layout: document
title: Longest Increasing Subsequence (LIS)
---
