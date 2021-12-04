#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <iostream>
#include "algorithm/Mo.hpp"
#include "atcoder/fenwicktree"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    Mo mo(N);
    for (int i = 0; i < Q; i++) {
        int l, r;
        std::cin >> l >> r;
        mo.add(l, r);
    }

    std::vector<int> B = A;
    sort(B.begin(), B.end());
    B.erase(unique(B.begin(), B.end()), B.end());
    for (int i = 0; i < N; i++) A[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
    int n = B.size();
    atcoder::fenwick_tree<int> FT(n);
    std::vector<long long> ans(Q);
    long long inv = 0;
    int sum = 0;

    auto add_left = [&](int idx) {
        inv += FT.sum(0, A[idx]);
        sum++;
        FT.add(A[idx], 1);
    };
    auto add_right = [&](int idx) {
        inv += FT.sum(A[idx] + 1, n);
        sum++;
        FT.add(A[idx], 1);
    };
    auto del_left = [&](int idx) {
        inv -= FT.sum(0, A[idx]);
        sum--;
        FT.add(A[idx], -1);
    };
    auto del_right = [&](int idx) {
        inv -= FT.sum(A[idx] + 1, n);
        sum--;
        FT.add(A[idx], -1);
    };
    auto rem = [&](int idx) { ans[idx] = inv; };

    mo.run(add_left, add_right, del_left, del_right, rem);

    for (int i = 0; i < Q; i++) std::cout << ans[i] << '\n';
    return 0;
}