---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/FastFourierTransform.hpp
    title: Fast Fourier Transform
  - icon: ':heavy_check_mark:'
    path: tree/CentroidDecomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
    links:
    - https://judge.yosupo.jp/problem/frequency_table_of_tree_distance
  bundledCode: "#line 1 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
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
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"convolution/FastFourierTransform.hpp\"\
    \n\n/**\n * @brief Fast Fourier Transform\n * @docs docs/convolution/FastFourierTransform.md\n\
    \ */\nnamespace FastFourierTransform {\nstruct Complex {\n    double x, y;\n \
    \   Complex() : x(0), y(0) {}\n    Complex(double x, double y) : x(x), y(y) {}\n\
    \    inline Complex operator+(const Complex& c) const { return Complex(x + c.x,\
    \ y + c.y); }\n    inline Complex operator-(const Complex& c) const { return Complex(x\
    \ - c.x, y - c.y); }\n    inline Complex operator*(const Complex& c) const { return\
    \ Complex(x * c.x - y * c.y, x * c.y + y * c.x); }\n    inline Complex conj()\
    \ const { return Complex(x, -y); }\n};\nconst double PI = acosl(-1);\nvector<Complex>\
    \ roots = {{0, 0}, {1, 0}};\nvector<int> rev = {0, 1};\nint base = 1;\nvoid ensure_base(int\
    \ nbase) {\n    if (nbase <= base) return;\n    rev.resize(1 << nbase);\n    for\
    \ (int i = 0; i < (1 << nbase); i++) {\n        rev[i] = (rev[i >> 1] >> 1) |\
    \ ((i & 1) << (nbase - 1));\n    }\n    roots.resize(1 << nbase);\n    for (;\
    \ base < nbase; base++) {\n        double angle = PI * 2.0 / (1 << (base + 1));\n\
    \        for (int i = 1 << (base - 1); i < (1 << base); i++) {\n            roots[i\
    \ << 1] = roots[i];\n            double angle_i = angle * ((i << 1 | 1) - (1 <<\
    \ base));\n            roots[i << 1 | 1] = Complex(cos(angle_i), sin(angle_i));\n\
    \        }\n    }\n}\nvoid fft(vector<Complex>& a, int n) {\n    int zeros = __builtin_ctz(n);\n\
    \    ensure_base(zeros);\n    int shift = base - zeros;\n    for (int i = 0; i\
    \ < n; i++) {\n        if (i < (rev[i] >> shift)) {\n            swap(a[i], a[rev[i]\
    \ >> shift]);\n        }\n    }\n    for (int k = 1; k < n; k <<= 1) {\n     \
    \   for (int i = 0; i < n; i += (k << 1)) {\n            for (int j = 0; j < k;\
    \ j++) {\n                Complex z = a[i + j + k] * roots[j + k];\n         \
    \       a[i + j + k] = a[i + j] - z;\n                a[i + j] = a[i + j] + z;\n\
    \            }\n        }\n    }\n}\nvector<long long> multiply(const vector<int>&\
    \ a, const vector<int>& b) {\n    int need = a.size() + b.size() - 1;\n    int\
    \ nbase = 1;\n    while ((1 << nbase) < need) nbase++;\n    ensure_base(nbase);\n\
    \    int sz = 1 << nbase;\n    vector<Complex> C(sz);\n    for (int i = 0; i <\
    \ sz; i++) {\n        int x = (i < a.size() ? a[i] : 0);\n        int y = (i <\
    \ b.size() ? b[i] : 0);\n        C[i] = Complex(x, y);\n    }\n    fft(C, sz);\n\
    \    Complex r(0, -0.25 / (sz >> 1)), s(0, 1), t(0.5, 0);\n    for (int i = 0;\
    \ i <= (sz >> 1); i++) {\n        int j = (sz - i) & (sz - 1);\n        Complex\
    \ z = (C[j] * C[j] - (C[i] * C[i]).conj()) * r;\n        C[j] = (C[i] * C[i] -\
    \ (C[j] * C[j]).conj()) * r;\n        C[i] = z;\n    }\n    for (int i = 0; i\
    \ < (sz >> 1); i++) {\n        Complex C0 = (C[i] + C[i + (sz >> 1)]) * t;\n \
    \       Complex C1 = (C[i] - C[i + (sz >> 1)]) * t * roots[(sz >> 1) + i];\n \
    \       C[i] = C0 + C1 * s;\n    }\n    fft(C, sz >> 1);\n    vector<long long>\
    \ res(need);\n    for (int i = 0; i < need; i++) {\n        res[i] = llround(i\
    \ & 1 ? C[i >> 1].y : C[i >> 1].x);\n    }\n    return res;\n}\n}  // namespace\
    \ FastFourierTransform\n#line 4 \"tree/CentroidDecomposition.hpp\"\n\nstruct CentroidDecomposition\
    \ {\n    std::vector<std::vector<int>> G;\n\n    CentroidDecomposition(int n)\
    \ : G(n), n(n), sub(n), is_centroid(n) {}\n\n    void add_edge(int u, int v) {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    std::vector<int> build(int x = 0)\
    \ {\n        centroids.clear();\n        fill(is_centroid.begin(), is_centroid.end(),\
    \ false);\n        centroid_decomposition(x);\n        return centroids;\n   \
    \ }\n\nprivate:\n    int n;\n    std::vector<int> sub, centroids;\n    std::vector<bool>\
    \ is_centroid;\n\n    int dfs_sz(int v, int p) {\n        sub[v] = 1;\n      \
    \  for (int& u : G[v]) {\n            if (u == p || is_centroid[u]) continue;\n\
    \            sub[v] += dfs_sz(u, v);\n        }\n        return sub[v];\n    }\n\
    \n    int dfs_search_centroid(int v, int p, int mid) {\n        for (int& u :\
    \ G[v]) {\n            if (u == p || is_centroid[u]) continue;\n            if\
    \ (sub[u] > mid) return dfs_search_centroid(u, v, mid);\n        }\n        return\
    \ v;\n    }\n\n    void centroid_decomposition(int r) {\n        int centroid\
    \ = dfs_search_centroid(r, -1, dfs_sz(r, -1) / 2);\n        centroids.emplace_back(centroid);\n\
    \        is_centroid[centroid] = true;\n        for (int& ch : G[centroid]) {\n\
    \            if (is_centroid[ch]) continue;\n            centroid_decomposition(ch);\n\
    \        }\n    }\n};\n\n/**\n * @brief Centroid Decomposition\n * @docs docs/tree/CentroidDecomposition.md\n\
    \ */\n#line 6 \"test/yosupo/frequency_table_of_tree_distance.test.cpp\"\n\nint\
    \ main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n  \
    \  cin >> N;\n    CentroidDecomposition CD(N);\n    for (int i = 0; i < N - 1;\
    \ i++) {\n        int a, b;\n        cin >> a >> b;\n        CD.add_edge(a, b);\n\
    \    }\n\n    vector<int> alive(N, true);\n    auto& G = CD.G;\n    auto calc\
    \ = [&](auto self, int v, int p, int d, vector<int>& cnt) -> void {\n        while\
    \ ((int)cnt.size() <= d) cnt.emplace_back(0);\n        cnt[d]++;\n        for\
    \ (int& u : G[v]) {\n            if (u == p || !alive[u]) continue;\n        \
    \    self(self, u, v, d + 1, cnt);\n        }\n    };\n\n    auto cs = CD.build();\n\
    \    vector<long long> ans(2 * N, 0);\n\n    for (int& root : cs) {\n        alive[root]\
    \ = 0;\n        vector<int> sum{1};\n        for (int& ch : G[root]) {\n     \
    \       if (!alive[ch]) continue;\n            vector<int> cnt;\n            calc(calc,\
    \ ch, root, 1, cnt);\n            auto sub = FastFourierTransform::multiply(cnt,\
    \ cnt);\n            for (size_t i = 0; i < sub.size(); i++) ans[i] -= sub[i];\n\
    \            while (sum.size() < cnt.size()) sum.emplace_back(0);\n          \
    \  for (size_t i = 0; i < cnt.size(); i++) sum[i] += cnt[i];\n        }\n    \
    \    auto add = FastFourierTransform::multiply(sum, sum);\n        for (size_t\
    \ i = 0; i < add.size(); i++) ans[i] += add[i];\n    }\n\n    for (int i = 1;\
    \ i < N; i++) cout << ans[i] / 2 << (i + 1 == N ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/FastFourierTransform.hpp\"\
    \n#include \"../../tree/CentroidDecomposition.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N;\n    cin >> N;\n    CentroidDecomposition\
    \ CD(N);\n    for (int i = 0; i < N - 1; i++) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        CD.add_edge(a, b);\n    }\n\n    vector<int> alive(N, true);\n\
    \    auto& G = CD.G;\n    auto calc = [&](auto self, int v, int p, int d, vector<int>&\
    \ cnt) -> void {\n        while ((int)cnt.size() <= d) cnt.emplace_back(0);\n\
    \        cnt[d]++;\n        for (int& u : G[v]) {\n            if (u == p || !alive[u])\
    \ continue;\n            self(self, u, v, d + 1, cnt);\n        }\n    };\n\n\
    \    auto cs = CD.build();\n    vector<long long> ans(2 * N, 0);\n\n    for (int&\
    \ root : cs) {\n        alive[root] = 0;\n        vector<int> sum{1};\n      \
    \  for (int& ch : G[root]) {\n            if (!alive[ch]) continue;\n        \
    \    vector<int> cnt;\n            calc(calc, ch, root, 1, cnt);\n           \
    \ auto sub = FastFourierTransform::multiply(cnt, cnt);\n            for (size_t\
    \ i = 0; i < sub.size(); i++) ans[i] -= sub[i];\n            while (sum.size()\
    \ < cnt.size()) sum.emplace_back(0);\n            for (size_t i = 0; i < cnt.size();\
    \ i++) sum[i] += cnt[i];\n        }\n        auto add = FastFourierTransform::multiply(sum,\
    \ sum);\n        for (size_t i = 0; i < add.size(); i++) ans[i] += add[i];\n \
    \   }\n\n    for (int i = 1; i < N; i++) cout << ans[i] / 2 << (i + 1 == N ? '\\\
    n' : ' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/FastFourierTransform.hpp
  - tree/CentroidDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/frequency_table_of_tree_distance.test.cpp
  requiredBy: []
  timestamp: '2021-10-03 22:16:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/frequency_table_of_tree_distance.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp
- /verify/test/yosupo/frequency_table_of_tree_distance.test.cpp.html
title: test/yosupo/frequency_table_of_tree_distance.test.cpp
---
