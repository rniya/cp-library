---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryTrie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#include <iostream>\n#line 2 \"datastructure/BinaryTrie.hpp\"\n#include <array>\n\
    #include <cassert>\n#include <vector>\n\ntemplate <typename T, int MAX_LOG> struct\
    \ BinaryTrie {\n    struct Node {\n        std::array<int, 2> nxt;\n        int\
    \ count;\n        Node() : nxt{-1, -1}, count(0) {}\n    };\n\n    std::vector<Node>\
    \ nodes;\n\n    inline int& next(int i, int j) { return nodes[i].nxt[j]; }\n\n\
    \    BinaryTrie() { nodes.emplace_back(); }\n\n    void insert(const T& x) {\n\
    \        int cur = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n    \
    \        int f = x >> i & 1;\n            int nxt = next(cur, f);\n          \
    \  if (nxt == -1) {\n                nxt = nodes.size();\n                next(cur,\
    \ f) = nxt;\n                nodes.emplace_back();\n            }\n          \
    \  nodes[cur].count++;\n            cur = nxt;\n        }\n        nodes[cur].count++;\n\
    \    }\n\n    void erase(const T& x) {\n        assert(count(x));\n        int\
    \ cur = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            int\
    \ f = x >> i & 1;\n            nodes[cur].count--;\n            cur = next(cur,\
    \ f);\n        }\n        nodes[cur].count--;\n    }\n\n    int find(const T&\
    \ x) {\n        int cur = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n\
    \            int f = x >> i & 1;\n            cur = next(cur, f);\n          \
    \  if (cur == -1) return -1;\n        }\n        return cur;\n    }\n\n    int\
    \ count(const T& x) {\n        int idx = find(x);\n        return idx == -1 ?\
    \ 0 : nodes[idx].count;\n    }\n\n    T min_element(const T& xor_val = 0) {\n\
    \        int cur = 0;\n        T res = 0;\n        for (int i = MAX_LOG - 1; i\
    \ >= 0; i--) {\n            int f = xor_val >> i & 1;\n            int l = next(cur,\
    \ f), r = next(cur, f ^ 1);\n            if (l == -1 or nodes[l].count == 0) {\n\
    \                cur = r;\n                res |= T(f ^ 1) << i;\n           \
    \ } else {\n                cur = l;\n                res |= T(f) << i;\n    \
    \        }\n        }\n        return res;\n    }\n\n    T max_element(const T&\
    \ xor_val = 0) { return min_element(~xor_val); }\n\n    T kth_element(int k, const\
    \ T& xor_val = 0) const {\n        int cur = 0;\n        T res = 0;\n        for\
    \ (int i = MAX_LOG - 1; i >= 0; i--) {\n            int f = xor_val >> i & 1;\n\
    \            int l = next(cur, f), r = next(cur, f ^ 1);\n            if (l ==\
    \ -1 or nodes[l].count <= k) {\n                cur = r;\n                k -=\
    \ (l == -1 ? 0 : nodes[l].count);\n                res |= T(f ^ 1) << i;\n   \
    \         } else {\n                cur = l;\n                res |= T(f) << i;\n\
    \            }\n        }\n        return res;\n    }\n\n    int count_less(const\
    \ T& x, const T& xor_val = 0) const {\n        int cur = 0;\n        int res =\
    \ 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            int f = xor_val\
    \ >> i & 1, g = x >> i & 1;\n            int l = next(cur, f), r = next(cur, f\
    \ ^ 1);\n            if (f != g and l != -1) res += nodes[l].count;\n        \
    \    cur = next(cur, g);\n            if (cur == -1) break;\n        }\n     \
    \   return res;\n    }\n};\n#line 5 \"test/yosupo/set_xor_min.test.cpp\"\n\nint\
    \ main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int\
    \ Q;\n    std::cin >> Q;\n\n    BinaryTrie<int, 30> BT;\n\n    for (; Q--;) {\n\
    \        int t, x;\n        std::cin >> t >> x;\n        if (t == 0) {\n     \
    \       if (BT.count(x)) continue;\n            BT.insert(x);\n        } else\
    \ if (t == 1) {\n            if (!BT.count(x)) continue;\n            BT.erase(x);\n\
    \        } else\n            std::cout << (BT.min_element(x) ^ x) << '\\n';\n\
    \    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <iostream>\n#include \"datastructure/BinaryTrie.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int Q;\n    std::cin >> Q;\n\n   \
    \ BinaryTrie<int, 30> BT;\n\n    for (; Q--;) {\n        int t, x;\n        std::cin\
    \ >> t >> x;\n        if (t == 0) {\n            if (BT.count(x)) continue;\n\
    \            BT.insert(x);\n        } else if (t == 1) {\n            if (!BT.count(x))\
    \ continue;\n            BT.erase(x);\n        } else\n            std::cout <<\
    \ (BT.min_element(x) ^ x) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - datastructure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2022-04-14 01:34:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---
