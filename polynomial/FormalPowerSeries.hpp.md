---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: polynomial/multipoint_evaluation.hpp
    title: multipoint evaluation
  - icon: ':heavy_check_mark:'
    path: polynomial/subset_sum.hpp
    title: $\#_p$ Subset Sum
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/division_of_polynomials.test.cpp
    title: test/yosupo/division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/multipoint_evaluation.test.cpp
    title: test/yosupo/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
    title: test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/product_of_polynomial_sequence.test.cpp
    title: test/yosupo/product_of_polynomial_sequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sharp_p_subset_sum.test.cpp
    title: test/yosupo/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_of_formal_power_series.test.cpp
    title: test/yosupo/sqrt_of_formal_power_series.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Exp of Formal Power Series
    links:
    - https://arxiv.org/pdf/1301.5804.pdf
  bundledCode: "#line 2 \"polynomial/FormalPowerSeries.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#include <queue>\n#include <utility>\n\
    #include <vector>\n\n#line 1 \"atcoder/convolution.hpp\"\n\n\n\n#line 5 \"atcoder/convolution.hpp\"\
    \n#include <array>\n#line 7 \"atcoder/convolution.hpp\"\n#include <type_traits>\n\
    #line 9 \"atcoder/convolution.hpp\"\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param n `0 <= n`\n// @return minimum non-negative `x` s.t.\
    \ `n <= 2**x`\nint ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) <\
    \ (unsigned int)(n)) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return\
    \ minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned\
    \ int n) {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1\
    \ \"atcoder/modint.hpp\"\n\n\n\n#line 5 \"atcoder/modint.hpp\"\n#include <numeric>\n\
    #line 7 \"atcoder/modint.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\
    \n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#line 5 \"atcoder/internal_math.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n// @param m `1 <= m`\n// @return x mod m\nconstexpr long long\
    \ safe_mod(long long x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n\
    \    return x;\n}\n\n// Fast modular multiplication by barrett reduction\n// Reference:\
    \ https://en.wikipedia.org/wiki/Barrett_reduction\n// NOTE: reconsider after Ice\
    \ Lake\nstruct barrett {\n    unsigned int _m;\n    unsigned long long im;\n\n\
    \    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned int m) : _m(m),\
    \ im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n    unsigned int\
    \ umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n    // @param b\
    \ `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned int\
    \ a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im = 0,\
    \ so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n        //\
    \ -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0 <= c,\
    \ d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r\
    \ + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 +\
    \ m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n       \
    \ unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
    \ long long x;\n        _umul128(z, im, &x);\n#else\n        unsigned long long\
    \ x =\n            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);\n\
    #endif\n        unsigned int v = (unsigned int)(z - x * _m);\n        if (_m <=\
    \ v) v += _m;\n        return v;\n    }\n};\n\n// @param n `0 <= n`\n// @param\
    \ m `1 <= m`\n// @return `(x ** n) % m`\nconstexpr long long pow_mod_constexpr(long\
    \ long x, long long n, int m) {\n    if (m == 1) return 0;\n    unsigned int _m\
    \ = (unsigned int)(m);\n    unsigned long long r = 1;\n    unsigned long long\
    \ y = safe_mod(x, m);\n    while (n) {\n        if (n & 1) r = (r * y) % _m;\n\
    \        y = (y * y) % _m;\n        n >>= 1;\n    }\n    return r;\n}\n\n// Reference:\n\
    // M. Forisek and J. Jancina,\n// Fast Primality Testing for Integers That Fit\
    \ into a Machine Word\n// @param n `0 <= n`\nconstexpr bool is_prime_constexpr(int\
    \ n) {\n    if (n <= 1) return false;\n    if (n == 2 || n == 7 || n == 61) return\
    \ true;\n    if (n % 2 == 0) return false;\n    long long d = n - 1;\n    while\
    \ (d % 2 == 0) d /= 2;\n    constexpr long long bases[3] = {2, 7, 61};\n    for\
    \ (long long a : bases) {\n        long long t = d;\n        long long y = pow_mod_constexpr(a,\
    \ t, n);\n        while (t != n - 1 && y != 1 && y != n - 1) {\n            y\
    \ = y * y % n;\n            t <<= 1;\n        }\n        if (y != n - 1 && t %\
    \ 2 == 0) {\n            return false;\n        }\n    }\n    return true;\n}\n\
    template <int n> constexpr bool is_prime = is_prime_constexpr(n);\n\n// @param\
    \ b `1 <= b`\n// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x\
    \ < b/g\nconstexpr std::pair<long long, long long> inv_gcd(long long a, long long\
    \ b) {\n    a = safe_mod(a, b);\n    if (a == 0) return {b, 0};\n\n    // Contracts:\n\
    \    // [1] s - m0 * a = 0 (mod b)\n    // [2] t - m1 * a = 0 (mod b)\n    //\
    \ [3] s * |m1| + t * |m0| <= b\n    long long s = b, t = a;\n    long long m0\
    \ = 0, m1 = 1;\n\n    while (t) {\n        long long u = s / t;\n        s -=\
    \ t * u;\n        m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b\n\n        // [3]:\n\
    \        // (s - t * u) * |m1| + t * |m0 - m1 * u|\n        // <= s * |m1| - t\
    \ * u * |m1| + t * (|m0| + |m1| * u)\n        // = s * |m1| + t * |m0| <= b\n\n\
    \        auto tmp = s;\n        s = t;\n        t = tmp;\n        tmp = m0;\n\
    \        m0 = m1;\n        m1 = tmp;\n    }\n    // by [3]: |m0| <= b/g\n    //\
    \ by g != b: |m0| < b/g\n    if (m0 < 0) m0 += b / s;\n    return {s, m0};\n}\n\
    \n// Compile time primitive root\n// @param m must be prime\n// @return primitive\
    \ root (and minimum in now)\nconstexpr int primitive_root_constexpr(int m) {\n\
    \    if (m == 2) return 1;\n    if (m == 167772161) return 3;\n    if (m == 469762049)\
    \ return 3;\n    if (m == 754974721) return 11;\n    if (m == 998244353) return\
    \ 3;\n    int divs[20] = {};\n    divs[0] = 2;\n    int cnt = 1;\n    int x =\
    \ (m - 1) / 2;\n    while (x % 2 == 0) x /= 2;\n    for (int i = 3; (long long)(i)*i\
    \ <= x; i += 2) {\n        if (x % i == 0) {\n            divs[cnt++] = i;\n \
    \           while (x % i == 0) {\n                x /= i;\n            }\n   \
    \     }\n    }\n    if (x > 1) {\n        divs[cnt++] = x;\n    }\n    for (int\
    \ g = 2;; g++) {\n        bool ok = true;\n        for (int i = 0; i < cnt; i++)\
    \ {\n            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {\n    \
    \            ok = false;\n                break;\n            }\n        }\n \
    \       if (ok) return g;\n    }\n}\ntemplate <int m> constexpr int primitive_root\
    \ = primitive_root_constexpr(m);\n\n// @param n `n < 2^32`\n// @param m `1 <=\
    \ m < 2^32`\n// @return sum_{i=0}^{n-1} floor((ai + b) / m) (mod 2^64)\nunsigned\
    \ long long floor_sum_unsigned(unsigned long long n,\n                       \
    \               unsigned long long m,\n                                      unsigned\
    \ long long a,\n                                      unsigned long long b) {\n\
    \    unsigned long long ans = 0;\n    while (true) {\n        if (a >= m) {\n\
    \            ans += n * (n - 1) / 2 * (a / m);\n            a %= m;\n        }\n\
    \        if (b >= m) {\n            ans += n * (b / m);\n            b %= m;\n\
    \        }\n\n        unsigned long long y_max = a * n + b;\n        if (y_max\
    \ < m) break;\n        // y_max < m * (n + 1)\n        // floor(y_max / m) <=\
    \ n\n        n = (unsigned long long)(y_max / m);\n        b = (unsigned long\
    \ long)(y_max % m);\n        std::swap(m, a);\n    }\n    return ans;\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 1 \"atcoder/internal_type_traits.hpp\"\
    \n\n\n\n#line 7 \"atcoder/internal_type_traits.hpp\"\n\nnamespace atcoder {\n\n\
    namespace internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value ||\n   \
    \                               std::is_same<T, __int128>::value,\n          \
    \                    std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 14 \"atcoder/modint.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\nstruct modint_base {};\nstruct\
    \ static_modint_base : modint_base {};\n\ntemplate <class T> using is_modint =\
    \ std::is_base_of<modint_base, T>;\ntemplate <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;\n\
    \n}  // namespace internal\n\ntemplate <int m, std::enable_if_t<(1 <= m)>* = nullptr>\n\
    struct static_modint : internal::static_modint_base {\n    using mint = static_modint;\n\
    \n  public:\n    static constexpr int mod() { return m; }\n    static mint raw(int\
    \ v) {\n        mint x;\n        x._v = v;\n        return x;\n    }\n\n    static_modint()\
    \ : _v(0) {}\n    template <class T, internal::is_signed_int_t<T>* = nullptr>\n\
    \    static_modint(T v) {\n        long long x = (long long)(v % (long long)(umod()));\n\
    \        if (x < 0) x += umod();\n        _v = (unsigned int)(x);\n    }\n   \
    \ template <class T, internal::is_unsigned_int_t<T>* = nullptr>\n    static_modint(T\
    \ v) {\n        _v = (unsigned int)(v % umod());\n    }\n\n    unsigned int val()\
    \ const { return _v; }\n\n    mint& operator++() {\n        _v++;\n        if\
    \ (_v == umod()) _v = 0;\n        return *this;\n    }\n    mint& operator--()\
    \ {\n        if (_v == 0) _v = umod();\n        _v--;\n        return *this;\n\
    \    }\n    mint operator++(int) {\n        mint result = *this;\n        ++*this;\n\
    \        return result;\n    }\n    mint operator--(int) {\n        mint result\
    \ = *this;\n        --*this;\n        return result;\n    }\n\n    mint& operator+=(const\
    \ mint& rhs) {\n        _v += rhs._v;\n        if (_v >= umod()) _v -= umod();\n\
    \        return *this;\n    }\n    mint& operator-=(const mint& rhs) {\n     \
    \   _v -= rhs._v;\n        if (_v >= umod()) _v += umod();\n        return *this;\n\
    \    }\n    mint& operator*=(const mint& rhs) {\n        unsigned long long z\
    \ = _v;\n        z *= rhs._v;\n        _v = (unsigned int)(z % umod());\n    \
    \    return *this;\n    }\n    mint& operator/=(const mint& rhs) { return *this\
    \ = *this * rhs.inv(); }\n\n    mint operator+() const { return *this; }\n   \
    \ mint operator-() const { return mint() - *this; }\n\n    mint pow(long long\
    \ n) const {\n        assert(0 <= n);\n        mint x = *this, r = 1;\n      \
    \  while (n) {\n            if (n & 1) r *= x;\n            x *= x;\n        \
    \    n >>= 1;\n        }\n        return r;\n    }\n    mint inv() const {\n \
    \       if (prime) {\n            assert(_v);\n            return pow(umod() -\
    \ 2);\n        } else {\n            auto eg = internal::inv_gcd(_v, m);\n   \
    \         assert(eg.first == 1);\n            return eg.second;\n        }\n \
    \   }\n\n    friend mint operator+(const mint& lhs, const mint& rhs) {\n     \
    \   return mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs,\
    \ const mint& rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint\
    \ operator*(const mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n\
    \    }\n    friend mint operator/(const mint& lhs, const mint& rhs) {\n      \
    \  return mint(lhs) /= rhs;\n    }\n    friend bool operator==(const mint& lhs,\
    \ const mint& rhs) {\n        return lhs._v == rhs._v;\n    }\n    friend bool\
    \ operator!=(const mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n\
    \    }\n\n  private:\n    unsigned int _v;\n    static constexpr unsigned int\
    \ umod() { return m; }\n    static constexpr bool prime = internal::is_prime<m>;\n\
    };\n\ntemplate <int id> struct dynamic_modint : internal::modint_base {\n    using\
    \ mint = dynamic_modint;\n\n  public:\n    static int mod() { return (int)(bt.umod());\
    \ }\n    static void set_mod(int m) {\n        assert(1 <= m);\n        bt = internal::barrett(m);\n\
    \    }\n    static mint raw(int v) {\n        mint x;\n        x._v = v;\n   \
    \     return x;\n    }\n\n    dynamic_modint() : _v(0) {}\n    template <class\
    \ T, internal::is_signed_int_t<T>* = nullptr>\n    dynamic_modint(T v) {\n   \
    \     long long x = (long long)(v % (long long)(mod()));\n        if (x < 0) x\
    \ += mod();\n        _v = (unsigned int)(x);\n    }\n    template <class T, internal::is_unsigned_int_t<T>*\
    \ = nullptr>\n    dynamic_modint(T v) {\n        _v = (unsigned int)(v % mod());\n\
    \    }\n\n    unsigned int val() const { return _v; }\n\n    mint& operator++()\
    \ {\n        _v++;\n        if (_v == umod()) _v = 0;\n        return *this;\n\
    \    }\n    mint& operator--() {\n        if (_v == 0) _v = umod();\n        _v--;\n\
    \        return *this;\n    }\n    mint operator++(int) {\n        mint result\
    \ = *this;\n        ++*this;\n        return result;\n    }\n    mint operator--(int)\
    \ {\n        mint result = *this;\n        --*this;\n        return result;\n\
    \    }\n\n    mint& operator+=(const mint& rhs) {\n        _v += rhs._v;\n   \
    \     if (_v >= umod()) _v -= umod();\n        return *this;\n    }\n    mint&\
    \ operator-=(const mint& rhs) {\n        _v += mod() - rhs._v;\n        if (_v\
    \ >= umod()) _v -= umod();\n        return *this;\n    }\n    mint& operator*=(const\
    \ mint& rhs) {\n        _v = bt.mul(_v, rhs._v);\n        return *this;\n    }\n\
    \    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }\n\
    \n    mint operator+() const { return *this; }\n    mint operator-() const { return\
    \ mint() - *this; }\n\n    mint pow(long long n) const {\n        assert(0 <=\
    \ n);\n        mint x = *this, r = 1;\n        while (n) {\n            if (n\
    \ & 1) r *= x;\n            x *= x;\n            n >>= 1;\n        }\n       \
    \ return r;\n    }\n    mint inv() const {\n        auto eg = internal::inv_gcd(_v,\
    \ mod());\n        assert(eg.first == 1);\n        return eg.second;\n    }\n\n\
    \    friend mint operator+(const mint& lhs, const mint& rhs) {\n        return\
    \ mint(lhs) += rhs;\n    }\n    friend mint operator-(const mint& lhs, const mint&\
    \ rhs) {\n        return mint(lhs) -= rhs;\n    }\n    friend mint operator*(const\
    \ mint& lhs, const mint& rhs) {\n        return mint(lhs) *= rhs;\n    }\n   \
    \ friend mint operator/(const mint& lhs, const mint& rhs) {\n        return mint(lhs)\
    \ /= rhs;\n    }\n    friend bool operator==(const mint& lhs, const mint& rhs)\
    \ {\n        return lhs._v == rhs._v;\n    }\n    friend bool operator!=(const\
    \ mint& lhs, const mint& rhs) {\n        return lhs._v != rhs._v;\n    }\n\n \
    \ private:\n    unsigned int _v;\n    static internal::barrett bt;\n    static\
    \ unsigned int umod() { return bt.umod(); }\n};\ntemplate <int id> internal::barrett\
    \ dynamic_modint<id>::bt(998244353);\n\nusing modint998244353 = static_modint<998244353>;\n\
    using modint1000000007 = static_modint<1000000007>;\nusing modint = dynamic_modint<-1>;\n\
    \nnamespace internal {\n\ntemplate <class T>\nusing is_static_modint = std::is_base_of<internal::static_modint_base,\
    \ T>;\n\ntemplate <class T>\nusing is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;\n\
    \ntemplate <class> struct is_dynamic_modint : public std::false_type {};\ntemplate\
    \ <int id>\nstruct is_dynamic_modint<dynamic_modint<id>> : public std::true_type\
    \ {};\n\ntemplate <class T>\nusing is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;\n\
    \n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 12 \"atcoder/convolution.hpp\"\
    \n\nnamespace atcoder {\n\nnamespace internal {\n\ntemplate <class mint,\n   \
    \       int g = internal::primitive_root<mint::mod()>,\n          internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstruct fft_info {\n    static constexpr int rank2 = bsf_constexpr(mint::mod()\
    \ - 1);\n    std::array<mint, rank2 + 1> root;   // root[i]^(2^i) == 1\n    std::array<mint,\
    \ rank2 + 1> iroot;  // root[i] * iroot[i] == 1\n\n    std::array<mint, std::max(0,\
    \ rank2 - 2 + 1)> rate2;\n    std::array<mint, std::max(0, rank2 - 2 + 1)> irate2;\n\
    \n    std::array<mint, std::max(0, rank2 - 3 + 1)> rate3;\n    std::array<mint,\
    \ std::max(0, rank2 - 3 + 1)> irate3;\n\n    fft_info() {\n        root[rank2]\
    \ = mint(g).pow((mint::mod() - 1) >> rank2);\n        iroot[rank2] = root[rank2].inv();\n\
    \        for (int i = rank2 - 1; i >= 0; i--) {\n            root[i] = root[i\
    \ + 1] * root[i + 1];\n            iroot[i] = iroot[i + 1] * iroot[i + 1];\n \
    \       }\n\n        {\n            mint prod = 1, iprod = 1;\n            for\
    \ (int i = 0; i <= rank2 - 2; i++) {\n                rate2[i] = root[i + 2] *\
    \ prod;\n                irate2[i] = iroot[i + 2] * iprod;\n                prod\
    \ *= iroot[i + 2];\n                iprod *= root[i + 2];\n            }\n   \
    \     }\n        {\n            mint prod = 1, iprod = 1;\n            for (int\
    \ i = 0; i <= rank2 - 3; i++) {\n                rate3[i] = root[i + 3] * prod;\n\
    \                irate3[i] = iroot[i + 3] * iprod;\n                prod *= iroot[i\
    \ + 3];\n                iprod *= root[i + 3];\n            }\n        }\n   \
    \ }\n};\n\ntemplate <class mint, internal::is_static_modint_t<mint>* = nullptr>\n\
    void butterfly(std::vector<mint>& a) {\n    int n = int(a.size());\n    int h\
    \ = internal::ceil_pow2(n);\n\n    static const fft_info<mint> info;\n\n    int\
    \ len = 0;  // a[i, i+(n>>len), i+2*(n>>len), ..] is transformed\n    while (len\
    \ < h) {\n        if (h - len == 1) {\n            int p = 1 << (h - len - 1);\n\
    \            mint rot = 1;\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto l = a[i + offset];\n               \
    \     auto r = a[i + offset + p] * rot;\n                    a[i + offset] = l\
    \ + r;\n                    a[i + offset + p] = l - r;\n                }\n  \
    \              if (s + 1 != (1 << len))\n                    rot *= info.rate2[bsf(~(unsigned\
    \ int)(s))];\n            }\n            len++;\n        } else {\n          \
    \  // 4-base\n            int p = 1 << (h - len - 2);\n            mint rot =\
    \ 1, imag = info.root[2];\n            for (int s = 0; s < (1 << len); s++) {\n\
    \                mint rot2 = rot * rot;\n                mint rot3 = rot2 * rot;\n\
    \                int offset = s << (h - len);\n                for (int i = 0;\
    \ i < p; i++) {\n                    auto mod2 = 1ULL * mint::mod() * mint::mod();\n\
    \                    auto a0 = 1ULL * a[i + offset].val();\n                 \
    \   auto a1 = 1ULL * a[i + offset + p].val() * rot.val();\n                  \
    \  auto a2 = 1ULL * a[i + offset + 2 * p].val() * rot2.val();\n              \
    \      auto a3 = 1ULL * a[i + offset + 3 * p].val() * rot3.val();\n          \
    \          auto a1na3imag =\n                        1ULL * mint(a1 + mod2 - a3).val()\
    \ * imag.val();\n                    auto na2 = mod2 - a2;\n                 \
    \   a[i + offset] = a0 + a2 + a1 + a3;\n                    a[i + offset + 1 *\
    \ p] = a0 + a2 + (2 * mod2 - (a1 + a3));\n                    a[i + offset + 2\
    \ * p] = a0 + na2 + a1na3imag;\n                    a[i + offset + 3 * p] = a0\
    \ + na2 + (mod2 - a1na3imag);\n                }\n                if (s + 1 !=\
    \ (1 << len))\n                    rot *= info.rate3[bsf(~(unsigned int)(s))];\n\
    \            }\n            len += 2;\n        }\n    }\n}\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nvoid butterfly_inv(std::vector<mint>&\
    \ a) {\n    int n = int(a.size());\n    int h = internal::ceil_pow2(n);\n\n  \
    \  static const fft_info<mint> info;\n\n    int len = h;  // a[i, i+(n>>len),\
    \ i+2*(n>>len), ..] is transformed\n    while (len) {\n        if (len == 1) {\n\
    \            int p = 1 << (h - len);\n            mint irot = 1;\n           \
    \ for (int s = 0; s < (1 << (len - 1)); s++) {\n                int offset = s\
    \ << (h - len + 1);\n                for (int i = 0; i < p; i++) {\n         \
    \           auto l = a[i + offset];\n                    auto r = a[i + offset\
    \ + p];\n                    a[i + offset] = l + r;\n                    a[i +\
    \ offset + p] =\n                        (unsigned long long)(mint::mod() + l.val()\
    \ - r.val()) *\n                        irot.val();\n                    ;\n \
    \               }\n                if (s + 1 != (1 << (len - 1)))\n          \
    \          irot *= info.irate2[bsf(~(unsigned int)(s))];\n            }\n    \
    \        len--;\n        } else {\n            // 4-base\n            int p =\
    \ 1 << (h - len);\n            mint irot = 1, iimag = info.iroot[2];\n       \
    \     for (int s = 0; s < (1 << (len - 2)); s++) {\n                mint irot2\
    \ = irot * irot;\n                mint irot3 = irot2 * irot;\n               \
    \ int offset = s << (h - len + 2);\n                for (int i = 0; i < p; i++)\
    \ {\n                    auto a0 = 1ULL * a[i + offset + 0 * p].val();\n     \
    \               auto a1 = 1ULL * a[i + offset + 1 * p].val();\n              \
    \      auto a2 = 1ULL * a[i + offset + 2 * p].val();\n                    auto\
    \ a3 = 1ULL * a[i + offset + 3 * p].val();\n\n                    auto a2na3iimag\
    \ =\n                        1ULL *\n                        mint((mint::mod()\
    \ + a2 - a3) * iimag.val()).val();\n\n                    a[i + offset] = a0 +\
    \ a1 + a2 + a3;\n                    a[i + offset + 1 * p] =\n               \
    \         (a0 + (mint::mod() - a1) + a2na3iimag) * irot.val();\n             \
    \       a[i + offset + 2 * p] =\n                        (a0 + a1 + (mint::mod()\
    \ - a2) + (mint::mod() - a3)) *\n                        irot2.val();\n      \
    \              a[i + offset + 3 * p] =\n                        (a0 + (mint::mod()\
    \ - a1) + (mint::mod() - a2na3iimag)) *\n                        irot3.val();\n\
    \                }\n                if (s + 1 != (1 << (len - 2)))\n         \
    \           irot *= info.irate3[bsf(~(unsigned int)(s))];\n            }\n   \
    \         len -= 2;\n        }\n    }\n}\n\ntemplate <class mint, internal::is_static_modint_t<mint>*\
    \ = nullptr>\nstd::vector<mint> convolution_naive(const std::vector<mint>& a,\n\
    \                                    const std::vector<mint>& b) {\n    int n\
    \ = int(a.size()), m = int(b.size());\n    std::vector<mint> ans(n + m - 1);\n\
    \    if (n < m) {\n        for (int j = 0; j < m; j++) {\n            for (int\
    \ i = 0; i < n; i++) {\n                ans[i + j] += a[i] * b[j];\n         \
    \   }\n        }\n    } else {\n        for (int i = 0; i < n; i++) {\n      \
    \      for (int j = 0; j < m; j++) {\n                ans[i + j] += a[i] * b[j];\n\
    \            }\n        }\n    }\n    return ans;\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution_fft(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int n = int(a.size()), m = int(b.size());\n \
    \   int z = 1 << internal::ceil_pow2(n + m - 1);\n    a.resize(z);\n    internal::butterfly(a);\n\
    \    b.resize(z);\n    internal::butterfly(b);\n    for (int i = 0; i < z; i++)\
    \ {\n        a[i] *= b[i];\n    }\n    internal::butterfly_inv(a);\n    a.resize(n\
    \ + m - 1);\n    mint iz = mint(z).inv();\n    for (int i = 0; i < n + m - 1;\
    \ i++) a[i] *= iz;\n    return a;\n}\n\n}  // namespace internal\n\ntemplate <class\
    \ mint, internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(std::vector<mint>&&\
    \ a, std::vector<mint>&& b) {\n    int n = int(a.size()), m = int(b.size());\n\
    \    if (!n || !m) return {};\n    if (std::min(n, m) <= 60) return convolution_naive(a,\
    \ b);\n    return internal::convolution_fft(a, b);\n}\n\ntemplate <class mint,\
    \ internal::is_static_modint_t<mint>* = nullptr>\nstd::vector<mint> convolution(const\
    \ std::vector<mint>& a,\n                              const std::vector<mint>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n    if (std::min(n, m) <= 60) return convolution_naive(a, b);\n    return\
    \ internal::convolution_fft(a, b);\n}\n\ntemplate <unsigned int mod = 998244353,\n\
    \          class T,\n          std::enable_if_t<internal::is_integral<T>::value>*\
    \ = nullptr>\nstd::vector<T> convolution(const std::vector<T>& a, const std::vector<T>&\
    \ b) {\n    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return\
    \ {};\n\n    using mint = static_modint<mod>;\n    std::vector<mint> a2(n), b2(m);\n\
    \    for (int i = 0; i < n; i++) {\n        a2[i] = mint(a[i]);\n    }\n    for\
    \ (int i = 0; i < m; i++) {\n        b2[i] = mint(b[i]);\n    }\n    auto c2 =\
    \ convolution(move(a2), move(b2));\n    std::vector<T> c(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        c[i] = c2[i].val();\n    }\n    return\
    \ c;\n}\n\nstd::vector<long long> convolution_ll(const std::vector<long long>&\
    \ a,\n                                      const std::vector<long long>& b) {\n\
    \    int n = int(a.size()), m = int(b.size());\n    if (!n || !m) return {};\n\
    \n    static constexpr unsigned long long MOD1 = 754974721;  // 2^24\n    static\
    \ constexpr unsigned long long MOD2 = 167772161;  // 2^25\n    static constexpr\
    \ unsigned long long MOD3 = 469762049;  // 2^26\n    static constexpr unsigned\
    \ long long M2M3 = MOD2 * MOD3;\n    static constexpr unsigned long long M1M3\
    \ = MOD1 * MOD3;\n    static constexpr unsigned long long M1M2 = MOD1 * MOD2;\n\
    \    static constexpr unsigned long long M1M2M3 = MOD1 * MOD2 * MOD3;\n\n    static\
    \ constexpr unsigned long long i1 =\n        internal::inv_gcd(MOD2 * MOD3, MOD1).second;\n\
    \    static constexpr unsigned long long i2 =\n        internal::inv_gcd(MOD1\
    \ * MOD3, MOD2).second;\n    static constexpr unsigned long long i3 =\n      \
    \  internal::inv_gcd(MOD1 * MOD2, MOD3).second;\n\n    auto c1 = convolution<MOD1>(a,\
    \ b);\n    auto c2 = convolution<MOD2>(a, b);\n    auto c3 = convolution<MOD3>(a,\
    \ b);\n\n    std::vector<long long> c(n + m - 1);\n    for (int i = 0; i < n +\
    \ m - 1; i++) {\n        unsigned long long x = 0;\n        x += (c1[i] * i1)\
    \ % MOD1 * M2M3;\n        x += (c2[i] * i2) % MOD2 * M1M3;\n        x += (c3[i]\
    \ * i3) % MOD3 * M1M2;\n        // B = 2^63, -B <= x, r(real value) < B\n    \
    \    // (x, x - M, x - 2M, or x - 3M) = r (mod 2B)\n        // r = c1[i] (mod\
    \ MOD1)\n        // focus on MOD1\n        // r = x, x - M', x - 2M', x - 3M'\
    \ (M' = M % 2^64) (mod 2B)\n        // r = x,\n        //     x - M' + (0 or 2B),\n\
    \        //     x - 2M' + (0, 2B or 4B),\n        //     x - 3M' + (0, 2B, 4B\
    \ or 6B) (without mod!)\n        // (r - x) = 0, (0)\n        //           - M'\
    \ + (0 or 2B), (1)\n        //           -2M' + (0 or 2B or 4B), (2)\n       \
    \ //           -3M' + (0 or 2B or 4B or 6B) (3) (mod MOD1)\n        // we checked\
    \ that\n        //   ((1) mod MOD1) mod 5 = 2\n        //   ((2) mod MOD1) mod\
    \ 5 = 3\n        //   ((3) mod MOD1) mod 5 = 4\n        long long diff =\n   \
    \         c1[i] - internal::safe_mod((long long)(x), (long long)(MOD1));\n   \
    \     if (diff < 0) diff += MOD1;\n        static constexpr unsigned long long\
    \ offset[5] = {\n            0, 0, M1M2M3, 2 * M1M2M3, 3 * M1M2M3};\n        x\
    \ -= offset[diff % 5];\n        c[i] = x;\n    }\n\n    return c;\n}\n\n}  //\
    \ namespace atcoder\n\n\n#line 10 \"polynomial/FormalPowerSeries.hpp\"\n\ntemplate\
    \ <typename T> struct FormalPowerSeries : std::vector<T> {\nprivate:\n    using\
    \ std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n    void shrink()\
    \ {\n        while (this->size() and this->back() == T(0)) this->pop_back();\n\
    \    }\n\n    FPS pre(size_t sz) const { return FPS(this->begin(), this->begin()\
    \ + std::min(this->size(), sz)); }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        std::reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n\
    \    FPS operator>>(size_t sz) const {\n        if (this->size() <= sz) return\
    \ {};\n        return FPS(this->begin() + sz, this->end());\n    }\n\n    FPS\
    \ operator<<(size_t sz) const {\n        if (this->empty()) return {};\n     \
    \   FPS ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n        return\
    \ ret;\n    }\n\npublic:\n    FPS& operator+=(const FPS& r) {\n        if (r.size()\
    \ > this->size()) this->resize(r.size());\n        for (size_t i = 0; i < r.size();\
    \ i++) (*this)[i] += r[i];\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator+=(const T& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += v;\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const T& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n       \
    \ auto res = atcoder::convolution(*this, r);\n        return *this = {res.begin(),\
    \ res.end()};\n    }\n\n    FPS& operator*=(const T& v) {\n        for (auto&\
    \ x : (*this)) x *= v;\n        shrink();\n        return *this;\n    }\n\n  \
    \  FPS& operator/=(const FPS& r) {\n        if (this->size() < r.size()) {\n \
    \           this->clear();\n            return *this;\n        }\n        int\
    \ n = this->size() - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS& operator%=(const FPS& r) {\n        *this -= *this / r * r;\n\
    \        shrink();\n        return *this;\n    }\n\n    FPS operator+(const FPS&\
    \ r) const { return FPS(*this) += r; }\n\n    FPS operator+(const T& v) const\
    \ { return FPS(*this) += v; }\n\n    FPS operator-(const FPS& r) const { return\
    \ FPS(*this) -= r; }\n\n    FPS operator-(const T& v) const { return FPS(*this)\
    \ -= v; }\n\n    FPS operator*(const FPS& r) const { return FPS(*this) *= r; }\n\
    \n    FPS operator*(const T& v) const { return FPS(*this) *= v; }\n\n    FPS operator/(const\
    \ FPS& r) const { return FPS(*this) /= r; }\n\n    FPS operator%(const FPS& r)\
    \ const { return FPS(*this) %= r; }\n\n    FPS operator-() const {\n        FPS\
    \ ret = *this;\n        for (auto& v : ret) v = -v;\n        return ret;\n   \
    \ }\n\n    FPS differential() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) ret[i\
    \ - 1] = (*this)[i] * T(i);\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        const int n = (int)this->size();\n        FPS ret(n + 1);\n\
    \        ret[0] = T(0);\n        if (n > 0) ret[1] = T(1);\n        auto mod =\
    \ T::mod();\n        for (int i = 2; i <= n; i++) ret[i] = -ret[mod % i] * (mod\
    \ / i);\n        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n     \
    \   return ret;\n    }\n\n    FPS inv(int deg = -1) const {\n        assert((*this)[0]\
    \ != T(0));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        FPS ret{(*this)[0].inv()};\n        ret.reserve(deg);\n  \
    \      for (int d = 1; d < deg; d <<= 1) {\n            FPS f(d << 1), g(d <<\
    \ 1);\n            std::copy(this->begin(), this->begin() + std::min(n, d << 1),\
    \ f.begin());\n            std::copy(ret.begin(), ret.end(), g.begin());\n   \
    \         atcoder::internal::butterfly(f);\n            atcoder::internal::butterfly(g);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            std::fill(f.begin(), f.begin() + d, T(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            T iz = T(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++) ret.push_back(f[i] * iz);\n    \
    \    }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg = -1) const\
    \ {\n        assert((*this)[0] == T(1));\n        if (deg == -1) deg = (int)this->size();\n\
    \        return (differential() * inv(deg)).pre(deg - 1).integral();\n    }\n\n\
    \    FPS sqrt(const std::function<T(T)>& get_sqrt, int deg = -1) const {\n   \
    \     const int n = this->size();\n        if (deg == -1) deg = n;\n        if\
    \ (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == T(0)) {\n   \
    \         for (int i = 1; i < n; i++) {\n                if ((*this)[i] != T(0))\
    \ {\n                    if (i & 1) return {};\n                    if (deg -\
    \ i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, T(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, T(0));\n        }\n        auto sqrtf0\
    \ = T(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        T inv2 = T(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1) ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \        return ret.pre(deg);\n    }\n\n    /**\n     * @brief Exp of Formal Power\
    \ Series\n     *\n     * @see https://arxiv.org/pdf/1301.5804.pdf\n     */\n \
    \   FPS exp(int deg = -1) const {\n        assert(this->empty() or (*this)[0]\
    \ == T(0));\n        if (this->size() == 0) return {};\n        if (this->size()\
    \ == 1) return {T(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(T(0));\n \
    \       inv.push_back(T(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = T::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), T(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= T(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{T(1)}, g_fft{T(1), T(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const T iz1 = T(m).inv(), iz2 = T(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     // Step 2.a'\n                FPS _g(m);\n                for (int i = 0;\
    \ i < m; i++) _g[i] = f_fft[i] * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n\
    \                std::fill(_g.begin(), _g.begin() + (m >> 1), T(0));\n       \
    \         atcoder::internal::butterfly(_g);\n                for (int i = 0; i\
    \ < m; i++) _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\
    \ this->begin() + std::min((int)this->size(), m));\n            {\n          \
    \      // Step 2.b'\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(T(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                // Step 2.c'\n                for\
    \ (int i = 0; i < m; i++) x[i] *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.d' and 2.e'\n       \
    \         x -= f.differential();\n                x.resize(m << 1);\n        \
    \        for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = T(0);\n     \
    \           atcoder::internal::butterfly(x);\n                for (int i = 0;\
    \ i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.f'\n                x.pop_back();\n\
    \                inplace_integral(x);\n                for (int i = m; i < std::min((int)this->size(),\
    \ m << 1); i++) x[i] += (*this)[i];\n                std::fill(x.begin(), x.begin()\
    \ + m, T(0));\n            }\n            {\n                // Step 2.g' and\
    \ 2.h'\n                atcoder::internal::butterfly(x);\n                for\
    \ (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \                f.insert(f.end(), x.begin() + m, x.end());\n            }\n \
    \       }\n        return FPS{f.begin(), f.begin() + deg};\n    }\n\n    FPS pow(int64_t\
    \ k, int deg = -1) const {\n        const int n = (int)this->size();\n       \
    \ if (deg == -1) deg = n;\n        if (k == 0) {\n            auto res = FPS(deg,\
    \ T(0));\n            res[0] = T(1);\n            return res;\n        }\n   \
    \     for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0)) {\n \
    \               if (i >= (deg + k - 1) / k) return FPS(deg, T(0));\n         \
    \       T rev = (*this)[i].inv();\n                FPS ret = (((*this * rev) >>\
    \ i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n                ret = (ret\
    \ << (i * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ T(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n        T ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n\n    static FPS product_of_polynomial_sequence(const std::vector<FPS>&\
    \ fs) {\n        if (fs.empty()) return {T(1)};\n        auto comp = [](const\
    \ FPS& f, const FPS& g) { return f.size() > g.size(); };\n        std::priority_queue<FPS,\
    \ std::vector<FPS>, decltype(comp)> pq{comp};\n        for (const auto& f : fs)\
    \ pq.emplace(f);\n        while (pq.size() > 1) {\n            auto f = pq.top();\n\
    \            pq.pop();\n            auto g = pq.top();\n            pq.pop();\n\
    \            pq.emplace(f * g);\n        }\n        return pq.top();\n    }\n\n\
    \    static FPS pow_sparse(const std::vector<std::pair<int, T>>& f, int64_t k,\
    \ int n) {\n        assert(k >= 0);\n        int d = f.size(), offset = 0;\n \
    \       while (offset < d and f[offset].second == 0) offset++;\n        FPS res(n,\
    \ 0);\n        if (offset == d) {\n            if (k == 0) res[0]++;\n       \
    \     return res;\n        }\n        if (f[offset].first > 0) {\n           \
    \ int deg = f[offset].first;\n            if (k > (n - 1) / deg) return res;\n\
    \            std::vector<std::pair<int, T>> g(f.begin() + offset, f.end());\n\
    \            for (auto& p : g) p.first -= deg;\n            auto tmp = pow_sparse(g,\
    \ k, n - k * deg);\n            for (int i = 0; i < n - k * deg; i++) res[k *\
    \ deg + i] = tmp[i];\n            return res;\n        }\n        std::vector<T>\
    \ invs(n + 1);\n        invs[0] = T(0);\n        invs[1] = T(1);\n        auto\
    \ mod = T::mod();\n        for (int i = 2; i <= n; i++) invs[i] = -invs[mod %\
    \ i] * (mod / i);\n        res[0] = f[0].second.pow(k);\n        T coef = f[0].second.inv();\n\
    \        for (int i = 1; i < n; i++) {\n            for (int j = 1; j < d; j++)\
    \ {\n                if (i - f[j].first < 0) break;\n                res[i] +=\
    \ f[j].second * res[i - f[j].first] * (T(k) * f[j].first - (i - f[j].first));\n\
    \            }\n            res[i] *= invs[i] * coef;\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <queue>\n#include <utility>\n#include <vector>\n\n#include \"atcoder/convolution\"\
    \n\ntemplate <typename T> struct FormalPowerSeries : std::vector<T> {\nprivate:\n\
    \    using std::vector<T>::vector;\n    using FPS = FormalPowerSeries;\n    void\
    \ shrink() {\n        while (this->size() and this->back() == T(0)) this->pop_back();\n\
    \    }\n\n    FPS pre(size_t sz) const { return FPS(this->begin(), this->begin()\
    \ + std::min(this->size(), sz)); }\n\n    FPS rev() const {\n        FPS ret(*this);\n\
    \        std::reverse(ret.begin(), ret.end());\n        return ret;\n    }\n\n\
    \    FPS operator>>(size_t sz) const {\n        if (this->size() <= sz) return\
    \ {};\n        return FPS(this->begin() + sz, this->end());\n    }\n\n    FPS\
    \ operator<<(size_t sz) const {\n        if (this->empty()) return {};\n     \
    \   FPS ret(*this);\n        ret.insert(ret.begin(), sz, T(0));\n        return\
    \ ret;\n    }\n\npublic:\n    FPS& operator+=(const FPS& r) {\n        if (r.size()\
    \ > this->size()) this->resize(r.size());\n        for (size_t i = 0; i < r.size();\
    \ i++) (*this)[i] += r[i];\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator+=(const T& v) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += v;\n        shrink();\n        return *this;\n    }\n\n\
    \    FPS& operator-=(const FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n\
    \        for (size_t i = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const T& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n       \
    \ auto res = atcoder::convolution(*this, r);\n        return *this = {res.begin(),\
    \ res.end()};\n    }\n\n    FPS& operator*=(const T& v) {\n        for (auto&\
    \ x : (*this)) x *= v;\n        shrink();\n        return *this;\n    }\n\n  \
    \  FPS& operator/=(const FPS& r) {\n        if (this->size() < r.size()) {\n \
    \           this->clear();\n            return *this;\n        }\n        int\
    \ n = this->size() - r.size() + 1;\n        return *this = (rev().pre(n) * r.rev().inv(n)).pre(n).rev();\n\
    \    }\n\n    FPS& operator%=(const FPS& r) {\n        *this -= *this / r * r;\n\
    \        shrink();\n        return *this;\n    }\n\n    FPS operator+(const FPS&\
    \ r) const { return FPS(*this) += r; }\n\n    FPS operator+(const T& v) const\
    \ { return FPS(*this) += v; }\n\n    FPS operator-(const FPS& r) const { return\
    \ FPS(*this) -= r; }\n\n    FPS operator-(const T& v) const { return FPS(*this)\
    \ -= v; }\n\n    FPS operator*(const FPS& r) const { return FPS(*this) *= r; }\n\
    \n    FPS operator*(const T& v) const { return FPS(*this) *= v; }\n\n    FPS operator/(const\
    \ FPS& r) const { return FPS(*this) /= r; }\n\n    FPS operator%(const FPS& r)\
    \ const { return FPS(*this) %= r; }\n\n    FPS operator-() const {\n        FPS\
    \ ret = *this;\n        for (auto& v : ret) v = -v;\n        return ret;\n   \
    \ }\n\n    FPS differential() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(std::max(0, n - 1));\n        for (int i = 1; i < n; i++) ret[i\
    \ - 1] = (*this)[i] * T(i);\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        const int n = (int)this->size();\n        FPS ret(n + 1);\n\
    \        ret[0] = T(0);\n        if (n > 0) ret[1] = T(1);\n        auto mod =\
    \ T::mod();\n        for (int i = 2; i <= n; i++) ret[i] = -ret[mod % i] * (mod\
    \ / i);\n        for (int i = 0; i < n; i++) ret[i + 1] *= (*this)[i];\n     \
    \   return ret;\n    }\n\n    FPS inv(int deg = -1) const {\n        assert((*this)[0]\
    \ != T(0));\n        const int n = (int)this->size();\n        if (deg == -1)\
    \ deg = n;\n        FPS ret{(*this)[0].inv()};\n        ret.reserve(deg);\n  \
    \      for (int d = 1; d < deg; d <<= 1) {\n            FPS f(d << 1), g(d <<\
    \ 1);\n            std::copy(this->begin(), this->begin() + std::min(n, d << 1),\
    \ f.begin());\n            std::copy(ret.begin(), ret.end(), g.begin());\n   \
    \         atcoder::internal::butterfly(f);\n            atcoder::internal::butterfly(g);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            std::fill(f.begin(), f.begin() + d, T(0));\n            atcoder::internal::butterfly(f);\n\
    \            for (int i = 0; i < (d << 1); i++) f[i] *= g[i];\n            atcoder::internal::butterfly_inv(f);\n\
    \            T iz = T(d << 1).inv();\n            iz *= -iz;\n            for\
    \ (int i = d; i < std::min(d << 1, deg); i++) ret.push_back(f[i] * iz);\n    \
    \    }\n        return ret.pre(deg);\n    }\n\n    FPS log(int deg = -1) const\
    \ {\n        assert((*this)[0] == T(1));\n        if (deg == -1) deg = (int)this->size();\n\
    \        return (differential() * inv(deg)).pre(deg - 1).integral();\n    }\n\n\
    \    FPS sqrt(const std::function<T(T)>& get_sqrt, int deg = -1) const {\n   \
    \     const int n = this->size();\n        if (deg == -1) deg = n;\n        if\
    \ (this->empty()) return FPS(deg, 0);\n        if ((*this)[0] == T(0)) {\n   \
    \         for (int i = 1; i < n; i++) {\n                if ((*this)[i] != T(0))\
    \ {\n                    if (i & 1) return {};\n                    if (deg -\
    \ i / 2 <= 0) break;\n                    auto ret = (*this >> i).sqrt(get_sqrt,\
    \ deg - i / 2);\n                    if (ret.empty()) return {};\n           \
    \         ret = ret << (i / 2);\n                    if ((int)ret.size() < deg)\
    \ ret.resize(deg, T(0));\n                    return ret;\n                }\n\
    \            }\n            return FPS(deg, T(0));\n        }\n        auto sqrtf0\
    \ = T(get_sqrt((*this)[0]));\n        if (sqrtf0 * sqrtf0 != (*this)[0]) return\
    \ {};\n        FPS ret{sqrtf0};\n        T inv2 = T(2).inv();\n        for (int\
    \ i = 1; i < deg; i <<= 1) ret = (ret + pre(i << 1) * ret.inv(i << 1)) * inv2;\n\
    \        return ret.pre(deg);\n    }\n\n    /**\n     * @brief Exp of Formal Power\
    \ Series\n     *\n     * @see https://arxiv.org/pdf/1301.5804.pdf\n     */\n \
    \   FPS exp(int deg = -1) const {\n        assert(this->empty() or (*this)[0]\
    \ == T(0));\n        if (this->size() == 0) return {};\n        if (this->size()\
    \ == 1) return {T(1)};\n        if (deg == -1) deg = (int)this->size();\n    \
    \    FPS inv;\n        inv.reserve(deg + 1);\n        inv.push_back(T(0));\n \
    \       inv.push_back(T(1));\n        auto inplace_integral = [&](FPS& F) -> void\
    \ {\n            const int n = (int)F.size();\n            auto mod = T::mod();\n\
    \            while ((int)inv.size() <= n) {\n                int i = inv.size();\n\
    \                inv.push_back(-inv[mod % i] * (mod / i));\n            }\n  \
    \          F.insert(F.begin(), T(0));\n            for (int i = 1; i <= n; i++)\
    \ F[i] *= inv[i];\n        };\n        auto inplace_differential = [](FPS& F)\
    \ -> void {\n            if (F.empty()) return;\n            F.erase(F.begin());\n\
    \            for (size_t i = 0; i < F.size(); i++) F[i] *= T(i + 1);\n       \
    \ };\n        FPS f{1, (*this)[1]}, g{T(1)}, g_fft{T(1), T(1)};\n        for (int\
    \ m = 2; m < deg; m <<= 1) {\n            const T iz1 = T(m).inv(), iz2 = T(m\
    \ << 1).inv();\n            auto f_fft = f;\n            f_fft.resize(m << 1);\n\
    \            atcoder::internal::butterfly(f_fft);\n            {\n           \
    \     // Step 2.a'\n                FPS _g(m);\n                for (int i = 0;\
    \ i < m; i++) _g[i] = f_fft[i] * g_fft[i];\n                atcoder::internal::butterfly_inv(_g);\n\
    \                std::fill(_g.begin(), _g.begin() + (m >> 1), T(0));\n       \
    \         atcoder::internal::butterfly(_g);\n                for (int i = 0; i\
    \ < m; i++) _g[i] *= -g_fft[i] * iz1 * iz1;\n                atcoder::internal::butterfly_inv(_g);\n\
    \                g.insert(g.end(), _g.begin() + (m >> 1), _g.end());\n\n     \
    \           g_fft = g;\n                g_fft.resize(m << 1);\n              \
    \  atcoder::internal::butterfly(g_fft);\n            }\n            FPS x(this->begin(),\
    \ this->begin() + std::min((int)this->size(), m));\n            {\n          \
    \      // Step 2.b'\n                x.resize(m);\n                inplace_differential(x);\n\
    \                x.push_back(T(0));\n                atcoder::internal::butterfly(x);\n\
    \            }\n            {\n                // Step 2.c'\n                for\
    \ (int i = 0; i < m; i++) x[i] *= f_fft[i] * iz1;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.d' and 2.e'\n       \
    \         x -= f.differential();\n                x.resize(m << 1);\n        \
    \        for (int i = 0; i < m - 1; i++) x[m + i] = x[i], x[i] = T(0);\n     \
    \           atcoder::internal::butterfly(x);\n                for (int i = 0;\
    \ i < (m << 1); i++) x[i] *= g_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \            }\n            {\n                // Step 2.f'\n                x.pop_back();\n\
    \                inplace_integral(x);\n                for (int i = m; i < std::min((int)this->size(),\
    \ m << 1); i++) x[i] += (*this)[i];\n                std::fill(x.begin(), x.begin()\
    \ + m, T(0));\n            }\n            {\n                // Step 2.g' and\
    \ 2.h'\n                atcoder::internal::butterfly(x);\n                for\
    \ (int i = 0; i < (m << 1); i++) x[i] *= f_fft[i] * iz2;\n                atcoder::internal::butterfly_inv(x);\n\
    \                f.insert(f.end(), x.begin() + m, x.end());\n            }\n \
    \       }\n        return FPS{f.begin(), f.begin() + deg};\n    }\n\n    FPS pow(int64_t\
    \ k, int deg = -1) const {\n        const int n = (int)this->size();\n       \
    \ if (deg == -1) deg = n;\n        if (k == 0) {\n            auto res = FPS(deg,\
    \ T(0));\n            res[0] = T(1);\n            return res;\n        }\n   \
    \     for (int i = 0; i < n; i++) {\n            if ((*this)[i] != T(0)) {\n \
    \               if (i >= (deg + k - 1) / k) return FPS(deg, T(0));\n         \
    \       T rev = (*this)[i].inv();\n                FPS ret = (((*this * rev) >>\
    \ i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n                ret = (ret\
    \ << (i * k)).pre(deg);\n                if ((int)ret.size() < deg) ret.resize(deg,\
    \ T(0));\n                return ret;\n            }\n        }\n        return\
    \ FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n        T ret = 0, w = 1;\n\
    \        for (const auto& v : *this) ret += w * v, w *= x;\n        return ret;\n\
    \    }\n\n    static FPS product_of_polynomial_sequence(const std::vector<FPS>&\
    \ fs) {\n        if (fs.empty()) return {T(1)};\n        auto comp = [](const\
    \ FPS& f, const FPS& g) { return f.size() > g.size(); };\n        std::priority_queue<FPS,\
    \ std::vector<FPS>, decltype(comp)> pq{comp};\n        for (const auto& f : fs)\
    \ pq.emplace(f);\n        while (pq.size() > 1) {\n            auto f = pq.top();\n\
    \            pq.pop();\n            auto g = pq.top();\n            pq.pop();\n\
    \            pq.emplace(f * g);\n        }\n        return pq.top();\n    }\n\n\
    \    static FPS pow_sparse(const std::vector<std::pair<int, T>>& f, int64_t k,\
    \ int n) {\n        assert(k >= 0);\n        int d = f.size(), offset = 0;\n \
    \       while (offset < d and f[offset].second == 0) offset++;\n        FPS res(n,\
    \ 0);\n        if (offset == d) {\n            if (k == 0) res[0]++;\n       \
    \     return res;\n        }\n        if (f[offset].first > 0) {\n           \
    \ int deg = f[offset].first;\n            if (k > (n - 1) / deg) return res;\n\
    \            std::vector<std::pair<int, T>> g(f.begin() + offset, f.end());\n\
    \            for (auto& p : g) p.first -= deg;\n            auto tmp = pow_sparse(g,\
    \ k, n - k * deg);\n            for (int i = 0; i < n - k * deg; i++) res[k *\
    \ deg + i] = tmp[i];\n            return res;\n        }\n        std::vector<T>\
    \ invs(n + 1);\n        invs[0] = T(0);\n        invs[1] = T(1);\n        auto\
    \ mod = T::mod();\n        for (int i = 2; i <= n; i++) invs[i] = -invs[mod %\
    \ i] * (mod / i);\n        res[0] = f[0].second.pow(k);\n        T coef = f[0].second.inv();\n\
    \        for (int i = 1; i < n; i++) {\n            for (int j = 1; j < d; j++)\
    \ {\n                if (i - f[j].first < 0) break;\n                res[i] +=\
    \ f[j].second * res[i - f[j].first] * (T(k) * f[j].first - (i - f[j].first));\n\
    \            }\n            res[i] *= invs[i] * coef;\n        }\n        return\
    \ res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: polynomial/FormalPowerSeries.hpp
  requiredBy:
  - polynomial/multipoint_evaluation.hpp
  - polynomial/subset_sum.hpp
  timestamp: '2022-11-10 02:48:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/division_of_polynomials.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/product_of_polynomial_sequence.test.cpp
  - test/yosupo/sharp_p_subset_sum.test.cpp
  - test/yosupo/pow_of_formal_power_series_sparse.test.cpp
  - test/yosupo/sqrt_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/multipoint_evaluation.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
documentation_of: polynomial/FormalPowerSeries.hpp
layout: document
title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
---

## 概要
形式的冪級数 (Formal Power Series) を効率的に扱うためのライブラリ．
AC Library の convolution に準拠している．
`inv` 等の関数について特に $\mathbb{F}_{998244353}[x]$ 等 $\bmod$ が NTT-friendly な場合を想定した高速化のもとに実装しているため，$\mathbb{F}_{10^9 + 7}[x]$ 等を扱う際は注意が必要である．

以下では

$$
f(x) = \sum_{i = 0}^{N - 1} a_ix^i
$$

に対する操作を想定する．

| メンバ関数       | 効果                                                           | 時間計算量    |
| ---------------- | -------------------------------------------------------------- | ------------- |
| `differential()` | $f^\prime(x)$ を求める．                                       | $O(N)$        |
| `integral()`     | $\int f(x) \mathrm{d}x$ を求める．                             | $O(N)$        |
| `inv()`          | $\frac{1}{f(x)}$ を求める．                                    | $O(N \log N)$ |
| `log()`          | $\log (f(x))$ を求める．                                       | $O(N \log N)$ |
| `sqrt()`         | $\sqrt{f(x)}$ を求める．                                       | $O(N \log N)$ |
| `exp()`          | $\exp (f(x))$ を求める．                                       | $O(N \log N)$ |
| `pow(k)`         | $f(x)^k$ を求める．                                            | $O(N \log N)$ |
| `eval(x)`        | $f(x)$ について $x$ に実際に値を代入した際の式の値を計算する． | $O(N \log N)$ |

メンバ関数 `inv(), log(), sqrt(), exp(), pow()` については引数に `deg` を指定することでその次数で計算を打ち切ることが可能である．
これらの操作では高次の項がより次数の低い項に影響を及ぼすことはないため，打ち切りに問題はない．

### 各種アルゴリズムの詳細

#### 乗算
$f(x)g(x)$ を求める．
これは Number Theoretic Transform により $O(N \log N)$ で計算可能である．

#### （多項式としての）除算
多項式 $f(x), g(x)$ について $f(x) = q(x) g(x) + r(x)$ なる多項式 $q(x), r(x)\ (\deg r < \deg g)$ を求める．
以下，$\deg f = n - 1,\ \deg g = m - 1$ とすると $\deg q = n - m$ である．

$f$ について多項式 $f^R = f(x^{-1}) x^{n - 1}$ を定める．
商と余りの定義式を $x \gets x^{-1}$ として，両辺に $x^{n - 1}$ を掛けて，

$$
\begin{aligned}
    &&&f(x^{-1}) x^{n - 1} = q(x^{-1}) x^{n - m} \cdot g(x^{-1}) x^{m - 1} + r(x^{-1}) x^{m - 2} \cdot x^{n - m + 1} \\
    && \iff &f^R = q^R g^R + r^R x^{n - m + 1} \\
    && \implies & f^R = q^R g^R \pmod{x^{n - m + 1}}.
\end{aligned}
$$

$\deg q^R = n - m < n - m + 1$ より

$$
q^R = q^R \bmod x^{n - m + 1} = \frac{f^R}{g^R}.
$$

#### 微分・積分
$f^\prime(x), \int f(x) \mathrm{d}x$ を求める．
ただし，不定積分の積分定数は $0$ とする．
これは naive に計算可能である．
ここで，積分については $1$ から $N$ の $\mathbb{F}_p$ における逆元を求める必要があるが，これは愚直に求めようとすると時間計算量として $O(N \log \bmod)$ を要するが，$O(N)$ で求める方法がある．

$x$ の $\mathbb{F}_p$ における逆元を求めたい．
$p$ を $x$ で割ったときの商を $q$，余りを $r (r < x)$ とする．
$p = qx + r$ より，

$$
\begin{aligned}
    qx + r \equiv 0 \pmod{p}
    &\iff q + rx^{-1} \equiv 0 \pmod{p} \\
    &\iff r^{-1}q + x^{-1} \equiv 0 \pmod{p} \\
    &\iff x^{-1} \equiv -r^{-1}q \pmod{p}
\end{aligned}
$$

$r < x$ だから，上式に基づいて逆元テーブルを昇順に構築できる．

#### inv
$f(x)g(x) \equiv 1 \pmod{x^N}$ なる $g(x) = \sum_{i = 0}^{N - 1} b_ix^i$ を求める．
これを $\frac{1}{f(x)}$ とも表すことにする．

###### 補題
$fg_n \equiv 1 \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき，

$$
g_{2n} = 2g_n - fg_n^2
$$

が成立する．

###### 証明
$fg_n \equiv 1 \pmod{x^n}$ より，$fg_n - 1= hx^n$ と表せる．
このとき，$(fg_n - 1)^2 = h^2x^{2n}$ だから，

$$
\begin{aligned}
    (fg_n - 1)^2 \equiv 0 \pmod{x^{2n}}
    &\iff f^2g_n^2 -2fg_n + 1 \equiv 0 \pmod{x^{2n}} \\
    &\iff f(2g_n - fg_n^2) \equiv 1 \pmod{x^{2n}} \\
    &\iff fg_{2n} \equiv 1 \pmod{x^{2n}} \quad (g_{2n} = 2g_n - fg_n^2)
\end{aligned}
$$

となる．

$\blacksquare$

$a_0 \neq 0$ のとき，$g_1 = a_0^{-1}$ だから帰納的にダブリングの要領で計算することが可能となる．
計算量は

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．
また，$a_0 \neq 0$ が逆元の存在の必要条件にもなる．

ここで，以下の性質に注目する．

- $g_{2n}$ の $[0, n)$ 次の係数は $g_n$ のそれに一致する．
  よって，$g_{2n}$ の計算においては $fg_n^2$ の $[n, 2n)$ 次の係数が求まれば良い．
- $fg_n \equiv 1 \pmod{x^n}$ より $fg_n$ の $[1, n)$ 次の係数は $0$ であり，$fg_n$ の $n$ 次未満の部分の多項式を $h$ とすると，$h$ は $0$ 次の多項式となり，$g_n$ は $n - 1$ 次以下であるから $hg_n$ は $n - 1$ 次以下となり，$g_{2n}$ の計算においては無視して良い．

これらより，以下のより高速なアルゴリズムが提案される．
1. $f$ の $[0, n)$ 次の項を取り出したものを改めて $f$ と定める．
2. $h = fg_n \equiv x^{2n}$ を計算する．
3. $h$ の $[n, 2n)$ 次の項を取り出したものを改めて $h$ と定める．
4. $-hg_n$ を計算し，これの $[n, 2n)$ 次の係数が $g_{2n}$ のそれに一致する．

毎回畳み込むのではなく NTT と INTT をうまく組み合わせることで，高速化が可能である．

#### log
$\log (f(x))$，すなわち，

$$
f(x) \equiv \sum_{k = 0}^{N - 1} \frac{g(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$g(x)$ の定数項を $0$ とすると，$k \geq N$ については $g(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$f(x)$ の定数項が不定となり計算不可能である．
また，このとき $a_0 = 0^0 = 1$ である．

$\log(f(x))$ と $\int \frac{f^\prime(x)}{f(x)} \mathrm{d}x$ の $N$ 次未満の項は一致することが確認できる．
これを素直に実装すれば良い．

#### sqrt
$f(x) \equiv g(x)^2 \pmod{x^N}$ なる $g(x)$ を求める．
これを $\sqrt{f(x)}$ とも表すことにする．

これも inv と同様の考え方で計算可能である．

$g_n^2 \equiv f \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
$a_0 \neq 0$ であれば $g_n$ の 0 次の係数は $0$ ではないので $g_n$ には逆元が存在する．
このとき，

$$
\begin{aligned}
    (g_n^2 - f)^2 \equiv 0 \pmod{x^{2n}}
    &\iff g_n^4 - 2fg_n^2 + f^2 \equiv 0 \pmod{x^{2n}} \\
    &\iff g_n^2 - 2f + f^2g_n^{-2} \equiv 0 \pmod{x^{2n}} \\
    &\iff 4f \equiv g_n^2 + 2f + f^2g_n^{-2} \pmod{x^{2n}} \\
    &\iff f \equiv \left[\frac{1}{2}(g_n + fg_n^{-1})\right]^2 \pmod{x^{2n}} \\
\end{aligned}
$$

より，

$$
g_{2n} = \frac{1}{2}(g_n + fg_n^{-1})
$$

とすれば $g_{2n}^2 \equiv f \pmod{x^{2n}}$ が成立する．
$g_1$ については別途離散対数問題を解くことで計算可能である．
あとはダブリングの要領で計算でき，計算量は $g_n^{-1}$ の計算がネックとなり，

$$
T(n) = T(n/2) + O(n \log n)
$$

より $O(N \log N)$ を得る．

次に $a_0 = 0$ の場合について考える．
$f$ の非零係数をもつ項の次数の最小値を $i$ とすると，$i$ が奇数であれば求めたい平方根が存在しないことは容易にわかる．
$i$ が偶数の場合は $[i, n)$ 次の項を抽出し $x^{-i}$ をかけて詰めた多項式を改めて $f$ と定めれば，上記のアルゴリズムを適用することができ，その結果得られた多項式に $x^{i/2}$ をかけたものが求めたい平方根となる．

#### exp
$\exp (f(x))$ ，すなわち，

$$
g(x) \equiv \sum_{k = 0}^{N - 1} \frac{f(x)^k}{k!} \pmod{x^N}
$$

なる $g(x)$ を求める．
$a_0 = 0$ とすると，$k \geq N$ については $f(x)^k$ の次数が $N$ 以上となるので打ち切っても問題はない．
逆にそうでなければ，$g(x)$ の定数項が不定となり計算不可能である．

$\exp (f) \equiv g_n \pmod{x^n}$ なる $(n - 1)$ 次多項式 $g_n$ を定める．
このとき， inv や sqrt と同様にして，

$$
g_{2n} = g_n(1 + f - \log g_n)
$$

が成立する．
計算量は同じく $O(N \log N)$ である．

これは一般の場合に計算可能な方法だが，$\bmod$ が NTT-friendly な場合には別のより高速な手法を用いることができる [1] ．

#### pow
$f(x)^k \pmod{x^N}$ を求める．繰り返し二乗法を用いると $O(N \log N \log k)$ で計算可能であるが，$O(N \log N)$ で計算することができる．

$a_0 = 1$ のとき，

$$
f(x)^k \equiv \exp (k \log f(x)) \pmod{x^N}
$$

が成立することを利用する．
定数項が $1$ の多項式 $g(x)$ を用いて $f(x) = cx^lg(x)\ (l \geq 0)$ と表せる．
このとき，$f(x)^k = c^kx^{lk}g(x)^k$ であることを利用すれば良い．

#### inv（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$1 / f(x)$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$fg = 1$ より $f_0 g_0 = 1$ かつ $n \geq 1$ について $\sum_{i = 0}^n f_i g_{n - i} = 0$ より $f_0 g_n = - \sum_{i = 1}^n f_i g_{n - i}$ で $n$ の昇順に計算可能である．

より一般に $g$ を疎な $f$ で割った $g / f$ を求めることも同様の計算量で可能である．

#### log（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\log f$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$\log f = f^\prime / f$ であるから inv の場合と同様にして計算できる．
#### exp（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\exp f$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

疎でない場合の exp と同様に $f_0 = 0$ である．
$F = \exp f$ とすると，$F_0 = 1$ で，両辺微分して $F^\prime = F f^\prime$．
$f^\prime$ も疎であるから，$F_n$ までわかっているとき，右辺の $n$ 次の係数，すなわち $F^\prime$ の $n$ 次の係数が計算できるから $F$ の $n + 1$ 次の係数がわかる．

#### pow（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$f(x)^M$ の先頭 $N$ 項を $O(NK + \log M)$ で列挙することができる．

$f$ が定数項をもつ場合に帰着する．
$F = f^M$ とすると，両辺微分して $F^\prime = M f^{M - 1} f^\prime$ より $f F^\prime = M f^\prime F$．
$g = F^\prime$ として $n$ 次の係数について，$\sum_{i = 0}^n f_i g_{n - i} = M \sum_{i = 1}^n i F_{n - i + 1} f_i$ であり，$f_0 g_n = - \sum_{i = 1}^n f_i g_{n - i} + M \sum_{i = 1}^n i F_{n - i + 1} f_i$．$F_n$ までわかっているとき，右辺が計算可能であるから $g_n$ がわかり，$g = F^\prime$ より $F_{n + 1}  = \frac{g_n}{(n + 1) f_0}$．

#### sqrt（$f$ が sparse な場合）
$f$ の非零の個数を $K$ とすると，$\sqrt{f(x)}$ の先頭 $N$ 項を $O(NK)$ で列挙することができる．

$f$ の定数項が $1$ の場合に帰着すると，$\sqrt{f} = f^{1 / 2}$ が成立し，pow と同様にして計算可能である．

以上の $f$ が sparse な場合の各種演算は Number Theoretic Transform による積の高速化を必要としないため，$\mathbb{F}_{10^9 + 7}[x]$ 等，**法が NTT-friendly でない場合にも適用可能である．**

## 問題例
- [Codeforces Round #250 (Div. 1) E. The Child and Binary Tree](https://codeforces.com/contest/438/problem/E)

- [yukicoder No.1145 Sums of Powers](https://yukicoder.me/problems/no/1145)
  - 答えの母関数を考えると，

    $$ \begin{align*}
        \sum_{n = 0}^\infty x^n \sum_{i = 1}^N A_i^n
        &= \sum_{i = 1}^N \sum_{n = 0}^\infty (A_i x)^n \\
        &= \sum_{i = 1}^N \frac{1}{1 - A_i x}
    \end{align*} $$

    となり，これは分子と分母を二分木のように計算していくことで求めることができる．

    もしくは，

    $$ - \log (1 + x) = \sum_{n = 1}^\infty \frac{x^n}{n} $$

    を用いると


    $$ \begin{align*}
        - \log \prod_{i = 1}^N (1 - A_i x)
        &= \sum_{i = 1}^N - \log (1 - A_i x) \\
        &= \sum_{i = 1}^N \sum_{n = 0}^\infty \frac{(A_i x)^n}{n} \\
        &= \sum_{n = 0}^\infty \left(\sum_{i = 1}^N A_i^n \right) \frac{x^n}{n}
    \end{align*} $$

    となることからも計算可能である．

- [AtCoder Beginner Contest 222 H - Beautiful Binary Tree](https://atcoder.jp/contests/abc222/tasks/abc222_h)

- [AtCoder Beginner Contest 230 H - Bullion](https://atcoder.jp/contests/abc230/tasks/abc230_h)

- [AtCoder Beginner Contest 260 Ex - Colorfulness](https://atcoder.jp/contests/abc260/tasks/abc260_h)
  - 包除原理により $C(P) = n$ である $P$ の個数を求めた後，Sums of Powers と同様の考察により解くことができる．

- [灘校文化祭コンテスト 2022 Day1 K - Li](https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_k)

## Reference
[1] [A simple and fast algorithm for computing exponentials of power series](https://arxiv.org/pdf/1301.5804.pdf)

## Links
- [Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)
- [Nyaan's Library](https://nyaannyaan.github.io/library/)
- [fpsのニュートン法高速化(簡易版) – Dropbox Paper](https://paper.dropbox.com/doc/fps-EoHXQDZxfduAB8wD1PMBW)
- [形式的べき級数解説 \| maspyのHP](https://maspypy.com/category/%e5%bd%a2%e5%bc%8f%e7%9a%84%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e8%a7%a3%e8%aa%ac)
- [[Tutorial] Generating Functions in Competitive Programming (Part 1) - Codeforces](https://codeforces.com/blog/entry/77468)
- [[Tutorial] Generating Functions in Competitive Programming (Part 2) - Codeforces](https://codeforces.com/blog/entry/77551)
- [A problem collection of ODE and differential technique - Codeforces](https://codeforces.com/blog/entry/76447)
