---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':x:'
    path: string/Manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
  bundledCode: "#line 1 \"test/atcoder/ukuku09_d.cpp\"\n#define IGNORE\n\n#define\
    \ PROBLEM \"https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d\"\n\n#line 2 \"\
    base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long\
    \ ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/SegmentTree.hpp\"\
    \n\n/**\n * @brief Segment Tree\n * @docs docs/datastructure/SegmentTree.md\n\
    \ */\ntemplate <typename Monoid> struct SegmentTree {\n    typedef function<Monoid(Monoid,\
    \ Monoid)> F;\n    int n;\n    F f;\n    Monoid id;\n    vector<Monoid> dat;\n\
    \    SegmentTree(int n_, F f, Monoid id) : f(f), id(id) { init(n_); }\n    void\
    \ init(int n_) {\n        n = 1;\n        while (n < n_) n <<= 1;\n        dat.assign(n\
    \ << 1, id);\n    }\n    void build(const vector<Monoid>& v) {\n        for (int\
    \ i = 0; i < v.size(); i++) dat[i + n] = v[i];\n        for (int i = n - 1; i;\
    \ i--) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);\n    }\n    void update(int\
    \ k, Monoid x) {\n        dat[k += n] = x;\n        while (k >>= 1) dat[k] = f(dat[k\
    \ << 1 | 0], dat[k << 1 | 1]);\n    }\n    Monoid query(int a, int b) {\n    \
    \    if (a >= b) return id;\n        Monoid vl = id, vr = id;\n        for (int\
    \ l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl\
    \ = f(vl, dat[l++]);\n            if (r & 1) vr = f(dat[--r], vr);\n        }\n\
    \        return f(vl, vr);\n    }\n    template <typename C> int find_subtree(int\
    \ k, const C& check, Monoid& M, bool type) {\n        while (k < n) {\n      \
    \      Monoid nxt = type ? f(dat[k << 1 | type], M) : f(M, dat[k << 1 | type]);\n\
    \            if (check(nxt))\n                k = k << 1 | type;\n           \
    \ else\n                M = nxt, k = k << 1 | (type ^ 1);\n        }\n       \
    \ return k - n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy\
    \ \"check\"\n    template <typename C> int find_first(int a, const C& check) {\n\
    \        Monoid L = id;\n        if (a <= 0) {\n            if (check(f(L, dat[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = n;\n        for (int l = a + n, r = b + n; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, dat[l]);\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return -1;\n    }\n    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy\
    \ \"check\"\n    template <typename C> int find_last(int b, const C& check) {\n\
    \        Monoid R = id;\n        if (b >= n) {\n            if (check(f(dat[1],\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        int a = n;\n        for (int l = a, r = b + n; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (r & 1) {\n                Monoid nxt = f(dat[--r],\
    \ R);\n                if (check(nxt)) return find_subtree(r, check, R, true);\n\
    \                R = nxt;\n            }\n        }\n        return -1;\n    }\n\
    \    Monoid operator[](int i) { return dat[i + n]; }\n};\n#line 3 \"string/Manacher.hpp\"\
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
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ukuku09_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/ukuku09_d.cpp
- /library/test/atcoder/ukuku09_d.cpp.html
title: test/atcoder/ukuku09_d.cpp
---
