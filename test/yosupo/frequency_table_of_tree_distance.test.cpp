#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include <iostream>
#include "atcoder/convolution"
#include "tree/CentroidDecomposition.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    CentroidDecomposition CD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        CD.add_edge(a, b);
    }

    std::vector<int> alive(N, true);
    auto& G = CD.G;
    auto calc = [&](auto self, int v, int p, int d, std::vector<int>& cnt) -> void {
        while ((int)cnt.size() <= d) cnt.emplace_back(0);
        cnt[d]++;
        for (int& u : G[v]) {
            if (u == p || !alive[u]) continue;
            self(self, u, v, d + 1, cnt);
        }
    };

    auto cs = CD.build();
    std::vector<long long> ans(2 * N, 0);

    for (int& root : cs) {
        alive[root] = 0;
        std::vector<int> sum{1};
        for (int& ch : G[root]) {
            if (!alive[ch]) continue;
            std::vector<int> cnt;
            calc(calc, ch, root, 1, cnt);
            auto sub = atcoder::convolution(cnt, cnt);
            for (size_t i = 0; i < sub.size(); i++) ans[i] -= sub[i];
            while (sum.size() < cnt.size()) sum.emplace_back(0);
            for (size_t i = 0; i < cnt.size(); i++) sum[i] += cnt[i];
        }
        auto add = atcoder::convolution(sum, sum);
        for (size_t i = 0; i < add.size(); i++) ans[i] += add[i];
    }

    for (int i = 1; i < N; i++) std::cout << ans[i] / 2 << (i + 1 == N ? '\n' : ' ');
}