---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexd Tree (Fenwick Tree)
  - icon: ':heavy_check_mark:'
    path: datastructure/RangeTree.hpp
    title: "Range Tree (\u62BD\u8C61\u5316\u9818\u57DF\u6728)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#line\
    \ 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (size_t i =\
    \ 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \"\
    \ \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
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
    \ os, const deque<T>& v) {\n    for (size_t i = 0; i < v.size(); i++) {\n    \
    \    os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, size_t N> ostream& operator<<(ostream& os, const array<T,\
    \ N>& v) {\n    for (size_t i = 0; i < N; i++) {\n        os << v[i] << (i + 1\
    \ == N ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename\
    \ T> void print_tuple(ostream&, const T&) {}\ntemplate <int i, typename T, typename\
    \ H, class... Args> void print_tuple(ostream& os, const T& t) {\n    if (i) os\
    \ << ',';\n    os << get<i>(t);\n    print_tuple<i + 1, T, Args...>(os, t);\n\
    }\ntemplate <typename... Args> ostream& operator<<(ostream& os, const tuple<Args...>&\
    \ t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>, Args...>(os, t);\n\
    \    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class\
    \ Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr\
    \ << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate\
    \ <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate\
    \ <typename T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed\
    \ t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t)\
    \ { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return\
    \ a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ?\
    \ 64 : __builtin_ctzll(a); }\nint popcount(signed t) { return __builtin_popcount(t);\
    \ }\nint popcount(long long t) { return __builtin_popcountll(t); }\nbool ispow2(int\
    \ i) { return i && (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n)\
    \ - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y)\
    \ {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\n\
    template <class T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b)\
    \ {\n        a = b;\n        return true;\n    }\n    return false;\n}\ntemplate\
    \ <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n  \
    \      a = b;\n        return true;\n    }\n    return false;\n}\n\ntemplate <typename\
    \ T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n#pragma endregion\n\
    #line 4 \"datastructure/BinaryIndexedTree.hpp\"\n\ntemplate <typename T> struct\
    \ BinaryIndexedTree {\n    BinaryIndexedTree(int n) : n(n), data(n) {}\n\n   \
    \ void add(int k, T x) {\n        assert(0 <= k && k < n);\n        for (k++;\
    \ k <= n; k += k & -k) data[k - 1] += x;\n    }\n\n    T query(int l, int r) const\
    \ {\n        assert(0 <= l && l <= r && r <= n);\n        return sum(r) - sum(l);\n\
    \    }\n\n    T operator[](int i) const { return query(i, i + 1); }\n\n    int\
    \ lower_bound(T x) const {\n        if (x <= 0) return 0;\n        int cur = 0,\
    \ k = 1;\n        while (k < n) k <<= 1;\n        for (; k > 0; k >>= 1) {\n \
    \           if (cur + k <= n && data[cur + k - 1] < x) {\n                x -=\
    \ data[cur + k - 1];\n                cur += k;\n            }\n        }\n  \
    \      return cur;\n    }\n    int upper_bound(T x) const { return lower_bound(x\
    \ + 1); }\n\nprivate:\n    int n;\n    std::vector<T> data;\n\n    T sum(int r)\
    \ const {\n        T res = 0;\n        for (; r > 0; r -= r & -r) res += data[r\
    \ - 1];\n        return res;\n    }\n};\n\n/**\n * @brief Binary Indexd Tree (Fenwick\
    \ Tree)\n * @docs docs/datastructure/BinaryIndexedTree.md\n */\n#line 6 \"datastructure/RangeTree.hpp\"\
    \n\ntemplate <typename structure_t, typename value_t, typename coordinate_t> struct\
    \ RangeTree {\nprivate:\n    using structure_new = std::function<structure_t*(int)>;\n\
    \    using structure_set = std::function<void(structure_t&, int, value_t)>;\n\
    \    using structure_prod = std::function<value_t(structure_t&, int, int)>;\n\
    \    using value_merge = std::function<value_t(value_t, value_t)>;\n    using\
    \ Pt = std::pair<coordinate_t, coordinate_t>;\n\npublic:\n    RangeTree(const\
    \ structure_new& st_new,\n              const structure_set& st_set,\n       \
    \       const structure_prod& st_prod,\n              const value_merge& op,\n\
    \              const value_t& e)\n        : st_new(st_new), st_set(st_set), st_prod(st_prod),\
    \ op(op), e(e) {}\n\n    void add_point(coordinate_t x, coordinate_t y) { points.emplace_back(x,\
    \ y); }\n\n    void build() {\n        std::sort(points.begin(), points.end());\n\
    \        points.erase(std::unique(points.begin(), points.end()), points.end());\n\
    \        n = points.size();\n        yxs.resize(n << 1);\n        segs.resize(n\
    \ << 1, nullptr);\n        for (int i = 0; i < n; i++) yxs[n + i] = {{points[i].second,\
    \ points[i].first}};\n        for (int i = n - 1; i >= 0; i--) {\n           \
    \ auto& lch = yxs[i << 1 | 0];\n            auto& rch = yxs[i << 1 | 1];\n   \
    \         std::merge(lch.begin(), lch.end(), rch.begin(), rch.end(), std::back_inserter(yxs[i]));\n\
    \            yxs[i].erase(std::unique(yxs[i].begin(), yxs[i].end()), yxs[i].end());\n\
    \        }\n        for (int i = 0; i < (n << 1); i++) segs[i] = st_new(yxs[i].size());\n\
    \    }\n\n    void set(coordinate_t x, coordinate_t y, value_t val) {\n      \
    \  int i = std::distance(points.begin(), std::lower_bound(points.begin(), points.end(),\
    \ std::make_pair(x, y)));\n        assert(i < n && points[i] == std::make_pair(x,\
    \ y));\n        for (i += n; i; i >>= 1) st_set(*segs[i], zip(i, x, y), val);\n\
    \    }\n\n    value_t query(coordinate_t xl, coordinate_t xr, coordinate_t yl,\
    \ coordinate_t yr) {\n        assert(xl <= xr && yl <= yr);\n        value_t L\
    \ = e, R = e;\n        int l = zip(xl), r = zip(xr);\n        for (l += n, r +=\
    \ n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L, st_prod(*segs[l],\
    \ zip(l, yl), zip(l, yr))), l++;\n            if (r & 1) --r, R = op(st_prod(*segs[r],\
    \ zip(r, yl), zip(r, yr)), R);\n        }\n        return op(L, R);\n    }\n\n\
    private:\n    int n;\n    const structure_new st_new;\n    const structure_set\
    \ st_set;\n    const structure_prod st_prod;\n    const value_merge op;\n    const\
    \ value_t e;\n    std::vector<Pt> points;\n    std::vector<std::vector<Pt>> yxs;\n\
    \    std::vector<structure_t*> segs;\n\n    int zip(coordinate_t x) {\n      \
    \  auto compare = [](const Pt& l, const Pt& r) { return l.first < r.first; };\n\
    \        return std::distance(points.begin(),\n                             std::lower_bound(points.begin(),\
    \ points.end(), make_pair(x, coordinate_t()), compare));\n    }\n\n    int zip(int\
    \ i, coordinate_t y) {\n        auto compare = [](const Pt& l, const Pt& r) {\
    \ return l.first < r.first; };\n        return std::distance(yxs[i].begin(),\n\
    \                             std::lower_bound(yxs[i].begin(), yxs[i].end(), make_pair(y,\
    \ coordinate_t()), compare));\n    }\n\n    int zip(int i, coordinate_t x, coordinate_t\
    \ y) {\n        return std::distance(yxs[i].begin(), std::lower_bound(yxs[i].begin(),\
    \ yxs[i].end(), make_pair(y, x)));\n    }\n};\n\n/**\n * @brief Range Tree (\u62BD\
    \u8C61\u5316\u9818\u57DF\u6728)\n * @docs docs/datastructure/RangeTree.md\n */\n\
    #line 6 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n\nint main() {\n   \
    \ cin.tie(0);\n    ios::sync_with_stdio(false);\n    auto f = [](long long a,\
    \ long long b) { return a + b; };\n    using BIT = BinaryIndexedTree<long long>;\n\
    \    auto st_new = [](int n) { return new BIT(n); };\n    auto st_set = [](BIT&\
    \ bit, int i, long long x) { bit.add(i, x); };\n    auto st_prod = [](BIT& bit,\
    \ int l, int r) { return bit.query(l, r); };\n    RangeTree<BIT, long long, int>\
    \ RT(st_new, st_set, st_prod, f, 0LL);\n\n    int N, Q;\n    cin >> N >> Q;\n\
    \    vector<int> x(N), y(N), w(N), c(Q), s(Q), t(Q), u(Q), v(Q);\n    for (int\
    \ i = 0; i < N; i++) {\n        cin >> x[i] >> y[i] >> w[i];\n        RT.add_point(x[i],\
    \ y[i]);\n    }\n    for (int i = 0; i < Q; i++) {\n        cin >> c[i] >> s[i]\
    \ >> t[i] >> u[i];\n        if (c[i] == 0)\n            RT.add_point(s[i], t[i]);\n\
    \        else\n            cin >> v[i];\n    }\n\n    RT.build();\n    for (int\
    \ i = 0; i < N; i++) RT.set(x[i], y[i], w[i]);\n    for (int i = 0; i < Q; i++)\
    \ {\n        if (c[i] == 0)\n            RT.set(s[i], t[i], u[i]);\n        else\n\
    \            cout << RT.query(s[i], u[i], t[i], v[i]) << '\\n';\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/BinaryIndexedTree.hpp\"\
    \n#include \"../../datastructure/RangeTree.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    auto f = [](long long a, long long b) {\
    \ return a + b; };\n    using BIT = BinaryIndexedTree<long long>;\n    auto st_new\
    \ = [](int n) { return new BIT(n); };\n    auto st_set = [](BIT& bit, int i, long\
    \ long x) { bit.add(i, x); };\n    auto st_prod = [](BIT& bit, int l, int r) {\
    \ return bit.query(l, r); };\n    RangeTree<BIT, long long, int> RT(st_new, st_set,\
    \ st_prod, f, 0LL);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> x(N),\
    \ y(N), w(N), c(Q), s(Q), t(Q), u(Q), v(Q);\n    for (int i = 0; i < N; i++) {\n\
    \        cin >> x[i] >> y[i] >> w[i];\n        RT.add_point(x[i], y[i]);\n   \
    \ }\n    for (int i = 0; i < Q; i++) {\n        cin >> c[i] >> s[i] >> t[i] >>\
    \ u[i];\n        if (c[i] == 0)\n            RT.add_point(s[i], t[i]);\n     \
    \   else\n            cin >> v[i];\n    }\n\n    RT.build();\n    for (int i =\
    \ 0; i < N; i++) RT.set(x[i], y[i], w[i]);\n    for (int i = 0; i < Q; i++) {\n\
    \        if (c[i] == 0)\n            RT.set(s[i], t[i], u[i]);\n        else\n\
    \            cout << RT.query(s[i], u[i], t[i], v[i]) << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - base.hpp
  - datastructure/BinaryIndexedTree.hpp
  - datastructure/RangeTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.test.cpp
---
