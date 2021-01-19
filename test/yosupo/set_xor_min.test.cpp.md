---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryTrie.hpp
    title: Binary Trie
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo/set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nconst\
    \ long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int INF\
    \ = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/BinaryTrie.hpp\"\
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
    \ node->cnt;\n    }\n};\n#line 5 \"test/yosupo/set_xor_min.test.cpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q; cin >> Q;\n\n \
    \   BinaryTrie<int,30> BT;\n\n    for (;Q--;){\n        int t,x; cin >> t >> x;\n\
    \        if (t==0){\n            if (BT.count(x)) continue;\n            BT.insert(x);\n\
    \        } else if (t==1){\n            if (!BT.count(x)) continue;\n        \
    \    BT.erase(x);\n        } else cout << (BT.min_element(x)^x) << '\\n';\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../datastructure/BinaryTrie.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q; cin >> Q;\n\n \
    \   BinaryTrie<int,30> BT;\n\n    for (;Q--;){\n        int t,x; cin >> t >> x;\n\
    \        if (t==0){\n            if (BT.count(x)) continue;\n            BT.insert(x);\n\
    \        } else if (t==1){\n            if (!BT.count(x)) continue;\n        \
    \    BT.erase(x);\n        } else cout << (BT.min_element(x)^x) << '\\n';\n  \
    \  }\n}"
  dependsOn:
  - base.hpp
  - datastructure/BinaryTrie.hpp
  isVerificationFile: true
  path: test/yosupo/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/set_xor_min.test.cpp
- /verify/test/yosupo/set_xor_min.test.cpp.html
title: test/yosupo/set_xor_min.test.cpp
---
