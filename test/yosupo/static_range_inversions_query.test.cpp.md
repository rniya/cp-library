---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexd Tree (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: other/Mo.hpp
    title: Mo's algorithm
  - icon: ':heavy_check_mark:'
    path: util/compress.hpp
    title: "compress (\u5EA7\u6A19\u5727\u7E2E)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo/static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/BinaryIndexedTree.hpp\"\
    \n\ntemplate <typename T> struct BinaryIndexedTree {\n    BinaryIndexedTree(int\
    \ n) : n(n), data(n) {}\n\n    void add(int k, T x) {\n        assert(0 <= k &&\
    \ k < n);\n        for (k++; k <= n; k += k & -k) data[k - 1] += x;\n    }\n\n\
    \    T query(int l, int r) const {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        return sum(r) - sum(l);\n    }\n\n    T operator[](int i) const { return\
    \ query(i, i + 1); }\n\n    int lower_bound(T x) const {\n        if (x <= 0)\
    \ return 0;\n        int cur = 0, k = 1;\n        while (k < n) k <<= 1;\n   \
    \     for (; k > 0; k >>= 1) {\n            if (cur + k <= n && data[cur + k -\
    \ 1] < x) {\n                x -= data[cur + k - 1];\n                cur += k;\n\
    \            }\n        }\n        return cur;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n\n    T sum(int r) const {\n        T res = 0;\n        for (; r > 0;\
    \ r -= r & -r) res += data[r - 1];\n        return res;\n    }\n};\n\n/**\n *\
    \ @brief Binary Indexd Tree (Fenwick Tree)\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\n#line 6 \"other/Mo.hpp\"\n\nstruct Mo {\n    Mo(int n) : n(n) {}\n\n   \
    \ void add(int l, int r) {\n        assert(l <= r);\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL& add_left,\
    \ const AR& add_right, const DL& del_left, const DR del_right, const REM& rem)\
    \ {\n        int q = left.size(), width = n / std::min(std::max<int>(sqrt(q *\
    \ 2 / 3), 1), n);\n        std::vector<int> order(q);\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a, int\
    \ b) {\n            int ablock = left[a] / width, bblock = left[b] / width;\n\
    \            if (ablock != bblock) return ablock < bblock;\n            return\
    \ (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);\n        });\n\
    \n        int l = 0, r = 0;\n        for (auto idx : order) {\n            while\
    \ (l > left[idx]) add_left(--l);\n            while (r < right[idx]) add_right(r++);\n\
    \            while (l < left[idx]) del_left(l++);\n            while (r > right[idx])\
    \ del_right(--r);\n            rem(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename D, typename REM> void run(const A& add, const D& del, const REM&\
    \ rem) {\n        run(add, add, del, del, rem);\n    }\n\nprivate:\n    int n;\n\
    \    std::vector<int> left, right;\n};\n\n/**\n * @brief Mo's algorithm\n * @docs\
    \ docs/other/Mo.md\n */\n#line 5 \"util/compress.hpp\"\n\ntemplate <typename T>\
    \ std::map<T, int> compress(std::vector<T>& v) {\n    std::sort(v.begin(), v.end());\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n    std::map<T, int> res;\n\
    \    for (size_t i = 0; i < v.size(); i++) res[v[i]] = i;\n    return res;\n}\n\
    \n/**\n * @brief compress (\u5EA7\u6A19\u5727\u7E2E)\n */\n#line 7 \"test/yosupo/static_range_inversions_query.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> A(N);\n    for (int i = 0; i < N; i++)\
    \ cin >> A[i];\n\n    Mo mo(N);\n    for (int i = 0; i < Q; i++) {\n        int\
    \ l, r;\n        cin >> l >> r;\n        mo.add(l, r);\n    }\n\n    vector<int>\
    \ B = A;\n    map<int, int> mp = compress(B);\n    for (int i = 0; i < N; i++)\
    \ A[i] = mp[A[i]];\n    int n = mp.size();\n    BinaryIndexedTree<int> BIT(n);\n\
    \    vector<long long> ans(Q);\n    long long inv = 0;\n    int sum = 0;\n\n \
    \   auto add_left = [&](int idx) {\n        inv += BIT.query(0, A[idx]);\n   \
    \     sum++;\n        BIT.add(A[idx], 1);\n    };\n    auto add_right = [&](int\
    \ idx) {\n        inv += BIT.query(A[idx] + 1, n);\n        sum++;\n        BIT.add(A[idx],\
    \ 1);\n    };\n    auto del_left = [&](int idx) {\n        inv -= BIT.query(0,\
    \ A[idx]);\n        sum--;\n        BIT.add(A[idx], -1);\n    };\n    auto del_right\
    \ = [&](int idx) {\n        inv -= BIT.query(A[idx] + 1, n);\n        sum--;\n\
    \        BIT.add(A[idx], -1);\n    };\n    auto rem = [&](int idx) { ans[idx]\
    \ = inv; };\n\n    mo.run(add_left, add_right, del_left, del_right, rem);\n\n\
    \    for (int i = 0; i < Q; i++) cout << ans[i] << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/BinaryIndexedTree.hpp\"\
    \n#include \"../../other/Mo.hpp\"\n#include \"../../util/compress.hpp\"\n\nint\
    \ main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> A(N);\n    for (int i = 0; i < N; i++) cin\
    \ >> A[i];\n\n    Mo mo(N);\n    for (int i = 0; i < Q; i++) {\n        int l,\
    \ r;\n        cin >> l >> r;\n        mo.add(l, r);\n    }\n\n    vector<int>\
    \ B = A;\n    map<int, int> mp = compress(B);\n    for (int i = 0; i < N; i++)\
    \ A[i] = mp[A[i]];\n    int n = mp.size();\n    BinaryIndexedTree<int> BIT(n);\n\
    \    vector<long long> ans(Q);\n    long long inv = 0;\n    int sum = 0;\n\n \
    \   auto add_left = [&](int idx) {\n        inv += BIT.query(0, A[idx]);\n   \
    \     sum++;\n        BIT.add(A[idx], 1);\n    };\n    auto add_right = [&](int\
    \ idx) {\n        inv += BIT.query(A[idx] + 1, n);\n        sum++;\n        BIT.add(A[idx],\
    \ 1);\n    };\n    auto del_left = [&](int idx) {\n        inv -= BIT.query(0,\
    \ A[idx]);\n        sum--;\n        BIT.add(A[idx], -1);\n    };\n    auto del_right\
    \ = [&](int idx) {\n        inv -= BIT.query(A[idx] + 1, n);\n        sum--;\n\
    \        BIT.add(A[idx], -1);\n    };\n    auto rem = [&](int idx) { ans[idx]\
    \ = inv; };\n\n    mo.run(add_left, add_right, del_left, del_right, rem);\n\n\
    \    for (int i = 0; i < Q; i++) cout << ans[i] << '\\n';\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - datastructure/BinaryIndexedTree.hpp
  - other/Mo.hpp
  - util/compress.hpp
  isVerificationFile: true
  path: test/yosupo/static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2021-09-27 16:06:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_range_inversions_query.test.cpp
- /verify/test/yosupo/static_range_inversions_query.test.cpp.html
title: test/yosupo/static_range_inversions_query.test.cpp
---
