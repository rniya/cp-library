---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :x: Eulerのφ関数 <small>(math/euler_phi.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/euler_phi.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:03:02+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :x: <a href="../../verify/test/aoj/NTL_1_D.test.cpp.html">test/aoj/NTL_1_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Eulerのφ関数
 * @docs docs/math/euler_phi.md
 */

#include "../base.hpp"

template<typename T>
T euler_phi(T n){
    T res=n;
    for (T i=2;i*i<=n;++i) if (n%i==0){
        res-=res/i;
        while (n%i==0) n/=i;
    }
    if (n!=1) res-=res/n;
    return res;
}
vector<int> euler_phi_table(int n){
    vector<int> euler(n+1);
    iota(euler.begin(),euler.end(),0);
    for (int i=2;i<=n;++i) if (euler[i]==i){
        for (int j=i;j<=n;j+=i) euler[j]-=euler[j]/i;
    }
    return euler;
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/euler_phi.hpp"
/**
 * @brief Eulerのφ関数
 * @docs docs/math/euler_phi.md
 */

#line 2 "base.hpp"

#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1000000007;
// const long long MOD=998244353;
const int INF=1e9;
const long long IINF=1e18;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
const char dir[4]={'D','R','U','L'};

template<typename T>
istream &operator>>(istream &is,vector<T> &v){
    for (T &x:v) is >> x;
    return is;
}
template<typename T>
ostream &operator<<(ostream &os,const vector<T> &v){
    for (int i=0;i<v.size();++i){
        os << v[i] << (i+1==v.size()?"": " ");
    }
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const pair<T,U> &p){
    os << '(' << p.first << ',' << p.second << ')';
    return os;
}
template<typename T,typename U>
ostream &operator<<(ostream &os,const map<T,U> &m){
    os << '{';
    for (auto itr=m.begin();itr!=m.end();++itr){
        os << '(' << itr->first << ',' << itr->second << ')';
        if (++itr!=m.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os,const set<T> &s){
    os << '{';
    for (auto itr=s.begin();itr!=s.end();++itr){
        os << *itr;
        if (++itr!=s.end()) os << ',';
        --itr;
    }
    os << '}';
    return os;
}

void debug_out(){cerr << '\n';}
template<class Head,class... Tail>
void debug_out(Head&& head,Tail&&... tail){
    cerr << head;
    if (sizeof...(Tail)>0) cerr << ", ";
    debug_out(move(tail)...);
}
#ifdef LOCAL
#define debug(...) cerr << " ";\
cerr << #__VA_ARGS__ << " :[" << __LINE__ << ":" << __FUNCTION__ << "]" << '\n';\
cerr << " ";\
debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

template<class T1,class T2> inline bool chmin(T1 &a,T2 b){
    if (a>b){a=b; return true;} return false;
}
template<class T1,class T2> inline bool chmax(T1 &a,T2 b){
    if (a<b){a=b; return true;} return false;
}
#pragma endregion
#line 7 "math/euler_phi.hpp"

template<typename T>
T euler_phi(T n){
    T res=n;
    for (T i=2;i*i<=n;++i) if (n%i==0){
        res-=res/i;
        while (n%i==0) n/=i;
    }
    if (n!=1) res-=res/n;
    return res;
}
vector<int> euler_phi_table(int n){
    vector<int> euler(n+1);
    iota(euler.begin(),euler.end(),0);
    for (int i=2;i<=n;++i) if (euler[i]==i){
        for (int j=i;j<=n;j+=i) euler[j]-=euler[j]/i;
    }
    return euler;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

