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


# :x: test/yosupo/static_range_inversions_query.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/static_range_inversions_query.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-15 13:26:33+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_inversions_query">https://judge.yosupo.jp/problem/static_range_inversions_query</a>


## Depends on

* :question: <a href="../../../library/base.hpp.html">base.hpp</a>
* :question: <a href="../../../library/datastructure/BinaryIndexedTree.hpp.html">Binary Indexed Tree <small>(datastructure/BinaryIndexedTree.hpp)</small></a>
* :x: <a href="../../../library/other/Mo.hpp.html">Mo's Algorithm <small>(other/Mo.hpp)</small></a>
* :x: <a href="../../../library/util/compress.hpp.html">compress <small>(util/compress.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../base.hpp"
#include "../../util/compress.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../other/Mo.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i=0;i<N;++i) cin >> A[i];

    Mo mo(N);
    for (int i=0;i<Q;++i){
        int l,r; cin >> l >> r;
        mo.insert(l,r);
    }

    map<int,int> mp=dict(compress(A));
    for (int i=0;i<N;++i) A[i]=mp[A[i]];
    int n=mp.size();
    BinaryIndexedTree<int> BIT(n+1);
    vector<long long> ans(Q);
    long long inv=0; int sum=0;
    auto add_left=[&](int idx){
        inv+=BIT.sum0(A[idx]-1);
        ++sum; BIT.add0(A[idx],1);
    };
    auto add_right=[&](int idx){
        inv+=sum-BIT.sum0(A[idx]);
        ++sum; BIT.add0(A[idx],1);
    };
    auto del_left=[&](int idx){
        inv-=BIT.sum0(A[idx]-1);
        --sum; BIT.add0(A[idx],-1);
    };
    auto del_right=[&](int idx){
        inv-=sum-BIT.sum0(A[idx]);
        --sum; BIT.add0(A[idx],-1);
    };
    auto rem=[&](int idx){
        ans[idx]=inv;
    };

    mo.build(add_left,add_right,del_left,del_right,rem);

    for (int i=0;i<Q;++i) cout << ans[i] << '\n';
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: util/compress.hpp: line 5: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

