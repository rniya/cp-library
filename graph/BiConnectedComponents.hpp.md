---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: graph/LowLink.hpp
    title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"graph/LowLink.hpp\"\
    \n\n/**\n * @brief Low Link (\u6A4B/\u95A2\u7BC0\u70B9)\n * @docs docs/graph/LowLink.md\n\
    \ */\nstruct LowLink {\n    int n, time;\n    vector<int> ord, low;\n    vector<vector<int>>\
    \ G;\n    vector<int> articulation;\n    vector<pair<int, int>> bridge;\n    LowLink(int\
    \ n) : n(n), time(0), ord(n, -1), low(n), G(n) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\
    \    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v]) swap(u, v);\n\
    \        return ord[u] < low[v];\n    }\n    void dfs(int v, int p) {\n      \
    \  ord[v] = low[v] = time++;\n        bool is_articulation = false;\n        int\
    \ cnt = 0;\n        for (int u : G[v]) {\n            if (u == p) continue;\n\
    \            if (~ord[u]) {\n                low[v] = min(low[v], ord[u]);\n \
    \               continue;\n            }\n            cnt++;\n            dfs(u,\
    \ v);\n            low[v] = min(low[v], low[u]);\n            is_articulation\
    \ |= (~p && ord[v] <= low[u]);\n            if (is_bridge(v, u)) bridge.emplace_back(v,\
    \ u);\n        }\n        is_articulation |= (p < 0 && cnt > 1);\n        if (is_articulation)\
    \ articulation.emplace_back(v);\n    }\n    void build() {\n        for (int v\
    \ = 0; v < n; v++) {\n            if (ord[v] < 0) dfs(v, -1);\n        }\n   \
    \ }\n};\n#line 3 \"graph/BiConnectedComponents.hpp\"\n\nstruct BiConnectedComponents\
    \ : LowLink {\n    using LowLink::G;\n    using LowLink::low;\n    using LowLink::LowLink;\n\
    \    using LowLink::ord;\n\n    vector<vector<pair<int, int>>> bc;\n    vector<pair<int,\
    \ int>> tmp;\n    vector<bool> used;\n\n    vector<vector<pair<int, int>>> build()\
    \ {\n        LowLink::build();\n        used.assign(G.size(), false);\n      \
    \  for (size_t i = 0; i < used.size(); i++) {\n            if (used[i]) continue;\n\
    \            dfs(i, -1);\n        }\n        return bc;\n    }\n\n    void dfs(int\
    \ v, int p) {\n        used[v] = true;\n        bool flag = false;\n        for\
    \ (int& u : G[v]) {\n            if (u == p && !exchange(flag, true)) continue;\n\
    \            if (!used[u] || ord[u] < ord[v]) tmp.emplace_back(minmax(u, v));\n\
    \            if (!used[u]) {\n                dfs(u, v);\n                if (low[u]\
    \ >= ord[v]) {\n                    bc.emplace_back();\n                    for\
    \ (;;) {\n                        auto e = tmp.back();\n                     \
    \   bc.back().emplace_back(e);\n                        tmp.pop_back();\n    \
    \                    if (e.first == min(u, v) && e.second == max(u, v)) break;\n\
    \                    }\n                }\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include \"LowLink.hpp\"\n\nstruct BiConnectedComponents :\
    \ LowLink {\n    using LowLink::G;\n    using LowLink::low;\n    using LowLink::LowLink;\n\
    \    using LowLink::ord;\n\n    vector<vector<pair<int, int>>> bc;\n    vector<pair<int,\
    \ int>> tmp;\n    vector<bool> used;\n\n    vector<vector<pair<int, int>>> build()\
    \ {\n        LowLink::build();\n        used.assign(G.size(), false);\n      \
    \  for (size_t i = 0; i < used.size(); i++) {\n            if (used[i]) continue;\n\
    \            dfs(i, -1);\n        }\n        return bc;\n    }\n\n    void dfs(int\
    \ v, int p) {\n        used[v] = true;\n        bool flag = false;\n        for\
    \ (int& u : G[v]) {\n            if (u == p && !exchange(flag, true)) continue;\n\
    \            if (!used[u] || ord[u] < ord[v]) tmp.emplace_back(minmax(u, v));\n\
    \            if (!used[u]) {\n                dfs(u, v);\n                if (low[u]\
    \ >= ord[v]) {\n                    bc.emplace_back();\n                    for\
    \ (;;) {\n                        auto e = tmp.back();\n                     \
    \   bc.back().emplace_back(e);\n                        tmp.pop_back();\n    \
    \                    if (e.first == min(u, v) && e.second == max(u, v)) break;\n\
    \                    }\n                }\n            }\n        }\n    }\n};\n"
  dependsOn:
  - graph/LowLink.hpp
  - base.hpp
  isVerificationFile: false
  path: graph/BiConnectedComponents.hpp
  requiredBy: []
  timestamp: '2021-09-20 17:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/BiConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/BiConnectedComponents.hpp
- /library/graph/BiConnectedComponents.hpp.html
title: graph/BiConnectedComponents.hpp
---
