---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/tree/Rerooting.hpp
    title: Rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_path_composite_sum
    links:
    - https://judge.yosupo.jp/problem/tree_path_composite_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_path_composite_sum\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"tree/Rerooting.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nstruct TreeDP {\n    struct T {\n\
    \        mint sum, cnt;\n    };\n\n    std::vector<int> a, b, c;\n\n    T e()\
    \ { return {0, 0}; }\n\n    T op(const T& l, const T& r) { return {l.sum + r.sum,\
    \ l.cnt + r.cnt}; }\n\n    T add_vertex(const T& t, int v) { return {t.sum + a[v],\
    \ t.cnt + 1}; }\n\n    T add_edge(const T& t, int e) { return {t.sum * b[e] +\
    \ t.cnt * c[e], t.cnt}; }\n};\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N;\n    std::cin >> N;\n    std::vector<int>\
    \ a(N), u(N - 1), v(N - 1), b(N - 1), c(N - 1);\n    for (int i = 0; i < N; i++)\
    \ std::cin >> a[i];\n    for (int i = 0; i < N - 1; i++) std::cin >> u[i] >> v[i]\
    \ >> b[i] >> c[i];\n\n    TreeDP treedp{a, b, c};\n    Rerooting<TreeDP> G(N,\
    \ treedp);\n    for (int i = 0; i < N - 1; i++) G.add_edge(u[i], v[i]);\n\n  \
    \  auto ans = G.solve();\n    for (int i = 0; i < N; i++) std::cout << ans[i].sum.val()\
    \ << (i + 1 == N ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/tree/Rerooting.hpp
  isVerificationFile: true
  path: test/yosupo/tree_path_composite_sum.test.cpp
  requiredBy: []
  timestamp: '2024-10-28 15:43:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/tree_path_composite_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_path_composite_sum.test.cpp
- /verify/test/yosupo/tree_path_composite_sum.test.cpp.html
title: test/yosupo/tree_path_composite_sum.test.cpp
---
