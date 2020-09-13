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


# :heavy_check_mark: 最小費用流 <small>(flow/MinCostFlow.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/MinCostFlow.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 20:30:44+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_6_B.test.cpp.html">test/aoj/GRL_6_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 最小費用流
 * @docs docs/flow/MinCostFlow.md
 */

#pragma once

#include "../base.hpp"

template<typename T,typename E>
struct MinCostFlow{
    const E inf=numeric_limits<E>::max();
    struct edge{
        int to,rev; T cap; E cost;
        edge(int to,T cap,E cost,int rev):to(to),cap(cap),cost(cost),rev(rev){}
    };
    vector<vector<edge>> G;
    vector<pair<int,int>> pos;
    vector<E> dist;
    vector<int> prevv,preve;
    MinCostFlow(int n):G(n),dist(n),prevv(n),preve(n){}
    int add_edge(int from,int to,T cap,E cost){
        pos.emplace_back(from,G[from].size());
        G[from].emplace_back(to,cap,cost,G[to].size());
        G[to].emplace_back(from,0,-cost,G[from].size()-1);
        return pos.size()-1;
    }
    tuple<int,int,int,int,int> get_edge(int i){
        auto e=G[pos[i].first][pos[i].second];
        auto re=G[e.to][e.rev];
        return {pos[i].first,e.to,e.cap+re.cap,re.cap,e.cost};
    }
    vector<tuple<int,int,int,int,int>> edges(){
        vector<tuple<int,int,int,int,int>> res;
        for (int i=0;i<pos.size();++i){
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    E min_cost_flow(int s,int t,T f){
        E res=0;
        while(f>0){
            fill(dist.begin(),dist.end(),inf);
            dist[s]=0;
            bool update=true;
            while(update){
                update=false;
                for (int v=0;v<G.size();++v){
                    if (dist[v]==inf) continue;
                    for (int i=0;i<G[v].size();++i){
                        edge &e=G[v][i];
                        if (e.cap>0&&dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to]=v; preve[e.to]=i;
                            update=true;
                        }
                    }
                }
            }
            if (dist[t]==inf) return -1;
            T d=f;
            for (int v=t;v!=s;v=prevv[v]){
                d=min(d,G[prevv[v]][preve[v]].cap);
            }
            f-=d;
            res+=dist[t]*d;
            for (int v=t;v!=s;v=prevv[v]){
                edge &e=G[prevv[v]][preve[v]];
                e.cap-=d; G[v][e.rev].cap+=d;
            }
        }
        return res;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/MinCostFlow.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

