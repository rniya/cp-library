---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/math/sum_of_multiplicative_function.hpp\"\n#include\
    \ <cmath>\n#include <vector>\n\ntemplate <typename T, T (*f)(long long, long long)>\
    \ struct sum_of_multiplicative_function {\n    sum_of_multiplicative_function(long\
    \ long N) : N(N), sqN(sqrtl(N)) {\n        std::vector<bool> is_prime(sqN + 1,\
    \ true);\n        for (int i = 2; i <= sqN; i++) {\n            if (not is_prime[i])\
    \ continue;\n            primes.emplace_back(i);\n            for (int j = 2 *\
    \ i; j <= sqN; j += i) is_prime[j] = false;\n        }\n        quotients.emplace_back(0);\n\
    \        for (long long i = N; i > 0; i = N / (N / i + 1)) quotients.emplace_back(i);\n\
    \        len = quotients.size();\n    }\n\n    std::vector<T> counting_primes()\
    \ {\n        return calc([](long long n) -> T { return n; });\n    }\n\n    std::vector<T>\
    \ summing_primes() {\n        return calc([](long long n) -> T { return T(n) *\
    \ (n + 1) / 2; });\n    }\n\n    T solve(const std::vector<T>& S_prime) {\n  \
    \      if (N <= 0) return 0;\n        T res = S_prime[idx(N)] + 1;\n        for\
    \ (int i = 0; i < int(primes.size()); i++) dfs(primes[i], i, 1, 1, res, S_prime);\n\
    \        return res;\n    }\n\n    T sum_of_totient_function() {\n        auto\
    \ S0 = counting_primes();\n        auto S1 = summing_primes();\n        for (int\
    \ i = 0; i < int(S1.size()); i++) S1[i] -= S0[i];\n        return solve(S1);\n\
    \    }\n\n  private:\n    long long N, sqN;\n    int len;\n    std::vector<int>\
    \ primes;\n    std::vector<long long> quotients;\n\n    void dfs(long long n,\
    \ int i, int c, T cur, T& sum, const std::vector<T>& S_prime) {\n        sum +=\
    \ cur * f(primes[i], c + 1);\n        long long lim = N / n;\n        if (1LL\
    \ * primes[i] * primes[i] <= lim) dfs(n * primes[i], i, c + 1, cur, sum, S_prime);\n\
    \        cur *= f(primes[i], c);\n        sum += cur * (S_prime[idx(lim)] - S_prime[idx(primes[i])]);\n\
    \        int j = i + 1;\n        for (; j < int(primes.size()) and 1LL * primes[j]\
    \ * primes[j] <= lim; j++)\n            dfs(n * primes[j], j, 1, cur, sum, S_prime);\n\
    \    }\n\n    template <class G> std::vector<T> calc(G g) {\n        std::vector<T>\
    \ dp(len);\n        for (int i = 1; i < len; i++) dp[i] = g(quotients[i]) - g(1);\n\
    \        for (long long x = 2; x <= sqN; x++) {\n            if (dp[len - x] ==\
    \ dp[len - x + 1]) continue;\n            long long x2 = x * x;\n            T\
    \ pi = dp[len - x + 1], xi = dp[len - x] - dp[len - x + 1];\n            for (long\
    \ long i = 1, n = quotients[i]; i < len and n >= x2; n = quotients[++i]) {\n \
    \               dp[i] -= xi * (dp[i * x <= sqN ? i * x : len - n / x] - pi);\n\
    \            }\n        }\n        return dp;\n    }\n\n    int idx(long long\
    \ n) { return n <= sqN ? len - n : N / n; }\n};\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\ntemplate <typename T,\
    \ T (*f)(long long, long long)> struct sum_of_multiplicative_function {\n    sum_of_multiplicative_function(long\
    \ long N) : N(N), sqN(sqrtl(N)) {\n        std::vector<bool> is_prime(sqN + 1,\
    \ true);\n        for (int i = 2; i <= sqN; i++) {\n            if (not is_prime[i])\
    \ continue;\n            primes.emplace_back(i);\n            for (int j = 2 *\
    \ i; j <= sqN; j += i) is_prime[j] = false;\n        }\n        quotients.emplace_back(0);\n\
    \        for (long long i = N; i > 0; i = N / (N / i + 1)) quotients.emplace_back(i);\n\
    \        len = quotients.size();\n    }\n\n    std::vector<T> counting_primes()\
    \ {\n        return calc([](long long n) -> T { return n; });\n    }\n\n    std::vector<T>\
    \ summing_primes() {\n        return calc([](long long n) -> T { return T(n) *\
    \ (n + 1) / 2; });\n    }\n\n    T solve(const std::vector<T>& S_prime) {\n  \
    \      if (N <= 0) return 0;\n        T res = S_prime[idx(N)] + 1;\n        for\
    \ (int i = 0; i < int(primes.size()); i++) dfs(primes[i], i, 1, 1, res, S_prime);\n\
    \        return res;\n    }\n\n    T sum_of_totient_function() {\n        auto\
    \ S0 = counting_primes();\n        auto S1 = summing_primes();\n        for (int\
    \ i = 0; i < int(S1.size()); i++) S1[i] -= S0[i];\n        return solve(S1);\n\
    \    }\n\n  private:\n    long long N, sqN;\n    int len;\n    std::vector<int>\
    \ primes;\n    std::vector<long long> quotients;\n\n    void dfs(long long n,\
    \ int i, int c, T cur, T& sum, const std::vector<T>& S_prime) {\n        sum +=\
    \ cur * f(primes[i], c + 1);\n        long long lim = N / n;\n        if (1LL\
    \ * primes[i] * primes[i] <= lim) dfs(n * primes[i], i, c + 1, cur, sum, S_prime);\n\
    \        cur *= f(primes[i], c);\n        sum += cur * (S_prime[idx(lim)] - S_prime[idx(primes[i])]);\n\
    \        int j = i + 1;\n        for (; j < int(primes.size()) and 1LL * primes[j]\
    \ * primes[j] <= lim; j++)\n            dfs(n * primes[j], j, 1, cur, sum, S_prime);\n\
    \    }\n\n    template <class G> std::vector<T> calc(G g) {\n        std::vector<T>\
    \ dp(len);\n        for (int i = 1; i < len; i++) dp[i] = g(quotients[i]) - g(1);\n\
    \        for (long long x = 2; x <= sqN; x++) {\n            if (dp[len - x] ==\
    \ dp[len - x + 1]) continue;\n            long long x2 = x * x;\n            T\
    \ pi = dp[len - x + 1], xi = dp[len - x] - dp[len - x + 1];\n            for (long\
    \ long i = 1, n = quotients[i]; i < len and n >= x2; n = quotients[++i]) {\n \
    \               dp[i] -= xi * (dp[i * x <= sqN ? i * x : len - n / x] - pi);\n\
    \            }\n        }\n        return dp;\n    }\n\n    int idx(long long\
    \ n) { return n <= sqN ? len - n : N / n; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/math/sum_of_multiplicative_function.hpp
  requiredBy: []
  timestamp: '2024-08-27 15:05:21+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/sum_of_totient_function.test.cpp
