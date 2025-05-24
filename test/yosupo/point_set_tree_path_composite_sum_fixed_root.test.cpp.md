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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"tree/StaticTopTree.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nstruct TreeDP {\n    struct T {\n\
    \        mint a, b, cnt, sum;\n    };\n\n    static T rake(const T& l, const T&\
    \ r) { return {l.a, l.b, l.cnt + r.cnt, l.sum + r.sum}; }\n\n    static T compress(const\
    \ T& l, const T& r) {\n        mint a = l.a * r.a, b = l.a * r.b + l.b, cnt =\
    \ l.cnt + r.cnt, sum = l.sum + l.a * r.sum + l.b * r.cnt;\n        return {a,\
    \ b, cnt, sum};\n    }\n};\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int>\
    \ a(N), u(N - 1), v(N - 1), b(N - 1), c(N - 1);\n    for (int i = 0; i < N; i++)\
    \ {\n        std::cin >> a[i];\n    }\n    StaticTopTree stt(N);\n    std::vector<std::vector<int>>\
    \ g(N);\n    for (int i = 0; i < N - 1; i++) {\n        std::cin >> u[i] >> v[i]\
    \ >> b[i] >> c[i];\n        stt.add_edge(u[i], v[i]);\n        g[u[i]].emplace_back(i);\n\
    \        g[v[i]].emplace_back(i);\n    }\n\n    stt.build();\n    std::vector<int>\
    \ p(N);\n    auto dfs = [&](auto self, int cur, int pe) -> void {\n        p[cur]\
    \ = pe;\n        if (pe != -1) {\n            if (cur != v[pe]) {\n          \
    \      std::swap(u[pe], v[pe]);\n            }\n        }\n        for (int i\
    \ : g[cur]) {\n            if (i == pe) {\n                continue;\n       \
    \     }\n            self(self, u[i] ^ v[i] ^ cur, i);\n        }\n    };\n  \
    \  dfs(dfs, 0, -1);\n    auto vertex = [&](int v) -> TreeDP::T {\n        if (v\
    \ == 0) {\n            return {1, 0, 1, a[v]};\n        }\n        int e = p[v];\n\
    \        return {b[e], c[e], 1, mint(b[e]) * a[v] + c[e]};\n    };\n    DynamicTreeDP<TreeDP>\
    \ dp(N, stt, vertex);\n\n    for (; Q--;) {\n        int type;\n        std::cin\
    \ >> type;\n        if (type == 0) {\n            int w, x;\n            std::cin\
    \ >> w >> x;\n            a[w] = x;\n            dp.set(w, vertex(w));\n     \
    \   } else {\n            int e, y, z;\n            std::cin >> e >> y >> z;\n\
    \            b[e] = y, c[e] = z;\n            dp.set(v[e], vertex(v[e]));\n  \
    \      }\n        auto ans = dp.all_prod().sum;\n        std::cout << ans.val()\
    \ << \"\\n\";\n    }\n    return 0;\n}"
  dependsOn:
  - src/tree/StaticTopTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
  requiredBy: []
  timestamp: '2025-05-24 15:05:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
- /verify/test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp.html
title: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
---
