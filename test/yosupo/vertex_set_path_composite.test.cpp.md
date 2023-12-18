---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  - icon: ':heavy_check_mark:'
    path: src/util/modint.hpp
    title: modint (input/output)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/segtree:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"atcoder/segtree\"\n#include \"tree/HeavyLightDecomposition.hpp\"\
    \n#include \"util/modint.hpp\"\n\nusing mint = atcoder::modint998244353;\n\nstruct\
    \ S {\n    mint a, b;\n    S(mint a = 1, mint b = 0) : a(a), b(b) {}\n};\n\nS\
    \ opl(S l, S r) { return S(l.a * r.a, l.b * r.a + r.b); };\n\nS opr(S l, S r)\
    \ { return S(l.a * r.a, r.b * l.a + l.b); }\n\nS e() { return S(1, 0); }\n\nint\
    \ main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int\
    \ N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N), b(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i] >> b[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n        HLD.add_edge(u, v);\n    }\n\n    HLD.build();\n    std::vector<S>\
    \ v(N);\n    for (int i = 0; i < N; i++) {\n        int idx = HLD.idx(i);\n  \
    \      v[idx] = S(a[i], b[i]);\n    }\n    atcoder::segtree<S, opl, e> segl(v);\n\
    \    atcoder::segtree<S, opr, e> segr(v);\n\n    for (; Q--;) {\n        int t;\n\
    \        std::cin >> t;\n        if (t == 0) {\n            int p, c, d;\n   \
    \         std::cin >> p >> c >> d;\n            int x = HLD.idx(p);\n        \
    \    segl.set(x, S(c, d));\n            segr.set(x, S(c, d));\n        } else\
    \ {\n            int u, v, x;\n            std::cin >> u >> v >> x;\n        \
    \    mint ans = x;\n            auto q = [&](int l, int r) {\n               \
    \ if (l <= r) {\n                    S res = segl.prod(l, r);\n              \
    \      ans = res.a * ans + res.b;\n                } else {\n                \
    \    S res = segr.prod(r, l);\n                    ans = res.a * ans + res.b;\n\
    \                }\n            };\n            HLD.query_path_noncommutative(u,\
    \ v, q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - src/tree/HeavyLightDecomposition.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.test.cpp.html
title: test/yosupo/vertex_set_path_composite.test.cpp
---
