---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/string/AhoCorasick.hpp
    title: Aho Corasick
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/string/Trie.hpp\"\n#include <algorithm>\n#include <array>\n\
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
    \ idxs(int pos) { return pos < 0 ? std::vector<int>() : nodes[pos].idxs; }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <string>\n#include <vector>\n\ntemplate <size_t char_size, char margin\
    \ = 'a'> struct Trie {\n    struct Node {\n        std::array<int, char_size>\
    \ nxt;\n        std::vector<int> idxs;\n        int idx, sub;\n        char key;\n\
    \        Node(char c) : idx(-1), key(c) { std::fill(nxt.begin(), nxt.end(), -1);\
    \ }\n    };\n\n    std::vector<Node> nodes;\n\n    inline int& next(int i, int\
    \ j) { return nodes[i].nxt[j]; }\n\n    Trie() { nodes.emplace_back('$'); }\n\n\
    \    void add(const std::string& s, int x = 0) {\n        int cur = 0;\n     \
    \   for (const char& c : s) {\n            int k = c - margin;\n            if\
    \ (next(cur, k) < 0) {\n                next(cur, k) = nodes.size();\n       \
    \         nodes.emplace_back(c);\n            }\n            cur = next(cur, k);\n\
    \            nodes[cur].sub++;\n        }\n        nodes[cur].idx = x;\n     \
    \   nodes[cur].idxs.emplace_back(x);\n    }\n\n    int find(const std::string&\
    \ s) {\n        int cur = 0;\n        for (const char& c : s) {\n            int\
    \ k = c - margin;\n            if (next(cur, k) < 0) return -1;\n            cur\
    \ = next(cur, k);\n        }\n        return cur;\n    }\n\n    int move(int pos,\
    \ char c) {\n        assert(pos < (int)nodes.size());\n        return pos < 0\
    \ ? -1 : next(pos, c - margin);\n    }\n\n    int size() const { return nodes.size();\
    \ }\n\n    int idx(int pos) { return pos < 0 ? -1 : nodes[pos].idx; }\n\n    std::vector<int>\
    \ idxs(int pos) { return pos < 0 ? std::vector<int>() : nodes[pos].idxs; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/Trie.hpp
  requiredBy:
  - src/string/AhoCorasick.hpp
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1269.test.cpp
documentation_of: src/string/Trie.hpp
layout: document
title: Trie
---

## 概要