documentation_of: src/math/sum_of_multiplicative_function.hpp
layout: document
title: Sum of Multiplicative Function
---

## 入力

整数 $N$．

## 出力

素数 $p$ に対して $f(p)$ が $p$ についての多項式となるような乗法的関数 $f$ の和 $\sum _ {i = 1} ^ N f(i)$．

ただし，$\mathbb{Z} _ {> 0}$ を定義域とする関数 $f$ が，

- $f(1) = 1$
- $\gcd(a, b) = 1 \implies f(a b) = f(a) f(b)$

を満たすとき，$f$ は乗法的関数 (multiplicative function) であるという．

## 計算量

- 時間計算量 $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$（詳細を後述）
- 空間計算量 $\mathrm{O}(\sqrt{N})$

## 概要

### Black Algorithm

$\mathrm{gpf}(n)$ を $n$ の最大の素因数 (greatest prime factor) とする．

$1$ を根として，$1 < n \le N$ についてその親を $n / \mathrm{gpf}(n)$ とするような $N$ 頂点の木を考える．
この木上の葉でない頂点 $n$ について，その子頂点の集合を $T(n)$ として $\sum _ {t \in T(n)} f(t)$ を求めたい．

小さい方から $k$ 番目の素数を $p _ k$ とする．
$n > 1$ について，$\mathrm{gpf}(n) = p _ l$ とし，$n p _ k \le N$ を満たす最大の $k$ を $r$ とする．
このとき，$T(n) = \{n p _ l, n p _ {l + 1}, \dots , n p _ r\}$ である．
また，$n$ は葉ではなく $n p _ l \le N$ であるから，$p _ l \le \sqrt{N}$ が成立する．
$n = m p _ l ^ c\ (\gcd(m, p) = 1)$ と表せるとき，乗法的関数の性質から，

$$
\begin{aligned}
    \sum _ {t \in T(n)} f(t)
    &= \sum _ {l \le i \le r} f(n p _ i) \\
    &= f(m p _ l ^ {c + 1}) + \sum _ {l + 1 \le i \le r} f(n) f(p _ i) \quad (\because \gcd(n, p _ i) = 1) \\
    &= f(m) f(p _ l ^ {c + 1}) + f(n) \left( S _ \mathrm{prime} \left( \left \lfloor \frac{N}{n} \right \rfloor \right) - S _ \mathrm{prime} (p _ l)\right)
