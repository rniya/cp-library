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
    path: tree/EulerTourforEdge.hpp
    title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
  bundledCode: "#line 1 \"test/aoj/GRL_5_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
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
    \ */\n#line 3 \"tree/EulerTourforEdge.hpp\"\n\n/**\n * @brief Euler Tour (\u30D1\
    \u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)\n * @docs docs/tree/EulerTourforEdge.md\n\
    \ */\nclass EulerTourforEdge {\n    vector<int> ds, us, dep, btm;\n    void dfs(int\
    \ v, int p, int d) {\n        dep[v] = d;\n        for (int u : G[v]) {\n    \
    \        if (u == p) continue;\n            ds[u] = btm.size();\n            btm.emplace_back(u);\n\
    \            dfs(u, v, d + 1);\n            us[u] = btm.size();\n            btm.emplace_back(u);\n\
    \        }\n    }\n\npublic:\n    vector<vector<int>> G;\n    EulerTourforEdge(int\
    \ n) : ds(n), us(n), dep(n), G(n) {}\n    void add_edge(int u, int v) {\n    \
    \    G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    void build(int\
    \ r = 0) {\n        btm.clear();\n        ds[r] = btm.size();\n        btm.emplace_back(r);\n\
    \        dfs(r, -1, 0);\n        us[r] = btm.size();\n        btm.emplace_back(r);\n\
    \    }\n    int child(int u, int v) { return dep[u] < dep[v] ? v : u; }\n    int\
    \ bottom(int e) { return btm[e]; }\n    template <typename T, typename F> T query(int\
    \ v, F f) { return f(0, us[v]); }\n    // u or v must be lca(u,v)\n    template\
    \ <typename T, typename F> T query(int u, int v, F f) {\n        if (dep[u] <\
    \ dep[v]) swap(u, v);\n        return query<T>(u, f) - query<T>(v, f);\n    }\n\
    \    // v is child of the edge\n    template <typename T, typename G> void update(int\
    \ v, T x, G g) {\n        g(ds[v], x);\n        g(us[v], -x);\n    }\n};\n#line\
    \ 6 \"test/aoj/GRL_5_D.test.cpp\"\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n;\n    cin >> n;\n\n    EulerTourforEdge ET(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int k;\n        cin >> k;\n        for (; k--;) {\n \
    \           int c;\n            cin >> c;\n            ET.add_edge(i, c);\n  \
    \      }\n    }\n\n    ET.build();\n    BinaryIndexedTree<int> BIT(2 * n);\n \
    \   auto f = [&](int l, int r) { return BIT.query(l, r); };\n    auto g = [&](int\
    \ k, int w) { BIT.add(k, w); };\n\n    int q;\n    cin >> q;\n    for (; q--;)\
    \ {\n        int t;\n        cin >> t;\n        if (!t) {\n            int v,\
    \ w;\n            cin >> v >> w;\n            ET.update(v, w, g);\n        } else\
    \ {\n            int u;\n            cin >> u;\n            cout << ET.query<int>(u,\
    \ f) << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/BinaryIndexedTree.hpp\"\
    \n#include \"../../tree/EulerTourforEdge.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n;\n    cin >> n;\n\n    EulerTourforEdge\
    \ ET(n);\n    for (int i = 0; i < n; i++) {\n        int k;\n        cin >> k;\n\
    \        for (; k--;) {\n            int c;\n            cin >> c;\n         \
    \   ET.add_edge(i, c);\n        }\n    }\n\n    ET.build();\n    BinaryIndexedTree<int>\
    \ BIT(2 * n);\n    auto f = [&](int l, int r) { return BIT.query(l, r); };\n \
    \   auto g = [&](int k, int w) { BIT.add(k, w); };\n\n    int q;\n    cin >> q;\n\
    \    for (; q--;) {\n        int t;\n        cin >> t;\n        if (!t) {\n  \
    \          int v, w;\n            cin >> v >> w;\n            ET.update(v, w,\
    \ g);\n        } else {\n            int u;\n            cin >> u;\n         \
    \   cout << ET.query<int>(u, f) << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/BinaryIndexedTree.hpp
  - tree/EulerTourforEdge.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-09-20 21:09:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.test.cpp
- /verify/test/aoj/GRL_5_D.test.cpp.html
title: test/aoj/GRL_5_D.test.cpp
---
