---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.cpp
    title: test/atcoder/tdpc_fibonacci.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_A.test.cpp
    title: test/aoj/DPL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1050.test.cpp
    title: test/yukicoder/1050.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: modint
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "/**\n * @brief modint\n */\n\n#pragma once\n\n#include \"../base.hpp\"\n\n\
    template<uint32_t mod> class modint{\n    using i64=int64_t;\n    using u32=uint32_t;\n\
    \    using u64=uint64_t;\npublic:\n    u32 v;\n    constexpr modint(const i64\
    \ x=0) noexcept :v(x<0?mod-1-(-(x+1)%mod):x%mod){}\n    constexpr u32 &value()\
    \ noexcept {return v;}\n    constexpr const u32 &value() const noexcept {return\
    \ v;}\n    constexpr modint operator+(const modint &rhs) const noexcept {return\
    \ modint(*this)+=rhs;}\n    constexpr modint operator-(const modint &rhs) const\
    \ noexcept {return modint(*this)-=rhs;}\n    constexpr modint operator*(const\
    \ modint &rhs) const noexcept {return modint(*this)*=rhs;}\n    constexpr modint\
    \ operator/(const modint &rhs) const noexcept {return modint(*this)/=rhs;}\n \
    \   constexpr modint &operator+=(const modint &rhs) noexcept {\n        v+=rhs.v;\n\
    \        if (v>=mod) v-=mod;\n        return *this;\n    }\n    constexpr modint\
    \ &operator-=(const modint &rhs) noexcept {\n        if (v<rhs.v) v+=mod;\n  \
    \      v-=rhs.v;\n        return *this;\n    }\n    constexpr modint &operator*=(const\
    \ modint &rhs) noexcept {\n        v=(u64)v*rhs.v%mod;\n        return *this;\n\
    \    }\n    constexpr modint &operator/=(const modint &rhs) noexcept {\n     \
    \   return *this*=rhs.pow(mod-2);\n    }\n    constexpr modint pow(u64 exp) const\
    \ noexcept {\n        modint self(*this),res(1);\n        while (exp>0){\n   \
    \         if (exp&1) res*=self;\n            self*=self; exp>>=1;\n        }\n\
    \        return res;\n    }\n    constexpr modint &operator++() noexcept {if (++v==mod)\
    \ v=0; return *this;}\n    constexpr modint &operator--() noexcept {if (v==0)\
    \ v=mod; return --v,*this;}\n    constexpr modint operator++(int) noexcept {modint\
    \ t=*this; return ++*this,t;}\n    constexpr modint operator--(int) noexcept {modint\
    \ t=*this; return --*this,t;}\n    template<class T> friend constexpr modint operator+(T\
    \ x,modint y) noexcept {return modint(x)+y;}\n    template<class T> friend constexpr\
    \ modint operator-(T x,modint y) noexcept {return modint(x)-y;}\n    template<class\
    \ T> friend constexpr modint operator*(T x,modint y) noexcept {return modint(x)*y;}\n\
    \    template<class T> friend constexpr modint operator/(T x,modint y) noexcept\
    \ {return modint(x)/y;}\n    constexpr bool operator==(const modint &rhs) const\
    \ noexcept {return v==rhs.v;}\n    constexpr bool operator!=(const modint &rhs)\
    \ const noexcept {return v!=rhs.v;}\n    constexpr bool operator!() const noexcept\
    \ {return !v;}\n    friend istream &operator>>(istream &s,modint &rhs) noexcept\
    \ {\n        i64 v; rhs=modint{(s>>v,v)}; return s;\n    }\n    friend ostream\
    \ &operator<<(ostream &s,const modint &rhs) noexcept {\n        return s<<rhs.v;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: modulo/modint.hpp
  requiredBy:
  - test/atcoder/tdpc_fibonacci.cpp
  - convolution/NumberTheoreticTransform.hpp
  - convolution/ArbitaryModConvolution.hpp
  timestamp: '2020-09-22 13:03:14+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/aoj/DPL_5_A.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/yukicoder/3046.test.cpp
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/1050.test.cpp
  - test/yukicoder/665.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
documentation_of: modulo/modint.hpp
layout: document
redirect_from:
- /library/modulo/modint.hpp
- /library/modulo/modint.hpp.html
title: modint
---
