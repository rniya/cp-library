---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/453.test.cpp
    title: test/yukicoder/453.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Construct a new Simplex object
    links: []
  bundledCode: "#line 2 \"flow/Simplex.hpp\"\n#include <cassert>\n#include <numeric>\n\
    #include <vector>\n\nstruct Simplex {\n    bool infinity,           // which the\
    \ problem is unbounded or not\n        infeasible;          // which the problem\
    \ is infeasible or not\n    int n,                   // the number of variables\n\
    \        m;                   // the number of constraints\n    std::vector<double>\
    \ x;   // optimal solution\n    double opt;              // optimal value\n  \
    \  std::vector<int> index;  // indices of non-basis (< n) and basis (otherwise)\n\
    \    int r, s;                // pivot row / column\n    std::vector<std::vector<double>>\
    \ tableau;\n\n    /**\n     * @brief Construct a new Simplex object\n     *\n\
    \     * @param A Coefficients of constraints\n     * @param b Bounds of constraints\n\
    \     * @param c Coefficients of objective function\n     * @param mode choose\
    \ pivot by smallest subscript rule if mode = 0, largest coefficient rule otherwise\n\
    \     * @details Maximize cx s.t. Ax <= b and x >= 0\n     */\n    Simplex(const\
    \ std::vector<std::vector<double>>& A,\n            const std::vector<double>&\
    \ b,\n            const std::vector<double>& c,\n            int mode = 0) {\n\
    \        infinity = infeasible = false;\n        init(A, b, c);\n        solve(mode);\n\
    \    }\n\nprivate:\n    static constexpr double EPS = 1e-10;\n\n    inline int\
    \ sgn(const double& x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }\n\n    inline\
    \ int compare(const double& a, const double& b) { return sgn(a - b); }\n\n   \
    \ inline bool equals(const double& a, const double& b) { return compare(a, b)\
    \ == 0; }\n\n    void init(const std::vector<std::vector<double>>& A, const std::vector<double>&\
    \ b, const std::vector<double>& c) {\n        m = A.size(), n = c.size();\n\n\
    \        index.resize(n + 1 + m);\n        std::iota(index.begin(), index.end(),\
    \ 0);\n        tableau.assign(m + 2, std::vector<double>(n + 2, 0));\n\n     \
    \   r = m;\n        for (int i = 0; i < m; i++) {\n            for (int j = 0;\
    \ j < n; j++) tableau[i][j] = -A[i][j];\n            tableau[i][n] = 1;\n    \
    \        tableau[i][n + 1] = b[i];\n            if (tableau[i][n + 1] < tableau[r][n\
    \ + 1]) r = i;\n        }\n        for (int j = 0; j < n; j++) tableau[m][j] =\
    \ c[j];\n        tableau[m + 1][n] = -1;\n    }\n\n    void smallest_subscript_rule()\
    \ {\n        r = s = -1;\n        for (int j = 0; j < n + 1; j++) {\n        \
    \    if (s < 0 or index[j] < index[s]) {\n                if (compare(tableau[m\
    \ + 1][j], 0) > 0 or\n                    (equals(tableau[m + 1][j], 0) and compare(tableau[m][j],\
    \ 0) > 0)) {\n                    s = j;\n                }\n            }\n \
    \       }\n        if (s < 0) return;\n        r = -1;\n        for (int i = 0;\
    \ i < m; i++) {\n            if (compare(tableau[i][s], 0) >= 0) continue;\n \
    \           if (r < 0)\n                r = i;\n            else if (compare(tableau[i][n\
    \ + 1] / (-tableau[i][s]), tableau[r][n + 1] / (-tableau[r][s])) < 0)\n      \
    \          r = i;\n            else if (equals(tableau[i][n + 1] / (-tableau[i][s]),\
    \ tableau[r][n + 1] / (-tableau[r][s])) and\n                     index[n + 1\
    \ + i] < index[n + 1 + r]) {\n                r = i;\n            }\n        }\n\
    \    }\n\n    void largest_coefficient_rule() {\n        r = s = -1;\n       \
    \ double Max = 0;\n        for (int j = 0; j < n + 1; j++) {\n            if (compare(tableau[m\
    \ + 1][j], Max) > 0)\n                s = j, Max = tableau[m + 1][j];\n      \
    \      else if (equals(tableau[m + 1][j], 0) and compare(tableau[m][j], Max) >\
    \ 0)\n                s = j, Max = tableau[m][j];\n        }\n        if (s <\
    \ 0) return;\n        r = -1;\n        for (int i = 0; i < m; i++) {\n       \
    \     if (compare(tableau[i][s], 0) >= 0) continue;\n            if (r < 0)\n\
    \                r = i;\n            else if (compare(tableau[i][n + 1] / (-tableau[i][s]),\
    \ tableau[r][n + 1] / (-tableau[r][s])) < 0)\n                r = i;\n       \
    \ }\n    }\n\n    void solve(int mode) {\n        std::vector<int> nonzero;\n\
    \        for (s = n;;) {\n            if (r < m) {\n                std::swap(index[s],\
    \ index[n + 1 + r]);\n                tableau[r][s] = double(1) / tableau[r][s];\n\
    \                nonzero.clear();\n                for (int j = 0; j < n + 2;\
    \ j++) {\n                    if (j == s) continue;\n                    tableau[r][j]\
    \ *= -tableau[r][s];\n                    if (!equals(tableau[r][j], 0)) nonzero.emplace_back(j);\n\
    \                }\n                for (int i = 0; i < m + 2; i++) {\n      \
    \              if (i == r or equals(tableau[i][s], 0)) continue;\n           \
    \         for (const auto& j : nonzero) tableau[i][j] += tableau[i][s] * tableau[r][j];\n\
    \                    tableau[i][s] *= tableau[r][s];\n                }\n    \
    \        }\n\n            if (mode == 0)\n                smallest_subscript_rule();\n\
    \            else\n                largest_coefficient_rule();\n            if\
    \ (s < 0) break;\n            if (r < 0) {\n                infinity = true;\n\
    \                return;\n            }\n        }\n\n        if (compare(tableau[m\
    \ + 1][n + 1], 0) < 0) {\n            infeasible = true;\n            return;\n\
    \        }\n        x.assign(n, 0);\n        for (int i = 0; i < m; i++) {\n \
    \           if (index[n + 1 + i] < n) {\n                x[index[n + 1 + i]] =\
    \ tableau[i][n + 1];\n            }\n        }\n        opt = tableau[m][n + 1];\n\
    \    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <numeric>\n#include <vector>\n\
    \nstruct Simplex {\n    bool infinity,           // which the problem is unbounded\
    \ or not\n        infeasible;          // which the problem is infeasible or not\n\
    \    int n,                   // the number of variables\n        m;         \
    \          // the number of constraints\n    std::vector<double> x;   // optimal\
    \ solution\n    double opt;              // optimal value\n    std::vector<int>\
    \ index;  // indices of non-basis (< n) and basis (otherwise)\n    int r, s; \
    \               // pivot row / column\n    std::vector<std::vector<double>> tableau;\n\
    \n    /**\n     * @brief Construct a new Simplex object\n     *\n     * @param\
    \ A Coefficients of constraints\n     * @param b Bounds of constraints\n     *\
    \ @param c Coefficients of objective function\n     * @param mode choose pivot\
    \ by smallest subscript rule if mode = 0, largest coefficient rule otherwise\n\
    \     * @details Maximize cx s.t. Ax <= b and x >= 0\n     */\n    Simplex(const\
    \ std::vector<std::vector<double>>& A,\n            const std::vector<double>&\
    \ b,\n            const std::vector<double>& c,\n            int mode = 0) {\n\
    \        infinity = infeasible = false;\n        init(A, b, c);\n        solve(mode);\n\
    \    }\n\nprivate:\n    static constexpr double EPS = 1e-10;\n\n    inline int\
    \ sgn(const double& x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }\n\n    inline\
    \ int compare(const double& a, const double& b) { return sgn(a - b); }\n\n   \
    \ inline bool equals(const double& a, const double& b) { return compare(a, b)\
    \ == 0; }\n\n    void init(const std::vector<std::vector<double>>& A, const std::vector<double>&\
    \ b, const std::vector<double>& c) {\n        m = A.size(), n = c.size();\n\n\
    \        index.resize(n + 1 + m);\n        std::iota(index.begin(), index.end(),\
    \ 0);\n        tableau.assign(m + 2, std::vector<double>(n + 2, 0));\n\n     \
    \   r = m;\n        for (int i = 0; i < m; i++) {\n            for (int j = 0;\
    \ j < n; j++) tableau[i][j] = -A[i][j];\n            tableau[i][n] = 1;\n    \
    \        tableau[i][n + 1] = b[i];\n            if (tableau[i][n + 1] < tableau[r][n\
    \ + 1]) r = i;\n        }\n        for (int j = 0; j < n; j++) tableau[m][j] =\
    \ c[j];\n        tableau[m + 1][n] = -1;\n    }\n\n    void smallest_subscript_rule()\
    \ {\n        r = s = -1;\n        for (int j = 0; j < n + 1; j++) {\n        \
    \    if (s < 0 or index[j] < index[s]) {\n                if (compare(tableau[m\
    \ + 1][j], 0) > 0 or\n                    (equals(tableau[m + 1][j], 0) and compare(tableau[m][j],\
    \ 0) > 0)) {\n                    s = j;\n                }\n            }\n \
    \       }\n        if (s < 0) return;\n        r = -1;\n        for (int i = 0;\
    \ i < m; i++) {\n            if (compare(tableau[i][s], 0) >= 0) continue;\n \
    \           if (r < 0)\n                r = i;\n            else if (compare(tableau[i][n\
    \ + 1] / (-tableau[i][s]), tableau[r][n + 1] / (-tableau[r][s])) < 0)\n      \
    \          r = i;\n            else if (equals(tableau[i][n + 1] / (-tableau[i][s]),\
    \ tableau[r][n + 1] / (-tableau[r][s])) and\n                     index[n + 1\
    \ + i] < index[n + 1 + r]) {\n                r = i;\n            }\n        }\n\
    \    }\n\n    void largest_coefficient_rule() {\n        r = s = -1;\n       \
    \ double Max = 0;\n        for (int j = 0; j < n + 1; j++) {\n            if (compare(tableau[m\
    \ + 1][j], Max) > 0)\n                s = j, Max = tableau[m + 1][j];\n      \
    \      else if (equals(tableau[m + 1][j], 0) and compare(tableau[m][j], Max) >\
    \ 0)\n                s = j, Max = tableau[m][j];\n        }\n        if (s <\
    \ 0) return;\n        r = -1;\n        for (int i = 0; i < m; i++) {\n       \
    \     if (compare(tableau[i][s], 0) >= 0) continue;\n            if (r < 0)\n\
    \                r = i;\n            else if (compare(tableau[i][n + 1] / (-tableau[i][s]),\
    \ tableau[r][n + 1] / (-tableau[r][s])) < 0)\n                r = i;\n       \
    \ }\n    }\n\n    void solve(int mode) {\n        std::vector<int> nonzero;\n\
    \        for (s = n;;) {\n            if (r < m) {\n                std::swap(index[s],\
    \ index[n + 1 + r]);\n                tableau[r][s] = double(1) / tableau[r][s];\n\
    \                nonzero.clear();\n                for (int j = 0; j < n + 2;\
    \ j++) {\n                    if (j == s) continue;\n                    tableau[r][j]\
    \ *= -tableau[r][s];\n                    if (!equals(tableau[r][j], 0)) nonzero.emplace_back(j);\n\
    \                }\n                for (int i = 0; i < m + 2; i++) {\n      \
    \              if (i == r or equals(tableau[i][s], 0)) continue;\n           \
    \         for (const auto& j : nonzero) tableau[i][j] += tableau[i][s] * tableau[r][j];\n\
    \                    tableau[i][s] *= tableau[r][s];\n                }\n    \
    \        }\n\n            if (mode == 0)\n                smallest_subscript_rule();\n\
    \            else\n                largest_coefficient_rule();\n            if\
    \ (s < 0) break;\n            if (r < 0) {\n                infinity = true;\n\
    \                return;\n            }\n        }\n\n        if (compare(tableau[m\
    \ + 1][n + 1], 0) < 0) {\n            infeasible = true;\n            return;\n\
    \        }\n        x.assign(n, 0);\n        for (int i = 0; i < m; i++) {\n \
    \           if (index[n + 1 + i] < n) {\n                x[index[n + 1 + i]] =\
    \ tableau[i][n + 1];\n            }\n        }\n        opt = tableau[m][n + 1];\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/Simplex.hpp
  requiredBy: []
  timestamp: '2021-12-30 16:20:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/453.test.cpp
