#pragma once
#include <cmath>
#include <vector>

template <typename T, T (*f)(long long, long long)> struct sum_of_multiplicative_function {
    sum_of_multiplicative_function(long long N) : N(N), sqN(sqrtl(N)) {
        std::vector<bool> is_prime(sqN + 1, true);
        for (int i = 2; i <= sqN; i++) {
            if (not is_prime[i]) continue;
            primes.emplace_back(i);
            for (int j = 2 * i; j <= sqN; j += i) is_prime[j] = false;
        }
        quotients.emplace_back(0);
        for (long long i = N; i > 0; i = N / (N / i + 1)) quotients.emplace_back(i);
        len = quotients.size();
    }

    std::vector<T> counting_primes() {
        return calc([](long long n) -> T { return n; });
    }

    std::vector<T> summing_primes() {
        return calc([](long long n) -> T { return T(n) * (n + 1) / 2; });
    }

    T solve(const std::vector<T>& S_prime) {
        if (N <= 0) return 0;
        T res = S_prime[idx(N)] + 1;
        for (int i = 0; i < int(primes.size()); i++) dfs(primes[i], i, 1, 1, res, S_prime);
        return res;
    }

    T sum_of_totient_function() {
        auto S0 = counting_primes();
        auto S1 = summing_primes();
        for (int i = 0; i < int(S1.size()); i++) S1[i] -= S0[i];
        return solve(S1);
    }

  private:
    long long N, sqN;
    int len;
    std::vector<int> primes;
    std::vector<long long> quotients;

    void dfs(long long n, int i, int c, T cur, T& sum, const std::vector<T>& S_prime) {
        sum += cur * f(primes[i], c + 1);
        long long lim = N / n;
        if (1LL * primes[i] * primes[i] <= lim) dfs(n * primes[i], i, c + 1, cur, sum, S_prime);
        cur *= f(primes[i], c);
        sum += cur * (S_prime[idx(lim)] - S_prime[idx(primes[i])]);
        int j = i + 1;
        for (; j < int(primes.size()) and 1LL * primes[j] * primes[j] <= lim; j++)
            dfs(n * primes[j], j, 1, cur, sum, S_prime);
    }

    template <class G> std::vector<T> calc(G g) {
        std::vector<T> dp(len);
        for (int i = 1; i < len; i++) dp[i] = g(quotients[i]) - g(1);
        for (long long x = 2; x <= sqN; x++) {
            if (dp[len - x] == dp[len - x + 1]) continue;
            long long x2 = x * x;
            T pi = dp[len - x + 1], xi = dp[len - x] - dp[len - x + 1];
            for (long long i = 1, n = quotients[i]; i < len and n >= x2; n = quotients[++i]) {
                dp[i] -= xi * (dp[i * x <= sqN ? i * x : len - n / x] - pi);
            }
        }
        return dp;
    }

    int idx(long long n) { return n <= sqN ? len - n : N / n; }
};
