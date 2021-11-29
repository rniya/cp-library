---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sqrt_of_formal_power_series\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"polynomial/FormalPowerSeries.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <int MOD> std::istream& operator>>(std::istream&\
    \ is, static_modint<MOD>& x) {\n    int64_t v;\n    x = static_modint<MOD>{(is\
    \ >> v, v)};\n    return is;\n}\n\ntemplate <int MOD> std::ostream& operator<<(std::ostream&\
    \ os, const static_modint<MOD>& x) { return os << x.val(); }\n\ntemplate <int\
    \ ID> std::ostream& operator<<(std::ostream& os, const dynamic_modint<ID>& x)\
    \ { return os << x.val(); }\n\n}  // namespace atcoder\n\nusing mint = atcoder::modint998244353;\n\
    using FPS = FormalPowerSeries<mint>;\n\n// https://ei1333.github.io/library/math/combinatorics/mod-sqrt.cpp\n\
    \n/**\n * @brief Mod Pow(\u3079\u304D\u4E57)\n * @docs docs/mod-pow.md\n */\n\
    template <typename T> T mod_pow(T x, int64_t n, const T& p) {\n    T ret = 1;\n\
    \    while (n > 0) {\n        if (n & 1) (ret *= x) %= p;\n        (x *= x) %=\
    \ p;\n        n >>= 1;\n    }\n    return ret % p;\n}\n\n/**\n * @brief Mod Sqrt\n\
    \ */\ntemplate <typename T> T mod_sqrt(const T& a, const T& p) {\n    if (a ==\
    \ 0) return 0;\n    if (p == 2) return a;\n    if (mod_pow(a, (p - 1) >> 1, p)\
    \ != 1) return -1;\n    T b = 1;\n    while (mod_pow(b, (p - 1) >> 1, p) == 1)\
    \ ++b;\n    T e = 0, m = p - 1;\n    while (m % 2 == 0) m >>= 1, ++e;\n    T x\
    \ = mod_pow(a, (m - 1) >> 1, p);\n    T y = a * (x * x % p) % p;\n    (x *= a)\
    \ %= p;\n    T z = mod_pow(b, m, p);\n    while (y != 1) {\n        T j = 0, t\
    \ = y;\n        while (t != 1) {\n            j += 1;\n            (t *= t) %=\
    \ p;\n        }\n        z = mod_pow(z, T(1) << (e - j - 1), p);\n        (x *=\
    \ z) %= p;\n        (z *= z) %= p;\n        (y *= z) %= p;\n        e = j;\n \
    \   }\n    return x;\n}\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    FPS a(N);\n    for (int i = 0; i < N; i++)\
    \ std::cin >> a[i];\n    auto get_sqrt = [&](mint x) { return mod_sqrt<int64_t>(x.val(),\
    \ mint::mod()); };\n    FPS b = a.sqrt(get_sqrt);\n    if (b.empty()) {\n    \
    \    std::cout << -1 << '\\n';\n        return 0;\n    }\n    for (int i = 0;\
    \ i < N; i++) std::cout << b[i] << (i + 1 == N ? '\\n' : ' ');\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/sqrt_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/sqrt_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sqrt_of_formal_power_series.test.cpp
- /verify/test/yosupo/sqrt_of_formal_power_series.test.cpp.html
title: test/yosupo/sqrt_of_formal_power_series.test.cpp
---
