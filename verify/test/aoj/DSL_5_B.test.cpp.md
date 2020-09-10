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


# :heavy_check_mark: test/aoj/DSL_5_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_5_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B">https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../../library/datastructure/CumulativeSum2D.hpp.html">2次元累積和 <small>(datastructure/CumulativeSum2D.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "../../base.hpp"
#include "../../datastructure/CumulativeSum2D.hpp"

const int MAX_X=1010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<vector<int>> v(MAX_X,vector<int>(MAX_X,0));
    for (;N--;){
        int a,b,c,d; cin >> a >> b >> c >> d;
        ++v[a][b]; ++v[c][d]; --v[a][d]; --v[c][b];
    }

    CumulativeSum2D<int> CS(v);
    int ans=0;
    for (int i=0;i<MAX_X;++i){
        for (int j=0;j<MAX_X;++j){
            ans=max(ans,CS.query(0,i,0,j));
        }
    }

    cout << ans << '\n';
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/CumulativeSum2D.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
