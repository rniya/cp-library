---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/ConvexHullTrick.hpp
    title: Convex Hull Trick (Add-Monotonic Slope Optimization)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c
  bundledCode: "#line 1 \"test/atcoder/colopl2018_final_c.cpp\"\n#define IGNORE\n\n\
    #define PROBLEM \"https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/ConvexHullTrick.hpp\"\
    \n\ntemplate <typename T, bool isMin = true> struct ConvexHullTrick {\n    bool\
    \ empty() const { return lines.empty(); }\n\n    void add(T a, T b) {\n      \
    \  if (!isMin) a *= -1, b *= -1;\n        std::pair<T, T> l(a, b);\n        if\
    \ (empty()) {\n            lines.emplace_back(a, b);\n            return;\n  \
    \      }\n        if (lines.front().first <= a) {\n            if (lines.front().first\
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
    \ x) { return l.first * x + l.second; }\n};\n\n/**\n * @brief Convex Hull Trick\
    \ (Add-Monotonic Slope Optimization)\n * @docs docs/datastructure/ConvexHullTrick.md\n\
    \ */\n#line 7 \"test/atcoder/colopl2018_final_c.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N;\n    cin >> N;\n    vector<long\
    \ long> a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\n    ConvexHullTrick<long\
    \ long> CHT;\n\n    for (long long i = 0; i < N; i++) CHT.add(-2 * i, a[i] + i\
    \ * i);\n    for (long long i = 0; i < N; i++) cout << CHT.query_monotone_inc(i)\
    \ + i * i << '\\n';\n}\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/ConvexHullTrick.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n\
    \    cin >> N;\n    vector<long long> a(N);\n    for (int i = 0; i < N; i++) cin\
    \ >> a[i];\n\n    ConvexHullTrick<long long> CHT;\n\n    for (long long i = 0;\
    \ i < N; i++) CHT.add(-2 * i, a[i] + i * i);\n    for (long long i = 0; i < N;\
    \ i++) cout << CHT.query_monotone_inc(i) + i * i << '\\n';\n}"
  dependsOn:
  - base.hpp
  - datastructure/ConvexHullTrick.hpp
  isVerificationFile: false
  path: test/atcoder/colopl2018_final_c.cpp
  requiredBy: []
  timestamp: '2021-09-22 12:29:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/colopl2018_final_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/colopl2018_final_c.cpp
- /library/test/atcoder/colopl2018_final_c.cpp.html
title: test/atcoder/colopl2018_final_c.cpp
---
