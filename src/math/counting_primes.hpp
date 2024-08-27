#pragma once
#include <cmath>
#include <utility>
#include <vector>

namespace internal {

std::pair<std::vector<long long>, std::vector<long long>> pi_table(long long N) {
    std::vector<long long> ns{0};
    for (long long i = N; i > 0; i = N / (N / i + 1)) ns.emplace_back(i);
    auto f = ns;
    for (auto& val : f) val--;
    for (long long x = 2, sqN = sqrtl(N), len = ns.size(); x <= sqN; x++) {
        if (f[len - x] == f[len - x + 1]) continue;
        long long x2 = x * x, pi = f[len - x + 1];
        for (long long i = 1, n = ns[i]; i < len and n >= x2; n = ns[++i]) {
            f[i] -= f[i * x <= sqN ? i * x : len - n / x] - pi;
        }
    }
    return {ns, f};
}

}  // namespace internal

long long counting_primes(long long N) {
    if (N < 2) return 0;
    return internal::pi_table(N).second[1];
}