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


# :heavy_check_mark: Segment Tree Beats <small>(datastructure/SegmentTreeBeats.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/SegmentTreeBeats.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 18:32:52+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp.html">test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Segment Tree Beats
 * @docs docs/datastructure/LazySegmentTree.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
class SegmentTreeBeats{
    int n;
    static const T idm=numeric_limits<T>::min();
    static const T idM=numeric_limits<T>::max(),idl=idM;
    struct Node{
        T Max,Max_second,Min,Min_second,sum,laz_add,laz_val;
        int Max_count,Min_count,len;
        Node():Max(idm),Max_second(idm),Min(idM),Min_second(idM)
            ,laz_add(0),laz_val(idl),len(1){}
    };
    vector<Node> Nodes;
    inline void calc(int k){
        Node &p=Nodes[k];
        Node l=Nodes[(k<<1)+1],r=Nodes[(k<<1)+2];
        p.sum=l.sum+r.sum;
        if (l.Max<r.Max){
            p.Max=r.Max;
            p.Max_count=r.Max_count;
            p.Max_second=max(l.Max,r.Max_second);
        } else if (r.Max<l.Max){
            p.Max=l.Max;
            p.Max_count=l.Max_count;
            p.Max_second=max(l.Max_second,r.Max);
        } else {
            p.Max=l.Max;
            p.Max_count=l.Max_count+r.Max_count;
            p.Max_second=max(l.Max_second,r.Max_second);
        }
        if (l.Min<r.Min){
            p.Min=l.Min;
            p.Min_count=l.Min_count;
            p.Min_second=min(l.Min_second,r.Min);
        } else if (r.Min<l.Min){
            p.Min=r.Min;
            p.Min_count=r.Min_count;
            p.Min_second=min(l.Min,r.Min_second);
        } else {
            p.Min=l.Min;
            p.Min_count=l.Min_count+r.Min_count;
            p.Min_second=min(l.Min_second,r.Min_second);
        }
    }
    inline void update_node_min(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Max)*node.Max_count;
        if (node.Max==node.Min) node.Max=node.Min=x;
        else if (node.Max==node.Min_second) node.Max=node.Min_second=x;
        else node.Max=x;
        if (node.laz_val!=idl&&node.laz_val<x) node.laz_val=x;
    }
    inline void update_node_max(int k,T x){
        Node &node=Nodes[k];
        node.sum+=(x-node.Min)*node.Min_count;
        if (node.Min==node.Max) node.Min=node.Max=x;
        else if (node.Min==node.Max_second) node.Min=node.Max_second=x;
        else node.Min=x;
        if (node.laz_val!=idl&&x<node.laz_val) node.laz_val=x;
    }
    inline void update_node_add(int k,T x){
        Node &node=Nodes[k];
        node.Max+=x;
        if (node.Max_second!=idm) node.Max_second+=x;
        node.Min+=x;
        if (node.Min_second!=idM) node.Min_second+=x;
        node.sum+=x*node.len;
        (node.laz_val!=idl?node.laz_val:node.laz_add)+=x;
    }
    inline void update_node_val(int k,T x){
        Node &node=Nodes[k];
        node.Max=x; node.Max_second=idm;
        node.Min=x; node.Min_second=idM;
        node.Max_count=node.Min_count=node.len;
        node.sum=x*node.len;
        node.laz_val=x; node.laz_add=0;
    }
    inline void propagate(int k){
        if (k>=n-1) return;
        Node &node=Nodes[k];
        if (node.laz_val!=idl){
            update_node_val((k<<1)+1,node.laz_val);
            update_node_val((k<<1)+2,node.laz_val);
            node.laz_val=idl; return;
        }
        if (node.laz_add!=0){
            update_node_add((k<<1)+1,node.laz_add);
            update_node_add((k<<1)+2,node.laz_add);
            node.laz_add=0;
        }
        if (node.Max<Nodes[(k<<1)+1].Max) update_node_min((k<<1)+1,node.Max);
        if (node.Max<Nodes[(k<<1)+2].Max) update_node_min((k<<1)+2,node.Max);
        if (Nodes[(k<<1)+1].Min<node.Min) update_node_max((k<<1)+1,node.Min);
        if (Nodes[(k<<1)+2].Min<node.Min) update_node_max((k<<1)+2,node.Min);
    }
    inline void update_min(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||Nodes[k].Max<=x) return;
        if (a<=l&&r<=b&&Nodes[k].Max_second<x){
            update_node_min(k,x); return;
        }
        propagate(k);
        update_min(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_min(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_max(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a||x<=Nodes[k].Min) return;
        if (a<=l&&r<=b&&x<Nodes[k].Min_second){
            update_node_max(k,x); return;
        }
        propagate(k);
        update_max(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_max(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_add(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_add(k,x); return;
        }
        propagate(k);
        update_add(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_add(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline void update_val(int a,int b,T x,int k,int l,int r){
        if (b<=l||r<=a) return;
        if (a<=l&&r<=b){
            update_node_val(k,x); return;
        }
        propagate(k);
        update_val(a,b,x,(k<<1)+1,l,(l+r)>>1);
        update_val(a,b,x,(k<<1)+2,(l+r)>>1,r);
        calc(k);
    }
    inline T query_min(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idM;
        if (a<=l&&r<=b) return Nodes[k].Min;
        propagate(k);
        T vl=query_min(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_min(a,b,(k<<1)+2,(l+r)>>1,r);
        return min(vl,vr);
    }
    inline T query_max(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return idm;
        if (a<=l&&r<=b) return Nodes[k].Max;
        propagate(k);
        T vl=query_max(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_max(a,b,(k<<1)+2,(l+r)>>1,r);
        return max(vl,vr);
    }
    inline T query_sum(int a,int b,int k,int l,int r){
        if (b<=l||r<=a) return 0;
        if (a<=l&&r<=b) return Nodes[k].sum;
        propagate(k);
        T vl=query_sum(a,b,(k<<1)+1,l,(l+r)>>1);
        T vr=query_sum(a,b,(k<<1)+2,(l+r)>>1,r);
        return vl+vr;
    }
public:
    SegmentTreeBeats(int n_){init(n_);}
    void init(int n_){
        n=1;
        while(n<n_) n<<=1;
        Nodes.resize(n<<1);
    }
    void build(const vector<T> &v){
        for (int i=0;i<v.size();++i){
            Nodes[i+n-1].Max=Nodes[i+n-1].Min=Nodes[i+n-1].sum=v[i];
            Nodes[i+n-1].Max_count=Nodes[i+n-1].Min_count=Nodes[i+n-1].len=1;
        }
        for (int i=n-2;i>=0;--i){
            calc(i);
            Nodes[i].len=Nodes[(i<<1)+1].len+Nodes[(i<<1)+2].len;
        }
    }
    void update_min(int a,int b,T x){update_min(a,b,x,0,0,n);}
    void update_max(int a,int b,T x){update_max(a,b,x,0,0,n);}
    void update_add(int a,int b,T x){update_add(a,b,x,0,0,n);}
    void update_val(int a,int b,T x){update_val(a,b,x,0,0,n);}
    T query_min(int a,int b){return query_min(a,b,0,0,n);}
    T query_max(int a,int b){return query_max(a,b,0,0,n);}
    T query_sum(int a,int b){return query_sum(a,b,0,0,n);}
    T operator[](int i){return query_sum(i,i+1);}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/SegmentTreeBeats.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

