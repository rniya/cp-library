---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/colopl2018_final_c.cpp
    title: test/atcoder/colopl2018_final_c.cpp
  - icon: ':warning:'
    path: test/atcoder/dp_z.cpp
    title: test/atcoder/dp_z.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/952.test.cpp
    title: test/yukicoder/952.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/ConvexHullTrick.md
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/ConvexHullTrick.hpp\"\
    \n\n/**\n * @brief Convex Hull Trick\n * @docs docs/datastructure/ConvexHullTrick.md\n\
    \ */\ntemplate <typename T, bool isMin = true> struct ConvexHullTrick {\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n    };\n  \
    \  deque<Line> Lines;\n    bool empty() const { return Lines.empty(); }\n    inline\
    \ int sgn(T a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }\n    inline bool check(const\
    \ Line& a, const Line& b, const Line& c) {\n        if (b.b == a.b || c.b == b.b)\
    \ return sgn(b.a - a.a) * sgn(c.b - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);\n\
    \        return (long double)(b.a - a.a) * sgn(c.b - b.b) / (long double)abs(b.b\
    \ - a.b) >=\n               (long double)(c.a - b.a) * sgn(b.b - a.b) / (long\
    \ double)abs(c.b - b.b);\n    }\n    void add(T a, T b) {\n        if (!isMin)\
    \ a *= -1, b *= -1;\n        Line l(a, b);\n        if (empty()) {\n         \
    \   Lines.emplace_back(l);\n            return;\n        }\n        if (Lines.front().a\
    \ <= a) {\n            if (Lines.front().a == a) {\n                if (Lines.front().b\
    \ <= b) return;\n                Lines.pop_front();\n            }\n         \
    \   while (Lines.size() >= 2 && check(l, Lines.front(), Lines[1])) Lines.pop_front();\n\
    \            Lines.emplace_front(l);\n        } else {\n            if (Lines.back().a\
    \ == a) {\n                if (Lines.back().b <= b) return;\n                Lines.pop_back();\n\
    \            }\n            while (Lines.size() >= 2 && check(Lines[Lines.size()\
    \ - 2], Lines.back(), l)) Lines.pop_back();\n            Lines.emplace_back(l);\n\
    \        }\n    }\n    inline T f(const Line& l, const T& x) { return l.a * x\
    \ + l.b; }\n    T query(T x) {\n        int lb = -1, ub = Lines.size() - 1;\n\
    \        while (ub - lb > 1) {\n            int mid = (ub + lb) >> 1;\n      \
    \      (f(Lines[mid], x) >= f(Lines[mid + 1], x) ? lb : ub) = mid;\n        }\n\
    \        return (isMin ? f(Lines[ub], x) : -f(Lines[ub], x));\n    }\n    T query_monotone_inc(T\
    \ x) {\n        while (Lines.size() >= 2 && f(Lines.front(), x) >= f(Lines[1],\
    \ x)) Lines.pop_front();\n        return (isMin ? f(Lines.front(), x) : -f(Lines.front(),\
    \ x));\n    }\n    T query_monotone_dec(T x) {\n        while (Lines.size() >=\
    \ 2 && f(Lines.back(), x) >= f(Lines[Lines.size() - 2], x)) Lines.pop_back();\n\
    \        return (isMin ? f(Lines.back(), x) : -f(Lines.back(), x));\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Convex Hull Trick\n\
    \ * @docs docs/datastructure/ConvexHullTrick.md\n */\ntemplate <typename T, bool\
    \ isMin = true> struct ConvexHullTrick {\n    struct Line {\n        T a, b;\n\
    \        Line(T a, T b) : a(a), b(b) {}\n    };\n    deque<Line> Lines;\n    bool\
    \ empty() const { return Lines.empty(); }\n    inline int sgn(T a) { return a\
    \ == 0 ? 0 : (a < 0 ? -1 : 1); }\n    inline bool check(const Line& a, const Line&\
    \ b, const Line& c) {\n        if (b.b == a.b || c.b == b.b) return sgn(b.a -\
    \ a.a) * sgn(c.b - b.b) >= sgn(c.a - b.a) * sgn(b.b - a.b);\n        return (long\
    \ double)(b.a - a.a) * sgn(c.b - b.b) / (long double)abs(b.b - a.b) >=\n     \
    \          (long double)(c.a - b.a) * sgn(b.b - a.b) / (long double)abs(c.b -\
    \ b.b);\n    }\n    void add(T a, T b) {\n        if (!isMin) a *= -1, b *= -1;\n\
    \        Line l(a, b);\n        if (empty()) {\n            Lines.emplace_back(l);\n\
    \            return;\n        }\n        if (Lines.front().a <= a) {\n       \
    \     if (Lines.front().a == a) {\n                if (Lines.front().b <= b) return;\n\
    \                Lines.pop_front();\n            }\n            while (Lines.size()\
    \ >= 2 && check(l, Lines.front(), Lines[1])) Lines.pop_front();\n            Lines.emplace_front(l);\n\
    \        } else {\n            if (Lines.back().a == a) {\n                if\
    \ (Lines.back().b <= b) return;\n                Lines.pop_back();\n         \
    \   }\n            while (Lines.size() >= 2 && check(Lines[Lines.size() - 2],\
    \ Lines.back(), l)) Lines.pop_back();\n            Lines.emplace_back(l);\n  \
    \      }\n    }\n    inline T f(const Line& l, const T& x) { return l.a * x +\
    \ l.b; }\n    T query(T x) {\n        int lb = -1, ub = Lines.size() - 1;\n  \
    \      while (ub - lb > 1) {\n            int mid = (ub + lb) >> 1;\n        \
    \    (f(Lines[mid], x) >= f(Lines[mid + 1], x) ? lb : ub) = mid;\n        }\n\
    \        return (isMin ? f(Lines[ub], x) : -f(Lines[ub], x));\n    }\n    T query_monotone_inc(T\
    \ x) {\n        while (Lines.size() >= 2 && f(Lines.front(), x) >= f(Lines[1],\
    \ x)) Lines.pop_front();\n        return (isMin ? f(Lines.front(), x) : -f(Lines.front(),\
    \ x));\n    }\n    T query_monotone_dec(T x) {\n        while (Lines.size() >=\
    \ 2 && f(Lines.back(), x) >= f(Lines[Lines.size() - 2], x)) Lines.pop_back();\n\
    \        return (isMin ? f(Lines.back(), x) : -f(Lines.back(), x));\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/ConvexHullTrick.hpp
  requiredBy:
  - test/atcoder/colopl2018_final_c.cpp
  - test/atcoder/dp_z.cpp
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/952.test.cpp
documentation_of: datastructure/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/datastructure/ConvexHullTrick.hpp
- /library/datastructure/ConvexHullTrick.hpp.html
title: Convex Hull Trick
---
## 概要

## 計算量