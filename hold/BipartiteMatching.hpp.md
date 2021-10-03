---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/flow/BipartiteMatching.md
    document_title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"hold/BipartiteMatching.hpp\"\
    \n\n/**\n * @brief 2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\n * @docs docs/flow/BipartiteMatching.md\n */\nstruct BipartiteMatching\
    \ {\n    vector<vector<int>> G;\n    vector<int> match, alive, used;\n    int\
    \ time = 0;\n    BipartiteMatching(int n) : G(n), match(n, -1), alive(n, 1), used(n,\
    \ 0) {}\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n  \
    \      G[v].emplace_back(u);\n    }\n    bool dfs(int v) {\n        used[v] =\
    \ time;\n        for (int u : G[v]) {\n            int w = match[u];\n       \
    \     if (!alive[u]) continue;\n            if (w < 0 || (used[w] != time && dfs(w)))\
    \ {\n                match[v] = u;\n                match[u] = v;\n          \
    \      return true;\n            }\n        }\n        return false;\n    }\n\
    \    int build() {\n        int res = 0;\n        for (int i = 0; i < (int)G.size();\
    \ i++) {\n            if (!alive[i]) continue;\n            if (~match[i]) continue;\n\
    \            time++;\n            res += dfs(i);\n        }\n        return res;\n\
    \    }\n    int enable(int v) {\n        alive[v] = 1;\n        time++;\n    \
    \    return dfs(v);\n    }\n    int disable(int v) {\n        alive[v] = 0;\n\
    \        if (match[v] < 0) return 0;\n        match[v] = -1;\n        match[match[v]]\
    \ = -1;\n        time++;\n        int res = dfs(match[v]);\n        return res\
    \ - 1;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief 2\u90E8\u30B0\u30E9\
    \u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\n * @docs docs/flow/BipartiteMatching.md\n\
    \ */\nstruct BipartiteMatching {\n    vector<vector<int>> G;\n    vector<int>\
    \ match, alive, used;\n    int time = 0;\n    BipartiteMatching(int n) : G(n),\
    \ match(n, -1), alive(n, 1), used(n, 0) {}\n    void add_edge(int u, int v) {\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    bool\
    \ dfs(int v) {\n        used[v] = time;\n        for (int u : G[v]) {\n      \
    \      int w = match[u];\n            if (!alive[u]) continue;\n            if\
    \ (w < 0 || (used[w] != time && dfs(w))) {\n                match[v] = u;\n  \
    \              match[u] = v;\n                return true;\n            }\n  \
    \      }\n        return false;\n    }\n    int build() {\n        int res = 0;\n\
    \        for (int i = 0; i < (int)G.size(); i++) {\n            if (!alive[i])\
    \ continue;\n            if (~match[i]) continue;\n            time++;\n     \
    \       res += dfs(i);\n        }\n        return res;\n    }\n    int enable(int\
    \ v) {\n        alive[v] = 1;\n        time++;\n        return dfs(v);\n    }\n\
    \    int disable(int v) {\n        alive[v] = 0;\n        if (match[v] < 0) return\
    \ 0;\n        match[v] = -1;\n        match[match[v]] = -1;\n        time++;\n\
    \        int res = dfs(match[v]);\n        return res - 1;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: hold/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2021-09-21 16:26:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hold/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/hold/BipartiteMatching.hpp
- /library/hold/BipartiteMatching.hpp.html
title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
# Remarks
以下に書いてるあることは大嘘で, まだ最大マッチングしか実装していない.

## 概要
2部グラフにおける最大マッチング, 最小点被覆, 最大独立集合, 最小辺被覆を求める.
- 最大マッチング：どの2辺も端点を共有しないような辺集合.
- 最小点被覆：各辺の端点のうち少なくとも一方を必ず含むような点集合.
- 最大独立集合：どの2頂点も辺で結ばれていないような点集合.
- 最小辺被覆：各頂点を端点にもつ辺を必ず含むような辺集合.

一般に, 点被覆の補集合は独立集合をなし, その逆も成立する. よって, 最小点被覆の補集合が最大安定集合となり, その逆も成り立つ.

また, 最大マッチングの辺集合に対して, マッチングの端点になっていないような各頂点を端点にもつような辺を Greedy に追加していくと最小辺被覆になる.

ここで, 2部グラフにおいては最大マッチングの大きさと最小点被覆の大きさが等しくなる. また, 最大マッチングを構築する際の残余グラフから最小点被覆を実際に構成でき, 他についても構成可能となる.

よって, それぞれの大きさは頂点集合の大きさを $\|V\|$, 最大マッチングの大きさを $\|M\|$ とすると, 最小点被覆は $\|M\|$, 最大独立集合は $\|V\|-\|M\|$, 最小辺被覆は $\|V\|-\|M\|$ (ただし, 孤立点が存在する場合は辺被覆は存在しない)となる.

実装は Kuhn の $O(VE)$ のアルゴリズムを改善したもので, 実用上は十分高速で Hopcroft-Karp にも勝ることが多い. これでも間に合わない際には `shuffle()` をするか大人しく他のライブラリに頼る.

## Links
- [二部グラフの最小点被覆、最大安定集合 (最大独立集合)、最小辺被覆を総整理！ - Qiita](https://qiita.com/drken/items/7f98315b56c95a6181a4)
- [二部グラフの最小点被覆と最大安定集合と最小辺被覆の求め方](https://www.slideshare.net/drken1215/ss-86894312)
- [2部グラフにおける最大マッチングの個数と最小点被覆の個数の一致 - komiyamの日記](https://komiyam.hatenadiary.org/entry/20110208/1297112982)
- [Паросочетание. Быстрый Кун. - Codeforces](https://codeforces.com/blog/entry/17023)
- [二部マッチングでTLEに苦しんだ話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2019/05/07/013609)
