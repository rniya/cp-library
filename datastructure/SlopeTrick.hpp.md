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
  bundledCode: "#line 2 \"datastructure/SlopeTrick.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <queue>\n\ntemplate <typename T> struct SlopeTrick {\n  \
    \  // initialize as f(x) = 0\n    SlopeTrick() : min_f(0), add_l(0), add_r(0)\
    \ {}\n\n    // argmin f(x), min f(x)\n    std::tuple<T, T, T> query() const {\
    \ return {top_L(), top_R(), min_f}; }\n\n    // f(x) += b\n    void add_const(const\
    \ T& b) { min_f += b; }\n\n    // f(x) += max(a - x, 0) \\_\n    void add_a_minus_x(const\
    \ T& a) {\n        min_f += std::max(T(0), a - top_R());\n        push_R(a);\n\
    \        push_L(pop_R());\n    }\n\n    // f(x) += max(x - a, 0) _/\n    void\
    \ add_x_minus_a(const T& a) {\n        min_f += std::max(T(0), top_L() - a);\n\
    \        push_L(a);\n        push_R(pop_L());\n    }\n\n    // f(x) += |x - a|\
    \ \\/\n    void add_abs(const T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n\
    \    }\n\n    // f(x) <- min_{y <= x} f(y) \\/ -> \\_\n    void chmin_right()\
    \ {\n        while (!R.empty()) R.pop();\n    }\n\n    // f(x) <- min_{x <= y}\
    \ f(y)\n    void chmin_left() {\n        while (!L.empty()) L.pop();\n    }\n\n\
    \    // f(x) <- min_{x - b <= y <= x - a} f(y)\n    void shift(const T& a, const\
    \ T& b) {\n        assert(a <= b);\n        add_l += a;\n        add_r += b;\n\
    \    }\n\n    // f(x) <- f(x - a)\n    void shift(const T& a) { shift(a, a); }\n\
    \n    // return f(x), f destructive\n    T get_destructive(const T& x) {\n   \
    \     T res = min_f;\n        while (!L.empty()) res += std::max(T(0), pop_L()\
    \ - x);\n        while (!R.empty()) res += std::max(T(0), x - pop_R());\n    \
    \    return res;\n    }\n\n    // f(x) += g(x), g destructive\n    void merge_destructive(SlopeTrick&\
    \ g) {\n        if (g.size() < size()) {\n            std::swap(min_f, g.min_f);\n\
    \            std::swap(L, g.L);\n            std::swap(R, g.R);\n            std::swap(min_f,\
    \ g.add_l);\n            std::swap(min_f, g.add_r);\n        }\n        min_f\
    \ += g.min_f;\n        while (!g.L.empty()) add_a_minus_x(g.pop_L());\n      \
    \  while (!g.R.empty()) add_x_minus_a(g.pop_R());\n    }\n\nprivate:\n    const\
    \ T inf = std::numeric_limits<T>::max() / 2;\n    T min_f;\n    std::priority_queue<T,\
    \ std::vector<T>, std::less<>> L;\n    std::priority_queue<T, std::vector<T>,\
    \ std::greater<>> R;\n    T add_l, add_r;\n\n    void push_L(const T& a) { L.emplace(a\
    \ - add_l); }\n\n    T top_L() const { return L.empty() ? -inf : L.top() + add_l;\
    \ }\n\n    T pop_L() {\n        T res = top_L();\n        if (!L.empty()) L.pop();\n\
    \        return res;\n    }\n\n    void push_R(const T& a) { R.emplace(a - add_r);\
    \ }\n\n    T top_R() const { return R.empty() ? inf : R.top() + add_r; }\n\n \
    \   T pop_R() {\n        T res = top_R();\n        if (!R.empty()) R.pop();\n\
    \        return res;\n    }\n\n    size_t size() const { return L.size() + R.size();\
    \ }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n\n\
    template <typename T> struct SlopeTrick {\n    // initialize as f(x) = 0\n   \
    \ SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\n\n    // argmin f(x), min f(x)\n\
    \    std::tuple<T, T, T> query() const { return {top_L(), top_R(), min_f}; }\n\
    \n    // f(x) += b\n    void add_const(const T& b) { min_f += b; }\n\n    // f(x)\
    \ += max(a - x, 0) \\_\n    void add_a_minus_x(const T& a) {\n        min_f +=\
    \ std::max(T(0), a - top_R());\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n\n    // f(x) += max(x - a, 0) _/\n    void add_x_minus_a(const T& a)\
    \ {\n        min_f += std::max(T(0), top_L() - a);\n        push_L(a);\n     \
    \   push_R(pop_L());\n    }\n\n    // f(x) += |x - a| \\/\n    void add_abs(const\
    \ T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n    }\n\n   \
    \ // f(x) <- min_{y <= x} f(y) \\/ -> \\_\n    void chmin_right() {\n        while\
    \ (!R.empty()) R.pop();\n    }\n\n    // f(x) <- min_{x <= y} f(y)\n    void chmin_left()\
    \ {\n        while (!L.empty()) L.pop();\n    }\n\n    // f(x) <- min_{x - b <=\
    \ y <= x - a} f(y)\n    void shift(const T& a, const T& b) {\n        assert(a\
    \ <= b);\n        add_l += a;\n        add_r += b;\n    }\n\n    // f(x) <- f(x\
    \ - a)\n    void shift(const T& a) { shift(a, a); }\n\n    // return f(x), f destructive\n\
    \    T get_destructive(const T& x) {\n        T res = min_f;\n        while (!L.empty())\
    \ res += std::max(T(0), pop_L() - x);\n        while (!R.empty()) res += std::max(T(0),\
    \ x - pop_R());\n        return res;\n    }\n\n    // f(x) += g(x), g destructive\n\
    \    void merge_destructive(SlopeTrick& g) {\n        if (g.size() < size()) {\n\
    \            std::swap(min_f, g.min_f);\n            std::swap(L, g.L);\n    \
    \        std::swap(R, g.R);\n            std::swap(min_f, g.add_l);\n        \
    \    std::swap(min_f, g.add_r);\n        }\n        min_f += g.min_f;\n      \
    \  while (!g.L.empty()) add_a_minus_x(g.pop_L());\n        while (!g.R.empty())\
    \ add_x_minus_a(g.pop_R());\n    }\n\nprivate:\n    const T inf = std::numeric_limits<T>::max()\
    \ / 2;\n    T min_f;\n    std::priority_queue<T, std::vector<T>, std::less<>>\
    \ L;\n    std::priority_queue<T, std::vector<T>, std::greater<>> R;\n    T add_l,\
    \ add_r;\n\n    void push_L(const T& a) { L.emplace(a - add_l); }\n\n    T top_L()\
    \ const { return L.empty() ? -inf : L.top() + add_l; }\n\n    T pop_L() {\n  \
    \      T res = top_L();\n        if (!L.empty()) L.pop();\n        return res;\n\
    \    }\n\n    void push_R(const T& a) { R.emplace(a - add_r); }\n\n    T top_R()\
    \ const { return R.empty() ? inf : R.top() + add_r; }\n\n    T pop_R() {\n   \
    \     T res = top_R();\n        if (!R.empty()) R.pop();\n        return res;\n\
    \    }\n\n    size_t size() const { return L.size() + R.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/SlopeTrick.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/SlopeTrick.hpp
layout: document
redirect_from:
- /library/datastructure/SlopeTrick.hpp
- /library/datastructure/SlopeTrick.hpp.html
title: datastructure/SlopeTrick.hpp
---
