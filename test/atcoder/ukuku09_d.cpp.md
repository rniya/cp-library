---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: string/Manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
  bundledCode: "#line 1 \"test/atcoder/ukuku09_d.cpp\"\n#define IGNORE\n\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d\"\n\n#line 2 \"\
    base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region Macros\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/SegmentTree.hpp\"\
    \n\ntemplate <typename Monoid, typename F> struct SegmentTree {\n    SegmentTree(int\
    \ n, const F f, const Monoid& e) : n(n), f(f), e(e) {\n        size = 1;\n   \
    \     while (size < n) size <<= 1;\n        data.assign(size << 1, e);\n    }\n\
    \n    void set(int k, Monoid x) {\n        assert(0 <= k && k < n);\n        data[k\
    \ + size] = x;\n    }\n\n    void build() {\n        for (int k = size - 1; k\
    \ > 0; k--) {\n            data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n\
    \        }\n    }\n\n    void update(int k, Monoid x) {\n        assert(0 <= k\
    \ && k < n);\n        k += size;\n        data[k] = x;\n        while (k >>= 1)\
    \ data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n    }\n\n    void add(int\
    \ k, Monoid x) {\n        assert(0 <= k && k < n);\n        k += size;\n     \
    \   data[k] += x;\n        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k\
    \ << 1 | 1]);\n    }\n\n    Monoid query(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        Monoid L = e, R = e;\n        for (l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = f(L,\
    \ data[l++]);\n            if (r & 1) R = f(data[--r], R);\n        }\n      \
    \  return f(L, R);\n    }\n\n    Monoid all_prod() const { return data[1]; }\n\
    \n    Monoid operator[](const int& k) const { return data[k + size]; }\n\n   \
    \ template <typename C> int find_first(int l, const C& check) {\n        assert(0\
    \ <= l && l <= n);\n        assert(!check(e));\n        if (l == n) return n;\n\
    \        Monoid L = e;\n        if (l == 0) {\n            if (check(f(L, data[1])))\
    \ return find_subtree(1, check, L, false);\n            return n;\n        }\n\
    \        int r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, data[l]);\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return n;\n    }\n\n    template <typename C> int find_last(int r, const\
    \ C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(data[1], R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        int l = size;\n        for (r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n                Monoid\
    \ nxt = f(data[--r], R);\n                if (check(nxt)) return find_subtree(r,\
    \ check, R, false);\n                R = nxt;\n            }\n        }\n    \
    \    return -1;\n    }\n\nprivate:\n    int n, size;\n    std::vector<Monoid>\
    \ data;\n    const F f;\n    const Monoid e;\n\n    template <typename C> int\
    \ find_subtree(int a, const C& check, Monoid& M, bool type) {\n        while (a\
    \ < size) {\n            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M,\
    \ data[a << 1 | type]);\n            if (check(nxt))\n                a = a <<\
    \ 1 | type;\n            else\n                M = nxt, a = (a << 1 | 1) - type;\n\
    \        }\n        return a - size;\n    }\n};\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/datastructure/SegmentTree.md\n */\n#line 3 \"string/Manacher.hpp\"\
    \n\n/**\n * @brief Manacher\n * @docs docs/string/Manacher.md\n */\nvector<int>\
    \ Manacher(const string& s) {\n    int n = s.size();\n    vector<int> res(n);\n\
    \    for (int i = 0, j = 0; i < n;) {\n        while (i - j >= 0 && i + j < n\
    \ && s[i - j] == s[i + j]) j++;\n        res[i] = j;\n        int k = 1;\n   \
    \     while (i - k >= 0 && i + k < n && k + res[i - k] < j) res[i + k] = res[i\
    \ - k], k++;\n        i += k, j -= k;\n    }\n    return res;\n}\n\nvector<int>\
    \ PalindromeTable(const string& s) {\n    int n = s.size();\n    string t(n *\
    \ 2 + 1, '$');\n    for (int i = 0; i < n; i++) t[i * 2 + 1] = s[i];\n    vector<int>\
    \ v = Manacher(t), res;\n    for (int i = 1; i < n * 2; i++) res.emplace_back(v[i]\
    \ - 1);\n    return res;\n}\n#line 8 \"test/atcoder/ukuku09_d.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N, Q;\n    string\
    \ S;\n    cin >> N >> Q >> S;\n\n    vector<int> v = Manacher(S);\n    SegmentTree<int>\
    \ seg(\n        N, [](int a, int b) { return max(a, b); }, 0);\n    seg.build(v);\n\
    \n    for (; Q--;) {\n        int l, r;\n        cin >> l >> r;\n        --l;\n\
    \        int lb = 0, ub = (r - l + 1) / 2 + 1;\n        while (ub - lb > 1) {\n\
    \            int mid = (lb + ub) >> 1;\n            int x = seg.query(l + mid\
    \ - 1, r - mid + 1);\n            (mid <= x ? lb : ub) = mid;\n        }\n   \
    \     cout << lb * 2 - 1 << '\\n';\n    }\n}\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTree.hpp\"\
    \n#include \"../../string/Manacher.hpp\"\n\nint main() {\n    cin.tie(0);\n  \
    \  ios::sync_with_stdio(false);\n    int N, Q;\n    string S;\n    cin >> N >>\
    \ Q >> S;\n\n    vector<int> v = Manacher(S);\n    SegmentTree<int> seg(\n   \
    \     N, [](int a, int b) { return max(a, b); }, 0);\n    seg.build(v);\n\n  \
    \  for (; Q--;) {\n        int l, r;\n        cin >> l >> r;\n        --l;\n \
    \       int lb = 0, ub = (r - l + 1) / 2 + 1;\n        while (ub - lb > 1) {\n\
    \            int mid = (lb + ub) >> 1;\n            int x = seg.query(l + mid\
    \ - 1, r - mid + 1);\n            (mid <= x ? lb : ub) = mid;\n        }\n   \
    \     cout << lb * 2 - 1 << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTree.hpp
  - string/Manacher.hpp
  isVerificationFile: false
  path: test/atcoder/ukuku09_d.cpp
  requiredBy: []
  timestamp: '2021-09-20 22:49:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ukuku09_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/ukuku09_d.cpp
- /library/test/atcoder/ukuku09_d.cpp.html
title: test/atcoder/ukuku09_d.cpp
---
