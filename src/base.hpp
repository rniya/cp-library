#pragma once
#include <bits/stdc++.h>
#ifdef LOCAL
#include <debug.hpp>
#else
#define debug(...) void(0)
#endif

using namespace std;

typedef long long ll;
#define all(x) begin(x), end(x)
constexpr int INF = (1 << 30) - 1;
constexpr long long IINF = (1LL << 60) - 1;
constexpr int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

template <class T> istream& operator>>(istream& is, vector<T>& v) {
    for (auto& x : v) is >> x;
    return is;
}

template <class T> ostream& operator<<(ostream& os, const vector<T>& v) {
    auto sep = "";
    for (const auto& x : v) os << exchange(sep, " ") << x;
    return os;
}

template <class T, class U = T> bool chmin(T& x, U&& y) { return y < x and (x = forward<U>(y), true); }

template <class T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = forward<U>(y), true); }

template <class T> void mkuni(vector<T>& v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <class T> int lwb(const vector<T>& v, const T& x) { return lower_bound(begin(v), end(v), x) - begin(v); }
