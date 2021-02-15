---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: tree/TreeDiameter.hpp
    title: Tree Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo/tree_diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 2 \"base.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef __int128_t\
    \ i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n#define\
    \ ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {\n\
    \    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U, typename V, typename W>\
    \ ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {\n    os << '('\
    \ << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) <<\
    \ ')';\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
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
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class...\
    \ Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n   \
    \ if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n\
    #ifdef LOCAL\n#define debug(...)                                             \
    \                      \\\n    cerr << \" \";                                \
    \                                     \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"tree/TreeDiameter.hpp\"\
    \n\n/**\n * @brief Tree Diameter\n * @docs docs/tree/TreeDiameter.md\n */\ntemplate\
    \ <typename T> struct TreeDiameter {\n    vector<T> dp, par;\n    vector<vector<pair<int,\
    \ T>>> G;\n    TreeDiameter(int n) : dp(n), par(n), G(n) {}\n    void add_edge(int\
    \ u, int v, T c) {\n        G[u].emplace_back(v, c);\n        G[v].emplace_back(u,\
    \ c);\n    }\n    void dfs(int v, int p, int& s) {\n        par[v] = p;\n    \
    \    if (p < 0) dp[v] = T(0);\n        if (dp[s] < dp[v]) s = v;\n        for\
    \ (auto e : G[v]) {\n            int u = e.first;\n            if (u == p) continue;\n\
    \            dp[u] = dp[v] + e.second;\n            dfs(u, v, s);\n        }\n\
    \    }\n    pair<int, int> endPoints() {\n        int s = 0;\n        dfs(s, -1,\
    \ s);\n        int t = s;\n        dfs(t, -1, t);\n        return make_pair(s,\
    \ t);\n    }\n    T build() {\n        int t = endPoints().second;\n        return\
    \ dp[t];\n    }\n    vector<int> restore() {\n        int t = endPoints().second;\n\
    \        vector<int> res;\n        while (~t) {\n            res.emplace_back(t);\n\
    \            t = par[t];\n        }\n        return res;\n    }\n    vector<T>\
    \ distance(int v) {\n        dfs(v, -1, v);\n        return dp;\n    }\n    vector<T>\
    \ farthest() {\n        int t = endPoints().second;\n        auto ds = dp;\n \
    \       auto dt = distance(t);\n        for (int i = 0; i < (int)ds.size(); i++)\
    \ ds[i] = max(ds[i], dt[i]);\n        return ds;\n    }\n};\n#line 5 \"test/yosupo/tree_diameter.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n\
    \    cin >> N;\n\n    TreeDiameter<long long> TD(N);\n    for (int i = 0; i <\
    \ N - 1; i++) {\n        int a, b;\n        long long c;\n        cin >> a >>\
    \ b >> c;\n        TD.add_edge(a, b, c);\n    }\n\n    long long X = TD.build();\n\
    \    vector<int> ans = TD.restore();\n    int Y = ans.size();\n    cout << X <<\
    \ ' ' << Y << '\\n';\n    for (int i = 0; i < Y; i++) cout << ans[i] << (i + 1\
    \ == Y ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../tree/TreeDiameter.hpp\"\n\nint main() {\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n    cin >> N;\n\
    \n    TreeDiameter<long long> TD(N);\n    for (int i = 0; i < N - 1; i++) {\n\
    \        int a, b;\n        long long c;\n        cin >> a >> b >> c;\n      \
    \  TD.add_edge(a, b, c);\n    }\n\n    long long X = TD.build();\n    vector<int>\
    \ ans = TD.restore();\n    int Y = ans.size();\n    cout << X << ' ' << Y << '\\\
    n';\n    for (int i = 0; i < Y; i++) cout << ans[i] << (i + 1 == Y ? '\\n' : '\
    \ ');\n}"
  dependsOn:
  - base.hpp
  - tree/TreeDiameter.hpp
  isVerificationFile: true
  path: test/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_diameter.test.cpp
- /verify/test/yosupo/tree_diameter.test.cpp.html
title: test/yosupo/tree_diameter.test.cpp
---
