---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/DualSegmentTree.hpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.DualSegmentTree.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\n\n#line\
    \ 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n     \
    \   os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/DualSegmentTree.hpp\"\
    \n\n/**\n * @brief Dual Segment Tree\n * @docs docs/datastructure/DualSegmentTree.md\n\
    \ */\ntemplate <typename OperatorMonoid> struct DualSegmentTree {\n    typedef\
    \ function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> H;\n    int n, hi;\n\
    \    H h;\n    OperatorMonoid id1;\n    vector<OperatorMonoid> laz;\n    DualSegmentTree(int\
    \ n_, H h, OperatorMonoid id1) : h(h), id1(id1) { init(n_); }\n    void init(int\
    \ n_) {\n        n = 1, hi = 0;\n        while (n < n_) n <<= 1, hi++;\n     \
    \   laz.assign(n << 1, id1);\n    }\n    inline void propagate(int k) {\n    \
    \    if (laz[k] == id1) return;\n        laz[k << 1 | 0] = h(laz[k << 1 | 0],\
    \ laz[k]);\n        laz[k << 1 | 1] = h(laz[k << 1 | 1], laz[k]);\n        laz[k]\
    \ = id1;\n    }\n    inline void thrust(int k) {\n        for (int i = hi; i;\
    \ i--) propagate(k >> i);\n    }\n    void update(int a, int b, OperatorMonoid\
    \ x) {\n        if (a >= b) return;\n        thrust(a += n);\n        thrust(b\
    \ += n - 1);\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) laz[l] = h(laz[l], x), ++l;\n            if (r & 1) --r,\
    \ laz[r] = h(laz[r], x);\n        }\n    }\n    void set_val(int k, OperatorMonoid\
    \ x) {\n        thrust(k += n);\n        laz[k] = x;\n    }\n    OperatorMonoid\
    \ operator[](int k) {\n        thrust(k += n);\n        return laz[k];\n    }\n\
    };\n#line 5 \"test/aoj/DSL_2_D.DualSegmentTree.test.cpp\"\n\nint main() {\n  \
    \  cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n, q;\n    cin >> n\
    \ >> q;\n\n    auto h = [](int a, int b) { return b; };\n    DualSegmentTree<int>\
    \ seg(n, h, INT_MAX);\n\n    for (; q--;) {\n        int c, s, t, x, i;\n    \
    \    cin >> c;\n        if (!c) {\n            cin >> s >> t >> x;\n         \
    \   seg.update(s, t + 1, x);\n        } else {\n            cin >> i;\n      \
    \      cout << seg[i] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/DualSegmentTree.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    cin >> n >> q;\n\n    auto h = [](int a, int b) { return b; };\n   \
    \ DualSegmentTree<int> seg(n, h, INT_MAX);\n\n    for (; q--;) {\n        int\
    \ c, s, t, x, i;\n        cin >> c;\n        if (!c) {\n            cin >> s >>\
    \ t >> x;\n            seg.update(s, t + 1, x);\n        } else {\n          \
    \  cin >> i;\n            cout << seg[i] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/DualSegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.DualSegmentTree.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.DualSegmentTree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.DualSegmentTree.test.cpp
- /verify/test/aoj/DSL_2_D.DualSegmentTree.test.cpp.html
title: test/aoj/DSL_2_D.DualSegmentTree.test.cpp
---
