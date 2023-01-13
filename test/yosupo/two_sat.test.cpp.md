---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/graph/StronglyConnectedComponents.hpp
    title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/graph/TwoSAT.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    base.hpp\"\n#include \"graph/TwoSAT.hpp\"\n\nint main() {\n    cin.tie(0);\n \
    \   ios::sync_with_stdio(false);\n    string p, cnf;\n    int N, M;\n    cin >>\
    \ p >> cnf >> N >> M;\n\n    TwoSAT TS(N + 1);\n    for (int i = 0; i < M; i++)\
    \ {\n        int a, b, c;\n        cin >> a >> b >> c;\n        TS.add_clause(abs(a),\
    \ (a > 0), abs(b), (b > 0));\n    }\n\n    if (!TS.satisfiable()) {\n        cout\
    \ << \"s UNSATISFIABLE\" << '\\n';\n        return 0;\n    }\n    cout << \"s\
    \ SATISFIABLE\" << '\\n';\n    cout << \"v \";\n    auto ans = TS.answer();\n\
    \    for (int i = 1; i <= N; i++) cout << (ans[i] ? i : -i) << ' ';\n    cout\
    \ << \"0\\n\";\n    return 0;\n}"
  dependsOn:
  - src/base.hpp
  - src/graph/TwoSAT.hpp
  - src/graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2023-01-13 13:44:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