documentation_of: flow/Simplex.hpp
layout: document
title: "Simplex\uFF08\u5358\u4F53\u6CD5\uFF09"
---

## 概要
$$
\begin{alignedat}{5}
    & \mathrm{Maximize}     & \quad & \boldsymbol{c}^\top \boldsymbol{x}    \\
    & \mathrm{subject\ to}  & \quad & A \boldsymbol{x} \leq \boldsymbol{b}  \\
    &                       & \quad & \boldsymbol{x} \geq \boldsymbol{0}    \\
\end{alignedat}
$$

を解く．2 段階単体法を利用しており，$\boldsymbol{b} \geq \boldsymbol{0}$ といった制約には縛られない．

ピボットの対象となる基底変数と非規定変数の選び方については以下が代表的である．

- 最小添字規則 (smallest subscript rule)
  - 最も収束の遅い規則であることがわかっているものの，アルゴリズムの有限回での停止が保証されている．
- 最大係数規則 (largest coefficient rule)
  - 平均的な振舞いにおいては最も無難な規則とされているが有限回で停止するとは限らない（ただ，有限回で停止しないようなケースはかなり恣意的なケースである）．

これはデフォルトでは最小添字規則で計算するようにされているが，引数 `mode` によって切り替えることが可能である．テストしてみても概ね最小添字規則で十分高速に動作するのでこのままで構わないはず．
