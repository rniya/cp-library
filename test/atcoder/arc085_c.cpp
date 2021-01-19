#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/arc085/tasks/arc085_c"

#include "../../base.hpp"
#include "../../flow/ProjectSelectionProblem.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const long long inf = 1e18;
    int N;
    cin >> N;

    ProjectSelectionProblem<long long> PSP(N);
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        if (a > 0)
            PSP.x_false_profit(i - 1, a);
        else
            PSP.x_false_loss(i - 1, -a);
        for (int j = 2 * i; j <= N; j += i) {
            PSP.x_true_y_false_loss(i - 1, j - 1, inf);
        }
    }

    cout << -PSP.build() << '\n';
}