---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/SlidingWindowAggregation.hpp\"\n#include\
    \ <functional>\n#include <stack>\n\ntemplate <typename Monoid> struct SlidingWindowAggregation\
    \ {\n    typedef std::function<Monoid(Monoid, Monoid)> F;\n    std::stack<std::pair<Monoid,\
    \ Monoid>> front_stack, back_stack;\n    F f;\n    Monoid id;\n    SlidingWindowAggregation(F\
    \ f, Monoid id) : f(f), id(id), front_stack(), back_stack() {\n        front_stack.emplace(id,\
    \ id);\n        back_stack.emplace(id, id);\n    }\n    void push(const Monoid&\
    \ x) { back_stack.emplace(x, f(back_stack.top().second, x)); }\n    void pop()\
    \ {\n        if (front_stack.size() == 1) {\n            while (1 < (int)back_stack.size())\
    \ {\n                Monoid t = back_stack.top().first;\n                Monoid\
    \ calc = f(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    Monoid fold() { return f(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n"
  code: "#pragma once\n#include <functional>\n#include <stack>\n\ntemplate <typename\
    \ Monoid> struct SlidingWindowAggregation {\n    typedef std::function<Monoid(Monoid,\
    \ Monoid)> F;\n    std::stack<std::pair<Monoid, Monoid>> front_stack, back_stack;\n\
    \    F f;\n    Monoid id;\n    SlidingWindowAggregation(F f, Monoid id) : f(f),\
    \ id(id), front_stack(), back_stack() {\n        front_stack.emplace(id, id);\n\
    \        back_stack.emplace(id, id);\n    }\n    void push(const Monoid& x) {\
    \ back_stack.emplace(x, f(back_stack.top().second, x)); }\n    void pop() {\n\
    \        if (front_stack.size() == 1) {\n            while (1 < (int)back_stack.size())\
    \ {\n                Monoid t = back_stack.top().first;\n                Monoid\
    \ calc = f(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    Monoid fold() { return f(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: src/datastructure/SlidingWindowAggregation.hpp
layout: document
title: Sliding Window Aggregation
---

## 概要
