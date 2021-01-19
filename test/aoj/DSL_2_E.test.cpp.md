---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E
  bundledCode: "#line 1 \"test/aoj/DSL_2_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/LazySegmentTree.hpp\"\
    \n\n/**\n * @brief Lazy Segment Tree\n * @docs docs/datastructure/LazySegmentTree.md\n\
    \ */\ntemplate <typename Monoid, typename OperatorMonoid> struct LazySegmentTree\
    \ {\n    typedef function<Monoid(Monoid, Monoid)> F;\n    typedef function<Monoid(Monoid,\
    \ OperatorMonoid)> G;\n    typedef function<OperatorMonoid(OperatorMonoid, OperatorMonoid)>\
    \ H;\n    int n, hi;\n    F f;\n    G g;\n    H h;\n    Monoid id0;\n    OperatorMonoid\
    \ id1;\n    vector<Monoid> dat;\n    vector<OperatorMonoid> laz;\n    LazySegmentTree(int\
    \ n_, F f, G g, H h, Monoid id0, OperatorMonoid id1) : f(f), g(g), h(h), id0(id0),\
    \ id1(id1) {\n        init(n_);\n    }\n    void init(int n_) {\n        n = 1,\
    \ hi = 0;\n        while (n < n_) n <<= 1, hi++;\n        dat.assign(n << 1, id0);\n\
    \        laz.assign(n << 1, id1);\n    }\n    void build(const vector<Monoid>&\
    \ v) {\n        for (int i = 0; i < v.size(); i++) dat[i + n] = v[i];\n      \
    \  for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);\n\
    \    }\n    inline Monoid reflect(int k) { return laz[k] == id1 ? dat[k] : g(dat[k],\
    \ laz[k]); }\n    inline void propagate(int k) {\n        if (laz[k] == id1) return;\n\
    \        laz[k << 1 | 0] = h(laz[k << 1 | 0], laz[k]);\n        laz[k << 1 | 1]\
    \ = h(laz[k << 1 | 1], laz[k]);\n        dat[k] = reflect(k);\n        laz[k]\
    \ = id1;\n    }\n    inline void thrust(int k) {\n        for (int i = hi; i;\
    \ i--) propagate(k >> i);\n    }\n    inline void recalc(int k) {\n        while\
    \ (k >>= 1) dat[k] = f(reflect(k << 1 | 0), reflect(k << 1 | 1));\n    }\n   \
    \ void update(int a, int b, OperatorMonoid x) {\n        if (a >= b) return;\n\
    \        thrust(a += n);\n        thrust(b += n - 1);\n        for (int l = a,\
    \ r = b + 1; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) laz[l] = h(laz[l],\
    \ x), ++l;\n            if (r & 1) --r, laz[r] = h(laz[r], x);\n        }\n  \
    \      recalc(a);\n        recalc(b);\n    }\n    void set_val(int k, Monoid x)\
    \ {\n        thrust(k += n);\n        dat[k] = x, laz[k] = id1;\n        recalc(k);\n\
    \    }\n    Monoid query(int a, int b) {\n        if (a >= b) return id0;\n  \
    \      thrust(a += n);\n        thrust(b += n - 1);\n        Monoid vl = id0,\
    \ vr = id0;\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n \
    \           if (l & 1) vl = f(vl, reflect(l++));\n            if (r & 1) vr =\
    \ f(reflect(--r), vr);\n        }\n        return f(vl, vr);\n    }\n    template\
    \ <typename C> int find_subtree(int k, const C& check, Monoid& M, bool type) {\n\
    \        while (k < n) {\n            propagate(k);\n            Monoid nxt =\
    \ type ? f(reflect(k << 1 | type), M) : f(M, reflect(k << 1 | type));\n      \
    \      if (check(nxt))\n                k = k << 1 | type;\n            else\n\
    \                M = nxt, k = k << 1 | (type ^ 1);\n        }\n        return\
    \ k - n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy \"check\"\
    \n    template <typename C> int find_first(int a, const C& check) {\n        Monoid\
    \ L = id0;\n        if (a <= 0) {\n            if (check(f(L, reflect(1)))) return\
    \ find_subtree(1, check, L, false);\n            return -1;\n        }\n     \
    \   thrust(a + n);\n        int b = n;\n        for (int l = a + n, r = b + n;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                Monoid\
    \ nxt = f(L, reflect(l));\n                if (check(nxt)) return find_subtree(l,\
    \ check, L, false);\n                L = nxt;\n                l++;\n        \
    \    }\n        }\n        return -1;\n    }\n    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1])\
    \ satisfy \"check\"\n    template <typename C> int find_last(int b, const C& check)\
    \ {\n        Monoid R = id0;\n        if (b >= n) {\n            if (check(f(reflect(1),\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        thrust(b + n - 1);\n        int a = n;\n        for (int l = a,\
    \ r = b + n; l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n          \
    \      Monoid nxt = f(reflect(--r), R);\n                if (check(nxt)) return\
    \ find_subtree(r, check, R, true);\n                R = nxt;\n            }\n\
    \        }\n        return -1;\n    }\n    Monoid operator[](int i) { return query(i,\
    \ i + 1); }\n};\n#line 5 \"test/aoj/DSL_2_E.test.cpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n,q; cin >> n >> q;\n\n    auto f=[](int\
    \ a,int b){return a+b;};\n    LazySegmentTree<int,int> seg(n,f,f,f,0,0);\n\n \
    \   for (;q--;){\n        int c,s,t,x,i; cin >> c;\n        if (!c){\n       \
    \     cin >> s >> t >> x;\n            seg.update(s-1,t,x);\n        } else {\n\
    \            cin >> i;\n            cout << seg[i-1] << '\\n';\n        }\n  \
    \  }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/LazySegmentTree.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,q;\
    \ cin >> n >> q;\n\n    auto f=[](int a,int b){return a+b;};\n    LazySegmentTree<int,int>\
    \ seg(n,f,f,f,0,0);\n\n    for (;q--;){\n        int c,s,t,x,i; cin >> c;\n  \
    \      if (!c){\n            cin >> s >> t >> x;\n            seg.update(s-1,t,x);\n\
    \        } else {\n            cin >> i;\n            cout << seg[i-1] << '\\\
    n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_E.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_E.test.cpp
- /verify/test/aoj/DSL_2_E.test.cpp.html
title: test/aoj/DSL_2_E.test.cpp
---