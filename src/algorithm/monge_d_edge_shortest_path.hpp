#include <cassert>
#include <functional>
#include <limits>
#include <vector>
#include "golden_section_search.hpp"

template <typename T> std::vector<T> monge_shortest_path(int N, const std::function<T(int, int)>& f) {
    std::vector<T> dp(N + 1, std::numeric_limits<T>::max() / 2);
    std::vector<int> x(N + 1);
    dp[0] = x[0] = 0, x[N] = N;
    auto check = [&](int from, int to) {
        if (from >= to) return;
        T cost = f(from, to);
        if (dp[from] + cost < dp[to]) {
            dp[to] = dp[from] + cost;
            x[to] = from;
        }
    };
    auto solve = [&](auto&& self, int l, int r) -> void {
        if (l >= r) return;
        int m = (l + r) >> 1;
        x[m] = x[l];
        for (int i = x[l]; i <= x[r]; i++) check(i, m);
        if (r - l > 1) self(self, l, m);
        for (int i = l; i <= m; i++) check(i, r);
        if (r - l > 1) self(self, m, r);
    };
    solve(solve, 0, N);
    return dp;
}

long long monge_d_edge_shortest_path(int N, int D, long long upper, const std::function<long long(int, int)>& f) {
    assert(0 <= upper);
    auto dp = [&](long long x) -> long long {
        auto g = [&](int from, int to) -> long long { return f(from, to) + x; };
        long long cost = monge_shortest_path<long long>(N, g)[N];
        return cost - 1LL * D * x;
    };
    auto [tmp, res] = golden_section_search<long long, false>(dp, -upper, upper);
    return res;
}