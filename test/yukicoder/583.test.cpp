#define PROBLEM "https://yukicoder.me/problems/no/583"

#include "../../base.hpp"
#include "../../graph/EulerianTrail.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    EulerianTrail<false> ET(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        ET.add_edge(a, b);
    }

    cout << (ET.solve_semi().size() == 1 ? "YES" : "NO") << '\n';
}