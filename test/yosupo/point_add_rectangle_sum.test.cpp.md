---
data:
  _extendedDependsOn:
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
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#include\
    \ <iostream>\n#line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line\
    \ 5 \"atcoder/internal_type_traits.hpp\"\n#include <numeric>\n#include <type_traits>\n\
    \nnamespace atcoder {\n\nnamespace internal {\n\n#ifndef _MSC_VER\ntemplate <class\
    \ T>\nusing is_signed_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value ||\n                                  std::is_same<T, __int128>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int128 =\n\
    \    typename std::conditional<std::is_same<T, __uint128_t>::value ||\n      \
    \                            std::is_same<T, unsigned __int128>::value,\n    \
    \                          std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing make_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __int128_t>::value,\n                              __uint128_t,\n          \
    \                    unsigned __int128>;\n\ntemplate <class T>\nusing is_integral\
    \ = typename std::conditional<std::is_integral<T>::value ||\n                \
    \                                  is_signed_int128<T>::value ||\n           \
    \                                       is_unsigned_int128<T>::value,\n      \
    \                                        std::true_type,\n                   \
    \                           std::false_type>::type;\n\ntemplate <class T>\nusing\
    \ is_signed_int = typename std::conditional<(is_integral<T>::value &&\n      \
    \                                           std::is_signed<T>::value) ||\n   \
    \                                                 is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 2 \"datastructure/RangeTree.hpp\"\n#include <algorithm>\n\
    #line 4 \"datastructure/RangeTree.hpp\"\n#include <functional>\n#line 6 \"datastructure/RangeTree.hpp\"\
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
    \    }\n\n    value_t prod(coordinate_t xl, coordinate_t xr, coordinate_t yl,\
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
    \        return std::distance(\n            points.begin(), std::lower_bound(points.begin(),\
    \ points.end(), std::make_pair(x, coordinate_t()), compare));\n    }\n\n    int\
    \ zip(int i, coordinate_t y) {\n        auto compare = [](const Pt& l, const Pt&\
    \ r) { return l.first < r.first; };\n        return std::distance(\n         \
    \   yxs[i].begin(), std::lower_bound(yxs[i].begin(), yxs[i].end(), std::make_pair(y,\
    \ coordinate_t()), compare));\n    }\n\n    int zip(int i, coordinate_t x, coordinate_t\
    \ y) {\n        return std::distance(yxs[i].begin(), std::lower_bound(yxs[i].begin(),\
    \ yxs[i].end(), std::make_pair(y, x)));\n    }\n};\n\n/**\n * @brief Range Tree\
    \ (\u62BD\u8C61\u5316\u9818\u57DF\u6728)\n * @docs docs/datastructure/RangeTree.md\n\
    \ */\n#line 6 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n\nint main() {\n\
    \    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    auto f = [](long\
    \ long a, long long b) { return a + b; };\n    using FT = atcoder::fenwick_tree<long\
    \ long>;\n    auto st_new = [](int n) { return new FT(n); };\n    auto st_set\
    \ = [](FT& FT, int i, long long x) { FT.add(i, x); };\n    auto st_prod = [](FT&\
    \ FT, int l, int r) { return FT.sum(l, r); };\n    RangeTree<FT, long long, int>\
    \ RT(st_new, st_set, st_prod, f, 0LL);\n\n    int N, Q;\n    std::cin >> N >>\
    \ Q;\n    std::vector<int> x(N), y(N), w(N), c(Q), s(Q), t(Q), u(Q), v(Q);\n \
    \   for (int i = 0; i < N; i++) {\n        std::cin >> x[i] >> y[i] >> w[i];\n\
    \        RT.add_point(x[i], y[i]);\n    }\n    for (int i = 0; i < Q; i++) {\n\
    \        std::cin >> c[i] >> s[i] >> t[i] >> u[i];\n        if (c[i] == 0)\n \
    \           RT.add_point(s[i], t[i]);\n        else\n            std::cin >> v[i];\n\
    \    }\n\n    RT.build();\n    for (int i = 0; i < N; i++) RT.set(x[i], y[i],\
    \ w[i]);\n    for (int i = 0; i < Q; i++) {\n        if (c[i] == 0)\n        \
    \    RT.set(s[i], t[i], u[i]);\n        else\n            std::cout << RT.prod(s[i],\
    \ u[i], t[i], v[i]) << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <iostream>\n#include \"atcoder/fenwicktree\"\n#include \"datastructure/RangeTree.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    auto f = [](long long a, long long b) { return a + b; };\n    using FT =\
    \ atcoder::fenwick_tree<long long>;\n    auto st_new = [](int n) { return new\
    \ FT(n); };\n    auto st_set = [](FT& FT, int i, long long x) { FT.add(i, x);\
    \ };\n    auto st_prod = [](FT& FT, int l, int r) { return FT.sum(l, r); };\n\
    \    RangeTree<FT, long long, int> RT(st_new, st_set, st_prod, f, 0LL);\n\n  \
    \  int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> x(N), y(N), w(N),\
    \ c(Q), s(Q), t(Q), u(Q), v(Q);\n    for (int i = 0; i < N; i++) {\n        std::cin\
    \ >> x[i] >> y[i] >> w[i];\n        RT.add_point(x[i], y[i]);\n    }\n    for\
    \ (int i = 0; i < Q; i++) {\n        std::cin >> c[i] >> s[i] >> t[i] >> u[i];\n\
    \        if (c[i] == 0)\n            RT.add_point(s[i], t[i]);\n        else\n\
    \            std::cin >> v[i];\n    }\n\n    RT.build();\n    for (int i = 0;\
    \ i < N; i++) RT.set(x[i], y[i], w[i]);\n    for (int i = 0; i < Q; i++) {\n \
    \       if (c[i] == 0)\n            RT.set(s[i], t[i], u[i]);\n        else\n\
    \            std::cout << RT.prod(s[i], u[i], t[i], v[i]) << '\\n';\n    }\n \
    \   return 0;\n}"
  dependsOn:
  - datastructure/RangeTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-04 17:03:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.test.cpp
---
