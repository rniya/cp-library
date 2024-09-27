---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/UndoUnionFind.hpp
    title: Union Find with Undo Operation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/UndoUnionFind.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include <iostream>\n#include \"datastructure/UndoUnionFind.hpp\"\n\nint main()\
    \ {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    std::vector<int> t(Q), u(Q), v(Q);\n    std::vector<std::vector<int>>\
    \ G(Q + 1);\n    for (int i = 0; i < Q; i++) {\n        int k;\n        std::cin\
    \ >> t[i] >> k >> u[i] >> v[i];\n        G[++k].emplace_back(i + 1);\n    }\n\n\
    \    UndoUnionFind UF(N);\n    std::vector<int> ans(Q, -1);\n    auto dfs = [&](auto\
    \ self, int cur) -> void {\n        if (cur) {\n            if (!t[cur - 1])\n\
    \                UF.merge(u[cur - 1], v[cur - 1]);\n            else\n       \
    \         ans[cur - 1] = UF.same(u[cur - 1], v[cur - 1]);\n        }\n       \
    \ for (int nxt : G[cur]) self(self, nxt);\n        if (cur && !t[cur - 1]) UF.undo();\n\
    \    };\n    dfs(dfs, 0);\n    for (int i = 0; i < Q; i++) {\n        if (~ans[i])\
    \ {\n            std::cout << ans[i] << '\\n';\n        }\n    }\n    return 0;\n\
    }"
  dependsOn:
  - src/datastructure/UndoUnionFind.hpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 23:41:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp.html
title: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
---
