---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.5/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"datastructure/SlidingWindowAggregation.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nstruct S {\n    mint a, b;\n   \
    \ S(mint a, mint b) : a(a), b(b) {}\n};\n\nS op(S a, S b) { return S(a.a * b.a,\
    \ a.b * b.a + b.b); }\n\nS e() { return S(1, 0); }\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n\n    SlidingWindowAggregation<S, op,\
    \ e> swag;\n\n    int Q;\n    std::cin >> Q;\n    for (; Q--;) {\n        int\
    \ t;\n        std::cin >> t;\n        if (t == 0) {\n            int a, b;\n \
    \           std::cin >> a >> b;\n            swag.push(S(a, b));\n        } else\
    \ if (t == 1) {\n            swag.pop();\n        } else {\n            int x;\n\
    \            std::cin >> x;\n            S res = swag.fold();\n            mint\
    \ ans = res.a * x + res.b;\n            std::cout << ans.val() << '\\n';\n   \
    \     }\n    }\n}"
  dependsOn:
  - src/datastructure/SlidingWindowAggregation.hpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 23:53:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
