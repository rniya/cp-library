---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
  - icon: ':question:'
    path: polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
  - icon: ':x:'
    path: polynomial/multipoint_evaluation.hpp
    title: multipoint evaluation
  - icon: ':question:'
    path: util/modint.hpp
    title: util/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/multipoint_evaluation
    links:
    - https://judge.yosupo.jp/problem/multipoint_evaluation
  bundledCode: "#line 1 \"test/yosupo/multipoint_evaluation.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\n\n#line 1 \"polynomial/multipoint_evaluation.hpp\"\
    \n#include <vector>\n#line 1 \"polynomial/FormalPowerSeries.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <functional>\n#line 5 \"polynomial/FormalPowerSeries.hpp\"\
    \n\n#line 1 \"atcoder/convolution.hpp\"\n\n\n\n#line 5 \"atcoder/convolution.hpp\"\
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
    \n#line 1 \"atcoder/internal_math.hpp\"\n\n\n\n#include <utility>\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param m `1 <= m`\n// @return x mod m\nconstexpr long long safe_mod(long long\
    \ x, long long m) {\n    x %= m;\n    if (x < 0) x += m;\n    return x;\n}\n\n\
    // Fast modular multiplication by barrett reduction\n// Reference: https://en.wikipedia.org/wiki/Barrett_reduction\n\
    // NOTE: reconsider after Ice Lake\nstruct barrett {\n    unsigned int _m;\n \
    \   unsigned long long im;\n\n    // @param m `1 <= m < 2^31`\n    explicit barrett(unsigned\
    \ int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}\n\n    // @return m\n\
    \    unsigned int umod() const { return _m; }\n\n    // @param a `0 <= a < m`\n\
    \    // @param b `0 <= b < m`\n    // @return `a * b % m`\n    unsigned int mul(unsigned\
    \ int a, unsigned int b) const {\n        // [1] m = 1\n        // a = b = im\
    \ = 0, so okay\n\n        // [2] m >= 2\n        // im = ceil(2^64 / m)\n    \
    \    // -> im * m = 2^64 + r (0 <= r < m)\n        // let z = a*b = c*m + d (0\
    \ <= c, d < m)\n        // a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64\
    \ + c*r + d*im\n        // c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64\
    \ + m * (m + 1) < 2^64 * 2\n        // ((ab * im) >> 64) == c or c + 1\n     \
    \   unsigned long long z = a;\n        z *= b;\n#ifdef _MSC_VER\n        unsigned\
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
    \ namespace atcoder\n\n\n#line 7 \"polynomial/FormalPowerSeries.hpp\"\n\ntemplate\
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
    \ if (deg == -1) deg = n;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((*this)[i] != T(0)) {\n                if (i * k > deg) return FPS(deg,\
    \ T(0));\n                T rev = (*this)[i].inv();\n                FPS ret =\
    \ (((*this * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n      \
    \          ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, T(0));\n                return ret;\n            }\n\
    \        }\n        return FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n\
    \        T ret = 0, w = 1;\n        for (const auto& v : *this) ret += w * v,\
    \ w *= x;\n        return ret;\n    }\n};\n#line 3 \"polynomial/multipoint_evaluation.hpp\"\
    \n\ntemplate <typename T> struct subproduct_tree {\n    using poly = FormalPowerSeries<T>;\n\
    \    int m;\n    std::vector<poly> prod;\n    subproduct_tree(const std::vector<T>&\
    \ x) : m(x.size()) {\n        int k = 1;\n        while (k < m) k <<= 1;\n   \
    \     prod.assign(k << 1, {1});\n        for (int i = 0; i < m; i++) prod[k +\
    \ i] = {-x[i], 1};\n        for (int i = k - 1; i > 0; i--) prod[i] = prod[i <<\
    \ 1] * prod[i << 1 | 1];\n    }\n\n    int size() const { return prod.size() >>\
    \ 1; }\n\n    poly mid_prod(const poly& a, const poly& b) const {}\n\n    std::vector<T>\
    \ multipoint_evaluation(poly f) const {\n        std::vector<poly> rem(size()\
    \ << 1);\n        rem[1] = f % prod[1];\n        for (int i = 2; i < size() +\
    \ m; i++) rem[i] = rem[i >> 1] % prod[i];\n        std::vector<T> res(m);\n  \
    \      for (int i = 0; i < m; i++) res[i] = (rem[size() + i].empty() ? 0 : rem[size()\
    \ + i][0]);\n        return res;\n    }\n};\n#line 5 \"polynomial/FormalPowerSeries.hpp\"\
    \n\n#line 7 \"polynomial/FormalPowerSeries.hpp\"\n\ntemplate <typename T> struct\
    \ FormalPowerSeries : std::vector<T> {\nprivate:\n    using std::vector<T>::vector;\n\
    \    using FPS = FormalPowerSeries;\n    void shrink() {\n        while (this->size()\
    \ and this->back() == T(0)) this->pop_back();\n    }\n\n    FPS pre(size_t sz)\
    \ const { return FPS(this->begin(), this->begin() + std::min(this->size(), sz));\
    \ }\n\n    FPS rev() const {\n        FPS ret(*this);\n        std::reverse(ret.begin(),\
    \ ret.end());\n        return ret;\n    }\n\n    FPS operator>>(size_t sz) const\
    \ {\n        if (this->size() <= sz) return {};\n        return FPS(this->begin()\
    \ + sz, this->end());\n    }\n\n    FPS operator<<(size_t sz) const {\n      \
    \  if (this->empty()) return {};\n        FPS ret(*this);\n        ret.insert(ret.begin(),\
    \ sz, T(0));\n        return ret;\n    }\n\npublic:\n    FPS& operator+=(const\
    \ FPS& r) {\n        if (r.size() > this->size()) this->resize(r.size());\n  \
    \      for (size_t i = 0; i < r.size(); i++) (*this)[i] += r[i];\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator+=(const T& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] += v;\n        shrink();\n\
    \        return *this;\n    }\n\n    FPS& operator-=(const FPS& r) {\n       \
    \ if (r.size() > this->size()) this->resize(r.size());\n        for (size_t i\
    \ = 0; i < r.size(); i++) (*this)[i] -= r[i];\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator-=(const T& v) {\n        if (this->empty())\
    \ this->resize(1);\n        (*this)[0] -= v;\n        shrink();\n        return\
    \ *this;\n    }\n\n    FPS& operator*=(const FPS& r) {\n        auto res = atcoder::convolution(*this,\
    \ r);\n        return *this = {res.begin(), res.end()};\n    }\n\n    FPS& operator*=(const\
    \ T& v) {\n        for (auto& x : (*this)) x *= v;\n        shrink();\n      \
    \  return *this;\n    }\n\n    FPS& operator/=(const FPS& r) {\n        if (this->size()\
    \ < r.size()) {\n            this->clear();\n            return *this;\n     \
    \   }\n        int n = this->size() - r.size() + 1;\n        return *this = (rev().pre(n)\
    \ * r.rev().inv(n)).pre(n).rev();\n    }\n\n    FPS& operator%=(const FPS& r)\
    \ {\n        *this -= *this / r * r;\n        shrink();\n        return *this;\n\
    \    }\n\n    FPS operator+(const FPS& r) const { return FPS(*this) += r; }\n\n\
    \    FPS operator+(const T& v) const { return FPS(*this) += v; }\n\n    FPS operator-(const\
    \ FPS& r) const { return FPS(*this) -= r; }\n\n    FPS operator-(const T& v) const\
    \ { return FPS(*this) -= v; }\n\n    FPS operator*(const FPS& r) const { return\
    \ FPS(*this) *= r; }\n\n    FPS operator*(const T& v) const { return FPS(*this)\
    \ *= v; }\n\n    FPS operator/(const FPS& r) const { return FPS(*this) /= r; }\n\
    \n    FPS operator%(const FPS& r) const { return FPS(*this) %= r; }\n\n    FPS\
    \ operator-() const {\n        FPS ret = *this;\n        for (auto& v : ret) v\
    \ = -v;\n        return ret;\n    }\n\n    FPS differential() const {\n      \
    \  const int n = (int)this->size();\n        FPS ret(std::max(0, n - 1));\n  \
    \      for (int i = 1; i < n; i++) ret[i - 1] = (*this)[i] * T(i);\n        return\
    \ ret;\n    }\n\n    FPS integral() const {\n        const int n = (int)this->size();\n\
    \        FPS ret(n + 1);\n        ret[0] = T(0);\n        if (n > 0) ret[1] =\
    \ T(1);\n        auto mod = T::mod();\n        for (int i = 2; i <= n; i++) ret[i]\
    \ = -ret[mod % i] * (mod / i);\n        for (int i = 0; i < n; i++) ret[i + 1]\
    \ *= (*this)[i];\n        return ret;\n    }\n\n    FPS inv(int deg = -1) const\
    \ {\n        assert((*this)[0] != T(0));\n        const int n = (int)this->size();\n\
    \        if (deg == -1) deg = n;\n        FPS ret{(*this)[0].inv()};\n       \
    \ ret.reserve(deg);\n        for (int d = 1; d < deg; d <<= 1) {\n           \
    \ FPS f(d << 1), g(d << 1);\n            std::copy(this->begin(), this->begin()\
    \ + std::min(n, d << 1), f.begin());\n            std::copy(ret.begin(), ret.end(),\
    \ g.begin());\n            atcoder::internal::butterfly(f);\n            atcoder::internal::butterfly(g);\n\
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
    \ if (deg == -1) deg = n;\n        for (int i = 0; i < n; i++) {\n           \
    \ if ((*this)[i] != T(0)) {\n                if (i * k > deg) return FPS(deg,\
    \ T(0));\n                T rev = (*this)[i].inv();\n                FPS ret =\
    \ (((*this * rev) >> i).log(deg) * k).exp(deg) * ((*this)[i].pow(k));\n      \
    \          ret = (ret << (i * k)).pre(deg);\n                if ((int)ret.size()\
    \ < deg) ret.resize(deg, T(0));\n                return ret;\n            }\n\
    \        }\n        return FPS(deg, T(0));\n    }\n\n    T eval(T x) const {\n\
    \        T ret = 0, w = 1;\n        for (const auto& v : *this) ret += w * v,\
    \ w *= x;\n        return ret;\n    }\n};\n#line 2 \"util/modint.hpp\"\n#include\
    \ <iostream>\n#line 4 \"util/modint.hpp\"\n\nnamespace atcoder {\n\ntemplate <int\
    \ MOD> std::istream& operator>>(std::istream& is, static_modint<MOD>& x) {\n \
    \   int64_t v;\n    x = static_modint<MOD>{(is >> v, v)};\n    return is;\n}\n\
    \ntemplate <int MOD> std::ostream& operator<<(std::ostream& os, const static_modint<MOD>&\
    \ x) { return os << x.val(); }\n\ntemplate <int ID> std::ostream& operator<<(std::ostream&\
    \ os, const dynamic_modint<ID>& x) { return os << x.val(); }\n\n}  // namespace\
    \ atcoder\n#line 6 \"test/yosupo/multipoint_evaluation.test.cpp\"\n\nusing mint\
    \ = atcoder::modint998244353;\nusing Poly = FormalPowerSeries<mint>;\n\nint main()\
    \ {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, M;\n\
    \    std::cin >> N >> M;\n    Poly c(N);\n    std::vector<mint> p(M);\n    for\
    \ (int i = 0; i < N; i++) std::cin >> c[i];\n    for (int i = 0; i < M; i++) std::cin\
    \ >> p[i];\n\n    subproduct_tree<mint> tree(p);\n    auto f = tree.multipoint_evaluation(c);\n\
    \    for (int i = 0; i < M; i++) std::cout << f[i] << (i + 1 == M ? '\\n' : '\
    \ ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/multipoint_evaluation\"\
    \n\n#include \"polynomial/multipoint_evaluation.hpp\"\n#include \"polynomial/FormalPowerSeries.hpp\"\
    \n#include \"util/modint.hpp\"\n\nusing mint = atcoder::modint998244353;\nusing\
    \ Poly = FormalPowerSeries<mint>;\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    Poly c(N);\n    std::vector<mint>\
    \ p(M);\n    for (int i = 0; i < N; i++) std::cin >> c[i];\n    for (int i = 0;\
    \ i < M; i++) std::cin >> p[i];\n\n    subproduct_tree<mint> tree(p);\n    auto\
    \ f = tree.multipoint_evaluation(c);\n    for (int i = 0; i < M; i++) std::cout\
    \ << f[i] << (i + 1 == M ? '\\n' : ' ');\n}"
  dependsOn:
  - polynomial/multipoint_evaluation.hpp
  - polynomial/FormalPowerSeries.hpp
  - polynomial/FormalPowerSeries.hpp
  - util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/multipoint_evaluation.test.cpp
  requiredBy: []
  timestamp: '2022-10-18 10:53:32+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/multipoint_evaluation.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/multipoint_evaluation.test.cpp
- /verify/test/yosupo/multipoint_evaluation.test.cpp.html
title: test/yosupo/multipoint_evaluation.test.cpp
---