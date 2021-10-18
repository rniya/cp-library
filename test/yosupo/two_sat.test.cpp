#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../base.hpp"
#include "../../graph/TwoSAT.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string p, cnf;
    int N, M;
    cin >> p >> cnf >> N >> M;

    TwoSAT TS(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        TS.add_clause(abs(a), (a > 0), abs(b), (b > 0));
    }

    if (!TS.satisfiable()) {
        cout << "s UNSATISFIABLE" << '\n';
        return 0;
    }
    cout << "s SATISFIABLE" << '\n';
    cout << "v ";
    auto ans = TS.answer();
    for (int i = 1; i <= N; i++) cout << (ans[i] ? i : -i) << ' ';
    cout << "0\n";
    return 0;
}