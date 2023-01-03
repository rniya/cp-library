---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/run_enumerate.hpp
    title: Run Enumerate
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/runenumerate
    links:
    - https://judge.yosupo.jp/problem/runenumerate
  bundledCode: "#line 1 \"test/yosupo/runenumerate.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/runenumerate\"\n\n#include <iostream>\n#line 1\
    \ \"string/run_enumerate.hpp\"\n#include <string>\n#include <tuple>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace run_enumerate {\n\n// Reference:\n\
    // D. Gusfield,\n// Algorithms on Strings, Trees, and Sequences: Computer Science\
    \ and\n// Computational Biology\ntemplate <class T> std::vector<int> z_algorithm(const\
    \ std::vector<T>& s) {\n    int n = int(s.size());\n    if (n == 0) return {};\n\
    \    std::vector<int> z(n);\n    z[0] = 0;\n    for (int i = 1, j = 0; i < n;\
    \ i++) {\n        int& k = z[i];\n        k = (j + z[j] <= i) ? 0 : std::min(j\
    \ + z[j] - i, z[i - j]);\n        while (i + k < n && s[k] == s[i + k]) k++;\n\
    \        if (j + z[j] < i + z[i]) j = i;\n    }\n    z[0] = n;\n    return z;\n\
    }\n\nstd::vector<int> z_algorithm(const std::string& s) {\n    int n = int(s.size());\n\
    \    std::vector<int> s2(n);\n    for (int i = 0; i < n; i++) {\n        s2[i]\
    \ = s[i];\n    }\n    return z_algorithm(s2);\n}\n\ntemplate <class T> std::vector<std::tuple<int,\
    \ int, int>> enumerate(const std::vector<T>& s) {\n    int n = s.size();\n   \
    \ std::vector<std::tuple<int, int, int>> res;\n    auto dfs = [&](auto&& self,\
    \ int l, int r) -> void {\n        if (r - l <= 1) return;\n        int m = (l\
    \ + r) >> 1;\n        self(self, l, m);\n        self(self, m, r);\n        std::vector<T>\
    \ sl(s.rbegin() + n - m, s.rbegin() + n - l);\n        sl.insert(sl.end(), s.rbegin()\
    \ + n - r, s.rbegin() + n - l);\n        std::vector<T> sr(s.begin() + m, s.begin()\
    \ + r);\n        sr.insert(sr.end(), s.begin() + l, s.begin() + r);\n        auto\
    \ zsl = z_algorithm(sl), zsr = z_algorithm(sr);\n        for (int t = 1; t <=\
    \ m - l; t++) {\n            int ml = std::max(l, m - t - zsl[t]), mr = std::min(r,\
    \ m + zsr[r - l - t]);\n            if (mr - ml >= 2 * t and (ml == 0 or s[ml\
    \ - 1] != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))\n              \
    \  res.emplace_back(ml, mr, t);\n        }\n        for (int t = 1; t <= r - m;\
    \ t++) {\n            int ml = std::max(l, m - zsl[r - l - t]), mr = std::min(r,\
    \ m + t + zsr[t]);\n            if (mr - ml >= 2 * t and (ml == 0 or s[ml - 1]\
    \ != s[ml + t - 1]) and (mr == n or s[mr] != s[mr - t]))\n                res.emplace_back(ml,\
    \ mr, t);\n        }\n    };\n    dfs(dfs, 0, n);\n    sort(res.begin(), res.end());\n\
    \    std::vector<std::tuple<int, int, int>> nres;\n    int pl = -1, pr = -1;\n\
    \    for (auto [l, r, t] : res) {\n        if (l == pl and r == pr) continue;\n\
    \        pl = l, pr = r;\n        nres.emplace_back(t, l, r);\n    }\n    return\
    \ nres;\n}\n\nstd::vector<std::tuple<int, int, int>> enumerate(const std::string&\
    \ s) {\n    return enumerate(std::vector<char>(s.begin(), s.end()));\n}\n\n} \
    \ // namespace run_enumerate\n#line 5 \"test/yosupo/runenumerate.test.cpp\"\n\n\
    int main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n  \
    \  std::string S;\n    std::cin >> S;\n\n    auto res = run_enumerate::enumerate(S);\n\
    \    std::sort(res.begin(), res.end());\n    std::cout << res.size() << '\\n';\n\
    \    for (auto [t, l, r] : res) std::cout << t << ' ' << l << ' ' << r << '\\\
    n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/runenumerate\"\n\n#include\
    \ <iostream>\n#include \"string/run_enumerate.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    std::string S;\n    std::cin >> S;\n\
    \n    auto res = run_enumerate::enumerate(S);\n    std::sort(res.begin(), res.end());\n\
    \    std::cout << res.size() << '\\n';\n    for (auto [t, l, r] : res) std::cout\
    \ << t << ' ' << l << ' ' << r << '\\n';\n    return 0;\n}"
  dependsOn:
  - string/run_enumerate.hpp
  isVerificationFile: true
  path: test/yosupo/runenumerate.test.cpp
  requiredBy: []
  timestamp: '2023-01-03 16:26:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/runenumerate.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/runenumerate.test.cpp
- /verify/test/yosupo/runenumerate.test.cpp.html
title: test/yosupo/runenumerate.test.cpp
---
