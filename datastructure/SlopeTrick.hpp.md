---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SlopeTrick.md
    document_title: Slope Trick
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/SlopeTrick.hpp\"\
    \n\n/**\n * @brief Slope Trick\n * @docs docs/datastructure/SlopeTrick.md\n */\n\
    template <typename T> class SlopeTrick {\n    const T inf = numeric_limits<T>::max()\
    \ / 3;\n    T min_f;\n    priority_queue<T, vector<T>, less<>> L;\n    priority_queue<T,\
    \ vector<T>, greater<>> R;\n    T add_l, add_r;\n\n    void push_L(const T& x)\
    \ { L.emplace(x - add_l); }\n    T top_L() const { return !L.empty() ? L.top()\
    \ + add_l : -inf; }\n    T pop_L() {\n        T res = top_L();\n        if (!L.empty())\
    \ L.pop();\n        return res;\n    }\n    void clear_left() {\n        while\
    \ (!L.empty()) L.pop();\n    }\n    void push_R(const T& x) { R.emplace(x - add_r);\
    \ }\n    T top_R() const { return !R.empty() ? R.top() + add_r : inf; }\n    T\
    \ pop_R() {\n        T res = top_R();\n        if (!R.empty()) R.pop();\n    \
    \    return res;\n    }\n    void clear_right() {\n        while (!R.empty())\
    \ R.pop();\n    }\n    size_t size() const { return L.size() + R.size(); }\n\n\
    public:\n    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\n    tuple<T, T, T>\
    \ query() const { return make_tuple(top_L(), top_R(), min_f); }\n    // f(x) +=\
    \ a\n    void add_all(const T& a) { min_f += a; }\n    // add _/\n    // f(x)\
    \ += max(x - a, 0)\n    void add_x_minus_a(const T& a) {\n        min_f += max(top_L()\
    \ - a, T(0));\n        push_L(a);\n        push_R(pop_L());\n    }\n    // add\
    \ \\_\n    // f(x) += max(a - x, 0)\n    void add_a_minus_x(const T& a) {\n  \
    \      min_f += max(a - top_R(), T(0));\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n    // add \\/\n    // f(x) += abs(x - a)\n    void add_abs(const T& a)\
    \ {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n    }\n\n    // \\\
    / -> \\_\n    // f(x) <- min_{y <= x} f(y)\n    void cumulative_min_left() { clear_right();\
    \ }\n    // \\/ -> _/\n    // f(x) <- min_{x <= y} f(y)\n    void cumulative_min_right()\
    \ { clear_left(); }\n\n    // f(x) <- min_{x- b <= y <= x - a} f(y)\n    void\
    \ shift(const T& a, const T& b) {\n        assert(a <= b);\n        add_l += a;\n\
    \        add_r += b;\n    }\n    // f(x) <- f(x - a)\n    // note after this operation,\
    \ L and R are empty\n    void shift(const T& a) { shift(a, a); }\n\n    T get(const\
    \ T& x) {\n        T res = min_f;\n        while (!L.empty()) res += max(pop_L()\
    \ - x, T(0));\n        while (!R.empty()) res += max(x - pop_R(), T(0));\n   \
    \     return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Slope Trick\n *\
    \ @docs docs/datastructure/SlopeTrick.md\n */\ntemplate <typename T> class SlopeTrick\
    \ {\n    const T inf = numeric_limits<T>::max() / 3;\n    T min_f;\n    priority_queue<T,\
    \ vector<T>, less<>> L;\n    priority_queue<T, vector<T>, greater<>> R;\n    T\
    \ add_l, add_r;\n\n    void push_L(const T& x) { L.emplace(x - add_l); }\n   \
    \ T top_L() const { return !L.empty() ? L.top() + add_l : -inf; }\n    T pop_L()\
    \ {\n        T res = top_L();\n        if (!L.empty()) L.pop();\n        return\
    \ res;\n    }\n    void clear_left() {\n        while (!L.empty()) L.pop();\n\
    \    }\n    void push_R(const T& x) { R.emplace(x - add_r); }\n    T top_R() const\
    \ { return !R.empty() ? R.top() + add_r : inf; }\n    T pop_R() {\n        T res\
    \ = top_R();\n        if (!R.empty()) R.pop();\n        return res;\n    }\n \
    \   void clear_right() {\n        while (!R.empty()) R.pop();\n    }\n    size_t\
    \ size() const { return L.size() + R.size(); }\n\npublic:\n    SlopeTrick() :\
    \ min_f(0), add_l(0), add_r(0) {}\n    tuple<T, T, T> query() const { return make_tuple(top_L(),\
    \ top_R(), min_f); }\n    // f(x) += a\n    void add_all(const T& a) { min_f +=\
    \ a; }\n    // add _/\n    // f(x) += max(x - a, 0)\n    void add_x_minus_a(const\
    \ T& a) {\n        min_f += max(top_L() - a, T(0));\n        push_L(a);\n    \
    \    push_R(pop_L());\n    }\n    // add \\_\n    // f(x) += max(a - x, 0)\n \
    \   void add_a_minus_x(const T& a) {\n        min_f += max(a - top_R(), T(0));\n\
    \        push_R(a);\n        push_L(pop_R());\n    }\n    // add \\/\n    // f(x)\
    \ += abs(x - a)\n    void add_abs(const T& a) {\n        add_x_minus_a(a);\n \
    \       add_a_minus_x(a);\n    }\n\n    // \\/ -> \\_\n    // f(x) <- min_{y <=\
    \ x} f(y)\n    void cumulative_min_left() { clear_right(); }\n    // \\/ -> _/\n\
    \    // f(x) <- min_{x <= y} f(y)\n    void cumulative_min_right() { clear_left();\
    \ }\n\n    // f(x) <- min_{x- b <= y <= x - a} f(y)\n    void shift(const T& a,\
    \ const T& b) {\n        assert(a <= b);\n        add_l += a;\n        add_r +=\
    \ b;\n    }\n    // f(x) <- f(x - a)\n    // note after this operation, L and\
    \ R are empty\n    void shift(const T& a) { shift(a, a); }\n\n    T get(const\
    \ T& x) {\n        T res = min_f;\n        while (!L.empty()) res += max(pop_L()\
    \ - x, T(0));\n        while (!R.empty()) res += max(x - pop_R(), T(0));\n   \
    \     return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SlopeTrick.hpp
  requiredBy: []
  timestamp: '2021-09-11 01:27:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/SlopeTrick.hpp
