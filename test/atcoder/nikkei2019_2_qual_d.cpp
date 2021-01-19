#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d"

#include "../../base.hpp"
#include "../../graph/RangeEdgeGraph.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    RangeEdgeGraph<long long> REG(N);
    for (; M--;) {
        int L, R, C;
        cin >> L >> R >> C;
        --L;
        REG.add_edge(L, R, L, R, C);
    }

    long long ans = REG.build(0)[N - 1];
    cout << (ans > 1e15 ? -1 : ans) << '\n';
}