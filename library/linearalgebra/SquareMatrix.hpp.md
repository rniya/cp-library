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


# :warning: Square Matrix <small>(linearalgebra/SquareMatrix.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#1bbf1d9f5340fa94bf2c5fb5ce73a5f5">linearalgebra</a>
* <a href="{{ site.github.repository_url }}/blob/master/linearalgebra/SquareMatrix.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:00:32+09:00




## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Square Matrix
 * @docs docs/linearalgebra/Squarematrix.md
 */

#pragma once

#include "../base.hpp"

template<class K,size_t N>
struct SquareMatrix{
    array<array<K,N>,N> dat;
    SquareMatrix(){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                dat[i][j]=K();
    }
    size_t size() const{return N;}
    array<K,N> &operator[](size_t i){return dat[i];}
    const array<K,N> &operator[](size_t i) const{return dat[i];}
    static SquareMatrix I(){
        SquareMatrix res;
        for (size_t i=0;i<N;++i) res[i][i]=K(1);
        return res;
    }
    SquareMatrix &operator+=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]+=B[i][j];
        return (*this);
    }
    SquareMatrix operator+(const SquareMatrix &B) const{
        return SquareMatrix(*this)+=B;
    }
    SquareMatrix &operator-=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]-=B[i][j];
        return (*this);
    }
    SquareMatrix operator-(const SquareMatrix &B) const{
        return SquareMatrix(*this)-=B;
    }
    SquareMatrix &operator*=(const SquareMatrix &B){
        SquareMatrix res;
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                for (size_t k=0;k<N;++k)
                    res[i][j]+=(*this)[i][k]*B[k][j];
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator*(const SquareMatrix &B) const{
        return SquareMatrix(*this)*=B;
    }
    SquareMatrix &operator^=(long long k){
        SquareMatrix res=I();
        while(k){
            if (k&1LL) res*=*this;
            *this*=*this; k>>=1LL;
        }
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator^(long long k) const{
        return SquareMatrix(*this)^=k;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linearalgebra/SquareMatrix.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

