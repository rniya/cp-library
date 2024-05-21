---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/SlidingWindowAggregation.hpp\"\n#include\
    \ <functional>\n#include <stack>\n\ntemplate <class S, S (*op)(S, S), S (*e)()>\
    \ struct SlidingWindowAggregation {\n    std::stack<std::pair<S, S>> front_stack,\
    \ back_stack;\n    SlidingWindowAggregation() : front_stack(), back_stack() {\n\
    \        front_stack.emplace(e(), e());\n        back_stack.emplace(e(), e());\n\
    \    }\n    void push(const S& x) { back_stack.emplace(x, op(back_stack.top().second,\
    \ x)); }\n    void pop() {\n        if (front_stack.size() == 1) {\n         \
    \   while (1 < (int)back_stack.size()) {\n                S t = back_stack.top().first;\n\
    \                S calc = op(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    S fold() { return op(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <stack>\n\ntemplate <class\
    \ S, S (*op)(S, S), S (*e)()> struct SlidingWindowAggregation {\n    std::stack<std::pair<S,\
    \ S>> front_stack, back_stack;\n    SlidingWindowAggregation() : front_stack(),\
    \ back_stack() {\n        front_stack.emplace(e(), e());\n        back_stack.emplace(e(),\
    \ e());\n    }\n    void push(const S& x) { back_stack.emplace(x, op(back_stack.top().second,\
    \ x)); }\n    void pop() {\n        if (front_stack.size() == 1) {\n         \
    \   while (1 < (int)back_stack.size()) {\n                S t = back_stack.top().first;\n\
    \                S calc = op(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    S fold() { return op(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2024-05-21 23:41:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: src/datastructure/SlidingWindowAggregation.hpp
layout: document
title: Sliding Window Aggregation
---

## 概要

## 問題例
- [yukicoder No.2215 Slide Subset Sum](https://yukicoder.me/problems/no/2215)