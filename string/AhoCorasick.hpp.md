---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/Trie.hpp
    title: Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.AhoCorasick.test.cpp
    title: test/yukicoder/430.AhoCorasick.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/AhoCorasick.md
    document_title: Aho Corasick
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
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
    \ = 0; i < (int)s.size(); i++) {\n            int k = ctoi(s[i]);\n          \
    \  if (next(node, k) < 0) {\n                next(node, k) = Nodes.size();\n \
    \               Nodes.emplace_back(s[i], i + 1);\n            }\n            node\
    \ = next(node, k);\n        }\n        Nodes[node].idxs.emplace_back(x);\n   \
    \ }\n    int find(const string& s) {\n        int node = 0;\n        for (int\
    \ i = 0; i < (int)s.size(); i++) {\n            int k = ctoi(s[i]);\n        \
    \    if (next(node, k) < 0) return -1;\n            node = next(node, k);\n  \
    \      }\n        return node;\n    }\n    template <typename F> void query(const\
    \ string& s, const F& f, int l) {\n        int node = 0;\n        for (int i =\
    \ l; i < (int)s.size(); i++) {\n            node = next(node, s[i]);\n       \
    \     if (node < 0) return;\n            for (auto& idx : Nodes[node].idxs) f(idx);\n\
    \        }\n    }\n    int size() { return Nodes.size(); };\n    vector<int> idxs(int\
    \ node) { return Nodes[node].idxs; }\n};\n#line 4 \"string/AhoCorasick.hpp\"\n\
    \n/**\n * @brief Aho Corasick\n * @docs docs/string/AhoCorasick.md\n */\ntemplate\
    \ <int char_size> struct AhoCorasick : Trie<char_size + 1> {\n    using Trie<char_size\
    \ + 1>::Trie;\n    using Trie<char_size + 1>::next;\n    using Trie<char_size\
    \ + 1>::ctoi;\n    const int FAIL = char_size;\n    vector<int> cnt;\n    void\
    \ build(bool heavy = true) {\n        auto& Nodes = this->Nodes;\n        cnt.resize(Nodes.size());\n\
    \        for (int i = 0; i < (int)Nodes.size(); i++) {\n            cnt[i] = Nodes[i].idxs.size();\n\
    \        }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++)\
    \ {\n            if (~next(0, i)) {\n                next(next(0, i), FAIL) =\
    \ 0;\n                que.emplace(next(0, i));\n            } else\n         \
    \       next(0, i) = 0;\n        }\n        while (!que.empty()) {\n         \
    \   auto& node = Nodes[que.front()];\n            int fail = node.nxt[FAIL];\n\
    \            cnt[que.front()] += cnt[fail];\n            que.pop();\n        \
    \    for (int i = 0; i < char_size; i++) {\n                if (~node.nxt[i])\
    \ {\n                    next(node.nxt[i], FAIL) = next(fail, i);\n          \
    \          if (heavy) {\n                        auto& u = Nodes[node.nxt[i]].idxs;\n\
    \                        auto& v = Nodes[next(fail, i)].idxs;\n              \
    \          vector<int> w;\n                        set_union(u.begin(), u.end(),\
    \ v.begin(), v.end(), back_inserter(w));\n                        u = w;\n   \
    \                 }\n                    que.emplace(node.nxt[i]);\n         \
    \       } else\n                    node.nxt[i] = Nodes[fail].nxt[i];\n      \
    \      }\n        }\n    }\n    map<int, int> match(const string& s, int now =\
    \ 0) {\n        auto& Nodes = this->Nodes;\n        map<int, int> res;\n     \
    \   for (auto c : s) {\n            now = next(now, ctoi(c));\n            for\
    \ (auto& id : Nodes[now].idxs) res[id]++;\n        }\n        return res;\n  \
    \  }\n    int move(const char& c, int now) {\n        while (next(now, ctoi(c))\
    \ < 0) now = next(now, FAIL);\n        return next(now, ctoi(c));\n    }\n   \
    \ pair<long long, int> move(const string& s, int now = 0) {\n        long long\
    \ res = 0;\n        for (auto& c : s) {\n            int nxt = move(c, now);\n\
    \            res += cnt[nxt];\n            now = nxt;\n        }\n        return\
    \ {res, now};\n    }\n    int count(int node) { return cnt[node]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"Trie.hpp\"\n\n/**\n *\
    \ @brief Aho Corasick\n * @docs docs/string/AhoCorasick.md\n */\ntemplate <int\
    \ char_size> struct AhoCorasick : Trie<char_size + 1> {\n    using Trie<char_size\
    \ + 1>::Trie;\n    using Trie<char_size + 1>::next;\n    using Trie<char_size\
    \ + 1>::ctoi;\n    const int FAIL = char_size;\n    vector<int> cnt;\n    void\
    \ build(bool heavy = true) {\n        auto& Nodes = this->Nodes;\n        cnt.resize(Nodes.size());\n\
    \        for (int i = 0; i < (int)Nodes.size(); i++) {\n            cnt[i] = Nodes[i].idxs.size();\n\
    \        }\n        queue<int> que;\n        for (int i = 0; i <= char_size; i++)\
    \ {\n            if (~next(0, i)) {\n                next(next(0, i), FAIL) =\
    \ 0;\n                que.emplace(next(0, i));\n            } else\n         \
    \       next(0, i) = 0;\n        }\n        while (!que.empty()) {\n         \
    \   auto& node = Nodes[que.front()];\n            int fail = node.nxt[FAIL];\n\
    \            cnt[que.front()] += cnt[fail];\n            que.pop();\n        \
    \    for (int i = 0; i < char_size; i++) {\n                if (~node.nxt[i])\
    \ {\n                    next(node.nxt[i], FAIL) = next(fail, i);\n          \
    \          if (heavy) {\n                        auto& u = Nodes[node.nxt[i]].idxs;\n\
    \                        auto& v = Nodes[next(fail, i)].idxs;\n              \
    \          vector<int> w;\n                        set_union(u.begin(), u.end(),\
    \ v.begin(), v.end(), back_inserter(w));\n                        u = w;\n   \
    \                 }\n                    que.emplace(node.nxt[i]);\n         \
    \       } else\n                    node.nxt[i] = Nodes[fail].nxt[i];\n      \
    \      }\n        }\n    }\n    map<int, int> match(const string& s, int now =\
    \ 0) {\n        auto& Nodes = this->Nodes;\n        map<int, int> res;\n     \
    \   for (auto c : s) {\n            now = next(now, ctoi(c));\n            for\
    \ (auto& id : Nodes[now].idxs) res[id]++;\n        }\n        return res;\n  \
    \  }\n    int move(const char& c, int now) {\n        while (next(now, ctoi(c))\
    \ < 0) now = next(now, FAIL);\n        return next(now, ctoi(c));\n    }\n   \
    \ pair<long long, int> move(const string& s, int now = 0) {\n        long long\
    \ res = 0;\n        for (auto& c : s) {\n            int nxt = move(c, now);\n\
    \            res += cnt[nxt];\n            now = nxt;\n        }\n        return\
    \ {res, now};\n    }\n    int count(int node) { return cnt[node]; }\n};"
  dependsOn:
  - base.hpp
  - string/Trie.hpp
  isVerificationFile: false
  path: string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/430.AhoCorasick.test.cpp
documentation_of: string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/string/AhoCorasick.hpp
- /library/string/AhoCorasick.hpp.html
title: Aho Corasick
---
## 概要

## 計算量