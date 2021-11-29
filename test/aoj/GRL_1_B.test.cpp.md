---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/BellmanFord.hpp
    title: Bellman-Ford
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
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
    #line 6 \"graph/BellmanFord.hpp\"\n\ntemplate <typename T> struct BellmanFord\
    \ {\n    BellmanFord(int n) : n(n), d(n) {}\n\n    void add_edge(int from, int\
    \ to, T cost) {\n        assert(0 <= from and from < n);\n        assert(0 <=\
    \ to and to < n);\n        es.emplace_back(from, to, cost);\n    }\n\n    bool\
    \ find_negative_loop() {\n        fill(d.begin(), d.end(), 0);\n        for (int\
    \ i = 0, updated = 1; i < n and std::exchange(updated, 0); i++) {\n          \
    \  for (auto& e : es) {\n                if (d[e.from] + e.cost < d[e.to]) {\n\
    \                    d[e.to] = d[e.from] + e.cost;\n                    updated\
    \ = 1;\n                }\n            }\n            if (!updated) return true;\n\
    \            if (i == n - 1) return false;\n        }\n    }\n\n    std::vector<T>\
    \ solve(int s) {\n        assert(0 <= s and s < n);\n        fill(d.begin(), d.end(),\
    \ inf);\n        d[s] = 0;\n        for (int i = 0, updated = 1; i < n and std::exchange(updated,\
    \ 0); i++) {\n            for (auto& e : es) {\n                if (d[e.from]\
    \ != inf and d[e.from] + e.cost < d[e.to]) {\n                    d[e.to] = d[e.from]\
    \ + e.cost;\n                    updated = 1;\n                }\n           \
    \ }\n            if (!updated) break;\n            if (i == n - 1) return {};\n\
    \        }\n        return d;\n    }\n\n    std::vector<T> shortest_path(int s,\
    \ int t) {\n        assert(0 <= s and s < n);\n        assert(0 <= t and t < n);\n\
    \        fill(d.begin(), d.end(), inf);\n        d[s] = 0;\n        for (int i\
    \ = 0; i < 2 * n - 1; i++) {\n            for (auto& e : es) {\n             \
    \   if (d[e.from] != inf and d[e.from] + e.cost < d[e.to]) {\n               \
    \     d[e.to] = d[e.from] + e.cost;\n                    if (i >= n - 1) {\n \
    \                       if (e.to == t) return {};\n                        d[e.to]\
    \ = -inf;\n                    }\n                }\n            }\n        }\n\
    \        return d;\n    }\n\nprivate:\n    struct edge {\n        int from, to;\n\
    \        T cost;\n        edge(int from, int to, T cost) : from(from), to(to),\
    \ cost(cost) {}\n    };\n    int n;\n    const T inf = std::numeric_limits<T>::max()\
    \ / 2;\n    std::vector<T> d;\n    std::vector<edge> es;\n};\n\n/**\n * @brief\
    \ Bellman-Ford\n * @docs docs/graph/BellmanFord.md\n */\n#line 5 \"test/aoj/GRL_1_B.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V,\
    \ E, r;\n    cin >> V >> E >> r;\n\n    BellmanFord<int> BF(V);\n\n    for (int\
    \ i = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n  \
    \      BF.add_edge(s, t, d);\n    }\n\n    auto ans = BF.solve(r);\n    if (ans.empty())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\
    \    for (int i = 0; i < V; i++) {\n        if (ans[i] > 1e9)\n            cout\
    \ << \"INF\" << '\\n';\n        else\n            cout << ans[i] << '\\n';\n \
    \   }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/BellmanFord.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E,\
    \ r;\n    cin >> V >> E >> r;\n\n    BellmanFord<int> BF(V);\n\n    for (int i\
    \ = 0; i < E; i++) {\n        int s, t, d;\n        cin >> s >> t >> d;\n    \
    \    BF.add_edge(s, t, d);\n    }\n\n    auto ans = BF.solve(r);\n    if (ans.empty())\
    \ {\n        cout << \"NEGATIVE CYCLE\" << '\\n';\n        return 0;\n    }\n\
    \    for (int i = 0; i < V; i++) {\n        if (ans[i] > 1e9)\n            cout\
    \ << \"INF\" << '\\n';\n        else\n            cout << ans[i] << '\\n';\n \
    \   }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - graph/BellmanFord.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---
