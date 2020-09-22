---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: math/euler_phi.hpp
    title: "Euler\u306E\u03C6\u95A2\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#line 2 \"base.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n#define\
    \ LOCAL\n#pragma region Macros\ntypedef long long ll;\n#define ALL(x) (x).begin(),(x).end()\n\
    const long long MOD=1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF=1e9;\nconst long long IINF=1e18;\nconst int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};\n\
    const char dir[4]={'D','R','U','L'};\n\ntemplate<typename T>\nistream &operator>>(istream\
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
    \ return true;} return false;\n}\n#pragma endregion\n#line 1 \"math/euler_phi.hpp\"\
    \n/**\n * @brief Euler\u306E\u03C6\u95A2\u6570\n * @docs docs/math/euler_phi.md\n\
    \ */\n\n#line 7 \"math/euler_phi.hpp\"\n\ntemplate<typename T>\nT euler_phi(T\
    \ n){\n    T res=n;\n    for (T i=2;i*i<=n;++i) if (n%i==0){\n        res-=res/i;\n\
    \        while (n%i==0) n/=i;\n    }\n    if (n!=1) res-=res/n;\n    return res;\n\
    }\nvector<int> euler_phi_table(int n){\n    vector<int> euler(n+1);\n    iota(euler.begin(),euler.end(),0);\n\
    \    for (int i=2;i<=n;++i) if (euler[i]==i){\n        for (int j=i;j<=n;j+=i)\
    \ euler[j]-=euler[j]/i;\n    }\n    return euler;\n};\n#line 5 \"test/aoj/NTL_1_D.test.cpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\
    \ cin >> n;\n\n    cout << euler_phi(n) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../math/euler_phi.hpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n; cin >>\
    \ n;\n\n    cout << euler_phi(n) << '\\n';\n}"
  dependsOn:
  - base.hpp
  - math/euler_phi.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-10 15:23:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---
