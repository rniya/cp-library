---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/string/Trie.hpp
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
    links: []
  bundledCode: "#line 2 \"src/string/AhoCorasick.hpp\"\n#include <algorithm>\n#include\
    \ <map>\n#include <queue>\n#line 3 \"src/string/Trie.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <string>\n#include <vector>\n\ntemplate <size_t char_size,\
    \ char margin = 'a'> struct Trie {\n    struct Node {\n        std::array<int,\
    \ char_size> nxt;\n        std::vector<int> idxs;\n        int idx, sub;\n   \
    \     char key;\n        Node(char c) : idx(-1), key(c) { std::fill(nxt.begin(),\
    \ nxt.end(), -1); }\n    };\n\n    std::vector<Node> nodes;\n\n    inline int&\
    \ next(int i, int j) { return nodes[i].nxt[j]; }\n\n    Trie() { nodes.emplace_back('$');\
    \ }\n\n    void add(const std::string& s, int x = 0) {\n        int cur = 0;\n\
    \        for (const char& c : s) {\n            int k = c - margin;\n        \
    \    if (next(cur, k) < 0) {\n                next(cur, k) = nodes.size();\n \
    \               nodes.emplace_back(c);\n            }\n            cur = next(cur,\
    \ k);\n            nodes[cur].sub++;\n        }\n        nodes[cur].idx = x;\n\
    \        nodes[cur].idxs.emplace_back(x);\n    }\n\n    int find(const std::string&\
    \ s) {\n        int cur = 0;\n        for (const char& c : s) {\n            int\
    \ k = c - margin;\n            if (next(cur, k) < 0) return -1;\n            cur\
    \ = next(cur, k);\n        }\n        return cur;\n    }\n\n    int move(int pos,\
    \ char c) {\n        assert(pos < (int)nodes.size());\n        return pos < 0\
    \ ? -1 : next(pos, c - margin);\n    }\n\n    int size() const { return nodes.size();\
    \ }\n\n    int idx(int pos) { return pos < 0 ? -1 : nodes[pos].idx; }\n\n    std::vector<int>\
    \ idxs(int pos) { return pos < 0 ? std::vector<int>() : nodes[pos].idxs; }\n};\n\
    #line 6 \"src/string/AhoCorasick.hpp\"\n\ntemplate <size_t char_size, char margin\
    \ = 'a'> struct AhoCorasick : Trie<char_size + 1, margin> {\n    void build(bool\
    \ heavy = true) {\n        int n = nodes.size();\n        cnt.resize(n);\n   \
    \     for (int i = 0; i < n; i++) cnt[i] = nodes[i].idxs.size();\n        std::queue<int>\
    \ que;\n        for (size_t i = 0; i <= char_size; i++) {\n            if (~next(0,\
    \ i)) {\n                next(next(0, i), FAIL) = 0;\n                que.emplace(next(0,\
    \ i));\n            } else\n                next(0, i) = 0;\n        }\n     \
    \   while (!que.empty()) {\n            auto& cur = nodes[que.front()];\n    \
    \        int fail = cur.nxt[FAIL];\n            cnt[que.front()] += cnt[fail];\n\
    \            que.pop();\n            for (size_t i = 0; i < char_size; i++) {\n\
    \                int& nxt = cur.nxt[i];\n                if (nxt < 0) {\n    \
    \                nxt = next(fail, i);\n                    continue;\n       \
    \         }\n                next(nxt, FAIL) = next(fail, i);\n              \
    \  if (heavy) {\n                    auto& u = nodes[nxt].idxs;\n            \
    \        auto& v = nodes[next(fail, i)].idxs;\n                    std::vector<int>\
    \ w;\n                    std::set_union(u.begin(), u.end(), v.begin(), v.end(),\
    \ back_inserter(w));\n                    u = w;\n                }\n        \
    \        que.emplace(nxt);\n            }\n        }\n    }\n\n    long long match(const\
    \ std::string& s) {\n        long long res = 0;\n        int cur = 0;\n      \
    \  for (const char& c : s) {\n            cur = next(cur, c - margin);\n     \
    \       res += cnt[cur];\n        }\n        return res;\n    }\n\n    std::map<int,\
    \ int> frequency(const std::string& s) {\n        std::map<int, int> res;\n  \
    \      int cur = 0;\n        for (const char& c : s) {\n            cur = next(cur,\
    \ c - margin);\n            for (auto& idx : nodes[cur].idxs) res[idx]++;\n  \
    \      }\n        return res;\n    }\n\n    int count(int pos) { return cnt[pos];\
    \ }\n\nprivate:\n    using super = Trie<char_size + 1, margin>;\n    using super::next;\n\
    \    using super::nodes;\n\n    const int FAIL = char_size;\n    std::vector<int>\
    \ cnt;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <queue>\n#include\
    \ \"Trie.hpp\"\n\ntemplate <size_t char_size, char margin = 'a'> struct AhoCorasick\
    \ : Trie<char_size + 1, margin> {\n    void build(bool heavy = true) {\n     \
    \   int n = nodes.size();\n        cnt.resize(n);\n        for (int i = 0; i <\
    \ n; i++) cnt[i] = nodes[i].idxs.size();\n        std::queue<int> que;\n     \
    \   for (size_t i = 0; i <= char_size; i++) {\n            if (~next(0, i)) {\n\
    \                next(next(0, i), FAIL) = 0;\n                que.emplace(next(0,\
    \ i));\n            } else\n                next(0, i) = 0;\n        }\n     \
    \   while (!que.empty()) {\n            auto& cur = nodes[que.front()];\n    \
    \        int fail = cur.nxt[FAIL];\n            cnt[que.front()] += cnt[fail];\n\
    \            que.pop();\n            for (size_t i = 0; i < char_size; i++) {\n\
    \                int& nxt = cur.nxt[i];\n                if (nxt < 0) {\n    \
    \                nxt = next(fail, i);\n                    continue;\n       \
    \         }\n                next(nxt, FAIL) = next(fail, i);\n              \
    \  if (heavy) {\n                    auto& u = nodes[nxt].idxs;\n            \
    \        auto& v = nodes[next(fail, i)].idxs;\n                    std::vector<int>\
    \ w;\n                    std::set_union(u.begin(), u.end(), v.begin(), v.end(),\
    \ back_inserter(w));\n                    u = w;\n                }\n        \
    \        que.emplace(nxt);\n            }\n        }\n    }\n\n    long long match(const\
    \ std::string& s) {\n        long long res = 0;\n        int cur = 0;\n      \
    \  for (const char& c : s) {\n            cur = next(cur, c - margin);\n     \
    \       res += cnt[cur];\n        }\n        return res;\n    }\n\n    std::map<int,\
    \ int> frequency(const std::string& s) {\n        std::map<int, int> res;\n  \
    \      int cur = 0;\n        for (const char& c : s) {\n            cur = next(cur,\
    \ c - margin);\n            for (auto& idx : nodes[cur].idxs) res[idx]++;\n  \
    \      }\n        return res;\n    }\n\n    int count(int pos) { return cnt[pos];\
    \ }\n\nprivate:\n    using super = Trie<char_size + 1, margin>;\n    using super::next;\n\
    \    using super::nodes;\n\n    const int FAIL = char_size;\n    std::vector<int>\
    \ cnt;\n};\n"
  dependsOn:
  - src/string/Trie.hpp
  isVerificationFile: false
  path: src/string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/430.AhoCorasick.test.cpp
  - test/yukicoder/1269.test.cpp
documentation_of: src/string/AhoCorasick.hpp
layout: document
title: Aho Corasick
---

## 概要
各パターン文字列を区別する必要がない場合には `build()` の引数 `heavy` を `false` にする．
