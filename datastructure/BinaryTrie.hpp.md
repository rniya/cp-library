---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BinaryTrie.md
    document_title: Binary Trie
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/BinaryTrie.hpp\"\
    \n\n/**\n * @brief Binary Trie\n * @docs docs/datastructure/BinaryTrie.md\n */\n\
    template <typename T, int MAX_LOG> class BinaryTrie {\n    struct Node {\n   \
    \     int cnt;\n        Node* ch[2];\n        Node() : cnt(0), ch{nullptr, nullptr}\
    \ {}\n    };\n    Node* root;\n    Node* add(Node* node, T val, int b = MAX_LOG\
    \ - 1) {\n        if (!node) node = new Node;\n        node->cnt += 1;\n     \
    \   if (b < 0) return node;\n        bool f = (val >> (T)b) & (T)1;\n        node->ch[f]\
    \ = add(node->ch[f], val, b - 1);\n        return node;\n    }\n    Node* sub(Node*\
    \ node, T val, int b = MAX_LOG - 1) {\n        node->cnt -= 1;\n        if (node->cnt\
    \ == 0) return nullptr;\n        if (b < 0) return node;\n        bool f = (val\
    \ >> (T)b) & (T)1;\n        node->ch[f] = sub(node->ch[f], val, b - 1);\n    \
    \    return node;\n    }\n    T get_min(Node* node, T val, int b = MAX_LOG - 1)\
    \ const {\n        if (b < 0) return 0;\n        bool f = (val >> (T)b) & (T)1;\n\
    \        f ^= !node->ch[f];\n        return get_min(node->ch[f], val, b - 1) |\
    \ (T)f << (T)b;\n    }\n    T get(Node* node, int k, int b = MAX_LOG - 1) const\
    \ {\n        if (b < 0) return 0;\n        int m = node->ch[0] ? node->ch[0]->cnt\
    \ : 0;\n        return k < m ? get(node->ch[0], k, b - 1) : get(node->ch[1], k\
    \ - m, b - 1) | (T)1 << (T)b;\n    }\n    int count_lower(Node* node, T val, int\
    \ b = MAX_LOG - 1) {\n        if (!node || b < 0) return 0;\n        bool f =\
    \ (val >> (T)b) & (T)1;\n        return (f && node->ch[0] ? node->ch[0]->cnt :\
    \ 0) + count_lower(node->ch[f], val, b - 1);\n    }\n\npublic:\n    BinaryTrie()\
    \ : root(nullptr) {}\n    int size() const { return root ? root->cnt : 0; }\n\
    \    bool empty() const { return !root; }\n    void insert(T val) { root = add(root,\
    \ val); }\n    void erase(T val) { root = sub(root, val); }\n    T max_element(T\
    \ bias = 0) const { return get_min(root, ~bias); }\n    T min_element(T bias =\
    \ 0) const { return get_min(root, bias); }\n    int lower_bound(T val) { return\
    \ count_lower(root, val); }\n    int upper_bound(T val) { return count_lower(root,\
    \ val + 1); }\n    T operator[](int k) const { return get(root, k); }\n    int\
    \ count(T val) const {\n        if (!root) return 0;\n        Node* node = root;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            node = node->ch[(val\
    \ >> (T)i) & (T)1];\n            if (!node) return 0;\n        }\n        return\
    \ node->cnt;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Binary Trie\n *\
    \ @docs docs/datastructure/BinaryTrie.md\n */\ntemplate <typename T, int MAX_LOG>\
    \ class BinaryTrie {\n    struct Node {\n        int cnt;\n        Node* ch[2];\n\
    \        Node() : cnt(0), ch{nullptr, nullptr} {}\n    };\n    Node* root;\n \
    \   Node* add(Node* node, T val, int b = MAX_LOG - 1) {\n        if (!node) node\
    \ = new Node;\n        node->cnt += 1;\n        if (b < 0) return node;\n    \
    \    bool f = (val >> (T)b) & (T)1;\n        node->ch[f] = add(node->ch[f], val,\
    \ b - 1);\n        return node;\n    }\n    Node* sub(Node* node, T val, int b\
    \ = MAX_LOG - 1) {\n        node->cnt -= 1;\n        if (node->cnt == 0) return\
    \ nullptr;\n        if (b < 0) return node;\n        bool f = (val >> (T)b) &\
    \ (T)1;\n        node->ch[f] = sub(node->ch[f], val, b - 1);\n        return node;\n\
    \    }\n    T get_min(Node* node, T val, int b = MAX_LOG - 1) const {\n      \
    \  if (b < 0) return 0;\n        bool f = (val >> (T)b) & (T)1;\n        f ^=\
    \ !node->ch[f];\n        return get_min(node->ch[f], val, b - 1) | (T)f << (T)b;\n\
    \    }\n    T get(Node* node, int k, int b = MAX_LOG - 1) const {\n        if\
    \ (b < 0) return 0;\n        int m = node->ch[0] ? node->ch[0]->cnt : 0;\n   \
    \     return k < m ? get(node->ch[0], k, b - 1) : get(node->ch[1], k - m, b -\
    \ 1) | (T)1 << (T)b;\n    }\n    int count_lower(Node* node, T val, int b = MAX_LOG\
    \ - 1) {\n        if (!node || b < 0) return 0;\n        bool f = (val >> (T)b)\
    \ & (T)1;\n        return (f && node->ch[0] ? node->ch[0]->cnt : 0) + count_lower(node->ch[f],\
    \ val, b - 1);\n    }\n\npublic:\n    BinaryTrie() : root(nullptr) {}\n    int\
    \ size() const { return root ? root->cnt : 0; }\n    bool empty() const { return\
    \ !root; }\n    void insert(T val) { root = add(root, val); }\n    void erase(T\
    \ val) { root = sub(root, val); }\n    T max_element(T bias = 0) const { return\
    \ get_min(root, ~bias); }\n    T min_element(T bias = 0) const { return get_min(root,\
    \ bias); }\n    int lower_bound(T val) { return count_lower(root, val); }\n  \
    \  int upper_bound(T val) { return count_lower(root, val + 1); }\n    T operator[](int\
    \ k) const { return get(root, k); }\n    int count(T val) const {\n        if\
    \ (!root) return 0;\n        Node* node = root;\n        for (int i = MAX_LOG\
    \ - 1; i >= 0; i--) {\n            node = node->ch[(val >> (T)i) & (T)1];\n  \
    \          if (!node) return 0;\n        }\n        return node->cnt;\n    }\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: datastructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryTrie.hpp
- /library/datastructure/BinaryTrie.hpp.html
title: Binary Trie
---
## 概要

## 計算量