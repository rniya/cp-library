---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/952.test.cpp
    title: test/yukicoder/952.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/ConvexHullTrick.hpp\"\n#include <cassert>\n\
    #include <queue>\n\ntemplate <typename T, bool isMin = true> struct ConvexHullTrick\
    \ {\n    bool empty() const { return lines.empty(); }\n\n    void add(T a, T b)\
    \ {\n        if (!isMin) a *= -1, b *= -1;\n        std::pair<T, T> l(a, b);\n\
    \        if (empty()) {\n            lines.emplace_back(a, b);\n            return;\n\
    \        }\n        if (lines.front().first <= a) {\n            if (lines.front().first\
    \ == a) {\n                if (lines.front().second <= b) return;\n          \
    \      lines.pop_back();\n            }\n            while (lines.size() >= 2\
    \ && check(l, lines.front(), lines[1])) lines.pop_front();\n            lines.emplace_front(l);\n\
    \        } else if (a <= lines.back().first) {\n            if (lines.back().first\
    \ == a) {\n                if (lines.back().second <= b) return;\n           \
    \     lines.pop_back();\n            }\n            while (lines.size() >= 2 &&\
    \ check(lines[lines.size() - 2], lines.back(), l)) lines.pop_back();\n       \
    \     lines.emplace_back(l);\n        } else\n            assert(false);\n   \
    \ }\n\n    T query(T x) {\n        assert(!called_query_monotonic_inc && !called_query_monotonic_dec);\n\
    \        assert(!empty());\n        called_query = true;\n        int lb = -1,\
    \ ub = lines.size() - 1;\n        while (ub - lb > 1) {\n            int mid =\
    \ (ub + lb) >> 1;\n            (f(lines[mid], x) >= f(lines[mid + 1], x) ? lb\
    \ : ub) = mid;\n        }\n        T res = f(lines[ub], x);\n        return isMin\
    \ ? res : -res;\n    }\n\n    T query_monotone_inc(T x) {\n        assert(!called_query\
    \ && !called_query_monotonic_dec);\n        assert(!empty());\n        if (!called_query_monotonic_inc)\n\
    \            called_query_monotonic_inc = true;\n        else\n            assert(prev_query\
    \ <= x);\n        prev_query = x;\n        while (lines.size() >= 2 && f(lines.front(),\
    \ x) >= f(lines[1], x)) lines.pop_front();\n        T res = f(lines.front(), x);\n\
    \        return isMin ? res : -res;\n    }\n\n    T query_monotone_dec(T x) {\n\
    \        assert(!called_query && !called_query_monotonic_inc);\n        assert(!empty());\n\
    \        if (!called_query_monotonic_dec)\n            called_query_monotonic_dec\
    \ = true;\n        else\n            assert(x <= prev_query);\n        prev_query\
    \ = x;\n        while (lines.size() >= 2 && f(lines.back(), x) >= f(lines[lines.size()\
    \ - 2], x)) lines.pop_back();\n        T res = f(lines.back(), x);\n        return\
    \ isMin ? res : -res;\n    }\n\nprivate:\n    std::deque<std::pair<T, T>> lines;\
    \  // slope decreases as index increases\n    bool called_query = false, called_query_monotonic_inc\
    \ = false, called_query_monotonic_dec = false;\n    T prev_query;\n\n    using\
    \ D = long double;\n\n    // check if b is unnecessary\n    inline bool check(const\
    \ std::pair<T, T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {\n\
    \        // return (b.first - a.first) * (c.second - b.second) >= (c.first - b.first)\
    \ * (b.second - a.second);\n        // note that slopes are distinct and decrease\n\
    \        return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second)\
    \ / (b.first - a.first);\n    }\n\n    inline T f(const std::pair<T, T>& l, T\
    \ x) { return l.first * x + l.second; }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <queue>\n\ntemplate <typename\
    \ T, bool isMin = true> struct ConvexHullTrick {\n    bool empty() const { return\
    \ lines.empty(); }\n\n    void add(T a, T b) {\n        if (!isMin) a *= -1, b\
    \ *= -1;\n        std::pair<T, T> l(a, b);\n        if (empty()) {\n         \
    \   lines.emplace_back(a, b);\n            return;\n        }\n        if (lines.front().first\
    \ <= a) {\n            if (lines.front().first == a) {\n                if (lines.front().second\
    \ <= b) return;\n                lines.pop_back();\n            }\n          \
    \  while (lines.size() >= 2 && check(l, lines.front(), lines[1])) lines.pop_front();\n\
    \            lines.emplace_front(l);\n        } else if (a <= lines.back().first)\
    \ {\n            if (lines.back().first == a) {\n                if (lines.back().second\
    \ <= b) return;\n                lines.pop_back();\n            }\n          \
    \  while (lines.size() >= 2 && check(lines[lines.size() - 2], lines.back(), l))\
    \ lines.pop_back();\n            lines.emplace_back(l);\n        } else\n    \
    \        assert(false);\n    }\n\n    T query(T x) {\n        assert(!called_query_monotonic_inc\
    \ && !called_query_monotonic_dec);\n        assert(!empty());\n        called_query\
    \ = true;\n        int lb = -1, ub = lines.size() - 1;\n        while (ub - lb\
    \ > 1) {\n            int mid = (ub + lb) >> 1;\n            (f(lines[mid], x)\
    \ >= f(lines[mid + 1], x) ? lb : ub) = mid;\n        }\n        T res = f(lines[ub],\
    \ x);\n        return isMin ? res : -res;\n    }\n\n    T query_monotone_inc(T\
    \ x) {\n        assert(!called_query && !called_query_monotonic_dec);\n      \
    \  assert(!empty());\n        if (!called_query_monotonic_inc)\n            called_query_monotonic_inc\
    \ = true;\n        else\n            assert(prev_query <= x);\n        prev_query\
    \ = x;\n        while (lines.size() >= 2 && f(lines.front(), x) >= f(lines[1],\
    \ x)) lines.pop_front();\n        T res = f(lines.front(), x);\n        return\
    \ isMin ? res : -res;\n    }\n\n    T query_monotone_dec(T x) {\n        assert(!called_query\
    \ && !called_query_monotonic_inc);\n        assert(!empty());\n        if (!called_query_monotonic_dec)\n\
    \            called_query_monotonic_dec = true;\n        else\n            assert(x\
    \ <= prev_query);\n        prev_query = x;\n        while (lines.size() >= 2 &&\
    \ f(lines.back(), x) >= f(lines[lines.size() - 2], x)) lines.pop_back();\n   \
    \     T res = f(lines.back(), x);\n        return isMin ? res : -res;\n    }\n\
    \nprivate:\n    std::deque<std::pair<T, T>> lines;  // slope decreases as index\
    \ increases\n    bool called_query = false, called_query_monotonic_inc = false,\
    \ called_query_monotonic_dec = false;\n    T prev_query;\n\n    using D = long\
    \ double;\n\n    // check if b is unnecessary\n    inline bool check(const std::pair<T,\
    \ T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {\n        // return\
    \ (b.first - a.first) * (c.second - b.second) >= (c.first - b.first) * (b.second\
    \ - a.second);\n        // note that slopes are distinct and decrease\n      \
    \  return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second)\
    \ / (b.first - a.first);\n    }\n\n    inline T f(const std::pair<T, T>& l, T\
    \ x) { return l.first * x + l.second; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/ConvexHullTrick.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/952.test.cpp
documentation_of: datastructure/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/datastructure/ConvexHullTrick.hpp
- /library/datastructure/ConvexHullTrick.hpp.html
title: datastructure/ConvexHullTrick.hpp
---
