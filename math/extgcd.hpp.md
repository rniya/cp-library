---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_E.test.cpp
    title: test/aoj/NTL_1_E.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5"
    links: []
  bundledCode: "#line 1 \"math/extgcd.hpp\"\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\
    \u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n */\n\n#line 2 \"base.hpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define LOCAL\n#pragma region\
    \ Macros\ntypedef long long ll;\n#define ALL(x) (x).begin(),(x).end()\nconst long\
    \ long MOD=1000000007;\n// const long long MOD=998244353;\nconst int INF=1e9;\n\
    const long long IINF=1e18;\nconst int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};\nconst\
    \ char dir[4]={'D','R','U','L'};\n\ntemplate<typename T>\nistream &operator>>(istream\
    \ &is,vector<T> &v){\n    for (T &x:v) is >> x;\n    return is;\n}\ntemplate<typename\
    \ T>\nostream &operator<<(ostream &os,const vector<T> &v){\n    for (int i=0;i<v.size();++i){\n\
    \        os << v[i] << (i+1==v.size()?\"\": \" \");\n    }\n    return os;\n}\n\
    template<typename T,typename U>\nostream &operator<<(ostream &os,const pair<T,U>\
    \ &p){\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate<typename T,typename U>\nostream &operator<<(ostream &os,const map<T,U>\
    \ &m){\n    os << '{';\n    for (auto itr=m.begin();itr!=m.end();++itr){\n   \
    \     os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr!=m.end())\
    \ os << ',';\n        --itr;\n    }\n    os << '}';\n    return os;\n}\ntemplate<typename\
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
    \ return true;} return false;\n}\n#pragma endregion\n#line 6 \"math/extgcd.hpp\"\
    \n\ntemplate<typename T> T extgcd(T a,T b,T &x,T &y){\n    T d=a;\n    if (b!=0){\n\
    \        d=extgcd(b,a%b,y,x);\n        y-=(a/b)*x;\n    } else x=1,y=0;\n    return\
    \ d;\n}\n"
  code: "/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\n */\n\n#include \"../base.hpp\"\n\ntemplate<typename T> T extgcd(T\
    \ a,T b,T &x,T &y){\n    T d=a;\n    if (b!=0){\n        d=extgcd(b,a%b,y,x);\n\
    \        y-=(a/b)*x;\n    } else x=1,y=0;\n    return d;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: math/extgcd.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:03:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/NTL_1_E.test.cpp
documentation_of: math/extgcd.hpp
layout: document
redirect_from:
- /library/math/extgcd.hpp
- /library/math/extgcd.hpp.html
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
