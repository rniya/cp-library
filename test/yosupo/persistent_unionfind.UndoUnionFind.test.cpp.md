---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../base.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/UndoUnionFind.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<int> t(Q), u(Q), v(Q);\n    vector<vector<int>>\
    \ G(Q + 1);\n    for (int i = 0; i < Q; i++) {\n        int k;\n        cin >>\
    \ t[i] >> k >> u[i] >> v[i];\n        G[++k].emplace_back(i + 1);\n    }\n\n \
    \   UndoUnionFind UF(N);\n    vector<int> ans(Q, -1);\n    auto dfs = [&](auto\
    \ self, int cur) -> void {\n        if (cur) {\n            if (!t[cur - 1])\n\
    \                UF.merge(u[cur - 1], v[cur - 1]);\n            else\n       \
    \         ans[cur - 1] = UF.same(u[cur - 1], v[cur - 1]);\n        }\n       \
    \ for (int nxt : G[cur]) self(self, nxt);\n        if (cur && !t[cur - 1]) UF.undo();\n\
    \    };\n    dfs(dfs, 0);\n    for (int i = 0; i < Q; i++) {\n        if (~ans[i])\
    \ {\n            cout << ans[i] << '\\n';\n        }\n    }\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
- /verify/test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp.html
title: test/yosupo/persistent_unionfind.UndoUnionFind.test.cpp
---
