---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/BipartiteMatching.hpp
    title: Bipartite Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 2 \"flow/BipartiteMatching.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <random>\n\
    #include <utility>\n#include <vector>\n\nstruct BipartiteMatching {\n    BipartiteMatching(int\
    \ U, int V) : U(U), V(V), t(0), solved(false), G(U), L(U, -1), R(V, -1), visited(U,\
    \ -1) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < U);\n\
    \        assert(0 <= v && v < V);\n        G[u].emplace_back(v);\n    }\n\n  \
    \  void shuffle() {\n        static std::mt19937 mt;\n        for (auto& v : G)\
    \ std::shuffle(v.begin(), v.end(), mt);\n    }\n\n    int solve() {\n        for\
    \ (bool updated = true; std::exchange(updated, false); t++) {\n            for\
    \ (int i = 0; i < U; i++) {\n                if (L[i] == -1) {\n             \
    \       updated |= dfs(i);\n                }\n            }\n        }\n    \
    \    solved = true;\n        return U - std::count(L.begin(), L.end(), -1);\n\
    \    }\n\n    std::vector<std::pair<int, int>> max_matching() const {\n      \
    \  assert(solved);\n        std::vector<std::pair<int, int>> res;\n        for\
    \ (int i = 0; i < U; i++) {\n            if (~L[i]) {\n                res.emplace_back(i,\
    \ L[i]);\n            }\n        }\n        return res;\n    }\n\nprivate:\n \
    \   int U, V, t;\n    bool solved;\n    std::vector<std::vector<int>> G;\n   \
    \ std::vector<int> L, R, visited;\n\n    bool dfs(int u) {\n        if (std::exchange(visited[u],\
    \ t) == t) return false;\n        for (int& v : G[u]) {\n            if (R[v]\
    \ == -1) {\n                L[u] = v, R[v] = u;\n                return true;\n\
    \            }\n        }\n        for (int& v : G[u]) {\n            if (dfs(R[v]))\
    \ {\n                L[u] = v, R[v] = u;\n                return true;\n     \
    \       }\n        }\n        return false;\n    }\n};\n\n/**\n * @brief Bipartite\
    \ Matching\n * @docs docs/flow/BipartiteMatching.md\n */\n#line 2 \"base.hpp\"\
    \n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region\
    \ Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int\
    \ uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n   \
    \     os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T, typename U> ostream& operator<<(ostream& os, const unordered_map<T, U>& m)\
    \ {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n     \
    \   os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr !=\
    \ m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
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
    #line 5 \"test/yosupo/bipartitematching.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int L, R, M;\n    cin >> L >> R >> M;\n\
    \n    BipartiteMatching BM(L, R);\n    for (; M--;) {\n        int a, b;\n   \
    \     cin >> a >> b;\n        BM.add_edge(a, b);\n    }\n\n    BM.solve();\n \
    \   auto ans = BM.max_matching();\n    cout << ans.size() << '\\n';\n    for (auto\
    \ p : ans) cout << p.first << ' ' << p.second << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../flow/BipartiteMatching.hpp\"\n#include \"../../base.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int L, R,\
    \ M;\n    cin >> L >> R >> M;\n\n    BipartiteMatching BM(L, R);\n    for (; M--;)\
    \ {\n        int a, b;\n        cin >> a >> b;\n        BM.add_edge(a, b);\n \
    \   }\n\n    BM.solve();\n    auto ans = BM.max_matching();\n    cout << ans.size()\
    \ << '\\n';\n    for (auto p : ans) cout << p.first << ' ' << p.second << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - flow/BipartiteMatching.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