\end{aligned}
$$

として所望の値が計算できる．
ここで，$S _ \mathrm{prime}(n) := \sum _ {p \le n, p \text{ is prime}} f(p)$ と定めた．

### $S _ \mathrm{prime}(n)$ の列挙

$S _ \mathrm{prime}(n)$ の値が必要となる $n$ は $\sqrt{n}$ 以下の素数及び $\left \lfloor \frac{N}{i} \right \rfloor\ (i \ge 1)$ と表せるような計 $\mathrm{O}(\sqrt{N})$ 個である．
素数 $p$ に対して $f(p)$ が $p$ についての多項式であり $f(p) = \sum _ i a _ i p ^ i$ と表せるとき，

$$
S _ \mathrm{prime}(n)
= \sum _ {p \le n, p \text{ is prime}} \sum _ i a _ i p ^ i
= \sum _ i a _ i \sum _ {p \le n, p \text{ is prime}} p ^ i
$$

となるため，$S _ \mathrm{prime} ^ i(n) := \sum _ {p \le n, p \text{ is prime}} p ^ i$ が列挙できれば良い．
これは Counting Primes と同様の動的計画法により可能である．

$f ^ i(n, x)$ を $2$ 以上 $n$ 以下であって，$x$ 以下でふるいをかけた際に残る整数 $p$ についての $p ^ i$ の和の個数と定めると，

$$
S _ \mathrm{prime} ^ i(n) = f ^ i\left( N, \left \lfloor \sqrt{N} \right \rfloor \right)
$$

である．
このとき，

$$
f ^ i(n, x) =
\begin{cases}
    f ^ i(n, x - 1) & (x \text{ is not prime} \lor n < x ^ 2) \\
    f ^ i(n, x - 1) - x ^ i \left( f ^ i \left( \left \lfloor \frac{n}{x} \right \rfloor, x - 1 \right) - S _ \mathrm{prime} ^ i(x - 1) \right) & (\text{o.w.})
\end{cases}
$$

が成立する．
$S _ \mathrm{prime} ^ i(n)$ を求めるにあたり必要となる $f ^ i(n, x)$ の値は $n = \left \lfloor \frac{N}{1} \right \rfloor, \left \lfloor \frac{N}{2} \right \rfloor, \dots , \left \lfloor \frac{N}{N} \right \rfloor$ 及び $x = 1, \dots , \left \lfloor \sqrt{N} \right \rfloor$ のみで，これを動的計画法により計算していく．
ライブラリでは登場頻度の高い $S _ \mathrm{prime} ^ 0(n), S _ \mathrm{prime} ^ 1(n)$ の列挙については補助関数を導入しているが，$2$ 次以上の場合は適宜加える必要がある．

全体の時間計算量について，後半の $S _ \mathrm{prime}(n)$ を求めるパートについては Counting Primes と同じく $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ である．
一方，前半パートの計算量は考えた木の葉でない頂点の数に比例するが，その数は一般には $\mathrm{O}(N ^ {1 - \epsilon})$ となる．
しかし，競技プログラミングで登場する制約内（$N \le 10 ^ {12}$ 程度を想定）では $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ として抑えることができ，実際高速に動作する．

| メンバ関数                  | 効果                                                                                                                                            | 時間計算量                                            |
| --------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------- | ----------------------------------------------------- |
| `counting_primes()`         | $S _ \mathrm{prime}^0(n)$，すなわち $n$ 以下の素数の個数を $\left \lfloor \frac{N}{i} \right \rfloor$ として表せる $n$ について降順に列挙する． | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `summing_primes()`          | $S _ \mathrm{prime}^1(n)$，すなわち $n$ 以下の素数の総和を $\left \lfloor \frac{N}{i} \right \rfloor$ として表せる $n$ について降順に列挙する． | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `solve(S_prime)`            | $S _ \mathrm{prime}$ のテーブルを引数として $\sum _ {i = 1} ^ N f(i)$ を計算する．                                                              | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |
| `sum_of_totient_function()` | $\sum _ {i = 1} ^ N \phi(i)$ を計算する．                                                                                                       | $\mathrm{O}\left( \frac{N ^ {3 / 4}}{\log N} \right)$ |

**$S _ {\mathrm{prime}}$ のテーブルは $S _ \mathrm{prime}^0, S _ \mathrm{prime}^1$ 等の線形結合により各自で計算する必要があることに注意．**

### 乗法的関数の例

- totient 関数 $\phi(n)$


## 出題例
- [第五回日本最強プログラマー学生選手権 -決勝- B - Erase Multiples](https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_b)