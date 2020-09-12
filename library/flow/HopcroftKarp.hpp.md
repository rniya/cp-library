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


# :heavy_check_mark: Hopcroft Karp <small>(flow/HopcroftKarp.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/HopcroftKarp.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 12:22:43+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_7_A.HopcroftKarp.test.cpp.html">test/aoj/GRL_7_A.HopcroftKarp.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Hopcroft Karp
 * @docs docs/flow/HopcroftKarp
 */

#pragma once

#include "../base.hpp"

struct HopcroftKarp{
private:
    int n,m,time;
    vector<vector<int>> G,rG;
    vector<int> match_l,match_r,level,used;
    void bfs(){
        fill(level.begin(),level.end(),-1);
        queue<int> que;
        for (int i=0;i<n;++i){
            if (match_l[i]==-1){
                level[i]=0;
                que.emplace(i);
            }
        }
        while(!que.empty()){
            int v=que.front(); que.pop();
            for (int u:G[v]){
                int w=match_r[u];
                if (~w&&level[w]<0){
                    level[w]=level[v]+1;
                    que.emplace(w);
                }
            }
        }
    }
    bool dfs(int v){
        used[v]=time;
        for (int u:G[v]){
            int w=match_r[u];
            if (w<0||(used[w]!=time&&level[w]==level[v]+1&&dfs(w))){
                match_r[u]=v; match_l[v]=u;
                return true;
            }
        }
        return false;
    }
public:
    HopcroftKarp(int n,int m):n(n),m(m),G(n),rG(m),match_l(n,-1),match_r(m,-1),level(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    vector<pair<int,int>> max_matching(){
        while(1){
            bfs(); ++time;
            int f=0;
            for (int i=0;i<n;++i){
                if (match_l[i]<0){
                    f+=dfs(i);
                }
            }
            if (!f) break;
        }
        vector<pair<int,int>> res;
        for (int i=0;i<n;++i){
            if (match_l[i]>=0){
                res.emplace_back(i,match_l[i]);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/HopcroftKarp.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

