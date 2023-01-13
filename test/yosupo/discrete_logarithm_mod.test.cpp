#define PROBLEM "https://judge.yosupo.jp/problem/discrete_logarithm_mod"

#include "base.hpp"
#include "math/discrete_logarithm.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (; T--;) {
        int X, Y, M;
        cin >> X >> Y >> M;
        cout << discrete_logarithm(X, Y, M) << '\n';
    }
    return 0;
}