#pragma once
#include <algorithm>
#include <tuple>
#include <vector>

namespace count_graphs {

std::vector<std::tuple<int, int, int>> enumerate_C4(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = G[i].size();
    auto comp = [&](int u, int v) -> bool { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };
    std::vector<std::vector<int>> H(n);
    for (int i = 0; i < n; i++) {
        for (const int& j : G[i]) {
            if (comp(i, j)) {
                H[i].emplace_back(j);
            }
        }
    }
    std::vector<bool> f(n, false);
    std::vector<std::tuple<int, int, int>> res;
    for (int i = 0; i < n; i++) {
        for (int& j : H[i]) f[j] = true;
        for (int& j : H[i]) {
            for (int& k : H[j]) {
                if (f[k]) {
                    res.emplace_back(i, j, k);
                }
            }
        }
        for (int& j : H[i]) f[j] = false;
    }
    return res;
}

long long count_C4(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = G[i].size();
    auto comp = [&](int u, int v) -> bool { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };
    std::vector<std::vector<int>> H(n);
    for (int i = 0; i < n; i++) {
        for (const int& j : G[i]) {
            if (comp(i, j)) {
                H[i].emplace_back(j);
            }
        }
    }
    std::vector<int> f(n, 0);
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (const int& j : G[i]) {
            for (const int& k : H[j]) {
                if (comp(i, k)) {
                    res += f[k];
                    f[k]++;
                }
            }
        }
        for (const int& j : G[i]) {
            for (const int& k : H[j]) {
                f[k] = 0;
            }
        }
    }
    return res;
}

long long count_K4(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> deg(n);
    for (int i = 0; i < n; i++) deg[i] = G[i].size();
    auto comp = [&](int u, int v) -> bool { return deg[u] != deg[v] ? deg[u] < deg[v] : u < v; };
    std::vector<std::vector<int>> H(n);
    for (int i = 0; i < n; i++) {
        for (const int& j : G[i]) {
            if (comp(i, j)) {
                H[i].emplace_back(j);
            }
        }
    }
    long long res = 0;
    std::vector<int> idx(n, -1);
    constexpr int B = 64;
    for (int i = 0; i < n; i++) {
        int len = H[i].size();
        for (int j = 0; j < len; j++) idx[H[i][j]] = j;
        std::vector<std::vector<int>> I(len);
        for (int j = 0; j < len; j++) {
            for (int& u : H[H[i][j]]) {
                if (idx[u] == -1) continue;
                I[j].emplace_back(idx[u]);
            }
        }
        for (int b = 0; b < (len + B - 1) / B; b++) {
            int L = B * b, R = std::min(len, L + B);
            std::vector<unsigned long long> adj(len, 0);
            for (int j = L; j < R; j++) {
                for (const int& k : I[j]) {
                    adj[k] |= 1ULL << (j - L);
                }
            }
            for (int j = 0; j < len; j++) {
                for (const int& k : I[j]) {
                    res += __builtin_popcountll(adj[j] & adj[k]);
                }
            }
        }
        for (int j = 0; j < len; j++) idx[H[i][j]] = -1;
    }
    return res;
}

}  // namespace count_graphs