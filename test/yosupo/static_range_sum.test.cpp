#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"

#include "base.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<long long> sum(N + 1, 0);
    for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + a[i];

    for (; Q--;) {
        int l, r;
        cin >> l >> r;
        cout << sum[r] - sum[l] << '\n';
    }
}