---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/StirlingSecond.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _extendedVerifiedWith:
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
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/FormalPowerSeries.hpp
    document_title: Formal Power Series
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ polynomial/FormalPowerSeries.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Formal Power Series\n * @docs docs/polynomial/FormalPowerSeries.hpp\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename M>\nstruct\
    \ FormalPowerSeries:vector<M>{\n    using vector<M>::vector;\n    using Poly=FormalPowerSeries;\n\
    \    using MUL=function<Poly(Poly,Poly)>;\n    static MUL &get_mul(){static MUL\
    \ mul=nullptr; return mul;}\n    static void set_mul(MUL f){get_mul()=f;}\n  \
    \  void shrink(){\n        while (this->size()&&this->back()==M(0)) this->pop_back();\n\
    \    }\n    Poly pre(int deg) const {return Poly(this->begin(),this->begin()+min((int)this->size(),deg));}\n\
    \    Poly operator+(const M &v) const {return Poly(*this)+=v;}\n    Poly operator+(const\
    \ Poly &p) const {return Poly(*this)+=p;}\n    Poly operator-(const M &v) const\
    \ {return Poly(*this)-=v;}\n    Poly operator-(const Poly &p) const {return Poly(*this)-=p;}\n\
    \    Poly operator*(const M &v) const {return Poly(*this)*=v;}\n    Poly operator*(const\
    \ Poly &p) const {return Poly(*this)*=p;}\n    Poly operator/(const Poly &p) const\
    \ {return Poly(*this)/=p;}\n    Poly operator%(const Poly &p) const {return Poly(*this)%=p;}\n\
    \    Poly &operator+=(const M &v){\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0]+=v;\n        return *this;\n    }\n    Poly &operator+=(const\
    \ Poly &p){\n        if (p.size()>this->size()) this->resize(p.size());\n    \
    \    for (int i=0;i<p.size();++i) (*this)[i]+=p[i];\n        return *this;\n \
    \   }\n    Poly &operator-=(const M &v){\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0]-=v;\n        return *this;\n    }\n    Poly &operator-=(const\
    \ Poly &p){\n        if (p.size()>this->size()) this->resize(p.size());\n    \
    \    for (int i=0;i<p.size();++i) (*this)[i]-=p[i];\n        return *this;\n \
    \   }\n    Poly &operator*=(const M &v){\n        for (int i=0;i<this->size();++i)\
    \ (*this)[i]*=v;\n        return *this;\n    }\n    Poly &operator*=(const Poly\
    \ &p){\n        if (this->empty()||p.empty()){\n            this->clear();\n \
    \           return *this;\n        }\n        assert(get_mul()!=nullptr);\n  \
    \      return *this=get_mul()(*this,p);\n    }\n    Poly &operator/=(const Poly\
    \ &p){\n        if (this->size()<p.size()){\n            this->clear();\n    \
    \        return *this;\n        }\n        int n=this->size()-p.size()-1;\n  \
    \      return *this=(rev().pre(n)*p.rev().inv(n)).pre(n).rev(n);\n    }\n    Poly\
    \ &operator%=(const Poly &p){return *this-=*this/p*p;}\n    Poly operator<<(const\
    \ int deg){\n        Poly res(*this);\n        res.insert(res.begin(),deg,M(0));\n\
    \        return res;\n    }\n    Poly operator>>(const int deg){\n        if (this->size()<=deg)\
    \ return {};\n        Poly res(*this);\n        res.erase(res.begin(),res.begin()+deg);\n\
    \        return res;\n    }\n    Poly operator-() const {\n        Poly res(this->size());\n\
    \        for (int i=0;i<this->size();++i) res[i]=-(*this)[i];\n        return\
    \ res;\n    }\n    Poly rev(int deg=-1) const {\n        Poly res(*this);\n  \
    \      if (~deg) res.resize(deg,M(0));\n        reverse(res.begin(),res.end());\n\
    \        return res;\n    }\n    Poly diff() const {\n        Poly res(max(0,(int)this->size()-1));\n\
    \        for (int i=1;i<this->size();++i) res[i-1]=(*this)[i]*M(i);\n        return\
    \ res;\n    }\n    Poly integral() const {\n        Poly res(this->size()+1);\n\
    \        res[0]=M(0);\n        for (int i=0;i<this->size();++i) res[i+1]=(*this)[i]/M(i+1);\n\
    \        return res;\n    }\n    Poly inv(int deg=-1) const {\n        assert((*this)[0]!=M(0));\n\
    \        if (deg<0) deg=this->size();\n        Poly res({M(1)/(*this)[0]});\n\
    \        for (int i=1;i<deg;i<<=1){\n            res=(res+res-res*res*pre(i<<1)).pre(i<<1);\n\
    \        }\n        return res.pre(deg);\n    }\n    Poly log(int deg=-1) const\
    \ {\n        assert((*this)[0]==M(1));\n        if (deg<0) deg=this->size();\n\
    \        return (this->diff()*this->inv(deg)).pre(deg-1).integral();\n    }\n\
    \    Poly sqrt(int deg=-1) const {\n        assert((*this)[0]==M(1));\n      \
    \  if (deg==-1) deg=this->size();\n        Poly res({M(1)});\n        M inv2=M(1)/M(2);\n\
    \        for (int i=1;i<deg;i<<=1){\n            res=(res+pre(i<<1)*res.inv(i<<1))*inv2;\n\
    \        }\n        return res.pre(deg);\n    }\n    Poly exp(int deg=-1){\n \
    \       assert((*this)[0]==M(0));\n        if (deg<0) deg=this->size();\n    \
    \    Poly res({M(1)});\n        for (int i=1;i<deg;i<<=1){\n            res=(res*(pre(i<<1)+M(1)-res.log(i<<1))).pre(i<<1);\n\
    \        }\n        return res.pre(deg);\n    }\n    Poly pow(long long k,int\
    \ deg=-1) const {\n        if (deg<0) deg=this->size();\n        for (int i=0;i<this->size();++i){\n\
    \            if ((*this)[i]==M(0)) continue;\n            if (k*i>deg) return\
    \ Poly(deg,M(0));\n            M inv=M(1)/(*this)[i];\n            Poly res=(((*this*inv)>>i).log()*k).exp()*(*this)[i].pow(k);\n\
    \            res=(res<<(i*k)).pre(deg);\n            if (res.size()<deg) res.resize(deg,M(0));\n\
    \            return res;\n        }\n        return *this;\n    }\n    Poly pow_mod(long\
    \ long k,const Poly &mod) const {\n        Poly x(*this),res={M(1)};\n       \
    \ while (k>0){\n            if (k&1) res=res*x%mod;\n            x=x*x%mod; k>>=1;\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/FormalPowerSeries.hpp
  requiredBy:
  - polynomial/StirlingSecond.hpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/3046.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
documentation_of: polynomial/FormalPowerSeries.hpp
layout: document
redirect_from:
- /library/polynomial/FormalPowerSeries.hpp
- /library/polynomial/FormalPowerSeries.hpp.html
title: Formal Power Series
---
