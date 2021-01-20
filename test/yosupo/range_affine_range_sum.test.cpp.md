---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':x:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_affine_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ?\
    \ \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {\n\
    \    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U, typename V, typename W>\
    \ ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {\n    os << '('\
    \ << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) <<\
    \ ')';\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n       \
    \ os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\
    \nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class... Tail> void\
    \ debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n    if (sizeof...(Tail)\
    \ > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define\
    \ debug(...)                                                                 \
    \  \\\n    cerr << \" \";                                                    \
    \                 \\\n    cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\"\
    \ << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \";                  \
    \                                                   \\\n    debug_out(__VA_ARGS__)\n\
    #else\n#define debug(...) 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y)\
    \ { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename T> T lcm(T x, T y)\
    \ { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class T2> inline bool chmin(T1&\
    \ a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a,\
    \ T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n#line 3 \"modulo/modint.hpp\"\n\n/**\n * @brief modint\n *\
    \ @docs docs/modulo/modint.md\n */\ntemplate <uint32_t mod> class modint {\n \
    \   using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \npublic:\n    u32 v;\n    constexpr modint(const i64 x = 0) noexcept : v(x <\
    \ 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& value() noexcept\
    \ { return v; }\n    constexpr const u32& value() const noexcept { return v; }\n\
    \    constexpr modint operator+(const modint& rhs) const noexcept { return modint(*this)\
    \ += rhs; }\n    constexpr modint operator-(const modint& rhs) const noexcept\
    \ { return modint(*this) -= rhs; }\n    constexpr modint operator*(const modint&\
    \ rhs) const noexcept { return modint(*this) *= rhs; }\n    constexpr modint operator/(const\
    \ modint& rhs) const noexcept { return modint(*this) /= rhs; }\n    constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n        v += rhs.v;\n    \
    \    if (v >= mod) v -= mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint& rhs) noexcept {\n        if (v < rhs.v) v += mod;\n\
    \        v -= rhs.v;\n        return *this;\n    }\n    constexpr modint& operator*=(const\
    \ modint& rhs) noexcept {\n        v = (u64)v * rhs.v % mod;\n        return *this;\n\
    \    }\n    constexpr modint& operator/=(const modint& rhs) noexcept { return\
    \ *this *= rhs.pow(mod - 2); }\n    constexpr modint pow(u64 exp) const noexcept\
    \ {\n        modint self(*this), res(1);\n        while (exp > 0) {\n        \
    \    if (exp & 1) res *= self;\n            self *= self;\n            exp >>=\
    \ 1;\n        }\n        return res;\n    }\n    constexpr modint& operator++()\
    \ noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n \
    \   constexpr modint& operator--() noexcept {\n        if (v == 0) v = mod;\n\
    \        return --v, *this;\n    }\n    constexpr modint operator++(int) noexcept\
    \ {\n        modint t = *this;\n        return ++*this, t;\n    }\n    constexpr\
    \ modint operator--(int) noexcept {\n        modint t = *this;\n        return\
    \ --*this, t;\n    }\n    constexpr modint operator-() const noexcept { return\
    \ modint(mod - v); }\n    template <class T> friend constexpr modint operator+(T\
    \ x, modint y) noexcept { return modint(x) + y; }\n    template <class T> friend\
    \ constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n\
    \    template <class T> friend constexpr modint operator*(T x, modint y) noexcept\
    \ { return modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend istream& operator>>(istream& s, modint&\
    \ rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n      \
    \  return s;\n    }\n    friend ostream& operator<<(ostream& s, const modint&\
    \ rhs) noexcept { return s << rhs.v; }\n};\n#line 3 \"datastructure/LazySegmentTree.hpp\"\
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
    \ i + 1); }\n};\n#line 6 \"test/yosupo/range_affine_range_sum.test.cpp\"\n\nusing\
    \ mint=modint<998244353>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N,Q; cin >> N >> Q;\n    vector<mint> a(N);\n    for (int i=0;i<N;++i)\
    \ cin >> a[i];\n\n    struct node{\n        mint sum; int a;\n        node(mint\
    \ sum,int a):sum(sum),a(a){}\n    };\n    struct add{\n        mint b,c;\n   \
    \     add(mint b,mint c):b(b),c(c){}\n        const bool operator==(const add\
    \ &rhs){\n            return b==rhs.b&&c==rhs.c;\n        }\n    };\n    auto\
    \ f=[](node a,node b){return node(a.sum+b.sum,a.a+b.a);};\n    auto g=[](node\
    \ a,add x){return node(a.sum*x.b+x.c*a.a,a.a);};\n    auto h=[](add a,add b){return\
    \ add(a.b*b.b,a.c*b.b+b.c);};\n    LazySegmentTree<node,add> seg(N,f,g,h,node(0,0),add(1,0));\n\
    \    vector<node> v;\n    for (int i=0;i<N;++i) v.emplace_back(a[i],1);\n    seg.build(v);\n\
    \n    for (;Q--;){\n        int t,l,r; cin >> t >> l >> r;\n        if (!t){\n\
    \            mint b,c; cin >> b >> c;\n            seg.update(l,r,add(b,c));\n\
    \        } else cout << seg.query(l,r).sum << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/LazySegmentTree.hpp\"\n\nusing mint=modint<998244353>;\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<mint> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    struct node{\n        mint sum; int a;\n        node(mint sum,int a):sum(sum),a(a){}\n\
    \    };\n    struct add{\n        mint b,c;\n        add(mint b,mint c):b(b),c(c){}\n\
    \        const bool operator==(const add &rhs){\n            return b==rhs.b&&c==rhs.c;\n\
    \        }\n    };\n    auto f=[](node a,node b){return node(a.sum+b.sum,a.a+b.a);};\n\
    \    auto g=[](node a,add x){return node(a.sum*x.b+x.c*a.a,a.a);};\n    auto h=[](add\
    \ a,add b){return add(a.b*b.b,a.c*b.b+b.c);};\n    LazySegmentTree<node,add> seg(N,f,g,h,node(0,0),add(1,0));\n\
    \    vector<node> v;\n    for (int i=0;i<N;++i) v.emplace_back(a[i],1);\n    seg.build(v);\n\
    \n    for (;Q--;){\n        int t,l,r; cin >> t >> l >> r;\n        if (!t){\n\
    \            mint b,c; cin >> b >> c;\n            seg.update(l,r,add(b,c));\n\
    \        } else cout << seg.query(l,r).sum << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
