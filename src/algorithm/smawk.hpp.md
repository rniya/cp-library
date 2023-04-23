---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/smawk.hpp\"\n#include <vector>\n\ntemplate\
    \ <class F> std::vector<int> smawk(int N, int M, const F& f) {\n    auto solve\
    \ = [&](auto&& self, const std::vector<int>& row, const std::vector<int>& col)\
    \ -> std::vector<int> {\n        int n = row.size();\n        if (n == 0) return\
    \ {};\n        std::vector<int> nrow, ncol;\n        for (const int& i : col)\
    \ {\n            while (not ncol.empty() and f(row[ncol.size() - 1], ncol.back())\
    \ > f(row[ncol.size() - 1], i))\n                ncol.pop_back();\n          \
    \  if (int(ncol.size()) < n) ncol.emplace_back(i);\n        }\n        for (int\
    \ i = 1; i < n; i += 2) nrow.emplace_back(row[i]);\n        auto nres = self(self,\
    \ nrow, ncol);\n        std::vector<int> res(n);\n        for (int i = 0; i <\
    \ int(nres.size()); i++) res[2 * i + 1] = nres[i];\n        for (int i = 0, j\
    \ = 0; i < n; i += 2) {\n            res[i] = ncol[j];\n            int last =\
    \ i + 1 == n ? ncol.back() : res[i + 1];\n            while (ncol[j] < last) {\n\
    \                j++;\n                if (f(row[i], res[i]) > f(row[i], ncol[j]))\
    \ res[i] = ncol[j];\n            }\n        }\n        return res;\n    };\n \
    \   std::vector<int> row(N), col(M);\n    iota(begin(row), end(row), 0);\n   \
    \ iota(begin(col), end(col), 0);\n    return solve(solve, row, col);\n}\n"
  code: "#include <vector>\n\ntemplate <class F> std::vector<int> smawk(int N, int\
    \ M, const F& f) {\n    auto solve = [&](auto&& self, const std::vector<int>&\
    \ row, const std::vector<int>& col) -> std::vector<int> {\n        int n = row.size();\n\
    \        if (n == 0) return {};\n        std::vector<int> nrow, ncol;\n      \
    \  for (const int& i : col) {\n            while (not ncol.empty() and f(row[ncol.size()\
    \ - 1], ncol.back()) > f(row[ncol.size() - 1], i))\n                ncol.pop_back();\n\
    \            if (int(ncol.size()) < n) ncol.emplace_back(i);\n        }\n    \
    \    for (int i = 1; i < n; i += 2) nrow.emplace_back(row[i]);\n        auto nres\
    \ = self(self, nrow, ncol);\n        std::vector<int> res(n);\n        for (int\
    \ i = 0; i < int(nres.size()); i++) res[2 * i + 1] = nres[i];\n        for (int\
    \ i = 0, j = 0; i < n; i += 2) {\n            res[i] = ncol[j];\n            int\
    \ last = i + 1 == n ? ncol.back() : res[i + 1];\n            while (ncol[j] <\
    \ last) {\n                j++;\n                if (f(row[i], res[i]) > f(row[i],\
    \ ncol[j])) res[i] = ncol[j];\n            }\n        }\n        return res;\n\
    \    };\n    std::vector<int> row(N), col(M);\n    iota(begin(row), end(row),\
    \ 0);\n    iota(begin(col), end(col), 0);\n    return solve(solve, row, col);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: src/algorithm/smawk.hpp
  requiredBy: []
  timestamp: '2023-04-24 02:22:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/smawk.hpp
layout: document
redirect_from:
- /library/src/algorithm/smawk.hpp
- /library/src/algorithm/smawk.hpp.html
title: src/algorithm/smawk.hpp
---
