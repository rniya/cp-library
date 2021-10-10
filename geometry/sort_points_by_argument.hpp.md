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
  bundledCode: "#line 1 \"geometry/sort_points_by_argument.hpp\"\n#include <cmath>\n\
    \nstruct pt {\n    long long x, y;\n    pt(long long x, long long y) : x(x), y(y)\
    \ {}\n};\nbool comp(pt l, pt r) {\n    auto la = std::atan2(l.y, l.x);\n    auto\
    \ ra = std::atan2(r.y, r.x);\n    if (std::abs(la - ra) > 1)\n        return la\
    \ < ra;\n    else\n        return l.x * r.y > l.y * r.x;\n}\n"
  code: "#include <cmath>\n\nstruct pt {\n    long long x, y;\n    pt(long long x,\
    \ long long y) : x(x), y(y) {}\n};\nbool comp(pt l, pt r) {\n    auto la = std::atan2(l.y,\
    \ l.x);\n    auto ra = std::atan2(r.y, r.x);\n    if (std::abs(la - ra) > 1)\n\
    \        return la < ra;\n    else\n        return l.x * r.y > l.y * r.x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/sort_points_by_argument.hpp
  requiredBy: []
  timestamp: '2021-10-10 15:55:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/sort_points_by_argument.hpp
layout: document
redirect_from:
- /library/geometry/sort_points_by_argument.hpp
- /library/geometry/sort_points_by_argument.hpp.html
title: geometry/sort_points_by_argument.hpp
---
