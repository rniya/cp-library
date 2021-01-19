---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: datastructure/UnionFindUndo.hpp
    title: "UnionFind (Undo\u53EF\u80FD)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n\
    #line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nconst long\
    \ long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int INF = 1e9;\n\
    const long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1,\
    \ 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\ntypedef long\
    \ long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/UnionFindUndo.hpp\"\
    \n\n/**\n * @brief UnionFind (Undo\u53EF\u80FD)\n * @docs docs/datastructure/UnionFindUndo.md\n\
    \ */\nstruct UnionFindUndo {\n    vector<int> dat;\n    stack<pair<int, int>>\
    \ hist;\n    UnionFindUndo(int n) : dat(n, -1) {}\n    int root(int x) { return\
    \ (dat[x] < 0 ? x : root(dat[x])); }\n    bool merge(int x, int y) {\n       \
    \ x = root(x);\n        y = root(y);\n        hist.emplace(x, dat[x]);\n     \
    \   hist.emplace(y, dat[y]);\n        if (x == y) return false;\n        if (dat[x]\
    \ > dat[y]) swap(x, y);\n        dat[x] += dat[y];\n        dat[y] = x;\n    \
    \    return true;\n    }\n    void undo() {\n        dat[hist.top().first] = hist.top().second;\n\
    \        hist.pop();\n        dat[hist.top().first] = hist.top().second;\n   \
    \     hist.pop();\n    }\n    void snapshot() {\n        while (!hist.empty())\
    \ hist.pop();\n    }\n    void rollback() {\n        while (!hist.empty()) undo();\n\
    \    }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -dat[root(x)]; }\n};\n#line 5 \"test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> t(Q),u(Q),v(Q);\n    vector<vector<int>> G(Q+1);\n\
    \    for (int i=0;i<Q;++i){\n        int k; cin >> t[i] >> k >> u[i] >> v[i];\n\
    \        G[++k].emplace_back(i+1);\n    }\n\n    UnionFindUndo UF(N);\n    vector<int>\
    \ ans(Q,-1);\n    auto dfs=[&](auto self,int cur)->void{\n        if (cur){\n\
    \            if (!t[cur-1]) UF.merge(u[cur-1],v[cur-1]);\n            else ans[cur-1]=UF.same(u[cur-1],v[cur-1]);\n\
    \        }\n        for (int nxt:G[cur]) self(self,nxt);\n        if (cur&&!t[cur-1])\
    \ UF.undo();\n    };\n    dfs(dfs,0);\n    for (int i=0;i<Q;++i){\n        if\
    \ (~ans[i]){\n            cout << ans[i] << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/UnionFindUndo.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<int> t(Q),u(Q),v(Q);\n    vector<vector<int>> G(Q+1);\n\
    \    for (int i=0;i<Q;++i){\n        int k; cin >> t[i] >> k >> u[i] >> v[i];\n\
    \        G[++k].emplace_back(i+1);\n    }\n\n    UnionFindUndo UF(N);\n    vector<int>\
    \ ans(Q,-1);\n    auto dfs=[&](auto self,int cur)->void{\n        if (cur){\n\
    \            if (!t[cur-1]) UF.merge(u[cur-1],v[cur-1]);\n            else ans[cur-1]=UF.same(u[cur-1],v[cur-1]);\n\
    \        }\n        for (int nxt:G[cur]) self(self,nxt);\n        if (cur&&!t[cur-1])\
    \ UF.undo();\n    };\n    dfs(dfs,0);\n    for (int i=0;i<Q;++i){\n        if\
    \ (~ans[i]){\n            cout << ans[i] << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/UnionFindUndo.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
- /verify/test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp.html
title: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
---