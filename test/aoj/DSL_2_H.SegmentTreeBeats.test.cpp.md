---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/SegmentTreeBeats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H
  bundledCode: "#line 1 \"test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\n\n#line\
    \ 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/SegmentTreeBeats.hpp\"\
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
    \ v) {\n        for (int i = 0; i < v.size(); i++) {\n            Nodes[i + n\
    \ - 1].Max = Nodes[i + n - 1].Min = Nodes[i + n - 1].sum = v[i];\n           \
    \ Nodes[i + n - 1].Max_count = Nodes[i + n - 1].Min_count = Nodes[i + n - 1].len\
    \ = 1;\n        }\n        for (int i = n - 2; i >= 0; --i) {\n            calc(i);\n\
    \            Nodes[i].len = Nodes[(i << 1) + 1].len + Nodes[(i << 1) + 2].len;\n\
    \        }\n    }\n    void update_min(int a, int b, T x) { update_min(a, b, x,\
    \ 0, 0, n); }\n    void update_max(int a, int b, T x) { update_max(a, b, x, 0,\
    \ 0, n); }\n    void update_add(int a, int b, T x) { update_add(a, b, x, 0, 0,\
    \ n); }\n    void update_val(int a, int b, T x) { update_val(a, b, x, 0, 0, n);\
    \ }\n    T query_min(int a, int b) { return query_min(a, b, 0, 0, n); }\n    T\
    \ query_max(int a, int b) { return query_max(a, b, 0, 0, n); }\n    T query_sum(int\
    \ a, int b) { return query_sum(a, b, 0, 0, n); }\n    T operator[](int i) { return\
    \ query_sum(i, i + 1); }\n};\n#line 5 \"test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,q;\
    \ cin >> n >> q;\n\n    SegmentTreeBeats<int> seg(n);\n    vector<int> v(n,0);\n\
    \    seg.build(v);\n\n    for (;q--;){\n        int c; cin >> c;\n        if (!c){\n\
    \            int s,t,x; cin >> s >> t >> x;\n            seg.update_add(s,t+1,x);\n\
    \        } else {\n            int s,t; cin >> s >> t;\n            cout << seg.query_min(s,t+1)\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTreeBeats.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,q;\
    \ cin >> n >> q;\n\n    SegmentTreeBeats<int> seg(n);\n    vector<int> v(n,0);\n\
    \    seg.build(v);\n\n    for (;q--;){\n        int c; cin >> c;\n        if (!c){\n\
    \            int s,t,x; cin >> s >> t >> x;\n            seg.update_add(s,t+1,x);\n\
    \        } else {\n            int s,t; cin >> s >> t;\n            cout << seg.query_min(s,t+1)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTreeBeats.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
- /verify/test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp.html
title: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
---