layout: document
redirect_from:
- /library/datastructure/SlopeTrick.hpp
- /library/datastructure/SlopeTrick.hpp.html
title: Slope Trick
---
## 概要
区分線形凸関数 $f(x)$ を傾きの変化点の集合を管理することで, 諸操作を効率的に行えるようにしたデータ構造.

- `query()` : $f(x)$ が最小値を取るような $x$ の最小値, 最大値, そのときの $f(x)$ の値を `tuple` にして返す.
- `add_all(a)` : $f(x)$ に均一に $a$ を加算する.
- `add_x_minus_a(a)` : $f(x)$ に $\max(x - a, 0)$ を加算する.
- `add_a_minus_x(a)` : $f(x)$ に $\max(a - x, 0)$ を加算する.
- `add_abs(a)` : $f(x)$ に $|x - a|$ を加算する.
- `cumulative_min_left()` : $f(x) \leftarrow \min_{y \leq x} f(y)$ とする.
- `cumulative_min_right()` : $f(x) \leftarrow \min_{x \leq y} f(y)$ とする.
- `shift(a, b)` : $f(x) \leftarrow \min_{y \in [x - b, x - a]} f(y)$ とする.
- `shift(a)` : $f(x) \leftarrow f(x - a)$ とする.
- `get(x)` : $f(x)$ を取得する. その際, それまでに取得した直線の情報は全て消えてしまうので注意.

## 計算量
- `query(), add_all()` : $O(1)$
- `add_x_minus_a(a), add_a_minus_x(a), add_abs(a)` : $O(\log Q)$
- `cumulative_min_left(), cumulative_min_right()` : $O(Q)$
- `shift(a, b), shift(a)` : $O(1)$
- `get(x)` : $O(Q)$

## 問題例
[AtCoder Beginner Contest 217 H- Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
[Codeforces LATOKEN Round 1 (Div. 1 + Div. 2) G. A New Beginning](https://codeforces.com/contest/1534/problem/G)

## 参照
[[Tutorial] Slope Trick - Codeforces](https://codeforces.com/blog/entry/47821)
[Slope trick explained - Codeforces](https://codeforces.com/blog/entry/77298)
[slope trick (1) 解説編 | maspyのHP](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
[Slope-Trick | Luzhiled’s Library](https://ei1333.github.io/library/structure/others/slope-trick.cpp)