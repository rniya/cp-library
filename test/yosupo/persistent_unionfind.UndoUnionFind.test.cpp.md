---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/UndoUnionFind.hpp
    title: Union Find with Undo operation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n\
    #line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace\
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
    #line 5 \"datastructure/UndoUnionFind.hpp\"\n\nstruct UndoUnionFind {\n    UndoUnionFind(int\
    \ n) : n(n), data(n, -1) {}\n\n    int find(int x) const {\n        assert(0 <=\
    \ x && x < n);\n        return data[x] < 0 ? x : find(data[x]);\n    }\n\n   \
    \ bool merge(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        x = find(x), y = find(y);\n        history.emplace(x,\
    \ data[x]);\n        history.emplace(y, data[y]);\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) const {\n        assert(0 <= x && x < n);\n        assert(0 <= y &&\
    \ y < n);\n        return find(x) == find(y);\n    }\n\n    int size(int x) const\
    \ {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n    }\n\
    \n    void undo() {\n        assert(!history.empty());\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n    }\n\n    void snapshot()\
    \ {\n        while (!history.empty()) history.pop();\n    }\n\n    void rollback()\
    \ {\n        while (!history.empty()) undo();\n    }\n\n    int operator[](int\
    \ x) const { return find(x); }\n\nprivate:\n    int n;\n    std::vector<int> data;\n\
    \    std::stack<std::pair<int, int>> history;\n};\n\n/**\n * @brief Union Find\
    \ with Undo operation\n * @docs docs/datastructure/UndoUnionFind.md\n */\n#line\
    \ 5 \"test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N, Q;\n    cin\
    \ >> N >> Q;\n    vector<int> t(Q), u(Q), v(Q);\n    vector<vector<int>> G(Q +\
    \ 1);\n    for (int i = 0; i < Q; i++) {\n        int k;\n        cin >> t[i]\
    \ >> k >> u[i] >> v[i];\n        G[++k].emplace_back(i + 1);\n    }\n\n    UndoUnionFind\
    \ UF(N);\n    vector<int> ans(Q, -1);\n    auto dfs = [&](auto self, int cur)\
    \ -> void {\n        if (cur) {\n            if (!t[cur - 1])\n              \
    \  UF.merge(u[cur - 1], v[cur - 1]);\n            else\n                ans[cur\
    \ - 1] = UF.same(u[cur - 1], v[cur - 1]);\n        }\n        for (int nxt : G[cur])\
    \ self(self, nxt);\n        if (cur && !t[cur - 1]) UF.undo();\n    };\n    dfs(dfs,\
    \ 0);\n    for (int i = 0; i < Q; i++) {\n        if (~ans[i]) {\n           \
    \ cout << ans[i] << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/UndoUnionFind.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> t(Q), u(Q), v(Q);\n    vector<vector<int>>\
    \ G(Q + 1);\n    for (int i = 0; i < Q; i++) {\n        int k;\n        cin >>\
    \ t[i] >> k >> u[i] >> v[i];\n        G[++k].emplace_back(i + 1);\n    }\n\n \
    \   UndoUnionFind UF(N);\n    vector<int> ans(Q, -1);\n    auto dfs = [&](auto\
    \ self, int cur) -> void {\n        if (cur) {\n            if (!t[cur - 1])\n\
    \                UF.merge(u[cur - 1], v[cur - 1]);\n            else\n       \
    \         ans[cur - 1] = UF.same(u[cur - 1], v[cur - 1]);\n        }\n       \
    \ for (int nxt : G[cur]) self(self, nxt);\n        if (cur && !t[cur - 1]) UF.undo();\n\
    \    };\n    dfs(dfs, 0);\n    for (int i = 0; i < Q; i++) {\n        if (~ans[i])\
    \ {\n            cout << ans[i] << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - datastructure/UndoUnionFind.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp.html
title: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
---
