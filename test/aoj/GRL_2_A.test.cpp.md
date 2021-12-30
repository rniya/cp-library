---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.hpp
    title: datastructure/UnionFind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Kruskal.hpp
    title: Kruskal
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\n\
    typedef unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (size_t i =\
    \ 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
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
    \ os, const deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n    \
    \    os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, size_t N> ostream& operator<<(ostream& os, const array<T,\
    \ N>& v) {\n    for (size_t i = 0; i < N; i++) {\n        os << v[i] << (i + 1\
    \ == N ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename\
    \ T> void print_tuple(ostream&, const T&) {}\ntemplate <int i, typename T, typename\
    \ H, class... Args> void print_tuple(ostream& os, const T& t) {\n    if (i) os\
    \ << ',';\n    os << get<i>(t);\n    print_tuple<i + 1, T, Args...>(os, t);\n\
    }\ntemplate <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>&\
    \ t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>, Args...>(os, t);\n\
    \    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class\
    \ Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate\
    \ <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate\
    \ <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n#pragma endregion\n\
    #line 5 \"datastructure/UnionFind.hpp\"\n\nstruct UnionFind {\n    UnionFind(int\
    \ n) : n(n), num(n), data(n, -1) {}\n\n    int find(int x) {\n        assert(0\
    \ <= x && x < n);\n        return data[x] < 0 ? x : data[x] = find(data[x]);\n\
    \    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x && x < n);\n \
    \       assert(0 <= y && y < n);\n        if ((x = find(x)) == (y = find(y)))\
    \ return false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        num--;\n        return true;\n  \
    \  }\n\n    bool same(int x, int y) {\n        assert(0 <= x && x < n);\n    \
    \    assert(0 <= y && y < n);\n        return find(x) == find(y);\n    }\n\n \
    \   int size(int x) {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n\
    \    }\n\n    int count() const { return num; }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<std::vector<int>> res(n);\n        for (int\
    \ i = 0; i < n; i++) res[find(i)].emplace_back(i);\n        res.erase(std::remove_if(res.begin(),\
    \ res.end(), [&](const std::vector<int>& v) { return v.empty(); }));\n       \
    \ return res;\n    }\n\n    int operator[](int x) { return find(x); }\n\nprivate:\n\
    \    int n, num;\n    // root node : -1 * component size\n    // otherwise : parent\n\
    \    std::vector<int> data;\n};\n#line 6 \"graph/Kruskal.hpp\"\n\ntemplate <typename\
    \ T> struct Kruskal {\n    Kruskal(int n) : n(n), called_build(false) {}\n\n \
    \   void add_edge(int u, int v, T cost, int idx = 0) {\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        es.emplace_back(u, v,\
    \ cost, idx);\n    }\n\n    T build() {\n        called_build = true;\n      \
    \  std::sort(es.begin(), es.end());\n        UnionFind uf(n);\n        T res =\
    \ 0;\n        for (auto& e : es) {\n            if (uf.merge(e.u, e.v)) {\n  \
    \              res += e.cost;\n                e.used = true;\n            }\n\
    \        }\n        return res;\n    }\n\n    std::vector<int> used_edges() {\n\
    \        assert(called_build);\n        int m = es.size();\n        std::vector<int>\
    \ res(m);\n        for (int i = 0; i < m; i++) res[es[i].idx] = es[i].used;\n\
    \        return res;\n    }\n\nprivate:\n    struct edge {\n        int u, v;\n\
    \        T cost;\n        int idx, used;\n        edge(int u, int v, T cost, int\
    \ idx) : u(u), v(v), cost(cost), idx(idx), used(false) {}\n        bool operator<(const\
    \ edge& e) const { return cost < e.cost; }\n    };\n    int n;\n    bool called_build;\n\
    \    std::vector<edge> es;\n};\n#line 5 \"test/aoj/GRL_2_A.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n    cin\
    \ >> V >> E;\n\n    Kruskal<int> K(V);\n\n    for (int i = 0; i < E; i++) {\n\
    \        int s, t, w;\n        cin >> s >> t >> w;\n        K.add_edge(s, t, w);\n\
    \    }\n\n    cout << K.build() << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/Kruskal.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n    cin\
    \ >> V >> E;\n\n    Kruskal<int> K(V);\n\n    for (int i = 0; i < E; i++) {\n\
    \        int s, t, w;\n        cin >> s >> t >> w;\n        K.add_edge(s, t, w);\n\
    \    }\n\n    cout << K.build() << '\\n';\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - graph/Kruskal.hpp
  - datastructure/UnionFind.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
