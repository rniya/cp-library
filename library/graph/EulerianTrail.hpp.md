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


# :heavy_check_mark: オイラーグラフ・準オイラーグラフの構築 <small>(graph/EulerianTrail.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/EulerianTrail.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:00:32+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/583.test.cpp.html">test/yukicoder/583.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief オイラーグラフ・準オイラーグラフの構築
 * @docs docs/graph/EulerianTrail.md
 */

#pragma once

#include "../base.hpp"

template<bool directed>
struct EulerianTrail{
    vector<vector<pair<int,int>>> G;
    vector<vector<int>> BG;
    vector<pair<int,int>> es;
    vector<int> used,visited,deg;
    EulerianTrail(int n):G(n),BG(n),visited(n,0),deg(n,0){}
    void add_edge(int u,int v){
        int m=es.size();
        es.emplace_back(u,v);
        used.emplace_back(0);
        BG[u].emplace_back(v);
        BG[v].emplace_back(u);
        G[u].emplace_back(v,m);
        ++deg[u];
        if (directed) --deg[v];
        else G[v].emplace_back(u,m),++deg[v];
    }
    void dfs(int v,int &s,int &t,int &check){
        visited[v]=1;
        if (directed){
            if (abs(deg[v])>1) check=0;
            else if (deg[v]==1){
                if (~s) check=0;
                else s=v;
            }
        } else {
            if (deg[v]&1){
                if (s<0) s=v;
                else if (t<0) t=v;
                else check=0;
            }
        }
        for (int u:BG[v]){
            if (visited[u]) continue;
            dfs(u,s,t,check);
        }
    }
    vector<int> go(int s){
        stack<pair<int,int>> st;
        vector<int> ord;
        st.emplace(s,-1);
        while(!st.empty()){
            int v=st.top().first;
            visited[v]=1;
            if (G[v].empty()){
                ord.emplace_back(st.top().second);
                st.pop();
            } else {
                auto e=G[v].back(); G[v].pop_back();
                if (used[e.second]) continue;
                used[e.second]=1;
                st.emplace(e);
            }
        }
        ord.pop_back();
        reverse(ord.begin(),ord.end());
        return ord;
    }
    vector<vector<int>> build(){
        for (int i=0;i<G.size();++i){
            if (directed&&deg[i]!=0) return {};
            if (!directed&&(deg[i]&1)) return {};
        }
        vector<vector<int>> res;
        for (int i=0;i<G.size();++i){
            if (G[i].empty()||visited[i]) continue;
            res.emplace_back(go(i));
        }
        return res;
    }
    vector<vector<int>> build_semi(){
        vector<vector<int>> res;
        for (int i=0;i<G.size();++i){
            if (visited[i]) continue;
            int s=-1,t=-1,check=1;
            dfs(i,s,t,check);
            if (!check) return {};
            res.emplace_back(go(~s?s:i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }
    pair<int,int> operator[](int i){return es[i];}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/EulerianTrail.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

