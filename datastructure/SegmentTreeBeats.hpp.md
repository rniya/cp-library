---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/LazySegmentTree.md
    document_title: Segment Tree Beats
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t\
    \ i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n#define\
    \ ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
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
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (size_t i\
    \ = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" :\
    \ \" \");\n    }\n    return os;\n}\ntemplate <typename T, size_t N> ostream&\
    \ operator<<(ostream& os, const array<T, N>& v) {\n    for (size_t i = 0; i <\
    \ N; i++) {\n        os << v[i] << (i + 1 == N ? \"\" : \" \");\n    }\n    return\
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
    \ void(0)\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\nlong long MSK(int n) {\
    \ return (1LL << n) - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y\
    \ >= 1);\n    return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T>\
    \ T floor(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y\
    \ + 1) / y);\n}\n\ntemplate <class T1, class T2> inline bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n\
    \    if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <typename T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n}\ntemplate <typename T> int\
    \ lwb(const vector<T>& v, const T& x) { return lower_bound(v.begin(), v.end(),\
    \ x) - v.begin(); }\n#pragma endregion\n#line 3 \"datastructure/SegmentTreeBeats.hpp\"\
    \n\n/**\n * @brief Segment Tree Beats\n * @docs docs/datastructure/LazySegmentTree.md\n\
    \ */\ntemplate <typename T> class SegmentTreeBeats {\n    int n;\n    static const\
    \ T idm = numeric_limits<T>::min();\n    static const T idM = numeric_limits<T>::max(),\
    \ idl = idM;\n    struct Node {\n        T Max, Max_second, Min, Min_second, sum,\
    \ laz_add, laz_val;\n        int Max_count, Min_count, len;\n        Node() :\
    \ Max(idm), Max_second(idm), Min(idM), Min_second(idM), laz_add(0), laz_val(idl),\
    \ len(1) {}\n    };\n    vector<Node> Nodes;\n    inline void calc(int k) {\n\
    \        Node& p = Nodes[k];\n        Node l = Nodes[(k << 1) + 1], r = Nodes[(k\
    \ << 1) + 2];\n        p.sum = l.sum + r.sum;\n        if (l.Max < r.Max) {\n\
    \            p.Max = r.Max;\n            p.Max_count = r.Max_count;\n        \
    \    p.Max_second = max(l.Max, r.Max_second);\n        } else if (r.Max < l.Max)\
    \ {\n            p.Max = l.Max;\n            p.Max_count = l.Max_count;\n    \
    \        p.Max_second = max(l.Max_second, r.Max);\n        } else {\n        \
    \    p.Max = l.Max;\n            p.Max_count = l.Max_count + r.Max_count;\n  \
    \          p.Max_second = max(l.Max_second, r.Max_second);\n        }\n      \
    \  if (l.Min < r.Min) {\n            p.Min = l.Min;\n            p.Min_count =\
    \ l.Min_count;\n            p.Min_second = min(l.Min_second, r.Min);\n       \
    \ } else if (r.Min < l.Min) {\n            p.Min = r.Min;\n            p.Min_count\
    \ = r.Min_count;\n            p.Min_second = min(l.Min, r.Min_second);\n     \
    \   } else {\n            p.Min = l.Min;\n            p.Min_count = l.Min_count\
    \ + r.Min_count;\n            p.Min_second = min(l.Min_second, r.Min_second);\n\
    \        }\n    }\n    inline void update_node_min(int k, T x) {\n        Node&\
    \ node = Nodes[k];\n        node.sum += (x - node.Max) * node.Max_count;\n   \
    \     if (node.Max == node.Min)\n            node.Max = node.Min = x;\n      \
    \  else if (node.Max == node.Min_second)\n            node.Max = node.Min_second\
    \ = x;\n        else\n            node.Max = x;\n        if (node.laz_val != idl\
    \ && node.laz_val < x) node.laz_val = x;\n    }\n    inline void update_node_max(int\
    \ k, T x) {\n        Node& node = Nodes[k];\n        node.sum += (x - node.Min)\
    \ * node.Min_count;\n        if (node.Min == node.Max)\n            node.Min =\
    \ node.Max = x;\n        else if (node.Min == node.Max_second)\n            node.Min\
    \ = node.Max_second = x;\n        else\n            node.Min = x;\n        if\
    \ (node.laz_val != idl && x < node.laz_val) node.laz_val = x;\n    }\n    inline\
    \ void update_node_add(int k, T x) {\n        Node& node = Nodes[k];\n       \
    \ node.Max += x;\n        if (node.Max_second != idm) node.Max_second += x;\n\
    \        node.Min += x;\n        if (node.Min_second != idM) node.Min_second +=\
    \ x;\n        node.sum += x * node.len;\n        (node.laz_val != idl ? node.laz_val\
    \ : node.laz_add) += x;\n    }\n    inline void update_node_val(int k, T x) {\n\
    \        Node& node = Nodes[k];\n        node.Max = x;\n        node.Max_second\
    \ = idm;\n        node.Min = x;\n        node.Min_second = idM;\n        node.Max_count\
    \ = node.Min_count = node.len;\n        node.sum = x * node.len;\n        node.laz_val\
    \ = x;\n        node.laz_add = 0;\n    }\n    inline void propagate(int k) {\n\
    \        if (k >= n - 1) return;\n        Node& node = Nodes[k];\n        if (node.laz_val\
    \ != idl) {\n            update_node_val((k << 1) + 1, node.laz_val);\n      \
    \      update_node_val((k << 1) + 2, node.laz_val);\n            node.laz_val\
    \ = idl;\n            return;\n        }\n        if (node.laz_add != 0) {\n \
    \           update_node_add((k << 1) + 1, node.laz_add);\n            update_node_add((k\
    \ << 1) + 2, node.laz_add);\n            node.laz_add = 0;\n        }\n      \
    \  if (node.Max < Nodes[(k << 1) + 1].Max) update_node_min((k << 1) + 1, node.Max);\n\
    \        if (node.Max < Nodes[(k << 1) + 2].Max) update_node_min((k << 1) + 2,\
    \ node.Max);\n        if (Nodes[(k << 1) + 1].Min < node.Min) update_node_max((k\
    \ << 1) + 1, node.Min);\n        if (Nodes[(k << 1) + 2].Min < node.Min) update_node_max((k\
    \ << 1) + 2, node.Min);\n    }\n    inline void update_min(int a, int b, T x,\
    \ int k, int l, int r) {\n        if (b <= l || r <= a || Nodes[k].Max <= x) return;\n\
    \        if (a <= l && r <= b && Nodes[k].Max_second < x) {\n            update_node_min(k,\
    \ x);\n            return;\n        }\n        propagate(k);\n        update_min(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_min(a, b, x, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline void update_max(int\
    \ a, int b, T x, int k, int l, int r) {\n        if (b <= l || r <= a || x <=\
    \ Nodes[k].Min) return;\n        if (a <= l && r <= b && x < Nodes[k].Min_second)\
    \ {\n            update_node_max(k, x);\n            return;\n        }\n    \
    \    propagate(k);\n        update_max(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n\
    \        update_max(a, b, x, (k << 1) + 2, (l + r) >> 1, r);\n        calc(k);\n\
    \    }\n    inline void update_add(int a, int b, T x, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) {\n    \
    \        update_node_add(k, x);\n            return;\n        }\n        propagate(k);\n\
    \        update_add(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_add(a,\
    \ b, x, (k << 1) + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline void\
    \ update_val(int a, int b, T x, int k, int l, int r) {\n        if (b <= l ||\
    \ r <= a) return;\n        if (a <= l && r <= b) {\n            update_node_val(k,\
    \ x);\n            return;\n        }\n        propagate(k);\n        update_val(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_val(a, b, x, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline T query_min(int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return idM;\n\
    \        if (a <= l && r <= b) return Nodes[k].Min;\n        propagate(k);\n \
    \       T vl = query_min(a, b, (k << 1) + 1, l, (l + r) >> 1);\n        T vr =\
    \ query_min(a, b, (k << 1) + 2, (l + r) >> 1, r);\n        return min(vl, vr);\n\
    \    }\n    inline T query_max(int a, int b, int k, int l, int r) {\n        if\
    \ (b <= l || r <= a) return idm;\n        if (a <= l && r <= b) return Nodes[k].Max;\n\
    \        propagate(k);\n        T vl = query_max(a, b, (k << 1) + 1, l, (l + r)\
    \ >> 1);\n        T vr = query_max(a, b, (k << 1) + 2, (l + r) >> 1, r);\n   \
    \     return max(vl, vr);\n    }\n    inline T query_sum(int a, int b, int k,\
    \ int l, int r) {\n        if (b <= l || r <= a) return 0;\n        if (a <= l\
    \ && r <= b) return Nodes[k].sum;\n        propagate(k);\n        T vl = query_sum(a,\
    \ b, (k << 1) + 1, l, (l + r) >> 1);\n        T vr = query_sum(a, b, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        return vl + vr;\n    }\n\npublic:\n    SegmentTreeBeats(int\
    \ n_) { init(n_); }\n    void init(int n_) {\n        n = 1;\n        while (n\
    \ < n_) n <<= 1;\n        Nodes.resize(n << 1);\n    }\n    void build(const vector<T>&\
    \ v) {\n        for (int i = 0; i < (int)v.size(); i++) {\n            Nodes[i\
    \ + n - 1].Max = Nodes[i + n - 1].Min = Nodes[i + n - 1].sum = v[i];\n       \
    \     Nodes[i + n - 1].Max_count = Nodes[i + n - 1].Min_count = Nodes[i + n -\
    \ 1].len = 1;\n        }\n        for (int i = n - 2; i >= 0; --i) {\n       \
    \     calc(i);\n            Nodes[i].len = Nodes[(i << 1) + 1].len + Nodes[(i\
    \ << 1) + 2].len;\n        }\n    }\n    void update_min(int a, int b, T x) {\
    \ update_min(a, b, x, 0, 0, n); }\n    void update_max(int a, int b, T x) { update_max(a,\
    \ b, x, 0, 0, n); }\n    void update_add(int a, int b, T x) { update_add(a, b,\
    \ x, 0, 0, n); }\n    void update_val(int a, int b, T x) { update_val(a, b, x,\
    \ 0, 0, n); }\n    T query_min(int a, int b) { return query_min(a, b, 0, 0, n);\
    \ }\n    T query_max(int a, int b) { return query_max(a, b, 0, 0, n); }\n    T\
    \ query_sum(int a, int b) { return query_sum(a, b, 0, 0, n); }\n    T operator[](int\
    \ i) { return query_sum(i, i + 1); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Segment Tree Beats\n\
    \ * @docs docs/datastructure/LazySegmentTree.md\n */\ntemplate <typename T> class\
    \ SegmentTreeBeats {\n    int n;\n    static const T idm = numeric_limits<T>::min();\n\
    \    static const T idM = numeric_limits<T>::max(), idl = idM;\n    struct Node\
    \ {\n        T Max, Max_second, Min, Min_second, sum, laz_add, laz_val;\n    \
    \    int Max_count, Min_count, len;\n        Node() : Max(idm), Max_second(idm),\
    \ Min(idM), Min_second(idM), laz_add(0), laz_val(idl), len(1) {}\n    };\n   \
    \ vector<Node> Nodes;\n    inline void calc(int k) {\n        Node& p = Nodes[k];\n\
    \        Node l = Nodes[(k << 1) + 1], r = Nodes[(k << 1) + 2];\n        p.sum\
    \ = l.sum + r.sum;\n        if (l.Max < r.Max) {\n            p.Max = r.Max;\n\
    \            p.Max_count = r.Max_count;\n            p.Max_second = max(l.Max,\
    \ r.Max_second);\n        } else if (r.Max < l.Max) {\n            p.Max = l.Max;\n\
    \            p.Max_count = l.Max_count;\n            p.Max_second = max(l.Max_second,\
    \ r.Max);\n        } else {\n            p.Max = l.Max;\n            p.Max_count\
    \ = l.Max_count + r.Max_count;\n            p.Max_second = max(l.Max_second, r.Max_second);\n\
    \        }\n        if (l.Min < r.Min) {\n            p.Min = l.Min;\n       \
    \     p.Min_count = l.Min_count;\n            p.Min_second = min(l.Min_second,\
    \ r.Min);\n        } else if (r.Min < l.Min) {\n            p.Min = r.Min;\n \
    \           p.Min_count = r.Min_count;\n            p.Min_second = min(l.Min,\
    \ r.Min_second);\n        } else {\n            p.Min = l.Min;\n            p.Min_count\
    \ = l.Min_count + r.Min_count;\n            p.Min_second = min(l.Min_second, r.Min_second);\n\
    \        }\n    }\n    inline void update_node_min(int k, T x) {\n        Node&\
    \ node = Nodes[k];\n        node.sum += (x - node.Max) * node.Max_count;\n   \
    \     if (node.Max == node.Min)\n            node.Max = node.Min = x;\n      \
    \  else if (node.Max == node.Min_second)\n            node.Max = node.Min_second\
    \ = x;\n        else\n            node.Max = x;\n        if (node.laz_val != idl\
    \ && node.laz_val < x) node.laz_val = x;\n    }\n    inline void update_node_max(int\
    \ k, T x) {\n        Node& node = Nodes[k];\n        node.sum += (x - node.Min)\
    \ * node.Min_count;\n        if (node.Min == node.Max)\n            node.Min =\
    \ node.Max = x;\n        else if (node.Min == node.Max_second)\n            node.Min\
    \ = node.Max_second = x;\n        else\n            node.Min = x;\n        if\
    \ (node.laz_val != idl && x < node.laz_val) node.laz_val = x;\n    }\n    inline\
    \ void update_node_add(int k, T x) {\n        Node& node = Nodes[k];\n       \
    \ node.Max += x;\n        if (node.Max_second != idm) node.Max_second += x;\n\
    \        node.Min += x;\n        if (node.Min_second != idM) node.Min_second +=\
    \ x;\n        node.sum += x * node.len;\n        (node.laz_val != idl ? node.laz_val\
    \ : node.laz_add) += x;\n    }\n    inline void update_node_val(int k, T x) {\n\
    \        Node& node = Nodes[k];\n        node.Max = x;\n        node.Max_second\
    \ = idm;\n        node.Min = x;\n        node.Min_second = idM;\n        node.Max_count\
    \ = node.Min_count = node.len;\n        node.sum = x * node.len;\n        node.laz_val\
    \ = x;\n        node.laz_add = 0;\n    }\n    inline void propagate(int k) {\n\
    \        if (k >= n - 1) return;\n        Node& node = Nodes[k];\n        if (node.laz_val\
    \ != idl) {\n            update_node_val((k << 1) + 1, node.laz_val);\n      \
    \      update_node_val((k << 1) + 2, node.laz_val);\n            node.laz_val\
    \ = idl;\n            return;\n        }\n        if (node.laz_add != 0) {\n \
    \           update_node_add((k << 1) + 1, node.laz_add);\n            update_node_add((k\
    \ << 1) + 2, node.laz_add);\n            node.laz_add = 0;\n        }\n      \
    \  if (node.Max < Nodes[(k << 1) + 1].Max) update_node_min((k << 1) + 1, node.Max);\n\
    \        if (node.Max < Nodes[(k << 1) + 2].Max) update_node_min((k << 1) + 2,\
    \ node.Max);\n        if (Nodes[(k << 1) + 1].Min < node.Min) update_node_max((k\
    \ << 1) + 1, node.Min);\n        if (Nodes[(k << 1) + 2].Min < node.Min) update_node_max((k\
    \ << 1) + 2, node.Min);\n    }\n    inline void update_min(int a, int b, T x,\
    \ int k, int l, int r) {\n        if (b <= l || r <= a || Nodes[k].Max <= x) return;\n\
    \        if (a <= l && r <= b && Nodes[k].Max_second < x) {\n            update_node_min(k,\
    \ x);\n            return;\n        }\n        propagate(k);\n        update_min(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_min(a, b, x, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline void update_max(int\
    \ a, int b, T x, int k, int l, int r) {\n        if (b <= l || r <= a || x <=\
    \ Nodes[k].Min) return;\n        if (a <= l && r <= b && x < Nodes[k].Min_second)\
    \ {\n            update_node_max(k, x);\n            return;\n        }\n    \
    \    propagate(k);\n        update_max(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n\
    \        update_max(a, b, x, (k << 1) + 2, (l + r) >> 1, r);\n        calc(k);\n\
    \    }\n    inline void update_add(int a, int b, T x, int k, int l, int r) {\n\
    \        if (b <= l || r <= a) return;\n        if (a <= l && r <= b) {\n    \
    \        update_node_add(k, x);\n            return;\n        }\n        propagate(k);\n\
    \        update_add(a, b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_add(a,\
    \ b, x, (k << 1) + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline void\
    \ update_val(int a, int b, T x, int k, int l, int r) {\n        if (b <= l ||\
    \ r <= a) return;\n        if (a <= l && r <= b) {\n            update_node_val(k,\
    \ x);\n            return;\n        }\n        propagate(k);\n        update_val(a,\
    \ b, x, (k << 1) + 1, l, (l + r) >> 1);\n        update_val(a, b, x, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        calc(k);\n    }\n    inline T query_min(int\
    \ a, int b, int k, int l, int r) {\n        if (b <= l || r <= a) return idM;\n\
    \        if (a <= l && r <= b) return Nodes[k].Min;\n        propagate(k);\n \
    \       T vl = query_min(a, b, (k << 1) + 1, l, (l + r) >> 1);\n        T vr =\
    \ query_min(a, b, (k << 1) + 2, (l + r) >> 1, r);\n        return min(vl, vr);\n\
    \    }\n    inline T query_max(int a, int b, int k, int l, int r) {\n        if\
    \ (b <= l || r <= a) return idm;\n        if (a <= l && r <= b) return Nodes[k].Max;\n\
    \        propagate(k);\n        T vl = query_max(a, b, (k << 1) + 1, l, (l + r)\
    \ >> 1);\n        T vr = query_max(a, b, (k << 1) + 2, (l + r) >> 1, r);\n   \
    \     return max(vl, vr);\n    }\n    inline T query_sum(int a, int b, int k,\
    \ int l, int r) {\n        if (b <= l || r <= a) return 0;\n        if (a <= l\
    \ && r <= b) return Nodes[k].sum;\n        propagate(k);\n        T vl = query_sum(a,\
    \ b, (k << 1) + 1, l, (l + r) >> 1);\n        T vr = query_sum(a, b, (k << 1)\
    \ + 2, (l + r) >> 1, r);\n        return vl + vr;\n    }\n\npublic:\n    SegmentTreeBeats(int\
    \ n_) { init(n_); }\n    void init(int n_) {\n        n = 1;\n        while (n\
    \ < n_) n <<= 1;\n        Nodes.resize(n << 1);\n    }\n    void build(const vector<T>&\
    \ v) {\n        for (int i = 0; i < (int)v.size(); i++) {\n            Nodes[i\
    \ + n - 1].Max = Nodes[i + n - 1].Min = Nodes[i + n - 1].sum = v[i];\n       \
    \     Nodes[i + n - 1].Max_count = Nodes[i + n - 1].Min_count = Nodes[i + n -\
    \ 1].len = 1;\n        }\n        for (int i = n - 2; i >= 0; --i) {\n       \
    \     calc(i);\n            Nodes[i].len = Nodes[(i << 1) + 1].len + Nodes[(i\
    \ << 1) + 2].len;\n        }\n    }\n    void update_min(int a, int b, T x) {\
    \ update_min(a, b, x, 0, 0, n); }\n    void update_max(int a, int b, T x) { update_max(a,\
    \ b, x, 0, 0, n); }\n    void update_add(int a, int b, T x) { update_add(a, b,\
    \ x, 0, 0, n); }\n    void update_val(int a, int b, T x) { update_val(a, b, x,\
    \ 0, 0, n); }\n    T query_min(int a, int b) { return query_min(a, b, 0, 0, n);\
    \ }\n    T query_max(int a, int b) { return query_max(a, b, 0, 0, n); }\n    T\
    \ query_sum(int a, int b) { return query_sum(a, b, 0, 0, n); }\n    T operator[](int\
    \ i) { return query_sum(i, i + 1); }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: datastructure/SegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/datastructure/SegmentTreeBeats.hpp
- /library/datastructure/SegmentTreeBeats.hpp.html
title: Segment Tree Beats
---
