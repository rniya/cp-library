---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/StaticTopTree.hpp
    title: Static Top Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
    links:
    - https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"tree/StaticTopTree.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nstruct TreeDP {\n    struct Path\
    \ {\n        mint a, b, c, sub;\n    };\n\n    struct Point {\n        mint val,\
    \ sub;\n    };\n\n    std::vector<int> a, b, c;\n\n    Path vertex(int v) { return\
    \ {b[v], mint(a[v]) * b[v] + c[v], c[v], 1}; }\n\n    Path compress(const Path&\
    \ l, const Path& r) {\n        return {l.a * r.a, l.a * r.b + l.b + l.c * r.sub,\
    \ l.c + l.a * r.c, l.sub + r.sub};\n    }\n\n    Path add_vertex(const Point&\
    \ p, int v) {\n        return {b[v], (p.val + a[v]) * b[v] + (p.sub + 1) * c[v],\
    \ c[v], p.sub + 1};\n    }\n\n    Point rake(const Point& l, const Point& r) {\
    \ return {l.val + r.val, l.sub + r.sub}; }\n\n    Point add_edge(const Path& p)\
    \ { return {p.b, p.sub}; }\n};\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ a(N), u(N - 1), v(N - 1), b(N - 1), c(N - 1);\n    for (int i = 0; i < N; i++)\
    \ {\n        std::cin >> a[i];\n    }\n    StaticTopTree stt(N);\n    for (int\
    \ i = 0; i < N - 1; i++) {\n        std::cin >> u[i] >> v[i] >> b[i] >> c[i];\n\
    \        stt.add_edge(u[i], v[i]);\n    }\n\n    stt.build();\n    std::vector<int>\
    \ par(N);\n    auto& G = stt.G;\n    std::queue<int> que;\n    par[0] = -1;\n\
    \    que.emplace(0);\n    while (not que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (const int& u : G[v]) {\n            par[u] =\
    \ v;\n            que.emplace(u);\n        }\n    }\n    std::vector<int> B(N),\
    \ C(N);\n    for (int i = 0; i < N - 1; i++) {\n        if (par[v[i]] != u[i])\
    \ {\n            std::swap(u[i], v[i]);\n        }\n        assert(par[v[i]] ==\
    \ u[i]);\n        B[v[i]] = b[i], C[v[i]] = c[i];\n    }\n    B[0] = 1, C[0] =\
    \ 0;\n    TreeDP treedp{a, B, C};\n    DynamicDPonStaticTopTree dp(stt, treedp);\n\
    \n    for (; Q--;) {\n        int t;\n        std::cin >> t;\n        if (t ==\
    \ 0) {\n            int w, x;\n            std::cin >> w >> x;\n            treedp.a[w]\
    \ = x;\n            dp.set(w);\n        } else {\n            int e, y, z;\n \
    \           std::cin >> e >> y >> z;\n            int w = v[e];\n            treedp.b[w]\
    \ = y;\n            treedp.c[w] = z;\n            dp.set(w);\n        }\n    \
    \    mint ans = dp.all_prod().b;\n        std::cout << ans.val() << '\\n';\n \
    \   }\n    return 0;\n}"
  dependsOn:
  - src/tree/StaticTopTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 01:15:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
