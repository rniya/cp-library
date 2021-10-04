---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':warning:'
    path: datastructure/PartiallyPersistentUnionFind.hpp
    title: Partially Persistent Union Find
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
    \n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region Macros\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n     \
    \   os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"datastructure/PartiallyPersistentUnionFind.hpp\"\
    \n\nstruct PartiallyPersistentUnionFind {\n    PartiallyPersistentUnionFind(int\
    \ n)\n        : n(n), time(0), data(n, -1), last(n, std::numeric_limits<int>::max()),\
    \ history(n) {\n        for (auto& v : history) v.emplace_back(-1, -1);\n    }\n\
    \n    int find(int t, int x) const {\n        assert(0 <= x && x < n);\n     \
    \   return t < last[x] ? x : find(t, data[x]);\n    }\n\n    bool merge(int x,\
    \ int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n\
    \        time++;\n        if ((x = find(time, x)) == (y = find(time, y))) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        history[x].emplace_back(time, data[x]);\n        data[y] =\
    \ x;\n        last[y] = time;\n        return true;\n    }\n\n    bool same(int\
    \ t, int x, int y) const {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        return find(t, x) == find(t, y);\n    }\n\n    int\
    \ size(int t, int x) const {\n        assert(0 <= x && x < n);\n        x = find(t,\
    \ x);\n        return -prev(lower_bound(history[x].begin(), history[x].end(),\
    \ std::make_pair(t, 0)))->second;\n    }\n\nprivate:\n    int n, time;\n    std::vector<int>\
    \ data, last;\n    std::vector<std::vector<std::pair<int, int>>> history;\n};\n\
    \n/**\n * @brief Partially Persistent Union Find\n * @docs docs/datastructure/PartiallyPersistentUnionFind.md\n\
    \ */\n#line 7 \"test/atcoder/agc002_d.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N, M;\n    cin >> N >> M;\n\n    PartiallyPersistentUnionFind\
    \ UF(N);\n\n    for (int i = 0; i < M; i++) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        UF.merge(--a, --b);\n    }\n\n    int Q;\n    cin >> Q;\n\
    \    for (; Q--;) {\n        int x, y, z;\n        cin >> x >> y >> z;\n     \
    \   --x, --y;\n        int lb = 0, ub = M + 1;\n        while (ub - lb > 1) {\n\
    \            int mid = (ub + lb) >> 1;\n            int s = UF.size(mid, x);\n\
    \            if (!UF.same(mid, x, y)) s += UF.size(mid, y);\n            (s >=\
    \ z ? ub : lb) = mid;\n        }\n        cout << ub << '\\n';\n    }\n}\n"
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
  timestamp: '2021-10-04 17:13:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/agc002_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/agc002_d.cpp
- /library/test/atcoder/agc002_d.cpp.html
title: test/atcoder/agc002_d.cpp
---
