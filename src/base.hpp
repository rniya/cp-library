#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void(0)
#endif

template <class T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

template <class T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {
    auto sep = "";
    for (const auto& x : v) os << std::exchange(sep, " ") << x;
    return os;
}

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x and (x = std::forward<U>(y), true); }

template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = std::forward<U>(y), true); }

template <class T> void mkuni(std::vector<T>& v) {
    std::sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <class T> int lwb(const std::vector<T>& v, const T& x) {
    return std::lower_bound(begin(v), end(v), x) - begin(v);
}
