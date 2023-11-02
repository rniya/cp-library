#pragma once
#include <cassert>
#include <vector>

namespace internal {

unsigned long long f(unsigned long long,
                     const std::vector<unsigned long long>&,
                     const std::vector<unsigned long long>&,
                     const std::vector<unsigned long long>&);
unsigned long long g(unsigned long long,
                     const std::vector<unsigned long long>&,
                     const std::vector<unsigned long long>&,
                     const std::vector<unsigned long long>&);

unsigned long long f(unsigned long long S,
                     const std::vector<unsigned long long>& G,
                     const std::vector<unsigned long long>& path,
                     const std::vector<unsigned long long>& cycle) {
    unsigned long long res = 1;
    for (; S;) {
        int v = __builtin_ctzll(S);
        unsigned long long comp = 1ULL << v, seen = 0;
        for (; comp & ~seen;) {
            int u = __builtin_ctzll(comp & ~seen);
            comp |= G[u] & S;
            seen |= 1ULL << u;
        }
        res *= g(comp, G, path, cycle);
        S &= ~comp;
    }
    return res;
}

unsigned long long g(unsigned long long S,
                     const std::vector<unsigned long long>& G,
                     const std::vector<unsigned long long>& path,
                     const std::vector<unsigned long long>& cycle) {
    if (!S) return 1;
    if (!(S & (S - 1))) return 2;
    int maxi = -1, argmax = -1, one = 0, tot = __builtin_popcountll(S);
    for (unsigned long long T = S; T;) {
        int v = __builtin_ctzll(T);
        T &= ~(1ULL << v);
        int deg = __builtin_popcountll(G[v] & S);
        if (maxi < deg) {
            maxi = deg;
            argmax = v;
        }
        one += (deg == 1);
    }
    if (maxi <= 2) return one ? path[tot] : cycle[tot];
    S &= ~(1ULL << argmax);
    return f(S, G, path, cycle) + f(S & ~G[argmax], G, path, cycle);
}

}  // namespace internal

unsigned long long count_independent_set(const std::vector<unsigned long long>& G) {
    int n = G.size();
    assert(n < 64);
    if (n == 0) return 1;
    std::vector<unsigned long long> path(n + 1), cycle(n + 1);
    path[0] = 1, path[1] = 2;
    for (int i = 2; i <= n; i++) path[i] = path[i - 1] + path[i - 2];
    cycle[0] = 2, cycle[1] = 1;
    for (int i = 2; i <= n; i++) cycle[i] = cycle[i - 1] + cycle[i - 2];
    return internal::f((1ULL << n) - 1, G, path, cycle);
}
