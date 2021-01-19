---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: string/AhoCorasick.hpp
    title: Aho Corasick
  - icon: ':warning:'
    path: test/atcoder/tenka1_2016_final_c.cpp
    title: test/atcoder/tenka1_2016_final_c.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430.AhoCorasick.test.cpp
    title: test/yukicoder/430.AhoCorasick.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/string/Trie.md
    document_title: Trie
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/Trie.hpp\"\n\n/**\n\
    \ * @brief Trie\n * @docs docs/string/Trie.md\n */\ntemplate <int char_size> struct\
    \ Trie {\n    struct TrieNode {\n        char c;\n        int dep;\n        vector<int>\
    \ nxt, idxs;\n        TrieNode(char c, int dep) : c(c), dep(dep), nxt(char_size,\
    \ -1) {}\n    };\n    vector<TrieNode> Nodes;\n    function<int(char)> ctoi;\n\
    \    Trie(function<int(char)> ctoi) : ctoi(ctoi) { Nodes.emplace_back('$', 0);\
    \ }\n    inline int& next(int node, int c) { return Nodes[node].nxt[c]; }\n  \
    \  inline int& next(int node, char c) { return next(node, ctoi(c)); }\n    void\
    \ add(const string& s, int x = 0) {\n        int node = 0;\n        for (int i\
    \ = 0; i < s.size(); i++) {\n            int k = ctoi(s[i]);\n            if (next(node,\
    \ k) < 0) {\n                next(node, k) = Nodes.size();\n                Nodes.emplace_back(s[i],\
    \ i + 1);\n            }\n            node = next(node, k);\n        }\n     \
    \   Nodes[node].idxs.emplace_back(x);\n    }\n    int find(const string& s) {\n\
    \        int node = 0;\n        for (int i = 0; i < s.size(); i++) {\n       \
    \     int k = ctoi(s[i]);\n            if (next(node, k) < 0) return -1;\n   \
    \         node = next(node, k);\n        }\n        return node;\n    }\n    template\
    \ <typename F> void query(const string& s, const F& f, int l) {\n        int node\
    \ = 0;\n        for (int i = l; i < s.size(); i++) {\n            node = next(node,\
    \ s[i]);\n            if (node < 0) return;\n            for (auto& idx : Nodes[node].idxs)\
    \ f(idx);\n        }\n    }\n    int size() { return Nodes.size(); };\n    vector<int>\
    \ idxs(int node) { return Nodes[node].idxs; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Trie\n * @docs docs/string/Trie.md\n\
    \ */\ntemplate <int char_size> struct Trie {\n    struct TrieNode {\n        char\
    \ c;\n        int dep;\n        vector<int> nxt, idxs;\n        TrieNode(char\
    \ c, int dep) : c(c), dep(dep), nxt(char_size, -1) {}\n    };\n    vector<TrieNode>\
    \ Nodes;\n    function<int(char)> ctoi;\n    Trie(function<int(char)> ctoi) :\
    \ ctoi(ctoi) { Nodes.emplace_back('$', 0); }\n    inline int& next(int node, int\
    \ c) { return Nodes[node].nxt[c]; }\n    inline int& next(int node, char c) {\
    \ return next(node, ctoi(c)); }\n    void add(const string& s, int x = 0) {\n\
    \        int node = 0;\n        for (int i = 0; i < s.size(); i++) {\n       \
    \     int k = ctoi(s[i]);\n            if (next(node, k) < 0) {\n            \
    \    next(node, k) = Nodes.size();\n                Nodes.emplace_back(s[i], i\
    \ + 1);\n            }\n            node = next(node, k);\n        }\n       \
    \ Nodes[node].idxs.emplace_back(x);\n    }\n    int find(const string& s) {\n\
    \        int node = 0;\n        for (int i = 0; i < s.size(); i++) {\n       \
    \     int k = ctoi(s[i]);\n            if (next(node, k) < 0) return -1;\n   \
    \         node = next(node, k);\n        }\n        return node;\n    }\n    template\
    \ <typename F> void query(const string& s, const F& f, int l) {\n        int node\
    \ = 0;\n        for (int i = l; i < s.size(); i++) {\n            node = next(node,\
    \ s[i]);\n            if (node < 0) return;\n            for (auto& idx : Nodes[node].idxs)\
    \ f(idx);\n        }\n    }\n    int size() { return Nodes.size(); };\n    vector<int>\
    \ idxs(int node) { return Nodes[node].idxs; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy:
  - string/AhoCorasick.hpp
  - test/atcoder/tenka1_2016_final_c.cpp
  timestamp: '2021-01-19 15:22:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/430.AhoCorasick.test.cpp
documentation_of: string/Trie.hpp
layout: document
redirect_from:
- /library/string/Trie.hpp
- /library/string/Trie.hpp.html
title: Trie
---
## 概要

## 計算量