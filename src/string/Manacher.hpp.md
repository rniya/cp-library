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
  bundledCode: "#line 2 \"src/string/Manacher.hpp\"\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> Manacher(const std::string& s) {\n    int n = s.size();\n \
    \   std::vector<int> res(n);\n    for (int i = 0, j = 0; i < n;) {\n        while\
    \ (i - j >= 0 and i + j < n and s[i - j] == s[i + j]) j++;\n        res[i] = j;\n\
    \        int k = 1;\n        while (i - k >= 0 and i + k < n and k + res[i - k]\
    \ < j) res[i + k] = res[i - k], k++;\n        i += k;\n        j -= k;\n    }\n\
    \    return res;\n}\n\nstd::vector<int> PalindromeTable(const std::string& s)\
    \ {\n    int n = s.size();\n    std::string t(n * 2 + 1, '$');\n    for (int i\
    \ = 0; i < n; i++) t[i * 2 + 1] = s[i];\n    std::vector<int> v = Manacher(t),\
    \ res;\n    for (int i = 1; i < n * 2; i++) res.emplace_back(v[i] - 1);\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> Manacher(const\
    \ std::string& s) {\n    int n = s.size();\n    std::vector<int> res(n);\n   \
    \ for (int i = 0, j = 0; i < n;) {\n        while (i - j >= 0 and i + j < n and\
    \ s[i - j] == s[i + j]) j++;\n        res[i] = j;\n        int k = 1;\n      \
    \  while (i - k >= 0 and i + k < n and k + res[i - k] < j) res[i + k] = res[i\
    \ - k], k++;\n        i += k;\n        j -= k;\n    }\n    return res;\n}\n\n\
    std::vector<int> PalindromeTable(const std::string& s) {\n    int n = s.size();\n\
    \    std::string t(n * 2 + 1, '$');\n    for (int i = 0; i < n; i++) t[i * 2 +\
    \ 1] = s[i];\n    std::vector<int> v = Manacher(t), res;\n    for (int i = 1;\
    \ i < n * 2; i++) res.emplace_back(v[i] - 1);\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Manacher.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/Manacher.hpp
layout: document
title: "Manacher\uFF08\u56DE\u5206\u534A\u5F84\uFF09"
---

## 概要
