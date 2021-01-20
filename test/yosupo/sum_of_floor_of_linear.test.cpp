#define PROBLEM "https://judge.yosupo.jp/problem/sum_of_floor_of_linear"

#include "../../base.hpp"
#include "../../math/floor_sum.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (; T--;) {
        int N, M, A, B;
        cin >> N >> M >> A >> B;
        cout << floor_sum(N, M, A, B) << '\n';
    }
}