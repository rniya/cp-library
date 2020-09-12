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


# :heavy_check_mark: Primal Dual <small>(flow/PrimalDual.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/PrimalDual.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 21:18:12+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_B.PrimalDual.test.cpp.html">test/aoj/GRL_6_B.PrimalDual.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Primal Dual
 * @docs docs/flow/PrimalDual.md
 */

#pragma once

#include "../base.hpp"

template<typename T,typename E>
struct PrimalDual{
    const E inf=numeric_limits<E>::max();
    struct edge{
        int to,rev; T cap; E cost;
        edge(int to,T cap,E cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<pair<int,int>> pos;
    vector<E> h,dist;
    vector<int> prevv,preve;
    PrimalDual(int n):G(n),h(n),dist(n),prevv(n),preve(n){}
    int add_edge(int from,int to,T cap,E cost){
        pos.emplace_back(from,G[from].size());
        G[from].emplace_back(to,cap,cost,G[to].size());
        G[to].emplace_back(from,0,-cost,G[from].size()-1);
        return pos.size()-1;
    }
    tuple<int,int,int,int,int> get_edge(int i){
        auto e=G[pos[i].first][pos[i].second];
        auto re=G[e.to][e.rev];
        return {e.from,e.to,e.cap+re.cap,re.cap,e.cost};
    }
    void dijkstra(int s){
        struct P{
            E c; int v;
            P(E c,int v):c(c),v(v){}
            bool operator<(const P &rhs) const {return c>rhs.c;}
        };
        priority_queue<P> pq;
        fill(dist.begin(),dist.end(),inf);
        dist[s]=0; pq.emplace(dist[s],s);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.v;
            if (dist[v]<p.c) continue;
            for (int i=0;i<G[v].size();++i){
                auto &e=G[v][i];
                if (e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v; preve[e.to]=i;
                    pq.emplace(dist[e.to],e.to);
                }
            }
        }
    }
    vector<pair<T,E>> slope(int s,int t,T lim){
        T f=0; E c=0,pre=-1;
        vector<pair<T,E>> res;
        res.emplace_back(f,c);
        while(f<lim){
            dijkstra(s);
            if (dist[t]==inf) break;
            for (int v=0;v<G.size();++v) h[v]+=dist[v];
            T d=lim-f;
            for (int v=t;v!=s;v=prevv[v]){
                d=min(d,G[prevv[v]][preve[v]].cap);
            }
            for (int v=t;v!=s;v=prevv[v]){
                auto &e=G[prevv[v]][preve[v]];
                e.cap-=d; G[v][e.rev].cap+=d;
            }
            f+=d; c+=h[t]*d;
            if (pre==h[t]) res.pop_back();
            res.emplace_back(f,c);
            pre=c;
        }
        return res;
    }
    E min_cost_flow(int s,int t,T f){
        auto res=slope(s,t,f).back();
        return res.first==f?res.second:-1;
    }
    pair<T,E> min_cost_max_flow(int s,int t){
        return slope(s,t,numeric_limits<T>::max()).back();
    }
    vector<pair<T,E>> min_cost_slope(int s,int t){
        return slope(s,t,numeric_limits<T>::max());
    }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/PrimalDual.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

