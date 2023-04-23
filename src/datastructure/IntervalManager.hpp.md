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
  bundledCode: "#line 2 \"src/datastructure/IntervalManager.hpp\"\n#include <algorithm>\n\
    #include <iostream>\n#include <limits>\n#include <set>\n#include <vector>\n\n\
    template <typename S, typename T> struct IntervalManager {\n    struct node {\n\
    \        T l, r;\n        S x;\n        node(T l, T r, S x) : l(l), r(r), x(x)\
    \ {}\n        constexpr bool operator<(const node& rhs) const { return l != rhs.l\
    \ ? l < rhs.l : r < rhs.r; }\n    };\n\n    const S id = S();\n    std::set<node>\
    \ s;\n\n    IntervalManager() {}\n\n    IntervalManager(const std::vector<S>&\
    \ v) {\n        std::vector<node> tmp;\n        for (size_t l = 0; l < v.size();)\
    \ {\n            size_t r = l;\n            while (r < v.size() and v[l] == v[r])\
    \ r++;\n            tmp.emplace_back(l, r, v[l]);\n            l = r;\n      \
    \  }\n        s = std::set<node>(tmp.begin(), tmp.end());\n    }\n\n    typename\
    \ std::set<node>::iterator getItr(const T& x) const {\n        auto itr = s.upper_bound(node(x,\
    \ std::numeric_limits<T>::max(), id));\n        if (itr == s.begin()) return s.end();\n\
    \        itr = prev(itr);\n        return itr->l <= x and x < itr->r ? itr : s.end();\n\
    \    }\n\n    node getSeg(const T& x) const {\n        auto itr = getItr(x);\n\
    \        return itr != s.end() ? *itr : node(x, x + 1, id);\n    }\n\n    S get(const\
    \ T& x) const {\n        auto seg = getSeg(x);\n        return seg.x;\n    }\n\
    \n    S operator[](const T& x) const { return get(x); }\n\n    template <typename\
    \ ADD, typename DEL> void apply(T l, T r, const S& x, const ADD& add, const DEL&\
    \ del) {\n        auto itr = s.lower_bound(node(l, std::numeric_limits<T>::min(),\
    \ id));\n        while (itr != s.end() and itr->l <= r) {\n            if (itr->l\
    \ == r) {\n                if (itr->x == x) {\n                    del(itr->l,\
    \ itr->r, itr->x);\n                    r = itr->r;\n                    itr =\
    \ s.erase(itr);\n                }\n                break;\n            }\n  \
    \          if (itr->r <= r) {\n                del(itr->l, itr->r, itr->x);\n\
    \                itr = s.erase(itr);\n            } else {\n                if\
    \ (itr->x == x) {\n                    r = itr->r;\n                    del(itr->l,\
    \ itr->r, itr->x);\n                    itr = s.erase(itr);\n                }\
    \ else {\n                    del(itr->l, r, itr->x);\n                    node\
    \ tmp = *itr;\n                    itr = s.erase(itr);\n                    itr\
    \ = s.emplace_hint(itr, r, tmp.r, tmp.x);\n                }\n            }\n\
    \        }\n\n        if (itr != s.begin()) {\n            itr = prev(itr);\n\
    \            if (itr->r == l) {\n                if (itr->x == x) {\n        \
    \            del(itr->l, itr->r, itr->x);\n                    l = itr->l;\n \
    \                   itr = s.erase(itr);\n                }\n            } else\
    \ if (l < itr->r) {\n                if (itr->x == x) {\n                    del(itr->l,\
    \ itr->r, itr->x);\n                    l = std::min(l, itr->l);\n           \
    \         r = std::max(r, itr->r);\n                    itr = s.erase(itr);\n\
    \                } else {\n                    if (r < itr->r) {\n           \
    \             itr = s.emplace_hint(next(itr), r, itr->r, itr->x);\n          \
    \              itr = prev(itr);\n                    }\n                    del(l,\
    \ std::min(r, itr->r), itr->x);\n                    node tmp = *itr;\n      \
    \              itr = s.erase(itr);\n                    itr = s.emplace_hint(itr,\
    \ tmp.l, l, tmp.x);\n                }\n            }\n        }\n\n        add(l,\
    \ r, x);\n        s.emplace(l, r, x);\n    }\n\n    void apply(T l, T r, const\
    \ S& x) {\n        apply(\n            l, r, x, [](T, T, S) {}, [](T, T, S) {});\n\
    \    }\n\n    friend std::ostream& operator<<(std::ostream& os, const IntervalManager&\
    \ im) {\n        for (const auto& e : im) os << \"([\" << e.l << \", \" << e.r\
    \ << \"): \" << e.x << \") \";\n        os << \"\\n\";\n        return os;\n \
    \   }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <iostream>\n#include <limits>\n\
    #include <set>\n#include <vector>\n\ntemplate <typename S, typename T> struct\
    \ IntervalManager {\n    struct node {\n        T l, r;\n        S x;\n      \
    \  node(T l, T r, S x) : l(l), r(r), x(x) {}\n        constexpr bool operator<(const\
    \ node& rhs) const { return l != rhs.l ? l < rhs.l : r < rhs.r; }\n    };\n\n\
    \    const S id = S();\n    std::set<node> s;\n\n    IntervalManager() {}\n\n\
    \    IntervalManager(const std::vector<S>& v) {\n        std::vector<node> tmp;\n\
    \        for (size_t l = 0; l < v.size();) {\n            size_t r = l;\n    \
    \        while (r < v.size() and v[l] == v[r]) r++;\n            tmp.emplace_back(l,\
    \ r, v[l]);\n            l = r;\n        }\n        s = std::set<node>(tmp.begin(),\
    \ tmp.end());\n    }\n\n    typename std::set<node>::iterator getItr(const T&\
    \ x) const {\n        auto itr = s.upper_bound(node(x, std::numeric_limits<T>::max(),\
    \ id));\n        if (itr == s.begin()) return s.end();\n        itr = prev(itr);\n\
    \        return itr->l <= x and x < itr->r ? itr : s.end();\n    }\n\n    node\
    \ getSeg(const T& x) const {\n        auto itr = getItr(x);\n        return itr\
    \ != s.end() ? *itr : node(x, x + 1, id);\n    }\n\n    S get(const T& x) const\
    \ {\n        auto seg = getSeg(x);\n        return seg.x;\n    }\n\n    S operator[](const\
    \ T& x) const { return get(x); }\n\n    template <typename ADD, typename DEL>\
    \ void apply(T l, T r, const S& x, const ADD& add, const DEL& del) {\n       \
    \ auto itr = s.lower_bound(node(l, std::numeric_limits<T>::min(), id));\n    \
    \    while (itr != s.end() and itr->l <= r) {\n            if (itr->l == r) {\n\
    \                if (itr->x == x) {\n                    del(itr->l, itr->r, itr->x);\n\
    \                    r = itr->r;\n                    itr = s.erase(itr);\n  \
    \              }\n                break;\n            }\n            if (itr->r\
    \ <= r) {\n                del(itr->l, itr->r, itr->x);\n                itr =\
    \ s.erase(itr);\n            } else {\n                if (itr->x == x) {\n  \
    \                  r = itr->r;\n                    del(itr->l, itr->r, itr->x);\n\
    \                    itr = s.erase(itr);\n                } else {\n         \
    \           del(itr->l, r, itr->x);\n                    node tmp = *itr;\n  \
    \                  itr = s.erase(itr);\n                    itr = s.emplace_hint(itr,\
    \ r, tmp.r, tmp.x);\n                }\n            }\n        }\n\n        if\
    \ (itr != s.begin()) {\n            itr = prev(itr);\n            if (itr->r ==\
    \ l) {\n                if (itr->x == x) {\n                    del(itr->l, itr->r,\
    \ itr->x);\n                    l = itr->l;\n                    itr = s.erase(itr);\n\
    \                }\n            } else if (l < itr->r) {\n                if (itr->x\
    \ == x) {\n                    del(itr->l, itr->r, itr->x);\n                \
    \    l = std::min(l, itr->l);\n                    r = std::max(r, itr->r);\n\
    \                    itr = s.erase(itr);\n                } else {\n         \
    \           if (r < itr->r) {\n                        itr = s.emplace_hint(next(itr),\
    \ r, itr->r, itr->x);\n                        itr = prev(itr);\n            \
    \        }\n                    del(l, std::min(r, itr->r), itr->x);\n       \
    \             node tmp = *itr;\n                    itr = s.erase(itr);\n    \
    \                itr = s.emplace_hint(itr, tmp.l, l, tmp.x);\n               \
    \ }\n            }\n        }\n\n        add(l, r, x);\n        s.emplace(l, r,\
    \ x);\n    }\n\n    void apply(T l, T r, const S& x) {\n        apply(\n     \
    \       l, r, x, [](T, T, S) {}, [](T, T, S) {});\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const IntervalManager& im) {\n        for (const\
    \ auto& e : im) os << \"([\" << e.l << \", \" << e.r << \"): \" << e.x << \")\
    \ \";\n        os << \"\\n\";\n        return os;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/IntervalManager.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/IntervalManager.hpp
layout: document
title: "\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\u69CB\u9020\u4F53"
---

## 概要

区間の挿入の際に自動でマージや削除等を行いながら値を管理する構造体。ほぼ丸々 Links の記事のパクリ。

## Links
- [区間を管理する構造体 - のいみのいみのいみのいみ](https://noimi.hatenablog.com/entry/2021/05/02/195143)