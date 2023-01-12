---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/Z_Algorithm.hpp\"\n#include <algorithm>\n#include\
    \ <vector>\n\ntemplate <typename T> std::vector<int> Z_Algorithm(const T& s) {\n\
    \    int n = s.size();\n    std::vector<int> z(n);\n    z[0] = n;\n    for (int\
    \ i = 1, j = 0; i < n;) {\n        while (i + j < n and s[j] == s[i + j]) j++;\n\
    \        z[i] = j;\n        if (j == 0) {\n            i++;\n            continue;\n\
    \        }\n        int k = 1;\n        while (i + k < n and k + z[k] < j) z[i\
    \ + k] = z[k], k++;\n        i += k;\n        j -= k;\n    }\n    return z;\n\
    }\n\ntemplate <typename T> std::vector<int> LCP(const T& s, const T& t) {\n  \
    \  T u(s);\n    u.insert(u.begin(), t.begin(), t.end());\n    std::vector<int>\
    \ z = Z_Algorithm(u);\n    for (int& i : z) i = std::min(i, (int)t.size());\n\
    \    return std::vector<int>(z.begin() + t.size(), z.end());\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T> std::vector<int> Z_Algorithm(const T& s) {\n    int n = s.size();\n    std::vector<int>\
    \ z(n);\n    z[0] = n;\n    for (int i = 1, j = 0; i < n;) {\n        while (i\
    \ + j < n and s[j] == s[i + j]) j++;\n        z[i] = j;\n        if (j == 0) {\n\
    \            i++;\n            continue;\n        }\n        int k = 1;\n    \
    \    while (i + k < n and k + z[k] < j) z[i + k] = z[k], k++;\n        i += k;\n\
    \        j -= k;\n    }\n    return z;\n}\n\ntemplate <typename T> std::vector<int>\
    \ LCP(const T& s, const T& t) {\n    T u(s);\n    u.insert(u.begin(), t.begin(),\
    \ t.end());\n    std::vector<int> z = Z_Algorithm(u);\n    for (int& i : z) i\
    \ = std::min(i, (int)t.size());\n    return std::vector<int>(z.begin() + t.size(),\
    \ z.end());\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Z_Algorithm.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/Z_Algorithm.hpp
layout: document
title: Z-Algorithm
---

## 概要
