---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: Strongly Connectes Components
  - icon: ':heavy_check_mark:'
    path: graph/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"graph/StronglyConnectedComponents.hpp\"\
    \n\nstruct StronglyConnectedComponents {\n    std::vector<std::vector<int>> G;\
    \  // graph after contraction\n    std::vector<int> comp;            // component\
    \ id vertex v belongs to\n\n    StronglyConnectedComponents(int n) : G(n), comp(n,\
    \ -1), n(n), time(0), group_num(0), ord(n, -1), low(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        G[u].emplace_back(v);\n    }\n\n    std::vector<std::vector<int>>\
    \ build() {\n        for (int i = 0; i < n; i++) {\n            if (ord[i] < 0)\
    \ {\n                dfs(i);\n            }\n        }\n        for (int& x :\
    \ comp) x = group_num - 1 - x;\n        std::vector<std::vector<int>> groups(group_num);\n\
    \        for (int i = 0; i < n; i++) groups[comp[i]].emplace_back(i);\n      \
    \  return groups;\n    }\n\n    std::vector<std::vector<int>> make_graph() {\n\
    \        std::vector<std::vector<int>> dag(group_num);\n        for (int v = 0;\
    \ v < n; v++) {\n            for (int& u : G[v]) {\n                if (comp[v]\
    \ != comp[u]) {\n                    dag[comp[v]].emplace_back(comp[u]);\n   \
    \             }\n            }\n        }\n        for (auto& to : dag) {\n  \
    \          std::sort(to.begin(), to.end());\n            to.erase(unique(to.begin(),\
    \ to.end()), to.end());\n        }\n        return dag;\n    }\n\n    int operator[](int\
    \ v) const { return comp[v]; }\n\nprivate:\n    int n, time, group_num;\n    std::vector<int>\
    \ ord, low, visited;\n\n    void dfs(int v) {\n        ord[v] = low[v] = time++;\n\
    \        visited.emplace_back(v);\n        for (int& u : G[v]) {\n           \
    \ if (ord[u] == -1) {\n                dfs(u);\n                low[v] = std::min(low[v],\
    \ low[u]);\n            } else if (comp[u] < 0) {\n                low[v] = std::min(low[v],\
    \ ord[u]);\n            }\n        }\n        if (ord[v] == low[v]) {\n      \
    \      while (true) {\n                int u = visited.back();\n             \
    \   visited.pop_back();\n                comp[u] = group_num;\n              \
    \  if (u == v) break;\n            }\n            group_num++;\n        }\n  \
    \  }\n};\n\n/**\n * @brief Strongly Connectes Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\n#line 4 \"graph/TwoSatisfiability.hpp\"\n\n/**\n * @brief 2-SAT\n * @docs\
    \ docs/graph/TwoSatisfiability.md\n */\nstruct TwoSatisfiability {\n    int n;\n\
    \    StronglyConnectedComponents SCC;\n    TwoSatisfiability(int n) : n(n), SCC(n\
    \ * 2) {}\n    int neg(int v) { return (n + v) % (n * 2); }\n    void add_if(int\
    \ u, int v) {\n        SCC.add_edge(u, v);\n        SCC.add_edge(neg(v), neg(u));\n\
    \    }\n    void add_or(int u, int v) { add_if(neg(u), v); }\n    void add_nand(int\
    \ u, int v) { add_if(u, neg(v)); }\n    void set_true(int v) { SCC.add_edge(neg(v),\
    \ v); }\n    void set_false(int v) { SCC.add_edge(v, neg(v)); }\n    vector<int>\
    \ build() {\n        SCC.build();\n        vector<int> res(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (SCC[i] == SCC[n + i]) return {};\n   \
    \         res[i] = SCC[i] > SCC[n + i];\n        }\n        return res;\n    }\n\
    };\n#line 6 \"test/yosupo/two_sat.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    string p, cnf;\n    cin >> p >> cnf;\n\
    \    int N, M;\n    cin >> N >> M;\n\n    TwoSatisfiability TS(N + 1);\n    for\
    \ (int i = 0; i < M; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        TS.add_or((a < 0 ? TS.neg(-a) : a), (b < 0 ? TS.neg(-b) : b));\n    }\n\
    \n    vector<int> ans = TS.build();\n    if (ans.empty()) {\n        cout << \"\
    s UNSATISFIABLE\" << '\\n';\n        return 0;\n    }\n    cout << \"s SATISFIABLE\"\
    \ << '\\n';\n    cout << \"v \";\n    for (int i = 1; i <= N; i++) cout << (ans[i]\
    \ ? i : -i) << ' ';\n    cout << \"0\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../base.hpp\"\n#include \"../../graph/StronglyConnectedComponents.hpp\"\n#include\
    \ \"../../graph/TwoSatisfiability.hpp\"\n\nint main() {\n    cin.tie(0);\n   \
    \ ios::sync_with_stdio(false);\n    string p, cnf;\n    cin >> p >> cnf;\n   \
    \ int N, M;\n    cin >> N >> M;\n\n    TwoSatisfiability TS(N + 1);\n    for (int\
    \ i = 0; i < M; i++) {\n        int a, b, c;\n        cin >> a >> b >> c;\n  \
    \      TS.add_or((a < 0 ? TS.neg(-a) : a), (b < 0 ? TS.neg(-b) : b));\n    }\n\
    \n    vector<int> ans = TS.build();\n    if (ans.empty()) {\n        cout << \"\
    s UNSATISFIABLE\" << '\\n';\n        return 0;\n    }\n    cout << \"s SATISFIABLE\"\
    \ << '\\n';\n    cout << \"v \";\n    for (int i = 1; i <= N; i++) cout << (ans[i]\
    \ ? i : -i) << ' ';\n    cout << \"0\\n\";\n}"
  dependsOn:
  - base.hpp
  - graph/StronglyConnectedComponents.hpp
  - graph/TwoSatisfiability.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2021-09-22 02:06:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
