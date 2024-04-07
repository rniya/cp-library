#define PROBLEM "https://yukicoder.me/problems/no/1240"

#include <iostream>
#include "math/set_function.hpp"

const int MAX_B = 18;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, X;
    std::cin >> N >> X;
    std::vector<int> A(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];

    long long ans = 0;
    std::vector<long long> cnt(1 << MAX_B, 0);
    for (int i = 0; i < N; i++) cnt[A[i]]++;
    std::vector<long long> conv = set_function::xor_convolution(cnt, cnt);
    for (int i = 0; i < X; i++) ans += conv[i] * i;

    for (int j = 0, mask = 1; j < MAX_B; j++, mask <<= 1) {
        fill(cnt.begin(), cnt.end(), 0);
        for (int i = 0; i < N; i++) {
            if (A[i] & mask) {
                cnt[A[i]]++;
                ans -= mask;
            }
        }
        conv = set_function::xor_convolution(cnt, cnt);
        for (int i = 0; i < X; i++) ans += conv[i] * mask;
    }

    std::cout << ans / 2 << '\n';
    return 0;
}