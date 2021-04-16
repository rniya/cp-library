---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
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
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\ntemplate <typename T> class BinaryIndexedTree {\n    T sum(int i) {\n  \
    \      T res = T();\n        for (; i > 0; i -= (i & -i)) res += dat[i];\n   \
    \     return res;\n    }\n\npublic:\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int\
    \ n_) : n(n_ + 1), dat(n + 1, 0) {}\n    void add(int i, const T& x) {\n     \
    \   for (++i; i <= n; i += (i & -i)) dat[i] += x;\n    }\n    T query(int l, int\
    \ r) { return sum(r) - sum(l); }\n    int lower_bound(T x) const {\n        if\
    \ (x <= 0) return 0;\n        int pos = 0, k = 1;\n        while (k < n) k <<=\
    \ 1;\n        for (; k > 0; k >>= 1) {\n            if (pos + k <= n && dat[pos\
    \ + k] < x) {\n                x -= dat[pos + k];\n                pos += k;\n\
    \            }\n        }\n        return pos;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n    T operator[](int i) { return query(i,\
    \ i + 1); }\n};\n#line 3 \"tree/EulerTourforEdge.hpp\"\n\n/**\n * @brief Euler\
    \ Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)\n * @docs docs/tree/EulerTourforEdge.md\n\
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
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.test.cpp
- /verify/test/aoj/GRL_5_D.test.cpp.html
title: test/aoj/GRL_5_D.test.cpp
---
