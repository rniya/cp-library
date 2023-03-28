---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':x:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/characteristic_polynomial.test.cpp
    title: test/yosupo/characteristic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_cliques.test.cpp
    title: test/yosupo/enumerate_cliques.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: test/yosupo/gcd_convolution.test.cpp
    title: test/yosupo/gcd_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_det.test.cpp
    title: test/yosupo/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/polynomial_taylor_shift.test.cpp
    title: test/yosupo/polynomial_taylor_shift.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
    title: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/product_of_polynomial_sequence.test.cpp
    title: test/yosupo/product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/803.test.cpp
    title: test/yukicoder/803.test.cpp
  - icon: ':x:'
    path: test/yukicoder/886.test.cpp
    title: test/yukicoder/886.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <iostream>\n#include \"atcoder/modint\"\n\nnamespace\
    \ atcoder {\n\ntemplate <int MOD> std::istream& operator>>(std::istream& is, static_modint<MOD>&\
    \ x) {\n    int64_t v;\n    x = static_modint<MOD>{(is >> v, v)};\n    return\
    \ is;\n}\n\ntemplate <int MOD> std::ostream& operator<<(std::ostream& os, const\
    \ static_modint<MOD>& x) { return os << x.val(); }\n\ntemplate <int ID> std::ostream&\
    \ operator<<(std::ostream& os, const dynamic_modint<ID>& x) { return os << x.val();\
    \ }\n\n}  // namespace atcoder\n"
  dependsOn: []
  isVerificationFile: false
  path: src/util/modint.hpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/enumerate_cliques.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/characteristic_polynomial.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/matrix_det.test.cpp
  - test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/product_of_polynomial_sequence.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/gcd_convolution.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/polynomial_taylor_shift.test.cpp
  - test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/yukicoder/1289.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yukicoder/803.test.cpp
  - test/yukicoder/1269.test.cpp
  - test/yukicoder/886.test.cpp
  - test/yukicoder/1907.test.cpp
documentation_of: src/util/modint.hpp
layout: document
redirect_from:
- /library/src/util/modint.hpp
- /library/src/util/modint.hpp.html
title: src/util/modint.hpp
---
