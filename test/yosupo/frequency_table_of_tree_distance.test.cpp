#define PROBLEM "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"

#include "../../base.hpp"
#include "../../convolution/FastFourierTransform.hpp"
#include "../../tree/CentroidDecomposition.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    CentroidDecomposition CD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        CD.add_edge(a, b);
    }

    vector<long long> ans(N, 0);
    auto calc = [&](auto self, int v, int p, int d, vector<int>& cnt) -> void {
        while (cnt.size() <= d) cnt.emplace_back(0);
        cnt[d]++;
        for (int u : CD[v]) {
            if (u == p || !CD.alive(u)) continue;
            self(self, u, v, d + 1, cnt);
        }
    };
    auto dfs = [&](auto self, int v) -> void {
        int c = CD.build(v);
        CD.disable(c);
        vector<int> sum{1};
        for (int u : CD[c]) {
            if (!CD.alive(u)) continue;
            self(self, u);
            vector<int> cnt;
            calc(calc, u, c, 1, cnt);
            while (sum.size() < cnt.size()) sum.emplace_back(0);
            for (int i = 0; i < cnt.size(); i++) sum[i] += cnt[i];
            auto mul = FastFourierTransform::multiply(cnt, cnt);
            for (int i = 0; i < mul.size(); i++) ans[i] -= mul[i];
        }
        auto ret = FastFourierTransform::multiply(sum, sum);
        for (int i = 0; i < ret.size(); i++) ans[i] += ret[i];
        CD.enable(c);
    };

    dfs(dfs, 0);
    for (int i = 1; i < N; i++) cout << ans[i] / 2 << (i + 1 == N ? '\n' : ' ');
}