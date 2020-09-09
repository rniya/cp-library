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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/DSL_1_A.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_1_A.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 15:10:28+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../../library/datastructure/UnionFind.hpp.html">datastructure/UnionFind.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "../../base.hpp"
#include "../../datastructure/UnionFind.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    UnionFind UF(n);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) UF.merge(x,y);
        else cout << UF.same(x,y) << '\n';
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_1_A.test.cpp"
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#line 2 "base.hpp"
#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#pragma region Macros
typedef long long ll;
#define ALL(x) (x).begin(),(x).end()
const long long MOD=1e9+7;
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
#line 3 "datastructure/UnionFind.hpp"

struct UnionFind{
    int num;
    vector<int> par,rank;
    UnionFind(int n):num(n),par(n),rank(n,1){
        iota(par.begin(),par.end(),0);
    }
    int root(int x){
        return (par[x]==x?x:par[x]=root(par[x]));
    }
    bool merge(int x, int y){
        x=root(x); y=root(y);
        if (x==y) return false;
        if (rank[x]<rank[y]) swap(x,y);
        par[y]=x;
        rank[x]+=rank[y];
        --num;
        return true;
    }
    bool same(int x, int y){return root(x)==root(y);}
    int size(int x){return rank[root(x)];}
    int count(){return num;}
};
#line 5 "test/aoj/DSL_1_A.test.cpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    UnionFind UF(n);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) UF.merge(x,y);
        else cout << UF.same(x,y) << '\n';
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

