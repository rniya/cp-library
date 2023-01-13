#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D"

#include "base.hpp"
#include "datastructure/Slide_Min.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];

    vector<int> ans = Slide_Min(a, L);
    for (size_t i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
}