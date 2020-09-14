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


# :heavy_check_mark: 実行時 modint <small>(modulo/runtime_modint.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5dcb4a1ea5a35da52691d50c8313c333">modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulo/runtime_modint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:23:12+09:00




## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/526.test.cpp.html">test/yukicoder/526.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 実行時 modint
 */

#pragma once

#include "../base.hpp"

class runtime_modint{
    using u64=uint_fast64_t;
    static u64 &mod(){
        static u64 mod_=0;
        return mod_;
    }
public:
    u64 a;
    static void set_mod(const u64 x){mod()=x;}
    static u64 get_mod(){return mod();}
    runtime_modint(const u64 x=0):a(x%get_mod()){}
    u64 &balue() noexcept{return a;}
    const u64 &value() const noexcept{return a;}
    runtime_modint &operator+=(const runtime_modint &rhs){
        a+=rhs.a;
        if (a>=get_mod()) a-=get_mod();
        return *this;
    }
    runtime_modint operator+(const runtime_modint &rhs) const{
        return runtime_modint(*this)+=rhs;
    }
    runtime_modint &operator-=(const runtime_modint &rhs){
        if (a<rhs.a) a+=get_mod();
        a-=rhs.a;
        return *this;
    }
    runtime_modint operator-(const runtime_modint &rhs) const{
        return runtime_modint(*this)-=rhs;
    }
    runtime_modint &operator*=(const runtime_modint &rhs){
        a=a*rhs.a%get_mod();
        return *this;
    }
    runtime_modint operator*(const runtime_modint &rhs) const{
        return runtime_modint(*this)*=rhs;
    }
    runtime_modint &operator/=(runtime_modint rhs){
        u64 exp=get_mod()-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    runtime_modint operator/(const runtime_modint &rhs) const{
        return runtime_modint(*this)/=rhs;
    }
    friend runtime_modint pow(runtime_modint rhs,long long exp) noexcept{
        runtime_modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    friend ostream &operator<<(ostream &s,const runtime_modint &rhs){
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,runtime_modint &rhs){
        u64 a; rhs=runtime_modint{(s >> a,a)}; return s;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: modulo/runtime_modint.hpp: line 5: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

