---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/euler_phi.md
    document_title: "Euler\u306E\u03C6\u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"math/euler_phi.hpp\"\n/**\n * @brief Euler\u306E\u03C6\u95A2\
    \u6570\n * @docs docs/math/euler_phi.md\n */\n\n#line 2 \"base.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define LOCAL\n#pragma region Macros\n\
    typedef long long ll;\n#define ALL(x) (x).begin(),(x).end()\nconst long long MOD=1000000007;\n\
    // const long long MOD=998244353;\nconst int INF=1e9;\nconst long long IINF=1e18;\n\
    const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};\nconst char dir[4]={'D','R','U','L'};\n\
    \ntemplate<typename T>\nistream &operator>>(istream &is,vector<T> &v){\n    for\
    \ (T &x:v) is >> x;\n    return is;\n}\ntemplate<typename T>\nostream &operator<<(ostream\
    \ &os,const vector<T> &v){\n    for (int i=0;i<v.size();++i){\n        os << v[i]\
    \ << (i+1==v.size()?\"\": \" \");\n    }\n    return os;\n}\ntemplate<typename\
    \ T,typename U>\nostream &operator<<(ostream &os,const pair<T,U> &p){\n    os\
    \ << '(' << p.first << ',' << p.second << ')';\n    return os;\n}\ntemplate<typename\
    \ T,typename U>\nostream &operator<<(ostream &os,const map<T,U> &m){\n    os <<\
    \ '{';\n    for (auto itr=m.begin();itr!=m.end();++itr){\n        os << '(' <<\
    \ itr->first << ',' << itr->second << ')';\n        if (++itr!=m.end()) os <<\
    \ ',';\n        --itr;\n    }\n    os << '}';\n    return os;\n}\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const set<T> &s){\n    os << '{';\n    for\
    \ (auto itr=s.begin();itr!=s.end();++itr){\n        os << *itr;\n        if (++itr!=s.end())\
    \ os << ',';\n        --itr;\n    }\n    os << '}';\n    return os;\n}\n\nvoid\
    \ debug_out(){cerr << '\\n';}\ntemplate<class Head,class... Tail>\nvoid debug_out(Head&&\
    \ head,Tail&&... tail){\n    cerr << head;\n    if (sizeof...(Tail)>0) cerr <<\
    \ \", \";\n    debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)\
    \ cerr << \" \";\\\ncerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__\
    \ << \"]\" << '\\n';\\\ncerr << \" \";\\\ndebug_out(__VA_ARGS__)\n#else\n#define\
    \ debug(...) 42\n#endif\n\ntemplate<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}\n\
    template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}\n\ntemplate<class T1,class\
    \ T2> inline bool chmin(T1 &a,T2 b){\n    if (a>b){a=b; return true;} return false;\n\
    }\ntemplate<class T1,class T2> inline bool chmax(T1 &a,T2 b){\n    if (a<b){a=b;\
    \ return true;} return false;\n}\n#pragma endregion\n#line 7 \"math/euler_phi.hpp\"\
    \n\ntemplate<typename T>\nT euler_phi(T n){\n    T res=n;\n    for (T i=2;i*i<=n;++i)\
    \ if (n%i==0){\n        res-=res/i;\n        while (n%i==0) n/=i;\n    }\n   \
    \ if (n!=1) res-=res/n;\n    return res;\n}\nvector<int> euler_phi_table(int n){\n\
    \    vector<int> euler(n+1);\n    iota(euler.begin(),euler.end(),0);\n    for\
    \ (int i=2;i<=n;++i) if (euler[i]==i){\n        for (int j=i;j<=n;j+=i) euler[j]-=euler[j]/i;\n\
    \    }\n    return euler;\n};\n"
  code: "/**\n * @brief Euler\u306E\u03C6\u95A2\u6570\n * @docs docs/math/euler_phi.md\n\
    \ */\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nT euler_phi(T n){\n\
    \    T res=n;\n    for (T i=2;i*i<=n;++i) if (n%i==0){\n        res-=res/i;\n\
    \        while (n%i==0) n/=i;\n    }\n    if (n!=1) res-=res/n;\n    return res;\n\
    }\nvector<int> euler_phi_table(int n){\n    vector<int> euler(n+1);\n    iota(euler.begin(),euler.end(),0);\n\
    \    for (int i=2;i<=n;++i) if (euler[i]==i){\n        for (int j=i;j<=n;j+=i)\
    \ euler[j]-=euler[j]/i;\n    }\n    return euler;\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/euler_phi.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:03:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_D.test.cpp
documentation_of: math/euler_phi.hpp
layout: document
redirect_from:
- /library/math/euler_phi.hpp
- /library/math/euler_phi.hpp.html
title: "Euler\u306E\u03C6\u95A2\u6570"
---
## 概要

## 計算量