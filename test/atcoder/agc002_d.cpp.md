---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: datastructure/PartiallyPersistentUnionFind.hpp
    title: Partially Persistent UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/agc002/tasks/agc002_d
  bundledCode: "#line 1 \"test/atcoder/agc002_d.cpp\"\n#define IGNORE\n\n#define PROBLEM\
    \ \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/PartiallyPersistentUnionFind.hpp\"\
    \n\n/**\n * @brief Partially Persistent UnionFind\n * @docs docs/datastructure/PartiallyPersistentUnionFind.md\n\
    \ */\nstruct PartiallyPersistentUnionFind {\n    const int inf = numeric_limits<int>::max()\
    \ / 2;\n    int now, num;\n    vector<int> par, time;\n    vector<vector<pair<int,\
    \ int>>> Size;\n    PartiallyPersistentUnionFind(int n) : now(0), num(n), par(n,\
    \ -1), Size(n), time(n, inf) {\n        for (int i = 0; i < n; i++) Size[i].emplace_back(0,\
    \ -1);\n    }\n    int root(int t, int x) {\n        if (t < time[x]) return x;\n\
    \        return root(t, par[x]);\n    }\n    int merge(int x, int y) {\n     \
    \   now++;\n        x = root(now, x), y = root(now, y);\n        if (x == y) return\
    \ 0;\n        if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\n  \
    \      par[y] = x;\n        time[y] = now;\n        Size[x].emplace_back(now,\
    \ par[x]);\n        num--;\n        return now;\n    }\n    bool same(int t, int\
    \ x, int y) { return root(t, x) == root(t, y); }\n    int size(int t, int x) {\n\
    \        x = root(t, x);\n        return -prev(lower_bound(Size[x].begin(), Size[x].end(),\
    \ make_pair(t, 0)))->second;\n    }\n    int count() { return num; }\n};\n#line\
    \ 7 \"test/atcoder/agc002_d.cpp\"\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N, M;\n    cin >> N >> M;\n\n    PartiallyPersistentUnionFind UF(N);\n\
    \n    for (int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n\
    \        UF.merge(--a, --b);\n    }\n\n    int Q;\n    cin >> Q;\n    for (; Q--;)\
    \ {\n        int x, y, z;\n        cin >> x >> y >> z;\n        --x, --y;\n  \
    \      int lb = 0, ub = M + 1;\n        while (ub - lb > 1) {\n            int\
    \ mid = (ub + lb) >> 1;\n            int s = UF.size(mid, x);\n            if\
    \ (!UF.same(mid, x, y)) s += UF.size(mid, y);\n            (s >= z ? ub : lb)\
    \ = mid;\n        }\n        cout << ub << '\\n';\n    }\n}\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/agc002/tasks/agc002_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/PartiallyPersistentUnionFind.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ M;\n    cin >> N >> M;\n\n    PartiallyPersistentUnionFind UF(N);\n\n    for\
    \ (int i = 0; i < M; i++) {\n        int a, b;\n        cin >> a >> b;\n     \
    \   UF.merge(--a, --b);\n    }\n\n    int Q;\n    cin >> Q;\n    for (; Q--;)\
    \ {\n        int x, y, z;\n        cin >> x >> y >> z;\n        --x, --y;\n  \
    \      int lb = 0, ub = M + 1;\n        while (ub - lb > 1) {\n            int\
    \ mid = (ub + lb) >> 1;\n            int s = UF.size(mid, x);\n            if\
    \ (!UF.same(mid, x, y)) s += UF.size(mid, y);\n            (s >= z ? ub : lb)\
    \ = mid;\n        }\n        cout << ub << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/PartiallyPersistentUnionFind.hpp
  isVerificationFile: false
  path: test/atcoder/agc002_d.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/agc002_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/agc002_d.cpp
- /library/test/atcoder/agc002_d.cpp.html
title: test/atcoder/agc002_d.cpp
---
