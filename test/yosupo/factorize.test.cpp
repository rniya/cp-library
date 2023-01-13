#define PROBLEM "https://judge.yosupo.jp/problem/factorize"

#include "base.hpp"
#include "math/fast_factorize.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    for (; Q--;) {
        long long a;
        cin >> a;
        auto res = fast_factorize::factorize(a);
        cout << res.size();
        for (auto& x : res) cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}