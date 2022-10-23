---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/Nimber.hpp
    title: math/Nimber.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"test/yosupo/nim_product_64.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/nim_product_64\"\n\n#include <iostream>\n#line\
    \ 2 \"math/Nimber.hpp\"\n#include <algorithm>\n#include <array>\n\nnamespace Nimber64\
    \ {\n\nstruct nim {\n    const static std::array<std::array<unsigned char, 256>,\
    \ 256> small;\n    const static std::array<std::array<std::array<nim, 256>, 8>,\
    \ 8> precalc;\n    unsigned long long v;\n\n    nim() : v(0) {}\n\n    nim(unsigned\
    \ long long _v) : v(_v) {}\n\n    nim& operator+=(const nim& rhs) {\n        v\
    \ ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator-=(const nim& rhs)\
    \ {\n        v ^= rhs.v;\n        return *this;\n    }\n\n    nim& operator*=(const\
    \ nim& rhs) {\n        nim res;\n        for (int i = 0; i < 8; i++) {\n     \
    \       for (int j = 0; j < 8; j++) {\n                res += precalc[i][j][small[(v\
    \ >> (8 * i)) & 255][(rhs.v >> (8 * j)) & 255]];\n            }\n        }\n \
    \       return *this = res;\n    }\n\n    const nim operator+(const nim& rhs)\
    \ const { return nim(*this) += rhs; }\n\n    const nim operator-(const nim& rhs)\
    \ const { return nim(*this) -= rhs; }\n\n    const nim operator*(const nim& rhs)\
    \ const { return nim(*this) *= rhs; }\n};\n\nnim mul_naive(nim l, nim r) {\n \
    \   unsigned long long a = l.v, b = r.v;\n    if (a < b) std::swap(a, b);\n  \
    \  if (b == 0) return 0;\n    if (b == 1) return a;\n    int p = 32;\n    while\
    \ (std::max(a, b) < (1ULL << p)) p >>= 1;\n    unsigned long long power = 1ULL\
    \ << p;\n    if (a >= power and b >= power) {\n        nim res;\n        res +=\
    \ mul_naive(a % power, b % power);\n        res += mul_naive(a / power, b % power).v\
    \ * power;\n        res += mul_naive(a % power, b / power).v * power;\n      \
    \  auto x = mul_naive(a / power, b / power);\n        res += x.v * power;\n  \
    \      res += mul_naive(x, power / 2);\n        return res;\n    } else\n    \
    \    return nim(mul_naive(a / power, b).v * power) + mul_naive(a % power, b);\n\
    }\n\nconst std::array<std::array<unsigned char, 256>, 256> nim::small = []() {\n\
    \    std::array<std::array<unsigned char, 256>, 256> small;\n    for (int i =\
    \ 0; i < 256; i++) {\n        for (int j = 0; j < 256; j++) {\n            small[i][j]\
    \ = (unsigned char)(mul_naive(i, j).v);\n        }\n    }\n    return small;\n\
    }();\n\nconst std::array<std::array<std::array<nim, 256>, 8>, 8> nim::precalc\
    \ = []() {\n    std::array<std::array<std::array<nim, 256>, 8>, 8> precalc;\n\
    \    for (int i = 0; i < 8; i++) {\n        for (int j = 0; j < 8; j++) {\n  \
    \          nim tmp = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));\n          \
    \  for (int k = 0; k < 256; k++) precalc[i][j][k] = mul_naive(tmp, k);\n     \
    \   }\n    }\n    return precalc;\n}();\n\n}  // namespace Nimber64\n#line 5 \"\
    test/yosupo/nim_product_64.test.cpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int T;\n    std::cin >> T;\n    for\
    \ (; T--;) {\n        unsigned long long A, B;\n        std::cin >> A >> B;\n\
    \        auto ans = (Nimber64::nim(A) * Nimber64::nim(B)).v;\n        std::cout\
    \ << ans << '\\n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\n\n#include\
    \ <iostream>\n#include \"math/Nimber.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int T;\n    std::cin >> T;\n    for\
    \ (; T--;) {\n        unsigned long long A, B;\n        std::cin >> A >> B;\n\
    \        auto ans = (Nimber64::nim(A) * Nimber64::nim(B)).v;\n        std::cout\
    \ << ans << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - math/Nimber.hpp
  isVerificationFile: true
  path: test/yosupo/nim_product_64.test.cpp
  requiredBy: []
  timestamp: '2022-10-23 23:11:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/nim_product_64.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/nim_product_64.test.cpp
- /verify/test/yosupo/nim_product_64.test.cpp.html
title: test/yosupo/nim_product_64.test.cpp
---
