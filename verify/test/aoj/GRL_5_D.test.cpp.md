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


# :heavy_check_mark: test/aoj/GRL_5_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_5_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 12:32:51+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D</a>


## Depends on

* :question: <a href="../../../library/base.hpp.html">base.hpp</a>
* :question: <a href="../../../library/datastructure/BinaryIndexedTree.hpp.html">Binary Indexed Tree <small>(datastructure/BinaryIndexedTree.hpp)</small></a>
* :heavy_check_mark: <a href="../../../library/tree/EulerTourforEdge.hpp.html">Euler Tour (パスに対する操作) <small>(tree/EulerTourforEdge.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../tree/EulerTourforEdge.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    EulerTourforEdge ET(n);
    for (int i=0;i<n;++i){
        int k; cin >> k;
        for (;k--;){
            int c; cin >> c;
            ET.add_edge(i,c);
        }
    }

    ET.build();
    BinaryIndexedTree<int> BIT(2*n);
    auto f=[&](int l,int r){return BIT.query0(l,r);};
    auto g=[&](int k,int w){BIT.add0(k,w);};

    int q; cin >> q;
    for (;q--;){
        int t; cin >> t;
        if (!t){
            int v,w; cin >> v >> w;
            ET.update(v,w,g);
        } else {
            int u; cin >> u;
            cout << ET.query<int>(u,f) << '\n';
        }
    }
}
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/BinaryIndexedTree.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

