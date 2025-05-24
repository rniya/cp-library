#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void(0)
#endif

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x and (x = std::forward<U>(y), true); }

template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y), true); }

template <class T> void mkuni(std::vector<T>& v) {
    std::ranges::sort(v);
    auto result = std::ranges::unique(v);
    v.erase(result.begin(), result.end());
}

template <class T> int lwb(const std::vector<T>& v, const T& x) {
    return std::distance(v.begin(), std::ranges::lower_bound(v, x));
}
