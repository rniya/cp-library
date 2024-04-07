---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_3_D.test.cpp
    title: test/aoj/DSL_3_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/Slide_Min.hpp\"\n#include <deque>\n#include\
    \ <vector>\n\ntemplate <typename T> std::vector<T> Slide_Min(const std::vector<T>&\
    \ v, int k) {\n    std::deque<int> deq;\n    std::vector<T> res;\n    for (int\
    \ i = 0; i < (int)v.size(); i++) {\n        while (!deq.empty() and v[deq.back()]\
    \ >= v[i]) deq.pop_back();\n        deq.emplace_back(i);\n        if (i - k +\
    \ 1 >= 0) {\n            res.emplace_back(v[deq.front()]);\n            if (deq.front()\
    \ == i - k + 1) deq.pop_front();\n        }\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include <deque>\n#include <vector>\n\ntemplate <typename T>\
    \ std::vector<T> Slide_Min(const std::vector<T>& v, int k) {\n    std::deque<int>\
    \ deq;\n    std::vector<T> res;\n    for (int i = 0; i < (int)v.size(); i++) {\n\
    \        while (!deq.empty() and v[deq.back()] >= v[i]) deq.pop_back();\n    \
    \    deq.emplace_back(i);\n        if (i - k + 1 >= 0) {\n            res.emplace_back(v[deq.front()]);\n\
    \            if (deq.front() == i - k + 1) deq.pop_front();\n        }\n    }\n\
    \    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/Slide_Min.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_3_D.test.cpp
documentation_of: src/datastructure/Slide_Min.hpp
layout: document
title: "\u30B9\u30E9\u30A4\u30C9\u6700\u5C0F\u5024"
---

## 概要
