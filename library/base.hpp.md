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
<script type="text/javascript" src="../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../assets/css/copy-button.css" />


# :question: base.hpp

<a href="../index.html">Back to top page</a>

* category: <a href="../index.html#5058f1af8388633f609cadb75a75dc9d">.</a>
* <a href="{{ site.github.repository_url }}/blob/master/base.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## Required by

* :warning: <a href="convolution/FastFourierTransform.hpp.html">Fast Fourier Transform <small>(convolution/FastFourierTransform.hpp)</small></a>
* :warning: <a href="convolution/NumberTheoreticTransform.hpp.html">Number Theoretic Transform <small>(convolution/NumberTheoreticTransform.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/BinaryIndexedTree.hpp.html">Binary Indexed Tree <small>(datastructure/BinaryIndexedTree.hpp)</small></a>
* :warning: <a href="datastructure/BinaryTrie.hpp.html">Binary Trie <small>(datastructure/BinaryTrie.hpp)</small></a>
* :warning: <a href="datastructure/ConvexHullTrick.hpp.html">Convex Hull Trick <small>(datastructure/ConvexHullTrick.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/CumulativeSum2D.hpp.html">2次元累積和 <small>(datastructure/CumulativeSum2D.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/DualSegmentTree.hpp.html">Dual Segment Tree <small>(datastructure/DualSegmentTree.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/LazySegmentTree.hpp.html">Lazy Segment Tree <small>(datastructure/LazySegmentTree.hpp)</small></a>
* :warning: <a href="datastructure/PartiallyPersistentUnionFind.hpp.html">Partially Persistent UnionFind <small>(datastructure/PartiallyPersistentUnionFind.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/SegmentTree.hpp.html">Segment Tree <small>(datastructure/SegmentTree.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/SegmentTreeBeats.hpp.html">Segment Tree Beats <small>(datastructure/SegmentTreeBeats.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/Slide_Min.hpp.html">スライド最小値 <small>(datastructure/Slide_Min.hpp)</small></a>
* :warning: <a href="datastructure/SlidingWindowAggregation.hpp.html">Sliding Window Aggregation (SWAG) <small>(datastructure/SlidingWindowAggregation.hpp)</small></a>
* :warning: <a href="datastructure/SparseTable.hpp.html">Sparse table <small>(datastructure/SparseTable.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/UnionFind.hpp.html">UnionFind <small>(datastructure/UnionFind.hpp)</small></a>
* :heavy_check_mark: <a href="datastructure/WeightedUnionFind.hpp.html">Weighted UnionFind <small>(datastructure/WeightedUnionFind.hpp)</small></a>
* :heavy_check_mark: <a href="graph/Dijkstra.hpp.html">Dijkstra <small>(graph/Dijkstra.hpp)</small></a>
* :heavy_check_mark: <a href="graph/LowLink.hpp.html">Low Link (橋/関節点) <small>(graph/LowLink.hpp)</small></a>
* :heavy_check_mark: <a href="graph/StronglyConnectedComponents.hpp.html">Strongly Connected Components <small>(graph/StronglyConnectedComponents.hpp)</small></a>
* :heavy_check_mark: <a href="graph/TopologicalSort.hpp.html">Topological Sort <small>(graph/TopologicalSort.hpp)</small></a>
* :warning: <a href="graph/TwoEdgeConnectedComponents.hpp.html">Two Edge Connected Components <small>(graph/TwoEdgeConnectedComponents.hpp)</small></a>
* :x: <a href="graph/WarshallFloyd.hpp.html">Warshall Floyd <small>(graph/WarshallFloyd.hpp)</small></a>
* :warning: <a href="modulo/modint.hpp.html">modint <small>(modulo/modint.hpp)</small></a>
* :warning: <a href="modulo/runtime_modint.hpp.html">実行時 modint <small>(modulo/runtime_modint.hpp)</small></a>
* :warning: <a href="test/aoj/DSL_3_D.SlidingWindowAggregation.cpp.html">test/aoj/DSL_3_D.SlidingWindowAggregation.cpp</a>
* :heavy_check_mark: <a href="tree/HeavyLightDecomposition.hpp.html">Heavy Light Decomposition <small>(tree/HeavyLightDecomposition.hpp)</small></a>
* :heavy_check_mark: <a href="tree/LowestCommonAncestor.hpp.html">Lowest Common Ancestor <small>(tree/LowestCommonAncestor.hpp)</small></a>
* :heavy_check_mark: <a href="tree/TreeDiameter.hpp.html">Tree Diameter <small>(tree/TreeDiameter.hpp)</small></a>
* :warning: <a href="util/compress.hpp.html">compress <small>(util/compress.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../verify/test/aoj/2667.test.cpp.html">test/aoj/2667.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_1_A.test.cpp.html">test/aoj/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_D.DualSegmentTree.test.cpp.html">test/aoj/DSL_2_D.DualSegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_E.DualSegmentTree.test.cpp.html">test/aoj/DSL_2_E.DualSegmentTree.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_G.test.cpp.html">test/aoj/DSL_2_G.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_H.test.cpp.html">test/aoj/DSL_2_H.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_2_I.test.cpp.html">test/aoj/DSL_2_I.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_3_D.test.cpp.html">test/aoj/DSL_3_D.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/DSL_5_B.test.cpp.html">test/aoj/DSL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>
* :x: <a href="../verify/test/aoj/GRL_1_C.test.cpp.html">test/aoj/GRL_1_C.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_3_A.test.cpp.html">test/aoj/GRL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_3_B.test.cpp.html">test/aoj/GRL_3_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_4_B.test.cpp.html">test/aoj/GRL_4_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_5_A.test.cpp.html">test/aoj/GRL_5_A.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_5_B.test.cpp.html">test/aoj/GRL_5_B.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp.html">test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>
* :heavy_check_mark: <a href="../verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp.html">test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../index.html">Back to top page</a>

